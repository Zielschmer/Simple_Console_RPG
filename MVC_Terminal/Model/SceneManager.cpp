#include "SceneManager.h"

#include "scene_City.h"
#include "scene_Combat.h"
#include "scene_Dungeon.h"
#include "scene_MainMenu.h"
#include "scene_Status.h"

SceneManager::SceneManager(MessageBus& bus) : bus(bus){
	bus.subscribe(MessageType::SCENE, [this](const Message& message) { this->pushScene(message); });
	bus.subscribe(MessageType::INPUT, [this](const Message& message) {this->getScene()->handleInput(message); });
	sceneStack.push_back(std::shared_ptr<Scene>(new MainMenu(bus)));
}
void SceneManager::pushScene(const Message& message) {
	switch (std::any_cast<SceneList>(message.data))
	{
	case SceneList::BACK:
		sceneStack.pop_back();
		break;
	case MAINMENU:
		sceneStack.push_back(std::shared_ptr<Scene>(new MainMenu(bus)));
		break;
	case STATUS:
		sceneStack.push_back(std::shared_ptr<Scene>(new SceneStatus(bus)));
		break;
	case CITY:
		sceneStack.push_back(std::shared_ptr<Scene>(new SceneCity(bus)));
		break;
	case COMBAT:
		sceneStack.push_back(std::shared_ptr<Scene>(new SceneCombat(bus)));
		break;
	case DUNGEON:
		sceneStack.push_back(std::shared_ptr<Scene>(new SceneDungeon(bus)));
		break;
	default:
		break;
	}
}
std::shared_ptr<Scene> SceneManager::getScene() {
	return sceneStack.back();
}