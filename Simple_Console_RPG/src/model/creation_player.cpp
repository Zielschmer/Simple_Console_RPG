#include <vector>

#include "..\control\includes\string-input.h"
#include "includes\system_components.h"

int pickScore(std::vector<int>& scoreOrder);

int calculateExtra(int& extraPoints);

Entity& characterCreation(ID nextID) {
	Entity_ptr newEntity(new Entity(00000011011, nextID));

	for (int i = 0; i < COMPONENTS_NUM; i++) {
		if (newEntity->getCompSet()[i] == 1) {
			switch (i)
			{
			case 0:
			{

				AbilityScore* abilityScore = new AbilityScore;
				abilityScore->m_ownerID = newEntity->getID();

				srand(time(NULL) + currentID);

				std::vector<int> scoreOrder;
				scoreOrder.push_back(rand() % 6);
				for (int j = 0; j < 5; j++) {
					scoreOrder.push_back(pickScore(scoreOrder));
				}
				int scoreValues[6];
				int extraPoints = 27;
				for (int j = 0; j < 6; j++) {
					if (extraPoints > 0) {
						int addExtra = calculateExtra(extraPoints);
						scoreValues[scoreOrder[j]] = 8 + addExtra;
						extraPoints -= addExtra;
					}
					else {
						scoreValues[scoreOrder[j]] = 8;
					}
				}
				int l = 0;
				while (extraPoints > 0) {
					if (scoreValues[scoreOrder[l]] < 18) {
						scoreValues[scoreOrder[l]]++;
						extraPoints--;
					}
					l++;
					if (l == 6) {
						l = 0;
					}
				}

				abilityScore->m_strength = scoreValues[0];
				abilityScore->m_dexterity = scoreValues[1];
				abilityScore->m_constitution = scoreValues[2];
				abilityScore->m_intelligence = scoreValues[3];
				abilityScore->m_faith = scoreValues[4];
				abilityScore->m_luck = scoreValues[5];

				std::unique_ptr<AbilityScore> abilityScorePointer(abilityScore);
				abilityScoreComponents.push_back(std::move(abilityScorePointer));
				break;

			}
			case 1:
			{
				Info* info = new Info;
				info->m_ownerID = newEntity->getID();

				std::string name = validStringInput();
				if (infoComponents.size() > 0) {
					for (int j = 0; j < infoComponents.size(); j++) {
						if (name == infoComponents[j]->m_name) {
							name = validStringInput();
						}
					}
				}
				info->m_name = name;

				std::string race;
				if (getAbilityScoreComponent(newEntity->getID()).m_strength > 15) {
					race = "Dwarf";
				}
				else if (getAbilityScoreComponent(newEntity->getID()).m_dexterity > 15) {
					race = "Halfling";
				}
				else if (getAbilityScoreComponent(newEntity->getID()).m_intelligence > 15) {
					race = "Elf";
				}
				else {
					race = "Human";
				}

				std::string sex;
				if (getAbilityScoreComponent(newEntity->getID()).m_faith > 13) {
					sex = "woman";
				}
				else {
					sex = "man";
				}
				
				info->m_description = ("A brave " + sex + " of the " + race + " race.");

				std::unique_ptr<Info> infoPointer(info);
				infoComponents.push_back(std::move(infoPointer));
				break;
			}
			case 2:
				break;
			case 3:
			{
				HitPoints* hitPoints = new HitPoints;
				hitPoints->m_ownerID = newEntity->getID();
				hitPoints->m_maxHP = getAbilityScoreComponent(newEntity->getID()).m_constitution;
				hitPoints->m_currentHP = hitPoints->m_maxHP;

				std::unique_ptr<HitPoints> hitPointsPointer(hitPoints);
				hitPointsComponents.push_back(std::move(hitPointsPointer));
				break;
			}
			case 4:
			{
				SpellSlots* spellSlots = new SpellSlots;
				spellSlots->m_ownerID = newEntity->getID();
				spellSlots->m_maxSpellSlots = (INITIAL_SPELLSLOTS + newEntity->getModifier(4));
				spellSlots->m_currentSpellSlots = spellSlots->m_maxSpellSlots;

				std::unique_ptr<SpellSlots> spellSlotsPointer(spellSlots);
				spellSlotsComponents.push_back(std::move(spellSlotsPointer));
				break;
			}
			default:

				break;
			}
		}
	}

	std::unique_ptr<Entity> newEntityPointer(newEntity);
	entityControl.push_back(std::move(newEntityPointer));
	return *newEntity;
}