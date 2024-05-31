#include "includes\entity.h"
#include <string>
#include "..\..\lib\includes\bestiary.h"
#include "includes\components-handling.h"

Entity& enemyCreation(int currentID, int whatEnemy) {
	Entity* character = new Entity("11000001011", currentID);

	for (int i = 0; i < COMPONENTS_NUM; i++) {
		if (character->checkBitset()[i] == 1) {
			switch (i) {
				case 0:
				{
					AbilityScore* abilityScore = new AbilityScore;
					abilityScore->m_ownerID = character->getID();
					createMonsterAbilityScore(*abilityScore, whatEnemy);

					std::unique_ptr<AbilityScore> abilityScorePointer(abilityScore);
					abilityScoreComponents.push_back(std::move(abilityScorePointer));
					break;
				}

				case 1:
				{
					Info* info = new Info;
					info->m_ownerID = character->getID();
					createMonsterInfo(*info, whatEnemy);

					int nameNum = 1;
					for (int j = 0; j < infoComponents.size(); j++) {
						if (info->m_description == infoComponents[j]->m_description) {
							nameNum++;
						}
					}

					info->m_name = (info->m_description + " " + std::to_string(nameNum));

					std::unique_ptr<Info> infoPointer(info);
					infoComponents.push_back(std::move(infoPointer));
					break;
				}

				case 3:
				{
					HitPoints* hitPoints = new HitPoints;
					hitPoints->m_ownerID = character->getID();
					createMonsterHitPoints(*hitPoints, whatEnemy);

					std::unique_ptr<HitPoints> hitPointsPointer(hitPoints);
					hitPointsComponents.push_back(std::move(hitPointsPointer));
					break;
				}

				case 9:
				{
					NaturalArmor* naturalArmor = new NaturalArmor;
					naturalArmor->m_ownerID = character->getID();
					createMonsterNaturalArmor(*naturalArmor, whatEnemy);

					std::unique_ptr<NaturalArmor> naturalArmorPointer(naturalArmor);
					naturalArmorComponents.push_back(std::move(naturalArmorPointer));
					break;
				}

				case 10:
				{
					NaturalWeapons* naturalWeapons = new NaturalWeapons;
					naturalWeapons->m_ownerID = character->getID();
					createMonsterNaturalWeapon(*naturalWeapons, whatEnemy);

					std::unique_ptr<NaturalWeapons> naturalWeaponsPointer(naturalWeapons);
					naturalWeaponsComponents.push_back(std::move(naturalWeaponsPointer));
					break;
				}

				default:
					break;

			}
		}

	}

	std::unique_ptr<Entity> characterPointer(character);
	entityControl.push_back(std::move(characterPointer));
	return *character;
}