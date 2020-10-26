//
// Created by 髙橋孝輔 on 2020/10/19.
//

#ifndef HELLOCLION_BALL_H
#define HELLOCLION_BALL_H

#include <SDL.h>
#include "Component.hpp"

class Ball : public Component {
public:
    Ball();

    ~Ball();

    void start() override;

    void update() override;

    void render(SDL_Renderer *renderer) override;
};


#endif //HELLOCLION_BALL_H
