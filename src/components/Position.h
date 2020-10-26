//
// Created by 髙橋孝輔 on 2020/10/19.
//

#ifndef HELLOCLION_POSITION_H
#define HELLOCLION_POSITION_H

#include <SDL.h>
#include "Component.hpp"

class Position : public Component {
private:
    float x;
    float y;

public:

    Position();

    ~Position();

    void start() override;

    void update() override;

    void render(SDL_Renderer *renderer) override;

    void setX(float newX);

    [[nodiscard]] float getX() const;

    void setY(float newY);

    [[nodiscard]] float getY() const;
};

#endif //HELLOCLION_POSITION_H
