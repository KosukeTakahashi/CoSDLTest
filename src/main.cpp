#include <iostream>
#include <memory>
#include <SDL.h>
#include "Scene.hpp"
#include "logger.hpp"
#include "evutils.hpp"
#include "components/Ball.h"
#include "components/Position.h"
#include "components/Text.h"
#include "components/KeyListener.h"

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::warn("Main", "Failed to initialize SDL. Abort.");
        return 1;
    }

    auto window = SDL_CreateWindow("SDL!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);

    {
        auto startScene = std::make_unique<Scene>();
        {
            auto obj = startScene->addGameObject("Title");

            auto txt = obj->addComponent<Text>();
            auto pos = obj->addComponent<Position>();
            txt->setSize(24);
            txt->setText("The test app for CoSDL. Press S to start or Q to quit.");
            pos->setX(400.0F);
            pos->setY(300.0F);

            auto listenerObj = startScene->addGameObject("Listener");
            auto listener = listenerObj->addComponent<KeyListener>();
            listener->setCallback([](const Uint8 *keyState) {
                if (keyState[SDL_SCANCODE_S])
                    EventUtils::dispatchExitScene();
                else if (keyState[SDL_SCANCODE_Q])
                    EventUtils::dispatchQuit();
            });
        }
        if (startScene->run(60, renderer)) {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            return 0;
        }
    }

    {
        auto mainScene = std::make_unique<Scene>();
        {
            auto obj = mainScene->addGameObject("Ball1");
            auto pos = obj->addComponent<Position>();
            auto ball = obj->addComponent<Ball>();

            auto listenerObj = mainScene->addGameObject("Listener");
            auto listener = listenerObj->addComponent<KeyListener>();
            listener->setCallback([](const Uint8 *keyState) {
                if (keyState[SDL_SCANCODE_Q])
                    EventUtils::dispatchExitScene();
            });
        }

        mainScene->run(60, renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}
