#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>
#include <any>

enum class MessageType {
    RENDER,
    LOG,
    INPUT,
    SCENE
};

enum SceneList {

    BACK,
    MAINMENU,
    STATUS,
    CITY,
    COMBAT,
    DUNGEON,

};

enum InputList {

    QUIT,
    RETURN,
    MENU,
    SAVE,
    LOAD,
    OPTION_A,
    OPTION_B,
    OPTION_C,
    OPTION_D,
    OPTION_E,
    OPTION_F,
    OPTION_G,
    OPTION_H,
    OPTION_I,
    OPTION_J,
    YES,
    NO,

};

enum RenderType {
    MIDDLE,
    TOPBAR,
    BOTBAR,
    SIDEBAR
};

struct RenderMail {
    RenderType type;
    std::string string;
};

struct Message {
    MessageType type;
    std::any data;
};

class MessageBus {
public:
    void subscribe(MessageType type, std::function<void(const Message&)> callback) {
        subscribers[type].push_back(callback);
    }

    void publish(const Message& message) {
        auto it = subscribers.find(message.type);
        if (it != subscribers.end()) {
            for (auto& callback : it->second) {
                callback(message);
            }
        }
    }

private:
    std::unordered_map<MessageType, std::vector<std::function<void(const Message&)>>> subscribers;
};

#endif
