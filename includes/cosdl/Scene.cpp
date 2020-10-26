#include <thread>
#include <SDL.h>
#include "./Scene.hpp"
#include "evcodes.hpp"
#include "logger.hpp"

Scene::Scene() {
}

Scene::~Scene() {
}

bool Scene::run(int fps, SDL_Renderer *renderer) {
    auto intervalMs = fps <= 0 ? 0 : 1000 / fps;
    SDL_Event ev;
    while (true) {
        auto start = SDL_GetTicks();
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT)
                return true;

            if (ev.type == SDL_USEREVENT) {
                if (ev.user.code == static_cast<int>(EventCodes::QUIT))
                    return true;
                else if (ev.user.code == static_cast<int>(EventCodes::EXIT_SCENE))
                    return false;
            }
        }

        for (const auto &obj : this->objects) {
            obj->update();
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (const auto &obj : this->objects) {
            obj->render(renderer);
        }
        SDL_RenderPresent(renderer);
        auto end = SDL_GetTicks();
        auto elapsed = end - start;
        if (elapsed < intervalMs) {
            SDL_Delay(intervalMs - elapsed);
        }

//        std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
    }
}

std::shared_ptr<GameObject> Scene::addGameObject(std::string label) {
    // Check if a object of the same label exists
    for (auto obj : this->objects) {
        if (obj->label == label) {
            Logger::warn("Scene#addGameObject", "A object of the same label found. Abort.");
            return nullptr;
        }
    }

    auto obj = std::make_shared<GameObject>();
    obj->label = label;
    obj->parent = this;
    this->objects.push_back(obj);
    return obj;
}

std::shared_ptr<GameObject> Scene::getGameObject(std::string label) {
    for (auto obj : this->objects) {
        if (obj->label == label) {
            return obj;
        }
    }

    return nullptr;
}

bool Scene::removeGameObject(std::string label) {
    auto targetIter = this->objects.begin();
    for (; targetIter != this->objects.end(); targetIter++) {
        if ((*targetIter)->label == label) {
            this->objects.erase(targetIter);
            return true;
        }
    }

    return false;
}
