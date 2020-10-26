#ifndef EV_UTILS_HPP
#define EV_UTILS_HPP

class EventUtils {
public:
    // 終了イベントを発火
    static void dispatchQuit();

    // 「シーンを抜ける」イベントを発火
    static void dispatchExitScene();
};

#endif
