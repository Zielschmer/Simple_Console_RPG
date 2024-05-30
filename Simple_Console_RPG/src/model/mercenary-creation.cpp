#include "includes\entity.h"
#include "..\..\lib\includes\spells.h"
#include "..\..\lib\includes\miracles.h"
#include "..\..\lib\includes\melodies.h"
#include "..\..\lib\includes\mercenary-names.h"

//Extern variables and functions

extern std::vector<std::unique_ptr<Entity>> entityControl;

extern std::vector<std::unique_ptr<Info>> infoComponents;
extern std::vector<std::unique_ptr<AbilityScore>> abilityScoreComponents;
extern std::vector<std::unique_ptr<int>> levelComponents;
extern std::vector<std::unique_ptr<HitPoints>> hitPointsComponents;
extern std::vector<std::unique_ptr<SpellSlots>> spellSlotsComponents;
extern std::vector<std::unique_ptr<Armor>> armorComponents;
extern std::vector<std::unique_ptr<MainHand>> mainHandComponents;
extern std::vector<std::unique_ptr<SecondHand>> secondHandComponents;
extern std::vector<std::unique_ptr<Cast>> castComponents;

Info& getInfoComponent(int componentID);

AbilityScore& getAbilityScoreComponent(int componentID);

int& getLevelComponent(int componentID);

HitPoints& getHitPointsComponent(int componentID);

SpellSlots& getSpellSlotsComponent(int componentID);

Armor& getArmorComponent(int componentID);

MainHand& getMainHandComponent(int componentID);

SecondHand& getSecondHandComponent(int componentID);

Cast& getCastComponent(int componentID);

int pickScore(std::vector<int>& scoreOrder);

int calculateExtra(int& extraPoints);

//File functions
Entity& mercenaryCreation(int currentID) {
	Entity* character = new Entity("00001111011", currentID);

	for (int i = 0; i < COMPONENTS_NUM; i++) {
		if (character->checkBitset()[i] == 1) {
			switch (i) {
				case 0:
				{

					AbilityScore* abilityScore = new AbilityScore;
					abilityScore->m_ownerID = character->getID();

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
					info->m_ownerID = character->getID();

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
							info->m_name = MaleDwarfNames[rand() % 30];
						}
						else {
							info->m_name = FemaleDwarfNames[rand() % 22];
						}
					}
					else if (race == "Halfling") {
						if (sex == "man") {
							info->m_name = MaleHalflingNames[rand() % 17];
						}
						else {
							info->m_name = FemaleHalflingNames[rand() % 18];
						}
					}
					else if (race == "Elf") {
						if (sex == "man") {
							info->m_name = MaleElfNames[rand() % 29];
						}
						else {
							info->m_name = FemaleElfNames[rand() % 30];
						}
					}
					else {
						if (sex == "man") {
							info->m_name = MaleHumanNames[rand() % 30];
						}
						else {
							info->m_name = FemaleHumanNames[rand() % 30];
						}
					}

					info->m_description = ("A brave " + sex + " of the " + race + " race.");

					std::unique_ptr<Info> infoPointer(info);
					infoComponents.push_back(std::move(infoPointer));
					break;
				}
				case 3:
				{
					HitPoints* hitPoints = new HitPoints;
					hitPoints->m_ownerID = character->getID();
					hitPoints->m_maxHP = getAbilityScoreComponent(character->getID()).m_constitution;
					hitPoints->m_currentHP = hitPoints->m_maxHP;

					std::unique_ptr<HitPoints> hitPointsPointer(hitPoints);
					hitPointsComponents.push_back(std::move(hitPointsPointer));
					break;
				}
				case 4:
				{
					SpellSlots* spellSlots = new SpellSlots;
					spellSlots->m_ownerID = character->getID();
					spellSlots->m_maxSpellSlots = (INITIAL_SPELLSLOTS + character->getModifier(4));
					spellSlots->m_currentSpellSlots = spellSlots->m_maxSpellSlots;

					std::unique_ptr<SpellSlots> spellSlotsPointer(spellSlots);
					spellSlotsComponents.push_back(std::move(spellSlotsPointer));
					break;
				}
				case 5:
				{
					Armor* armor = new Armor;
					armor->m_ownerID = character->getID();

					if (getAbilityScoreComponent(character->getID()).m_intelligence > 13 &&
						getAbilityScoreComponent(character->getID()).m_dexterity < 15 &&
						getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_faith &&
						getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_luck) {

						armor->m_name = "Robe";
						armor->m_baseArmor = 8;
						armor->m_armorModifier = 0;
						armor->m_fastCast = true;
						armor->m_dexterityDebuff = false;

						character->addComponent(8);
					}
					else if (getAbilityScoreComponent(character->getID()).m_faith > 13 &&
							getAbilityScoreComponent(character->getID()).m_faith > getAbilityScoreComponent(character->getID()).m_luck) {

						if (getAbilityScoreComponent(character->getID()).m_strength < 14) {
							armor->m_name = "Robe";
							armor->m_baseArmor = 8;
							armor->m_armorModifier = 0;
							armor->m_fastCast = true;
							armor->m_dexterityDebuff = false;
						}
						else {
							armor->m_name = "Chain Mail";
							armor->m_baseArmor = 14;
							armor->m_armorModifier = 1;
							armor->m_fastCast = false;
							armor->m_dexterityDebuff = true;
						}

						character->addComponent(8);
					}
					else if (getAbilityScoreComponent(character->getID()).m_luck > 13 &&
							getAbilityScoreComponent(character->getID()).m_strength < 14 &&
							getAbilityScoreComponent(character->getID()).m_dexterity < 14) {
						armor->m_name = "Robe";
						armor->m_baseArmor = 8;
						armor->m_armorModifier = 0;
						armor->m_fastCast = true;
						armor->m_dexterityDebuff = false;

						character->addComponent(8);
					}
					else if (getAbilityScoreComponent(character->getID()).m_dexterity > 13 &&
						getAbilityScoreComponent(character->getID()).m_dexterity > getAbilityScoreComponent(character->getID()).m_strength) {
						armor->m_name = "Leather Armor";
						armor->m_baseArmor = 10;
						armor->m_armorModifier = 2;
						armor->m_fastCast = false;
						armor->m_dexterityDebuff = false;
					}
					else if (getAbilityScoreComponent(character->getID()).m_dexterity < 10) {
						armor->m_name = "Chain Mail";
						armor->m_baseArmor = 14;
						armor->m_armorModifier = 1;
						armor->m_fastCast = false;
						armor->m_dexterityDebuff = true;
					}
					else {
						armor->m_name = "Ring Mail";
						armor->m_baseArmor = 12;
						armor->m_armorModifier = 0;
						armor->m_fastCast = false;
						armor->m_dexterityDebuff = false;
					}

					std::unique_ptr<Armor> armorPointer(armor);
					armorComponents.push_back(std::move(armorPointer));
					break;
				}
				case 6:
				{
					MainHand* mainHand = new MainHand;
					mainHand->m_ownerID = character->getID();

					if (getArmorComponent(character->getID()).m_name == "Robe") {
					
						if (getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_faith &&
							getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_luck) {

							if (getAbilityScoreComponent(character->getID()).m_strength < 14) {
								mainHand->m_name = "Staff";
								mainHand->m_baseAttack = 0;
								mainHand->m_attackModifier = 0;
								mainHand->m_twoHanded = false;
								mainHand->m_ranged = false;
								mainHand->m_intelligenceAdvantage = true;
								mainHand->m_faithAdvantage = false;
								mainHand->m_luckAdvantage = false;
							}
							else {
								mainHand->m_name = "Sword";
								mainHand->m_baseAttack = 6;
								mainHand->m_attackModifier = 1;
								mainHand->m_twoHanded = false;
								mainHand->m_ranged = false;
								mainHand->m_intelligenceAdvantage = false;
								mainHand->m_faithAdvantage = false;
								mainHand->m_luckAdvantage = false;

								character->addComponent(7);
							}

						}

						else if (getAbilityScoreComponent(character->getID()).m_faith > getAbilityScoreComponent(character->getID()).m_luck) {

							mainHand->m_name = "Rosary";
							mainHand->m_baseAttack = 0;
							mainHand->m_attackModifier = 0;
							mainHand->m_twoHanded = false;
							mainHand->m_ranged = false;
							mainHand->m_intelligenceAdvantage = false;
							mainHand->m_faithAdvantage = true;
							mainHand->m_luckAdvantage = false;
						}
						else {
							mainHand->m_name = "Harp";
							mainHand->m_baseAttack = 0;
							mainHand->m_attackModifier = 0;
							mainHand->m_twoHanded = true;
							mainHand->m_ranged = false;
							mainHand->m_intelligenceAdvantage = false;
							mainHand->m_faithAdvantage = false;
							mainHand->m_luckAdvantage = true;
						}
					
					}
					else if (getArmorComponent(character->getID()).m_name == "Leather Armor") {
						if (getAbilityScoreComponent(character->getID()).m_constitution < 11) {
							mainHand->m_name = "Bow";
							mainHand->m_baseAttack = 6;
							mainHand->m_attackModifier = 2;
							mainHand->m_twoHanded = true;
							mainHand->m_ranged = true;
							mainHand->m_intelligenceAdvantage = false;
							mainHand->m_faithAdvantage = false;
							mainHand->m_luckAdvantage = false;
						}
						else {
							mainHand->m_name = "Dagger";
							mainHand->m_baseAttack = 4;
							mainHand->m_attackModifier = 2;
							mainHand->m_twoHanded = false;
							mainHand->m_ranged = false;
							mainHand->m_intelligenceAdvantage = false;
							mainHand->m_faithAdvantage = false;
							mainHand->m_luckAdvantage = false;
						}
					}
					else if (getArmorComponent(character->getID()).m_name == "Chain Mail" &&
							getAbilityScoreComponent(character->getID()).m_faith > 13) {
						mainHand->m_name = "Mace";
						mainHand->m_baseAttack = 6;
						mainHand->m_attackModifier = 1;
						mainHand->m_twoHanded = false;
						mainHand->m_ranged = false;
						mainHand->m_intelligenceAdvantage = false;
						mainHand->m_faithAdvantage = false;
						mainHand->m_luckAdvantage = false;

						character->addComponent(7);
					}
					else if (getAbilityScoreComponent(character->getID()).m_strength > 15) {
						mainHand->m_name = "Hammer";
						mainHand->m_baseAttack = 8;
						mainHand->m_attackModifier = 1;
						mainHand->m_twoHanded = true;
						mainHand->m_ranged = false;
						mainHand->m_intelligenceAdvantage = false;
						mainHand->m_faithAdvantage = false;
						mainHand->m_luckAdvantage = false;
					}
					else {
						mainHand->m_name = "Sword";
						mainHand->m_baseAttack = 6;
						mainHand->m_attackModifier = 1;
						mainHand->m_twoHanded = false;
						mainHand->m_ranged = false;
						mainHand->m_intelligenceAdvantage = false;
						mainHand->m_faithAdvantage = false;
						mainHand->m_luckAdvantage = false;

						character->addComponent(7);
					}

					std::unique_ptr<MainHand> mainHandPointer(mainHand);
					mainHandComponents.push_back(std::move(mainHandPointer));
					break;
				}
				case 7:
				{
					SecondHand* secondHand = new SecondHand;
					secondHand->m_ownerID = character->getID();

					if (getArmorComponent(character->getID()).m_name == "Robe") {
						if (getAbilityScoreComponent(character->getID()).m_intelligence > getAbilityScoreComponent(character->getID()).m_faith) {
							secondHand->m_name = "Staff";
							secondHand->m_baseAttack = 0;
							secondHand->m_attackModifier = 0;
							secondHand->m_baseArmor = 0;
							secondHand->m_intelligenceAdvantage = true;
							secondHand->m_faithAdvantage = false;
						}
						else {
							secondHand->m_name = "Rosary";
							secondHand->m_baseAttack = 0;
							secondHand->m_attackModifier = 0;
							secondHand->m_baseArmor = 0;
							secondHand->m_intelligenceAdvantage = false;
							secondHand->m_faithAdvantage = true;
						}
					}
					else if (getMainHandComponent(character->getID()).m_name == "Mace") {
						secondHand->m_name = "Rosary";
						secondHand->m_baseAttack = 0;
						secondHand->m_attackModifier = 0;
						secondHand->m_baseArmor = 0;
						secondHand->m_intelligenceAdvantage = false;
						secondHand->m_faithAdvantage = true;
					}
					else {
						secondHand->m_name = "Shield";
						secondHand->m_baseAttack = 0;
						secondHand->m_attackModifier = 0;
						secondHand->m_baseArmor = 2;
						secondHand->m_intelligenceAdvantage = false;
						secondHand->m_faithAdvantage = false;
					}

					std::unique_ptr<SecondHand> secondHandPointer(secondHand);
					secondHandComponents.push_back(std::move(secondHandPointer));
					break;
				}
				case 8:
				{
					Cast* cast = new Cast;
					cast->m_ownerID = character->getID();

					if (getMainHandComponent(character->getID()).m_name == "Staff") {
						cast->m_spells.push_back(getMagicMissile());
						cast->m_spells.push_back(getFlare());
						cast->m_spells.push_back(getFreeze());
						cast->m_spells.push_back(getShock());
					}
					else if (getMainHandComponent(character->getID()).m_name == "Rosary") {
						cast->m_miracles.push_back(getTend());
						cast->m_miracles.push_back(getHeal());
						cast->m_miracles.push_back(getCure());
						cast->m_miracles.push_back(getPray());
					}
					else if (getMainHandComponent(character->getID()).m_name == "Harp") {
						cast->m_melodies.push_back(getInspiration());
						cast->m_melodies.push_back(getHaste());
						cast->m_melodies.push_back(getSlow());
						cast->m_melodies.push_back(getMighty());
						cast->m_melodies.push_back(getWither());
					}

					if (character->checkComponent(7)) {
						if (getSecondHandComponent(character->getID()).m_name == "Staff") {
							cast->m_spells.push_back(getMagicMissile());
							cast->m_spells.push_back(getFlare());
							cast->m_spells.push_back(getFreeze());
							cast->m_spells.push_back(getShock());
						}
						else if (getSecondHandComponent(character->getID()).m_name == "Rosary") {
							cast->m_miracles.push_back(getTend());
							cast->m_miracles.push_back(getHeal());
							cast->m_miracles.push_back(getCure());
							cast->m_miracles.push_back(getPray());
						}
					}

					std::unique_ptr<Cast> castPointer(cast);
					castComponents.push_back(std::move(castPointer));
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