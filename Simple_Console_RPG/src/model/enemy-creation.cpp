#include "includes\entity.h"
#include <string>
#include "..\..\lib\includes\bestiary.h"

//Extern variables and functions

extern std::vector<Entity> entityControl;

extern std::vector<Info> infoComponents;
extern std::vector<AbilityScore> abilityScoreComponents;
extern std::vector<HitPoints> hitPointsComponents;
extern std::vector<int> spellSlotsComponents;
extern std::vector<Armor> armorComponents;
extern std::vector<MainHand> mainHandComponents;
extern std::vector<SecondHand> secondHandComponents;
extern std::vector<Cast> castComponents;
extern std::vector<NaturalArmor> naturalArmorComponents;
extern std::vector<NaturalWeapons> naturalWeaponsComponents;

Info& getInfoComponent(int componentID);

AbilityScore& getAbilityScoreComponent(int componentID);

//File Functions
Entity& enemyCreation(int currentID, int whatEnemy) {
	Entity* character = new Entity("11000001011", currentID);

	for (int i = 0; i < COMPONENTS_NUM; i++) {
		if (character->checkBitset()[i] == 1) {
			switch (i) {
				case 0:
				{
					AbilityScore abilityScore;
					abilityScore.m_ownerID = character->getID();
					createMonsterAbilityScore(abilityScore, whatEnemy);

					abilityScoreComponents.push_back(abilityScore);
					break;
				}

				case 1:
				{
					Info info;
					info.m_ownerID = character->getID();
					createMonsterInfo(info, whatEnemy);

					int nameNum = 1;
					for (int j = 0; j < infoComponents.size(); j++) {
						if (info.m_description == infoComponents[j].m_description) {
							nameNum++;
						}
					}

					info.m_name = (info.m_description + " " + std::to_string(nameNum));

					infoComponents.push_back(info);
					break;
				}

				case 3:
				{
					HitPoints hitPoints;
					hitPoints.m_ownerID = character->getID();
					createMonsterHitPoints(hitPoints, whatEnemy);

					hitPointsComponents.push_back(hitPoints);
					break;
				}

				case 9:
				{
					NaturalArmor naturalArmor;
					naturalArmor.m_ownerID = character->getID();
					createMonsterNaturalArmor(naturalArmor, whatEnemy);

					naturalArmorComponents.push_back(naturalArmor);
					break;
				}

				case 10:
				{
					NaturalWeapons naturalWeapons;
					naturalWeapons.m_ownerID = character->getID();
					createMonsterNaturalWeapon(naturalWeapons, whatEnemy);

					naturalWeaponsComponents.push_back(naturalWeapons);
					break;
				}

				default:
					break;

			}
		}

	}

	entityControl.push_back(*character);
	return *character;
}