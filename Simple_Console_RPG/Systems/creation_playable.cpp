#include "includes\creation_playable.h"

#include "..\..\lib\includes\lib_names.h"
#include "includes\system_components.h"

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

void getArmor(Armor_ptr& newArmor, ArmorList armor) {

	switch (armor)
	{
	case NOARMOR:
		break;
	case ROBE:
		newArmor->m_name = "Robe";
		newArmor->m_baseArmor = 8;
		newArmor->m_armorMod = NOMOD;
		newArmor->m_fastCast = true;
		newArmor->m_dexterityDebuff = false;
		break;
	case LEATHER_ARMOR:
		newArmor->m_name = "Leather Armor";
		newArmor->m_baseArmor = 10;
		newArmor->m_armorMod = DEX;
		newArmor->m_fastCast = false;
		newArmor->m_dexterityDebuff = false;
		break;
	case RING_MAIL:
		newArmor->m_name = "Ring Mail";
		newArmor->m_baseArmor = 12;
		newArmor->m_armorMod = NOMOD;
		newArmor->m_fastCast = false;
		newArmor->m_dexterityDebuff = false;
		break;
	case CHAIN_MAIL:
		newArmor->m_name = "Chain Mail";
		newArmor->m_baseArmor = 14;
		newArmor->m_armorMod = STR;
		newArmor->m_fastCast = false;
		newArmor->m_dexterityDebuff = true;
		break;
	default:
		break;
	}

}

void getRHand(RHand_ptr& newRHand, WeaponList weapon) {

	switch (weapon)
	{
	case NOWEAPON:
		break;
	case SWORD:
		newRHand->m_name = "Sword";
		newRHand->m_diceAtk = D6;
		newRHand->m_atkMod = STR;
		newRHand->m_twoHanded = false;
		newRHand->m_range = 1;
		newRHand->m_castSpell = false;
		newRHand->m_castPray = false;
		newRHand->m_castSong = false;
		break;
	case DAGGER:
		newRHand->m_name = "Dagger";
		newRHand->m_diceAtk = D4;
		newRHand->m_atkMod = DEX;
		newRHand->m_twoHanded = false;
		newRHand->m_range = 1;
		newRHand->m_castSpell = false;
		newRHand->m_castPray = false;
		newRHand->m_castSong = false;
		break;
	case MACE:
		newRHand->m_name = "Mace";
		newRHand->m_diceAtk = D6;
		newRHand->m_atkMod = STR;
		newRHand->m_twoHanded = false;
		newRHand->m_range = 1;
		newRHand->m_castSpell = false;
		newRHand->m_castPray = false;
		newRHand->m_castSong = false;
		break;
	case HAMMER:
		newRHand->m_name = "Hammer";
		newRHand->m_diceAtk = D8;
		newRHand->m_atkMod = STR;
		newRHand->m_twoHanded = true;
		newRHand->m_range = 1;
		newRHand->m_castSpell = false;
		newRHand->m_castPray = false;
		newRHand->m_castSong = false;
		break;
	case BOW:
		newRHand->m_name = "Bow";
		newRHand->m_diceAtk = D6;
		newRHand->m_atkMod = DEX;
		newRHand->m_twoHanded = true;
		newRHand->m_range = 16;
		newRHand->m_castSpell = false;
		newRHand->m_castPray = false;
		newRHand->m_castSong = false;
		break;
	case STAFF:
		newRHand->m_name = "Staff";
		newRHand->m_diceAtk = D0;
		newRHand->m_atkMod = NOMOD;
		newRHand->m_twoHanded = false;
		newRHand->m_range = 1;
		newRHand->m_castSpell = true;
		newRHand->m_castPray = false;
		newRHand->m_castSong = false;
		break;
	case ROSARY:
		newRHand->m_name = "Rosary";
		newRHand->m_diceAtk = D0;
		newRHand->m_atkMod = NOMOD;
		newRHand->m_twoHanded = false;
		newRHand->m_range = 1;
		newRHand->m_castSpell = false;
		newRHand->m_castPray = true;
		newRHand->m_castSong = false;
		break;
	case HARP:
		newRHand->m_name = "Harp";
		newRHand->m_diceAtk = D0;
		newRHand->m_atkMod = NOMOD;
		newRHand->m_twoHanded = true;
		newRHand->m_range = 1;
		newRHand->m_castSpell = false;
		newRHand->m_castPray = false;
		newRHand->m_castSong = true;
		break;
	case SHIELD:
		break;
	default:
		break;
	}

}

ID createPlayable (ID& nextID, PlayableType type) {

	CompSet compSet;

	switch (type)
	{
	case PLAYER:
		compSet = CompSet("00000011111");
		break;
	case MERC:
		compSet = CompSet("00001111111");
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

				srand(time(NULL) + nextID);

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
			case 2:
			{
				Level_ptr newLevel(new Level_Comp);
				newLevel->m_ownerID = newEntity->getID();

				levelContainer.push_back(std::move(newLevel));
				break;
			}
			case 3:
			{
				Points_ptr newPoints(new Points_Comp);
				newPoints->m_ownerID = newEntity->getID();
				newPoints->m_maxHP = getScoreComp(newEntity->getID())->m_con;
				newPoints->m_currentHP = newPoints->m_maxHP;
				newPoints->m_maxSP = INITIAL_SPELLSLOTS + getScoreMod(newEntity->getID(), INT);
				newPoints->m_currentSP = newPoints->m_maxSP;

				pointsContainer.push_back(std::move(newPoints));
				break;
			}
			case 4:
			{
				Stats_ptr newStats(new Stats_Comp);
				newStats->m_ownerID = newEntity->getID();
				
				statsContainer.push_back(std::move(newStats));
				break;
			}
			case 5:
			{
				Armor_ptr newArmor(new Armor_Comp);
				newArmor->m_ownerID = newEntity->getID();

				if (getScoreComp(newEntity->getID())->m_int > 13 &&
					getScoreComp(newEntity->getID())->m_dex < 15 &&
					getScoreComp(newEntity->getID())->m_int > getScoreComp(newEntity->getID())->m_fth &&
					getScoreComp(newEntity->getID())->m_int > getScoreComp(newEntity->getID())->m_lck) {

					getArmor(newArmor, ROBE);

					newEntity->add_comp(CAST);
				}
				else if (getScoreComp(newEntity->getID())->m_fth > 13 &&
					getScoreComp(newEntity->getID())->m_fth > getScoreComp(newEntity->getID())->m_lck) {

					if (getScoreComp(newEntity->getID())->m_str < 14) {

						getArmor(newArmor, ROBE);

					}
					else {
						getArmor(newArmor, CHAIN_MAIL);
					}

					newEntity->add_comp(CAST);
				}
				else if (getScoreComp(newEntity->getID())->m_lck > 13 &&
					getScoreComp(newEntity->getID())->m_str < 14 &&
					getScoreComp(newEntity->getID())->m_dex < 14) {

					getArmor(newArmor, ROBE);

					newEntity->add_comp(CAST);
				}
				else if (getScoreComp(newEntity->getID())->m_dex > 13 &&
					getScoreComp(newEntity->getID())->m_dex > getScoreComp(newEntity->getID())->m_str) {

					getArmor(newArmor, LEATHER_ARMOR);

				}
				else if (getScoreComp(newEntity->getID())->m_dex < 10) {

					getArmor(newArmor, CHAIN_MAIL);

				}
				else {
					getArmor(newArmor, RING_MAIL);
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

							getRHand(newRHand, STAFF);

						}
						else {
							getRHand(newRHand, SWORD);
						}

					}

					else if (getScoreComp(newEntity->getID())->m_fth > getScoreComp(newEntity->getID())->m_lck) {

						getRHand(newRHand, ROSARY);

					}
					else {
						getRHand(newRHand, HARP);
					}

				}
				else if (getArmorComp(newEntity->getID())->m_name == "Leather Armor") {
					if (getScoreComp(newEntity->getID())->m_con < 11) {

						getRHand(newRHand, BOW);

					}
					else {
						getRHand(newRHand, DAGGER);
					}
				}
				else if (getArmorComp(newEntity->getID())->m_name == "Chain Mail" &&
					getScoreComp(newEntity->getID())->m_fth > 13) {

					getRHand(newRHand, MACE);

					newEntity->add_comp(LHAND);
				}
				else if (getScoreComp(newEntity->getID())->m_str > 15) {

					getRHand(newRHand, HAMMER);

				}
				else {
					getRHand(newRHand, SWORD);

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
						newLHand->m_diceAtk = D0;
						newLHand->m_atkMod = NOMOD;
						newLHand->m_armorClass = 0;
						newLHand->m_castSpell = true;
						newLHand->m_castPray = false;
					}
					else {
						newLHand->m_name = "Rosary";
						newLHand->m_diceAtk = D0;
						newLHand->m_atkMod = NOMOD;
						newLHand->m_armorClass = 0;
						newLHand->m_castSpell = false;
						newLHand->m_castPray = true;
					}
				}
				else if (getRHandComp(newEntity->getID())->m_name == "Mace") {
					newLHand->m_name = "Rosary";
					newLHand->m_diceAtk = D0;
					newLHand->m_atkMod = NOMOD;
					newLHand->m_armorClass = 0;
					newLHand->m_castSpell = false;
					newLHand->m_castPray = true;
				}
				else {
					newLHand->m_name = "Shield";
					newLHand->m_diceAtk = D0;
					newLHand->m_atkMod = NOMOD;
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
			}
		}
	}

	entityContainer.emplace_back(std::move(newEntity));
	return nextID-1;
}