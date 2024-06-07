#include "includes\creation_enemy.h"

#include <string>

#include "..\..\lib\includes\lib_entity.h"
#include "includes\system_components.h"

ID createEnemy (ID& nextID, EnemyList enemy) {

	CompSet compSet;

	switch (enemy)
	{
	case BAT:
		compSet = CompSet("11000011011");
		break;
	case RAT:
		compSet = CompSet("11000011011");
		break;
	case SCORPION:
		compSet = CompSet("11000011011");
		break;
	}

	Entity_ptr newEntity(new Entity(compSet, nextID));

	for (int i = 0; i < COMPONENTS_NUM; i++) {
		if (newEntity->getCompSet()[i] == 1) {
			switch (i) {
				case 0:
				{
					Score_ptr newScore(new Score_Comp);
					newScore->m_ownerID = newEntity->getID();
					getEnemyScore(*newScore, enemy);

					scoreContainer.push_back(std::move(newScore));
					break;
				}

				case 1:
				{
					Info_ptr newInfo(new Info_Comp);
					newInfo->m_ownerID = newEntity->getID();
					getEnemyInfo(*newInfo, enemy);

					int nameNum = 1;
					for (Info_ptr& member : infoContainer) {
						if (newInfo->m_desc == member->m_desc) {
							nameNum++;
						}
					}

					newInfo->m_name = (newInfo->m_desc + " " + std::to_string(nameNum));

					infoContainer.push_back(std::move(newInfo));
					break;
				}

				case 3:
				{
					Points_ptr newPoints(new Points_Comp);
					newPoints->m_ownerID = newEntity->getID();
					getEnemyPoints(*newPoints, enemy);

					pointsContainer.push_back(std::move(newPoints));
					break;
				}

				case 9:
				{
					NatArmor_ptr newNatArmor(new NatArmor_Comp);
					newNatArmor->m_ownerID = newEntity->getID();
					getEnemyNatArmor(*newNatArmor, enemy);

					natArmorContainer.push_back(std::move(newNatArmor));
					break;
				}

				case 10:
				{
					NatWeapon_ptr newNatWeapon(new NatWeapon_Comp);
					newNatWeapon->m_ownerID = newEntity->getID();
					getEnemyNatWeapon(*newNatWeapon, enemy);

					natWeaponContainer.push_back(std::move(newNatWeapon));
					break;
				}

				default:
					break;

			}
		}

	}

	entityContainer.push_back(std::move(newEntity));
	return nextID - 1;
}