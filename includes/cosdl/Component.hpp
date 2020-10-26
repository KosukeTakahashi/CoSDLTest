#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>
#include <SDL.h>
#include "./GameObject.hpp"

class GameObject;

/**
 * ゲーム
 *   ∟ Scene
 *     ⊢ GameObject
 *     | ⊢ Component  ← これ
 *     | ⊢ Component  ← これ
 *     | :
 *     |
 *     ⊢ GameObject
 *     | ⊢ Component  ← これ
 *     | ⊢ Component  ← これ
 *     | :
 *     :
 */
class Component {
public:
    // この Component がアタッチされている GameObject
    GameObject *parent;

    // コンストラクタ
    Component() {}

    // デストラクタ
    ~Component() {}

    // 初期化時に一回だけ呼ばれる
    virtual void start() = 0;

    // フレームの更新ごとに呼ばれる
    virtual void update() = 0;

    /**
     * 描画する．
     * \param renderer 描画対象の SDL_Renderer*．
     */
    virtual void render(SDL_Renderer *renderer) = 0;
};

#endif
