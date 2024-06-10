#include "generate_components.h"
#include "..\System_Containers\Containers.h"

extern std::string MaleDwarfNames[30];
extern std::string FemaleDwarfNames[22];
extern std::string MaleHalflingNames[17];
extern std::string FemaleHalflingNames[18];
extern std::string MaleElfNames[29];
extern std::string FemaleElfNames[30];
extern std::string MaleHumanNames[30];
extern std::string FemaleHumanNames[30];

Info_ptr generateInfo(ID& entityID) {
	Info_ptr newInfo(new CompInfo(entityID));

	std::string race;
	if (chkScore(entityID, STR) > 15u) {
		race = "Dwarf";
	}
	else if (chkScore(entityID, DEX) > 15u) {
		race = "Halfling";
	}
	else if (chkScore(entityID, INT) > 15u) {
		race = "Elf";
	}
	else {
		race = "Human";
	}

	std::string sex;
	if (chkScore(entityID, FTH) > 13u && rand() % 2 == 0) {
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

	return std::move(newInfo);
}