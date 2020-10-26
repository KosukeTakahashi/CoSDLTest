//
// Created by 髙橋孝輔 on 2020/10/22.
//

#include <SDL.h>
#include <SDL_ttf.h>
#include "evutils.hpp"
#include "logger.hpp"
#include "Text.h"
#include "Position.h"

Text::Text() : text(""),
               size(0),
               updateFlag(false),
               textSurface(nullptr) {}

Text::~Text() = default;

void Text::start() {
    if (!TTF_WasInit()) {
        Logger::warn("Component Text", "SDL_TTF was not initialized. Initializing now...");
        if (TTF_Init() != 0) {
            Logger::warn("Component Text", "Failed to initialize SDL_TTF. Abort.");
            EventUtils::dispatchQuit();
            return;
        } else {
            Logger::log("Component Text", "Successfully initialized SDL_TTF.");
        }
    }
}

void Text::update() {
    if (this->updateFlag) {
        if (this->textSurface != nullptr) {
            SDL_FreeSurface(this->textSurface);
            this->textSurface = nullptr;
        }

        auto font = TTF_OpenFont("../assets/mplus-1m-medium.ttf", this->size);
        if (font == nullptr) {
            Logger::warn("Component Text", "Could not open the font file. Abort.");
            return;
        }

        this->textSurface = TTF_RenderUTF8_Blended(font, this->text.c_str(), SDL_Color{0, 0, 0, 255});
        TTF_CloseFont(font);

        this->updateFlag = false;
    }
}

void Text::render(SDL_Renderer *renderer) {
    auto pos = this->parent->getComponent<Position>();
    if (pos == nullptr) {
        Logger::warn("Component Text", "The object has no component of type Position.");
        return;
    }

    SDL_Rect src = {
            0,
            0,
            this->textSurface->w,
            this->textSurface->h
    };

    SDL_Rect dst = {
            static_cast<int>(pos->getX() - this->textSurface->w / 2),
            static_cast<int>(pos->getY() - this->textSurface->h / 2),
            this->textSurface->w,
            this->textSurface->h
    };

    auto texture = SDL_CreateTextureFromSurface(renderer, this->textSurface);
    SDL_RenderCopy(renderer, texture, &src, &dst);
    SDL_DestroyTexture(texture);
}

void Text::setSize(const int size) {
    this->size = size;
    this->updateFlag = true;
}

void Text::setText(const std::string &newText) {
    this->text = newText;
    this->updateFlag = true;
}
