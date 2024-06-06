#include "includes\creation_mercenary.h"

#include "..\..\lib\includes\lib_names.h"
#include "includes\system_components.h"

int pickScore(std::vector<int>& scoreOrder);

int calculateExtra(int& extraPoints);

Entity& mercenaryCreation(ID nextID) {
	Entity_ptr newEntity(new Entity(11111110000, nextID));

	for (int i = 0; i < COMPONENTS_NUM; i++) {
		if (newEntity->getCompSet()[i] == 1) {
			switch (i) {
				case 0:
				{

					Score_ptr newScore(new Score_Comp);
					newScore->m_ownerID = newEntity->getID();

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

					newScore->m_str = scoreValues[0];
					newScore->m_dex = scoreValues[1];
					newScore->m_con = scoreValues[2];
					newScore->m_int = scoreValues[3];
					newScore->m_fth = scoreValues[4];
					newScore->m_lck = scoreValues[5];

					scoreContainer.push_back(std::move(newScore));
					break;

				}
				case 1:
				{
					Info_ptr newInfo(new Info_Comp);
					newInfo->m_ownerID = newEntity->getID();

					std::string race;
					if (getScoreComp(newEntity->getID())->m_str > 15) {
						race = "Dwarf";
					}
					else if (getScoreComp(newEntity->getID())->m_dex > 15) {
						race = "Halfling";
					}
					else if (getScoreComp(newEntity->getID())->m_int > 15) {
						race = "Elf";
					}
					else {
						race = "Human";
					}

					std::string sex;
					if (getScoreComp(newEntity->getID())->m_fth > 13 && rand() % 2 == 0) {
						sex = "woman";
					}
					else {
						sex = "man";
					}

					if (race == "Dwarf") {
						if (sex == "man") {
							newInfo->m_name = MaleDwarfNames[rand() % 30];
						}
						else {
							newInfo->m_name = FemaleDwarfNames[rand() % 22];
						}
					}
					else if (race == "Halfling") {
						if (sex == "man") {
							newInfo->m_name = MaleHalflingNames[rand() % 17];
						}
						else {
							newInfo->m_name = FemaleHalflingNames[rand() % 18];
						}
					}
					else if (race == "Elf") {
						if (sex == "man") {
							newInfo->m_name = MaleElfNames[rand() % 29];
						}
						else {
							newInfo->m_name = FemaleElfNames[rand() % 30];
						}
					}
					else {
						if (sex == "man") {
							newInfo->m_name = MaleHumanNames[rand() % 30];
						}
						else {
							newInfo->m_name = FemaleHumanNames[rand() % 30];
						}
					}

					newInfo->m_desc = ("A brave " + sex + " of the " + race + " race.");

					infoContainer.push_back(std::move(newInfo));
					break;
				}
				case 3:
				{
					Points_ptr newPoints(new Points_Comp);
					newPoints->m_ownerID = newEntity->getID();
					newPoints->m_maxHP = getScoreComp(newEntity->getID())->m_con;
					newPoints->m_currentHP = newPoints->m_maxHP;

					pointsContainer.push_back(std::move(newPoints));
					break;
				}
				case 4:
				{
					/*SpellSlots* spellSlots = new SpellSlots;
					spellSlots->m_ownerID = newEntity->getID();
					spellSlots->m_maxSpellSlots = (INITIAL_SPELLSLOTS + newEntity->getModifier(4));
					spellSlots->m_currentSpellSlots = spellSlots->m_maxSpellSlots;

					std::unique_ptr<SpellSlots> spellSlotsPointer(spellSlots);
					spellSlotsComponents.push_back(std::move(spellSlotsPointer));
					break;*/
				}
				case 5:
				{
					Armor_ptr newArmor(new Armor_Comp);
					newArmor->m_ownerID = newEntity->getID();

					if (getScoreComp(newEntity->getID())->m_int > 13 &&
						getScoreComp(newEntity->getID())->m_dex < 15 &&
						getScoreComp(newEntity->getID())->m_int > getScoreComp(newEntity->getID())->m_fth &&
						getScoreComp(newEntity->getID())->m_int > getScoreComp(newEntity->getID())->m_lck) {

						newArmor->m_name = "Robe";
						newArmor->m_baseArmor = 8;
						newArmor->m_armorModifier = 0;
						newArmor->m_fastCast = true;
						newArmor->m_dexterityDebuff = false;

						newEntity->add_comp(CAST);
					}
					else if (getScoreComp(newEntity->getID())->m_fth > 13 &&
							getScoreComp(newEntity->getID())->m_fth > getScoreComp(newEntity->getID())->m_lck) {

						if (getScoreComp(newEntity->getID())->m_str < 14) {
							newArmor->m_name = "Robe";
							newArmor->m_baseArmor = 8;
							newArmor->m_armorModifier = 0;
							newArmor->m_fastCast = true;
							newArmor->m_dexterityDebuff = false;
						}
						else {
							newArmor->m_name = "Chain Mail";
							newArmor->m_baseArmor = 14;
							newArmor->m_armorModifier = 1;
							newArmor->m_fastCast = false;
							newArmor->m_dexterityDebuff = true;
						}

						newEntity->add_comp(CAST);
					}
					else if (getScoreComp(newEntity->getID())->m_lck > 13 &&
							getScoreComp(newEntity->getID())->m_str < 14 &&
							getScoreComp(newEntity->getID())->m_dex < 14) {
						newArmor->m_name = "Robe";
						newArmor->m_baseArmor = 8;
						newArmor->m_armorModifier = 0;
						newArmor->m_fastCast = true;
						newArmor->m_dexterityDebuff = false;

						newEntity->add_comp(CAST);
					}
					else if (getScoreComp(newEntity->getID())->m_dex > 13 &&
						getScoreComp(newEntity->getID())->m_dex > getScoreComp(newEntity->getID())->m_str) {
						newArmor->m_name = "Leather Armor";
						newArmor->m_baseArmor = 10;
						newArmor->m_armorModifier = 2;
						newArmor->m_fastCast = false;
						newArmor->m_dexterityDebuff = false;
					}
					else if (getScoreComp(newEntity->getID())->m_dex < 10) {
						newArmor->m_name = "Chain Mail";
						newArmor->m_baseArmor = 14;
						newArmor->m_armorModifier = 1;
						newArmor->m_fastCast = false;
						newArmor->m_dexterityDebuff = true;
					}
					else {
						newArmor->m_name = "Ring Mail";
						newArmor->m_baseArmor = 12;
						newArmor->m_armorModifier = 0;
						newArmor->m_fastCast = false;
						newArmor->m_dexterityDebuff = false;
					}

					armorContainer.push_back(std::move(newArmor));
					break;
				}
				case 6:
				{
					RHand_ptr newRHand(new RHand_Comp);
					newRHand->m_ownerID = newEntity->getID();

					if (getArmorComp(newEntity->getID())->m_name == "Robe") {
					
						if (getScoreComp(newEntity->getID())->m_int > getScoreComp(newEntity->getID())->m_fth &&
							getScoreComp(newEntity->getID())->m_int > getScoreComp(newEntity->getID())->m_lck) {

							if (getScoreComp(newEntity->getID())->m_str < 14) {
								newRHand->m_name = "Staff";
								newRHand->m_diceAtk = 0;
								newRHand->m_atkMod = 0;
								newRHand->m_twoHanded = false;
								newRHand->m_range = 1;
								newRHand->m_castSpell = true;
								newRHand->m_castPray = false;
								newRHand->m_castSong = false;
							}
							else {
								newRHand->m_name = "Sword";
								newRHand->m_diceAtk = 6;
								newRHand->m_atkMod = 1;
								newRHand->m_twoHanded = false;
								newRHand->m_range = 1;
								newRHand->m_castSpell = false;
								newRHand->m_castPray = false;
								newRHand->m_castSong = false;

								newEntity->add_comp(LHAND);
							}

						}

						else if (getScoreComp(newEntity->getID())->m_fth > getScoreComp(newEntity->getID())->m_lck) {

							newRHand->m_name = "Rosary";
							newRHand->m_diceAtk = 0;
							newRHand->m_atkMod = 0;
							newRHand->m_twoHanded = false;
							newRHand->m_range = 1;
							newRHand->m_castSpell = false;
							newRHand->m_castPray = true;
							newRHand->m_castSong = false;
						}
						else {
							newRHand->m_name = "Harp";
							newRHand->m_diceAtk = 0;
							newRHand->m_atkMod = 0;
							newRHand->m_twoHanded = true;
							newRHand->m_range = 1;
							newRHand->m_castSpell = false;
							newRHand->m_castPray = false;
							newRHand->m_castSong = true;
						}
					
					}
					else if (getArmorComp(newEntity->getID())->m_name == "Leather Armor") {
						if (getScoreComp(newEntity->getID())->m_con < 11) {
							newRHand->m_name = "Bow";
							newRHand->m_diceAtk = 6;
							newRHand->m_atkMod = 2;
							newRHand->m_twoHanded = true;
							newRHand->m_range = 16;
							newRHand->m_castSpell = false;
							newRHand->m_castPray = false;
							newRHand->m_castSong = false;
						}
						else {
							newRHand->m_name = "Dagger";
							newRHand->m_diceAtk = 4;
							newRHand->m_atkMod = 2;
							newRHand->m_twoHanded = false;
							newRHand->m_range = 1;
							newRHand->m_castSpell = false;
							newRHand->m_castPray = false;
							newRHand->m_castSong = false;
						}
					}
					else if (getArmorComp(newEntity->getID())->m_name == "Chain Mail" &&
							getScoreComp(newEntity->getID())->m_fth > 13) {
						newRHand->m_name = "Mace";
						newRHand->m_diceAtk = 6;
						newRHand->m_atkMod = 1;
						newRHand->m_twoHanded = false;
						newRHand->m_range = 1;
						newRHand->m_castSpell = false;
						newRHand->m_castPray = false;
						newRHand->m_castSong = false;

						newEntity->add_comp(LHAND);
					}
					else if (getScoreComp(newEntity->getID())->m_str > 15) {
						newRHand->m_name = "Hammer";
						newRHand->m_diceAtk = 8;
						newRHand->m_atkMod = 1;
						newRHand->m_twoHanded = true;
						newRHand->m_range = 1;
						newRHand->m_castSpell = false;
						newRHand->m_castPray = false;
						newRHand->m_castSong = false;
					}
					else {
						newRHand->m_name = "Sword";
						newRHand->m_diceAtk = 6;
						newRHand->m_atkMod = 1;
						newRHand->m_twoHanded = false;
						newRHand->m_range = 1;
						newRHand->m_castSpell = false;
						newRHand->m_castPray = false;
						newRHand->m_castSong = false;

						newEntity->add_comp(LHAND);
					}

					rHandContainer.push_back(std::move(newRHand));
					break;
				}
				case 7:
				{
					LHand_ptr newLHand(new LHand_Comp);
					newLHand->m_ownerID = newEntity->getID();

					if (getArmorComp(newEntity->getID())->m_name == "Robe") {
						if (getScoreComp(newEntity->getID())->m_int > getScoreComp(newEntity->getID())->m_fth) {
							newLHand->m_name = "Staff";
							newLHand->m_diceAtk = 0;
							newLHand->m_atkMod = 0;
							newLHand->m_armorClass = 0;
							newLHand->m_castSpell = true;
							newLHand->m_castPray = false;
						}
						else {
							newLHand->m_name = "Rosary";
							newLHand->m_diceAtk = 0;
							newLHand->m_atkMod = 0;
							newLHand->m_armorClass = 0;
							newLHand->m_castSpell = false;
							newLHand->m_castPray = true;
						}
					}
					else if (getRHandComp(newEntity->getID())->m_name == "Mace") {
						newLHand->m_name = "Rosary";
						newLHand->m_diceAtk = 0;
						newLHand->m_atkMod = 0;
						newLHand->m_armorClass = 0;
						newLHand->m_castSpell = false;
						newLHand->m_castPray = true;
					}
					else {
						newLHand->m_name = "Shield";
						newLHand->m_diceAtk = 0;
						newLHand->m_atkMod = 0;
						newLHand->m_armorClass = 2;
						newLHand->m_castSpell = false;
						newLHand->m_castPray = false;
					}

					lHandContainer.push_back(std::move(newLHand));
					break;
				}
				case 8:
				{
					Cast_ptr newCast(new Cast_Comp);
					newCast->m_ownerID = newEntity->getID();

					if (getRHandComp(newEntity->getID())->m_name == "Staff") {
						newCast->m_spells.emplace_back(getSpell(MAGIC_MISSILES));
						newCast->m_spells.emplace_back(getSpell(FLARE));
						newCast->m_spells.emplace_back(getSpell(FREEZE));
						newCast->m_spells.emplace_back(getSpell(SHOCK));
					}
					else if (getRHandComp(newEntity->getID())->m_name == "Rosary") {
						newCast->m_prays.emplace_back(getPray(TEND));
						newCast->m_prays.emplace_back(getPray(HEAL));
						newCast->m_prays.emplace_back(getPray(CURE));
						newCast->m_prays.emplace_back(getPray(PRAY));
					}
					else if (getRHandComp(newEntity->getID())->m_name == "Harp") {
						newCast->m_songs.emplace_back(getSong(INSPIRATION));
						newCast->m_songs.emplace_back(getSong(HASTE));
						newCast->m_songs.emplace_back(getSong(SLOW));
						newCast->m_songs.emplace_back(getSong(MIGHTY));
						newCast->m_songs.emplace_back(getSong(WITHER));
					}

					if (newEntity->chk_comp(LHAND)) {
						if (getLHandComp(newEntity->getID())->m_name == "Staff") {
							newCast->m_spells.emplace_back(getSpell(MAGIC_MISSILES));
							newCast->m_spells.emplace_back(getSpell(FLARE));
							newCast->m_spells.emplace_back(getSpell(FREEZE));
							newCast->m_spells.emplace_back(getSpell(SHOCK));
						}
						else if (getLHandComp(newEntity->getID())->m_name == "Rosary") {
							newCast->m_prays.emplace_back(getPray(TEND));
							newCast->m_prays.emplace_back(getPray(HEAL));
							newCast->m_prays.emplace_back(getPray(CURE));
							newCast->m_prays.emplace_back(getPray(PRAY));
						}
					}

					castContainer.push_back(std::move(newCast));
					break;
				}
				default:

					break;
			}
		}
	}

	entityContainer.push_back(std::move(newEntity));
	return *newEntity;
}