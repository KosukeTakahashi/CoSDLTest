//
// Created by 髙橋孝輔 on 2020/10/22.
//

#ifndef COSDLTEST_TEXT_H
#define COSDLTEST_TEXT_H

#include <string>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>
#include "Component.hpp"

class Text : public Component {
private:
    bool updateFlag;
    int size;
    std::string text;
    SDL_Surface *textSurface;

public:
    Text();

    ~Text();

    void start() override;

    void update() override;

    void render(SDL_Renderer *renderer) override;

    void setSize(const int size);

    void setText(const std::string &newText);
};


#endif //COSDLTEST_TEXT_H
