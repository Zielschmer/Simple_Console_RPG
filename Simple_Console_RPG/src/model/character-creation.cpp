#include <vector>

#include "includes\entity.h"
#include "..\controller\includes\string-input.h"

//Extern variables and functions
extern std::vector<Info> infoComponents;
extern std::vector<AbilityScore> abilityScoreComponents;
extern std::vector<Armor> armorComponents;
extern std::vector<MainHand> mainHandComponents;
extern std::vector<SecondHand> secondHandComponents;
extern std::vector<Cast> castComponents;

Info& getInfoComponent(int componentID);

AbilityScore& getAbilityScoreComponent(int componentID);

Armor& getArmorComponent(int componentID);

MainHand& getMainHandComponent(int componentID);

SecondHand& getSecondHandComponent(int componentID);

Cast& getCastComponent(int componentID);

//File functions
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

Entity& characterCreation(int currentID) {
	Entity* character = new Entity("000011", currentID);

	for (int i = 0; i < 6; i++) {
		if (character->checkBitset()[i] == 1) {
			switch (i)
			{
			case 0:
			{

				AbilityScore abilityScore;
				abilityScore.m_ownerID = character->getID();

				srand(time(NULL) * rand() % 100 + currentID);

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
							scoreValues[scoreOrder[i]] = 8 + addExtra;
							extraPoints -= addExtra;
						}
						else {
							scoreValues[scoreOrder[i]] = 8;
						}
					}
					else {
						scoreValues[scoreOrder[i]] = 8 + extraPoints;
					}
				}

				abilityScore.m_strength = scoreValues[0];
				abilityScore.m_dexterity = scoreValues[1];
				abilityScore.m_constitution = scoreValues[2];
				abilityScore.m_intelligence = scoreValues[3];
				abilityScore.m_faith = scoreValues[4];
				abilityScore.m_luck = scoreValues[5];

				abilityScoreComponents.push_back(abilityScore);
				break;

			}
			case 1:
			{
				Info info;
				info.m_ownerID = character->getID();

				std::string name = validStringInput();
				if (infoComponents.size() > 0) {
					for (int i = 0; i < infoComponents.size(); i++) {
						if (name == infoComponents[i].m_name) {
							name = validStringInput();
						}
					}
				}
				info.m_name = name;

				std::string race;
				if (getAbilityScoreComponent(character->getID()).m_strength > 15) {
					race = "Dwarf";
				}
				else if (getAbilityScoreComponent(character->getID()).m_dexterity > 15) {
					race = "Halfling";
				}
				else if (getAbilityScoreComponent(character->getID()).m_intelligence > 15) {
					race = "Elf";
				}
				else {
					race = "Human";
				}

				std::string sex;
				if (getAbilityScoreComponent(character->getID()).m_faith > 13) {
					sex = "woman";
				}
				else {
					sex = "man";
				}
				
				info.m_description = ("A brave " + sex + " of the " + race + " race.");

				infoComponents.push_back(info);
				break;
			}
			default:

				break;
			}
		}
	}
	return *character;
}