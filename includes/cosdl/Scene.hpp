#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <list>
#include <thread>
#include <string>
#include <SDL.h>
#include "./GameObject.hpp"

class GameObject;

/**
 * ゲーム
 *   ∟ Scene          ← これ
 *     ⊢ GameObject
 *     | ⊢ Component
 *     | ⊢ Component
 *     | :
 *     |
 *     ⊢ GameObject
 *     | ⊢ Component
 *     | ⊢ Component
 *     | :
 *     :
 */
class Scene {
private:
    std::list<std::shared_ptr<GameObject>> objects;

public:
    // コンストラクタ
    Scene();

    // デストラクタ
    ~Scene();

    /**
     * シーンを実行する．
     * \param fps      最大fps
     * \param renderer レンダリング対象の SDL_Renderer*
     * \returns シーンの終了後続行する場合はfalse, さもなくばtrues
     */
    bool run(int fps, SDL_Renderer *renderer);

    /**
     * GameObject を追加する．
     * \param label 追加する GameObject に付加する，同一 Scene 内で一意なラベル．
     * \returns 追加した GameObject
     */
    std::shared_ptr<GameObject> addGameObject(std::string label);

    /**
     * GameObject をラベルによって検索する．
     * \param label 検索対象のラベル．
     * \returns 見つかればその GameObject，見つからなければ nullptr．
     */
    std::shared_ptr<GameObject> getGameObject(std::string label);

    /**
     * GameObject を検索し，削除する
     * \param label 削除対象のラベル．
     * \returns 削除対象が見つかり，削除されれば true，見つからなければ false．
     */
    bool removeGameObject(std::string label);
};

#endif
