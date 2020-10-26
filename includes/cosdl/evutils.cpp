#include <SDL.h>
#include "logger.hpp"
#include "./evcodes.hpp"
#include "./evutils.hpp"

void EventUtils::dispatchQuit() {
    if (!SDL_WasInit(SDL_INIT_EVENTS)) {
        Logger::warn("EventUtils#dispatchQuit", "SDL event sybsystem is not initialized. Abort.");
        return;
    }

    SDL_Event quitEv;
    quitEv.type = SDL_USEREVENT;
    quitEv.user.code = static_cast<int>(EventCodes::QUIT);
    SDL_PushEvent(&quitEv);
}

void EventUtils::dispatchExitScene() {
    if (!SDL_WasInit(SDL_INIT_EVENTS)) {
        Logger::warn("EventUtils#dispatchQuit", "SDL event sybsystem is not initialized. Abort.");
        return;
    }

    SDL_Event quitEv;
    quitEv.type = SDL_USEREVENT;
    quitEv.user.code = static_cast<int>(EventCodes::EXIT_SCENE);
    SDL_PushEvent(&quitEv);
}
