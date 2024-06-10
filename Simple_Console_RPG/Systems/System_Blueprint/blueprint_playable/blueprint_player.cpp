#include "blueprint_playable.h"

#include "..\blueprint.h"
#include "..\generate_components.h"
#include "..\..\System_Containers\Containers.h"
#include "..\..\Components\comp_score.h"
#include "..\..\Components\comp_info.h"
#include "..\..\Components\comp_level.h"
#include "..\..\Components\comp_points.h"
#include "..\..\Components\comp_stats.h"
#include "..\..\Components\comp_armor.h"
#include "..\..\Components\comp_main-hand.h"
#include "..\..\Components\comp_off-hand.h"
#include "..\..\Components\comp_cast.h"


const ID createPlayer() {

	Blueprint blueprint;

	//Register Score component
	blueprint.registerComponent(generateScore(ENTITY_ID));
	blueprint.addComponent(SCORE);

	//Register Level component
	auto compLevel = std::make_unique<CompLevel>(ENTITY_ID);
	compLevel->m_level = 1u;
	compLevel->m_currentExp = 0u;
	blueprint.registerComponent(std::move(compLevel));
	blueprint.addComponent(LEVEL);

	//Register Points component
	auto compPoints = std::make_unique<CompPoints>(ENTITY_ID);
	compPoints->m_maxHP = chkScore(ENTITY_ID, CON);
	compPoints->m_currentHP = compPoints->m_maxHP;
	compPoints->m_maxSP = INITIAL_SPELLPOINTS + getMod(ENTITY_ID, INT);
	compPoints->m_currentSP = compPoints->m_maxSP;
	blueprint.registerComponent(std::move(compPoints));
	blueprint.addComponent(POINTS);

	//Register Stats component
	auto compStats = std::make_unique<CompStats>(ENTITY_ID);
	compStats->m_AC = NMLROLL;
	compStats->m_atkRoll = NMLROLL;
	for (int i = 1; i < 7; i++) {
		compStats->m_scrRoll.emplace(i, NMLROLL);
	}
	for (int i = 1; i < 7; i++) {
		compStats->m_svgRoll.emplace(i, NMLROLL);
	}

	Entity_ptr entity = blueprint.instantiateEntity(ENTITY_ID);

	auto entityID = entity->m_ID;

	entityContainer.emplace(entityID, std::move(entity));

	return entityID;

}

const ID createMercenary() {

	Blueprint blueprint;

	//Register Score component
	blueprint.registerComponent(generateScore(ENTITY_ID));
	blueprint.addComponent(SCORE);

	//Register Info component
	blueprint.registerComponent(generateInfo(ENTITY_ID));
	blueprint.addComponent(INFO);

	//Register Level component
	auto compLevel = std::make_unique<CompLevel>(ENTITY_ID);
	compLevel->m_level = 1u;
	compLevel->m_currentExp = 0u;
	blueprint.registerComponent(std::move(compLevel));
	blueprint.addComponent(LEVEL);

	//Register Points component
	auto compPoints = std::make_unique<CompPoints>(ENTITY_ID);
	compPoints->m_maxHP = chkScore(ENTITY_ID, CON);
	compPoints->m_currentHP = compPoints->m_maxHP;
	compPoints->m_maxSP = INITIAL_SPELLPOINTS + getMod(ENTITY_ID, INT);
	compPoints->m_currentSP = compPoints->m_maxSP;
	blueprint.registerComponent(std::move(compPoints));
	blueprint.addComponent(POINTS);

	//Register Stats component
	auto compStats = std::make_unique<CompStats>(ENTITY_ID);
	compStats->m_AC = NMLROLL;
	compStats->m_atkRoll = NMLROLL;
	for (int i = 1; i < 7; i++) {
		compStats->m_scrRoll.emplace(i, NMLROLL);
	}
	for (int i = 1; i < 7; i++) {
		compStats->m_svgRoll.emplace(i, NMLROLL);
	}

	//Register Armor component
	blueprint.registerComponent(generateArmor(ENTITY_ID));
	blueprint.addComponent(ARMOR);

	//Register Main Hand component
	blueprint.registerComponent(generateMainHand(ENTITY_ID));
	blueprint.addComponent(MAINHAND);

	//Register Off Hand component
	if(blueprint.compSet.test(OFFHAND)) {
		blueprint.registerComponent(generateOffHand(ENTITY_ID));
	}

	//Register Cast component
	if (blueprint.compSet.test(CAST)) {
		blueprint.registerComponent(generateCast(ENTITY_ID));
	}

	Entity_ptr entity = blueprint.instantiateEntity(ENTITY_ID);

	auto entityID = entity->m_ID;

	entityContainer.emplace(entityID, std::move(entity));

	return entityID;

}