#include "blueprint_beasts.h"

#include "..\blueprint.h"
#include "..\generate_components.h"
#include "..\..\System_Dice\system_dice.h"
#include "..\..\System_Containers\Containers.h"
#include "..\..\..\Components\comp_score.h"
#include "..\..\..\Components\comp_info.h"
#include "..\..\..\Components\comp_level.h"
#include "..\..\..\Components\comp_points.h"
#include "..\..\..\Components\comp_stats.h"
#include "..\..\..\Components\comp_armor.h"
#include "..\..\..\Components\comp_main-hand.h"
#include "..\..\..\Components\comp_off-hand.h"
#include "..\..\..\Components\comp_cast.h"
#include "..\..\..\Components\comp_nat-armor.h"
#include "..\..\..\Components\comp_nat-weapons.h"
#include "..\..\..\Item_Library\Item_Interface.h"

const ID createBat() {

	Blueprint blueprint;

	//Register Score component
	auto compScore = std::make_unique<CompScore>(ENTITY_ID);
	compScore->m_str = 2;
	compScore->m_dex = 15;
	compScore->m_con = 8;
	compScore->m_int = 2;
	compScore->m_fth = 12;
	compScore->m_lck = 4;
	blueprint.registerComponent(std::move(compScore));
	blueprint.addComponent(SCORE);

	//Register Info component
	auto compInfo = std::make_unique<CompInfo>(ENTITY_ID);
	compInfo->m_desc = "Bat";
	static int batNum = 1;
	compInfo->m_name = (compInfo->m_desc + " " + std::to_string(batNum));
	batNum++;
	blueprint.registerComponent(std::move(compInfo));
	blueprint.addComponent(INFO);

	//Register Points component
	auto compPoints = std::make_unique<CompPoints>(ENTITY_ID);
	compPoints->m_maxHP = rollDice(D4, (-1));
	compPoints->m_currentHP = compPoints->m_maxHP;
	compPoints->m_maxSP = 0;
	compPoints->m_currentSP = 0;
	blueprint.registerComponent(std::move(compPoints));
	blueprint.addComponent(POINTS);

	//Register Natural Armor component
	auto compNatArmor = std::make_unique<CompNatArmor>(ENTITY_ID);
	compNatArmor->m_AC = 12;
	blueprint.registerComponent(std::move(compNatArmor));
	blueprint.addComponent(NAT_ARMOR);

	//Register Natural Weapon component
	auto compNatWeapons = std::make_unique<CompNatWeapons>(ENTITY_ID);
	compNatWeapons->m_weapons.emplace_back(createBite(ENTITY_ID));
	blueprint.registerComponent(std::move(compNatWeapons));
	blueprint.addComponent(NAT_WEAPONS);

	Entity_ptr entity = blueprint.instantiateEntity(ENTITY_ID);

	auto entityID = entity->m_ID;

	entityContainer.emplace(entityID, std::move(entity));

	return entityID;

}

const ID createRat() {

	Blueprint blueprint;

	//Register Score component
	auto compScore = std::make_unique<CompScore>(ENTITY_ID);
	compScore->m_str = 2;
	compScore->m_dex = 11;
	compScore->m_con = 9;
	compScore->m_int = 9;
	compScore->m_fth = 10;
	compScore->m_lck = 4;
	blueprint.registerComponent(std::move(compScore));
	blueprint.addComponent(SCORE);

	//Register Info component
	auto compInfo = std::make_unique<CompInfo>(ENTITY_ID);
	compInfo->m_desc = "Rat";
	static int ratNum = 1;
	compInfo->m_name = (compInfo->m_desc + " " + std::to_string(ratNum));
	ratNum++;
	blueprint.registerComponent(std::move(compInfo));
	blueprint.addComponent(INFO);

	//Register Points component
	auto compPoints = std::make_unique<CompPoints>(ENTITY_ID);
	compPoints->m_maxHP = rollDice(D4, (-1));
	compPoints->m_currentHP = compPoints->m_maxHP;
	compPoints->m_maxSP = 0;
	compPoints->m_currentSP = 0;
	blueprint.registerComponent(std::move(compPoints));
	blueprint.addComponent(POINTS);

	//Register Natural Armor component
	auto compNatArmor = std::make_unique<CompNatArmor>(ENTITY_ID);
	compNatArmor->m_AC = 10;
	blueprint.registerComponent(std::move(compNatArmor));
	blueprint.addComponent(NAT_ARMOR);

	//Register Natural Weapon component
	auto compNatWeapons = std::make_unique<CompNatWeapons>(ENTITY_ID);
	compNatWeapons->m_weapons.emplace_back(createBite(ENTITY_ID));
	blueprint.registerComponent(std::move(compNatWeapons));
	blueprint.addComponent(NAT_WEAPONS);

	Entity_ptr entity = blueprint.instantiateEntity(ENTITY_ID);

	auto entityID = entity->m_ID;

	entityContainer.emplace(entityID, std::move(entity));

	return entityID;

}

const ID createScorpion() {

	Blueprint blueprint;

	//Register Score component
	auto compScore = std::make_unique<CompScore>(ENTITY_ID);
	compScore->m_str = 2;
	compScore->m_dex = 11;
	compScore->m_con = 8;
	compScore->m_int = 1;
	compScore->m_fth = 8;
	compScore->m_lck = 2;
	blueprint.registerComponent(std::move(compScore));
	blueprint.addComponent(SCORE);

	//Register Info component
	auto compInfo = std::make_unique<CompInfo>(ENTITY_ID);
	compInfo->m_desc = "Scorpion";
	static int scorpionNum = 1;
	compInfo->m_name = (compInfo->m_desc + " " + std::to_string(scorpionNum));
	scorpionNum++;
	blueprint.registerComponent(std::move(compInfo));
	blueprint.addComponent(INFO);

	//Register Points component
	auto compPoints = std::make_unique<CompPoints>(ENTITY_ID);
	compPoints->m_maxHP = rollDice(D4, (-1));
	compPoints->m_currentHP = compPoints->m_maxHP;
	compPoints->m_maxSP = 0;
	compPoints->m_currentSP = 0;
	blueprint.registerComponent(std::move(compPoints));
	blueprint.addComponent(POINTS);

	//Register Natural Armor component
	auto compNatArmor = std::make_unique<CompNatArmor>(ENTITY_ID);
	compNatArmor->m_AC = 11;
	blueprint.registerComponent(std::move(compNatArmor));
	blueprint.addComponent(NAT_ARMOR);

	//Register Natural Weapon component
	auto compNatWeapons = std::make_unique<CompNatWeapons>(ENTITY_ID);
	compNatWeapons->m_weapons.emplace_back(createSting(ENTITY_ID));
	blueprint.registerComponent(std::move(compNatWeapons));
	blueprint.addComponent(NAT_WEAPONS);

	Entity_ptr entity = blueprint.instantiateEntity(ENTITY_ID);

	auto entityID = entity->m_ID;

	entityContainer.emplace(entityID, std::move(entity));

	return entityID;

}