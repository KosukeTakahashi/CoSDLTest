//
// Created by 髙橋孝輔 on 2020/10/19.
//

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "evutils.hpp"
#include "Ball.h"
#include "Position.h"

Ball::Ball() = default;

Ball::~Ball() = default;

void Ball::start() {}

void Ball::update() {
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    auto pos = this->parent->getComponent<Position>();
    if (keyState[SDL_SCANCODE_UP])
        pos->setY(pos->getY() - 1.0F);
    else if (keyState[SDL_SCANCODE_DOWN])
        pos->setY(pos->getY() + 1.0F);

    if (keyState[SDL_SCANCODE_RIGHT])
        pos->setX(pos->getX() + 1.0F);
    else if (keyState[SDL_SCANCODE_LEFT])
        pos->setX(pos->getX() - 1.0F);
}

void Ball::render(SDL_Renderer *renderer) {
    auto pos = this->parent->getComponent<Position>();
    filledCircleRGBA(renderer, (int) pos->getX(), (int) pos->getY(), 10, 255, 0, 0, 255);
}
