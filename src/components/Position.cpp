//
// Created by 髙橋孝輔 on 2020/10/19.
//

#include <SDL.h>
#include "Position.h"

Position::Position() {
    this->x = 0.0f;
    this->y = 0.0f;
}

Position::~Position() = default;

void Position::start() {}

void Position::update() {}

void Position::render(SDL_Renderer *renderer) {}

void Position::setX(const float newX) {
    this->x = newX;
}

float Position::getX() const {
    return this->x;
}

void Position::setY(const float newY) {
    this->y = newY;
}

float Position::getY() const {
    return this->y;
}
