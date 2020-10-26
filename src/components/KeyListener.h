//
// Created by 髙橋孝輔 on 2020/10/22.
//

#ifndef COSDLTEST_KEYLISTENER_H
#define COSDLTEST_KEYLISTENER_H

#include <functional>
#include <SDL.h>
#include "Component.hpp"

class KeyListener : public Component {
private:
    std::function<void(const Uint8 *)> callback;

public:
    KeyListener();

    ~KeyListener();

    void start() override;

    void update() override;

    void render(SDL_Renderer *renderer) override;

    void setCallback(std::function<void(const Uint8 *)> callback);
};


#endif //COSDLTEST_KEYLISTENER_H
