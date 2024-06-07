#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>

#include "..\Message.h"
#include "Scene.h"

class SceneManager {
public:
	SceneManager(MessageBus& bus);
	void pushScene(const Message& message);
	std::shared_ptr<Scene> getScene();
private:
	std::vector<std::shared_ptr<Scene>> sceneStack;
	MessageBus& bus;
};

#endif
