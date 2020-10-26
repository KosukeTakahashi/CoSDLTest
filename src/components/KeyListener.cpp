//
// Created by 髙橋孝輔 on 2020/10/22.
//

#include <functional>
#include <utility>
#include <SDL.h>
#include "KeyListener.h"

KeyListener::KeyListener() : callback([](const Uint8 *keyState) {}) {}

KeyListener::~KeyListener() {
    this->callback = [](const Uint8 *keyState) {};
}

void KeyListener::start() {}

void KeyListener::update() {
    auto keyState = SDL_GetKeyboardState(nullptr);
    this->callback(keyState);
}

void KeyListener::render(SDL_Renderer *renderer) {}

void KeyListener::setCallback(std::function<void(const Uint8 *)> callback) {
    this->callback = std::move(callback);
}
