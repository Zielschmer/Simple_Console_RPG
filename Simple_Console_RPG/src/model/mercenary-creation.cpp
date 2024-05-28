#include "includes\entity.h"
#include "..\..\lib\includes\spells.h"
#include "..\..\lib\includes\miracles.h"
#include "..\..\lib\includes\melodies.h"
#include "..\..\lib\includes\mercenary-names.h"

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

int pickScore(std::vector<int>& scoreOrder);

int calculateExtra(int& extraPoints);

//File functions
Entity& mercenaryCreation(int currentID) {
	Entity* character = new Entity("00001111", currentID);

	for (int i = 0; i < COMPONENTS_NUM; i++) {
		if (character->checkBitset()[i] == 1) {
			switch (i) {
				case 0:
				{

					AbilityScore abilityScore;
					abilityScore.m_ownerID = character->getID();

					srand(time(NULL)+currentID);

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
					if (getAbilityScoreComponent(character->getID()).m_faith > 13 && rand() % 2 == 0) {
						sex = "woman";
					}
					else {
						sex = "man";
					}

					if (race == "Dwarf") {
						if (sex == "man") {
							info.m_name = MaleDwarfNames[rand() % 30];
						}
						else {
							info.m_name = FemaleDwarfNames[rand() % 22];
						}
					}
					else if (race == "Halfling") {
						if (sex == "man") {
							info.m_name = MaleHalflingNames[rand() % 17];
						}
						else {
							info.m_name = FemaleHalflingNames[rand() % 18];
						}
					}
					else if (race == "Elf") {
						if (sex == "man") {
							info.m_name = MaleElfNames[rand() % 29];
						}
						else {
							info.m_name = FemaleElfNames[rand() % 30];
						}
					}
					else {
						if (sex == "man") {
							info.m_name = MaleHumanNames[rand() % 30];
						}
						else {
							info.m_name = FemaleHumanNames[rand() % 30];
						}
					}

					info.m_description = ("A brave " + sex + " of the " + race + " race.");

					infoComponents.push_back(info);
					break;
				}
				case 2:
				{
					Armor armor;
					armor.m_ownerID = character->getID();

					if (getAbilityScoreComponent(character->getID()).m_intelligence > 13 &&
						getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_faith &&
						getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_luck) {

						armor.m_name = "Robe";
						armor.m_baseArmor = 8;
						armor.m_armorModifier = 0;
						armor.m_fastCast = true;
						armor.m_dexterityDebuff = false;

						character->addComponent(5);
					}
					else if (getAbilityScoreComponent(character->getID()).m_faith > 13 &&
							getAbilityScoreComponent(character->getID()).m_faith > getAbilityScoreComponent(character->getID()).m_luck) {

						if (getAbilityScoreComponent(character->getID()).m_strength < 14) {
							armor.m_name = "Robe";
							armor.m_baseArmor = 8;
							armor.m_armorModifier = 0;
							armor.m_fastCast = true;
							armor.m_dexterityDebuff = false;
						}
						else {
							armor.m_name = "Chain Mail";
							armor.m_baseArmor = 14;
							armor.m_armorModifier = 1;
							armor.m_fastCast = false;
							armor.m_dexterityDebuff = true;
						}

						character->addComponent(5);
					}
					else if (getAbilityScoreComponent(character->getID()).m_luck > 13 &&
							getAbilityScoreComponent(character->getID()).m_strength < 14 &&
							getAbilityScoreComponent(character->getID()).m_dexterity < 14) {
						armor.m_name = "Robe";
						armor.m_baseArmor = 8;
						armor.m_armorModifier = 0;
						armor.m_fastCast = true;
						armor.m_dexterityDebuff = false;

						character->addComponent(5);
					}
					else if (getAbilityScoreComponent(character->getID()).m_dexterity > 13 &&
						getAbilityScoreComponent(character->getID()).m_dexterity > getAbilityScoreComponent(character->getID()).m_strength) {
						armor.m_name = "Leather Armor";
						armor.m_baseArmor = 10;
						armor.m_armorModifier = 2;
						armor.m_fastCast = false;
						armor.m_dexterityDebuff = false;
					}
					else if (getAbilityScoreComponent(character->getID()).m_dexterity < 10) {
						armor.m_name = "Chain Mail";
						armor.m_baseArmor = 14;
						armor.m_armorModifier = 1;
						armor.m_fastCast = false;
						armor.m_dexterityDebuff = true;
					}
					else {
						armor.m_name = "Ring Mail";
						armor.m_baseArmor = 12;
						armor.m_armorModifier = 0;
						armor.m_fastCast = false;
						armor.m_dexterityDebuff = false;
					}

					armorComponents.push_back(armor);
					break;
				}
				case 3:
				{
					MainHand mainHand;
					mainHand.m_ownerID = character->getID();

					if (getArmorComponent(character->getID()).m_name == "Robe") {
					
						if (getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_faith &&
							getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_luck) {

							if (getAbilityScoreComponent(character->getID()).m_strength < 14) {
								mainHand.m_name = "Staff";
								mainHand.m_baseAttack = 0;
								mainHand.m_attackModifier = 0;
								mainHand.m_twoHanded = false;
								mainHand.m_ranged = false;
								mainHand.m_intelligenceAdvantage = true;
								mainHand.m_faithAdvantage = false;
								mainHand.m_luckAdvantage = false;
							}
							else {
								mainHand.m_name = "Sword";
								mainHand.m_baseAttack = 2;
								mainHand.m_attackModifier = 1;
								mainHand.m_twoHanded = false;
								mainHand.m_ranged = false;
								mainHand.m_intelligenceAdvantage = false;
								mainHand.m_faithAdvantage = false;
								mainHand.m_luckAdvantage = false;

								character->addComponent(4);
							}

						}

						else if (getAbilityScoreComponent(character->getID()).m_faith > getAbilityScoreComponent(character->getID()).m_luck) {

							mainHand.m_name = "Rosary";
							mainHand.m_baseAttack = 0;
							mainHand.m_attackModifier = 0;
							mainHand.m_twoHanded = false;
							mainHand.m_ranged = false;
							mainHand.m_intelligenceAdvantage = false;
							mainHand.m_faithAdvantage = true;
							mainHand.m_luckAdvantage = false;
						}
						else {
							mainHand.m_name = "Harp";
							mainHand.m_baseAttack = 0;
							mainHand.m_attackModifier = 0;
							mainHand.m_twoHanded = true;
							mainHand.m_ranged = false;
							mainHand.m_intelligenceAdvantage = false;
							mainHand.m_faithAdvantage = false;
							mainHand.m_luckAdvantage = true;
						}
					
					}
					else if (getArmorComponent(character->getID()).m_name == "Leather Armor") {
						if (getAbilityScoreComponent(character->getID()).m_constitution < 11) {
							mainHand.m_name = "Bow";
							mainHand.m_baseAttack = 2;
							mainHand.m_attackModifier = 2;
							mainHand.m_twoHanded = true;
							mainHand.m_ranged = true;
							mainHand.m_intelligenceAdvantage = false;
							mainHand.m_faithAdvantage = false;
							mainHand.m_luckAdvantage = false;
						}
						else {
							mainHand.m_name = "Dagger";
							mainHand.m_baseAttack = 1;
							mainHand.m_attackModifier = 2;
							mainHand.m_twoHanded = false;
							mainHand.m_ranged = false;
							mainHand.m_intelligenceAdvantage = false;
							mainHand.m_faithAdvantage = false;
							mainHand.m_luckAdvantage = false;
						}
					}
					else if (getArmorComponent(character->getID()).m_name == "Chain Mail" &&
							getAbilityScoreComponent(character->getID()).m_faith > 13) {
						mainHand.m_name = "Mace";
						mainHand.m_baseAttack = 2;
						mainHand.m_attackModifier = 1;
						mainHand.m_twoHanded = false;
						mainHand.m_ranged = false;
						mainHand.m_intelligenceAdvantage = false;
						mainHand.m_faithAdvantage = false;
						mainHand.m_luckAdvantage = false;

						character->addComponent(4);
					}
					else if (getAbilityScoreComponent(character->getID()).m_strength > 15) {
						mainHand.m_name = "Hammer";
						mainHand.m_baseAttack = 3;
						mainHand.m_attackModifier = 1;
						mainHand.m_twoHanded = true;
						mainHand.m_ranged = false;
						mainHand.m_intelligenceAdvantage = false;
						mainHand.m_faithAdvantage = false;
						mainHand.m_luckAdvantage = false;
					}
					else {
						mainHand.m_name = "Sword";
						mainHand.m_baseAttack = 2;
						mainHand.m_attackModifier = 1;
						mainHand.m_twoHanded = false;
						mainHand.m_ranged = false;
						mainHand.m_intelligenceAdvantage = false;
						mainHand.m_faithAdvantage = false;
						mainHand.m_luckAdvantage = false;

						character->addComponent(4);
					}

					mainHandComponents.push_back(mainHand);
					break;
				}
				case 4:
				{
					SecondHand secondHand;
					secondHand.m_ownerID = character->getID();

					if (getArmorComponent(character->getID()).m_name == "Robe") {
						if (getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_faith) {
							secondHand.m_name = "Staff";
							secondHand.m_baseAttack = 0;
							secondHand.m_attackModifier = 0;
							secondHand.m_baseArmor = 0;
							secondHand.m_intelligenceAdvantage = true;
							secondHand.m_faithAdvantage = false;
						}
						else {
							secondHand.m_name = "Rosary";
							secondHand.m_baseAttack = 0;
							secondHand.m_attackModifier = 0;
							secondHand.m_baseArmor = 0;
							secondHand.m_intelligenceAdvantage = false;
							secondHand.m_faithAdvantage = true;
						}
					}
					else if (getMainHandComponent(character->getID()).m_name == "Mace") {
						secondHand.m_name = "Rosary";
						secondHand.m_baseAttack = 0;
						secondHand.m_attackModifier = 0;
						secondHand.m_baseArmor = 0;
						secondHand.m_intelligenceAdvantage = false;
						secondHand.m_faithAdvantage = true;
					}
					else {
						secondHand.m_name = "Shield";
						secondHand.m_baseAttack = 0;
						secondHand.m_attackModifier = 0;
						secondHand.m_baseArmor = 2;
						secondHand.m_intelligenceAdvantage = false;
						secondHand.m_faithAdvantage = false;
					}

					secondHandComponents.push_back(secondHand);
					break;
				}
				case 5:
				{
					Cast cast;
					cast.m_ownerID = character->getID();

					if (getMainHandComponent(character->getID()).m_name == "Staff") {
						cast.m_spells.push_back(getFlare());
						cast.m_spells.push_back(getFreeze());
						cast.m_spells.push_back(getShock());
					}
					else if (getMainHandComponent(character->getID()).m_name == "Rosary") {
						cast.m_miracles.push_back(getHeal());
						cast.m_miracles.push_back(getCure());
						cast.m_miracles.push_back(getPray());
					}
					else if (getMainHandComponent(character->getID()).m_name == "Harp") {
						cast.m_melodies.push_back(getHaste());
						cast.m_melodies.push_back(getSlow());
						cast.m_melodies.push_back(getMighty());
						cast.m_melodies.push_back(getWither());
					}

					if (character->checkComponent(4)) {
						if (getSecondHandComponent(character->getID()).m_name == "Staff") {
							cast.m_spells.push_back(getFlare());
							cast.m_spells.push_back(getFreeze());
							cast.m_spells.push_back(getShock());
						}
						else if (getSecondHandComponent(character->getID()).m_name == "Rosary") {
							cast.m_miracles.push_back(getHeal());
							cast.m_miracles.push_back(getCure());
							cast.m_miracles.push_back(getPray());
						}
					}

					castComponents.push_back(cast);
					break;
				}
				default:

					break;
			}
		}
	}
	return *character;
}