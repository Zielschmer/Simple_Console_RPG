#include <vector>

#include "includes\entity.h"

static int currentID = 0;
extern std::vector<Info> infoComponents;
extern std::vector<AbilityScore> abilityScoreComponents;
extern std::vector<Armor> armorComponents;
extern std::vector<MainHand> mainHandComponents;
extern std::vector<SecondHand> secondHandComponents;
extern std::vector<Magic> magicComponents;

int pickScore(std::vector<int>& scoreOrder) {
	int score = rand() % 6;
	for (int k = 0; k < scoreOrder.size(); k++) {
		if (score == scoreOrder[k]) {
			score = pickScore(scoreOrder);
		}
	}
	return score;
}

int calculateExtra(int& extraPoints) {
	int currentExtra = rand() % 9;
	if (extraPoints < currentExtra) {
		currentExtra = calculateExtra(extraPoints);
	}
	return currentExtra;
}

Entity& characterCreation() {
	Entity* player = new Entity("000011", currentID);

	for (int i = 0; i < 6; i++) {
		if (player->checkBitset()[i] == 1) {
			switch (i)
			{
			case 0:
			{
				Info info;
				info.m_ownerID = player->getID();
				info.m_name = "Guts";
				info.m_description = "The black swordsmen";
				infoComponents.push_back(info);
				break;
			}
			case 1:
			{
				AbilityScore abilityScore;
				abilityScore.m_ownerID = player->getID();

				srand(time(NULL));

				std::vector<int> scoreOrder;
				scoreOrder.push_back(rand() % 6);
				for (int j = 0; j < 5; j++) {
					scoreOrder.push_back(pickScore(scoreOrder));
				}
				int scoreValues[6];
				int extraPoints = 27;
				for (int i = 0; i < 6; i++) {
					if (i < 5) {
						if (extraPoints > 0) {
							int addExtra = calculateExtra(extraPoints);
							scoreValues[scoreOrder[i]] = 6 + addExtra;
							extraPoints -= addExtra;
						}
						else {
							scoreValues[scoreOrder[i]] = 6;
						}
					}
					else {
						scoreValues[scoreOrder[i]] = 6 + extraPoints;
					}
				}

				abilityScore.m_strength = scoreValues[0];
				abilityScore.m_dexterity = scoreValues[1];
				abilityScore.m_constitution = scoreValues[2];
				abilityScore.m_intelligence = scoreValues[3];
				abilityScore.m_faith = scoreValues[4];
				abilityScore.m_luck = scoreValues[5];

				abilityScoreComponents.push_back(abilityScore);

			}
			default:

				break;
			}
		}
	}
	currentID++;
	return *player;
}

Info& getInfoComponent(int componentID) {
	for (int i = 0; i < infoComponents.size(); i++) {
		if (infoComponents[i].m_ownerID == componentID) {
			return infoComponents[i];
		}
	}
}

AbilityScore& getAbilityScoreComponent(int componentID) {
	for (int i = 0; i < abilityScoreComponents.size(); i++) {
		if (abilityScoreComponents[i].m_ownerID == componentID) {
			return abilityScoreComponents[i];
		}
	}
}

Armor& getArmorComponent(int componentID) {
	for (int i = 0; i < armorComponents.size(); i++) {
		if (armorComponents[i].m_ownerID == componentID) {
			return armorComponents[i];
		}
	}
}

MainHand& getMainHandComponent(int componentID) {
	for (int i = 0; i < mainHandComponents.size(); i++) {
		if (mainHandComponents[i].m_ownerID == componentID) {
			return mainHandComponents[i];
		}
	}
}

SecondHand& getSecondHandComponent(int componentID) {
	for (int i = 0; i < secondHandComponents.size(); i++) {
		if (secondHandComponents[i].m_ownerID == componentID) {
			return secondHandComponents[i];
		}
	}
}

Magic& getMagicComponent(int componentID) {
	for (int i = 0; i < magicComponents.size(); i++) {
		if (magicComponents[i].m_ownerID == componentID) {
			return magicComponents[i];
		}
	}
}