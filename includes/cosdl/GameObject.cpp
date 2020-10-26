#include <SDL.h>
#include "./GameObject.hpp"

void GameObject::start() {
}

void GameObject::update() {
    for (auto component : this->components) {
        component->update();
    }
}

void GameObject::render(SDL_Renderer *renderer) {
    for (auto component : this->components) {
        component->render(renderer);
    }
}
