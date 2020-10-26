#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <memory>
#include <type_traits>
#include <list>
#include <string>
#include <SDL.h>
#include "./Scene.hpp"
#include "./Component.hpp"

class Scene;

class Component;

/**
 * ゲーム
 *   ∟ Scene
 *     ⊢ GameObject    ← これ
 *     | ⊢ Component
 *     | ⊢ Component
 *     | :
 *     |
 *     ⊢ GameObject    ← これ
 *     | ⊢ Component
 *     | ⊢ Component
 *     | :
 *     :
 */
class GameObject {
protected:
    std::list<std::shared_ptr<Component>> components;

public:
    // この GameObject が属する Scene．
    Scene *parent;

    // 同一 Scene 内で一意なラベル．
    std::string label;

    // コンストラクタ
    GameObject() {}

    // デストラクタ
    ~GameObject() {}

    // 初期化時に一回だけ呼ばれる．
    void start();

    // フレームの更新ごとに呼ばれる．
    void update();

    /**
     * 描画する．
     * \param renderer 描画対象の SDL_Renderer*．
     */
    void render(SDL_Renderer *renderer);

    /**
     * 指定した型のコンポーネントを追加する．
     * \tparam T 追加対象の，Component を継承するクラス．
     */
    template<class T>
    std::shared_ptr<T> addComponent() {
        // if (!std::is_base_of<Component, T>::value)
        //     return nullptr;
        static_assert(std::is_base_of<Component, T>::value, "T must derive class Component!");

        if (this->hasComponent<T>()) {
            return nullptr;
        }

        auto component = std::make_shared<T>();
        component->parent = this;
        component->start();

        this->components.push_back(std::dynamic_pointer_cast<Component>(component));

        return component;
    }

    /**
     * この GameObject が，指定した型のコンポーネントを持っているかを判定する．
     * \tparam T 検索対象の，Component を継承するクラス．
     * \returns 持っていれば true，さもなくば false．
     */
    template<class T>
    bool hasComponent() {
        // if (!std::is_base_of<Component, T>::value)
        //     return false;
        static_assert(std::is_base_of<Component, T>::value, "T must derive class Component!");

        for (auto component : this->components) {
            // return dynamic_cast<std::shared_ptr<T>>(component) != nullptr;
            if (std::dynamic_pointer_cast<T>(component) != nullptr) {
                return true;
            }
        }
        return false;
    }

    /**
     * 指定した型のコンポーネントを検索し，取得する．
     * \tparam T 検索対象の，Component を継承するクラス．
     * \returns 見つかればその コンポーネント，さもなくば nullptr．
     */
    template<class T>
    std::shared_ptr<T> getComponent() {
        static_assert(std::is_base_of<Component, T>::value, "T must derive class Component!");

        for (auto component : this->components) {
            // auto c = dynamic_cast<std::shared_ptr<T>>(component);
            auto c = std::dynamic_pointer_cast<T>(component);
            if (c != nullptr) {
                return c;
            }
        }

        return nullptr;
    }

    /**
     * 指定した型のコンポーネントを検索し，デタッチする．
     * \tparam T デタッチ対象の，Component を継承するクラス．
     * \returns デタッチ対象が見つかり，デタッチされれば true，さもなくば false．
     */
    template<class T>
    bool detatchComponent() {
        auto targetIter = this->components.begin();
        for (; targetIter != this->components.end(); targetIter++) {
            // if (dynamic_cast<std::shared_ptr<T>>(*targetIter) != nullptr)
            if (std::dynamic_pointer_cast<T>(*targetIter) != nullptr) {
                this->components.erase(targetIter);
                return true;
            }
        }

        return false;
    }
};

#endif
