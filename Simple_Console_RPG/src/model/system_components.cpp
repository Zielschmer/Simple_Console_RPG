#include "includes\system_components.h"

Container<Entity_ptr> entityContainer;
Container<Score_ptr> scoreContainer;
Container<Info_ptr> infoContainer;
Container<Level_ptr> levelContainer;
Container<Points_ptr> pointsContainer;
Container<Stats_ptr> statsContainer;
Container<Armor_ptr> armorContainer;
Container<RHand_ptr> rHandContainer;
Container<LHand_ptr> lHandContainer;
Container<Cast_ptr> castContainer;
Container<NatArmor_ptr> natArmorContainer;
Container<NatWeapon_ptr> natWeaponContainer;

Entity_ptr& getEntity(ID entityID) {
	for (int i = 0; i <entityContainer.size(); i++) {
		if (entityContainer[i]->getID() == entityID) {
			return entityContainer[i];
		}
	}
}

Score_ptr& getScoreComp(ID ownerID) {
	for (int i = 0; i < scoreContainer.size(); i++) {
		if (scoreContainer[i]->m_ownerID == ownerID) {
			return scoreContainer[i];
		}
	}
}

Info_ptr& getInfoComp(ID ownerID) {
	for (int i = 0; i < infoContainer.size(); i++) {
		if (infoContainer[i]->m_ownerID == ownerID) {
			return infoContainer[i];
		}
	}
}

Level_ptr& getLevelComp(ID ownerID) {
	for (int i = 0; i < levelContainer.size(); i++) {
		if (levelContainer[i]->m_ownerID == ownerID) {
			return levelContainer[i];
		}
	}
}

Points_ptr& getPointsComp(ID ownerID) {
	for (int i = 0; i < pointsContainer.size(); i++) {
		if (pointsContainer[i]->m_ownerID == ownerID) {
			return pointsContainer[i];
		}
	}
}

Stats_ptr& getStatsComp(ID ownerID) {
	for (int i = 0; i < statsContainer.size(); i++) {
		if (statsContainer[i]->m_ownerID == ownerID) {
			return statsContainer[i];
		}
	}
}

Armor_ptr& getArmorComp(ID ownerID) {
	for (int i = 0; i < armorContainer.size(); i++) {
		if (armorContainer[i]->m_ownerID == ownerID) {
			return armorContainer[i];
		}
	}
}

RHand_ptr& getRHandComp(ID ownerID) {
	for (int i = 0; i < rHandContainer.size(); i++) {
		if (rHandContainer[i]->m_ownerID == ownerID) {
			return rHandContainer[i];
		}
	}
}

LHand_ptr& getLHandComp(ID ownerID) {
	for (int i = 0; i < lHandContainer.size(); i++) {
		if (lHandContainer[i]->m_ownerID == ownerID) {
			return lHandContainer[i];
		}
	}
}

Cast_ptr& getCastComp(ID ownerID) {
	for (int i = 0; i < castContainer.size(); i++) {
		if (castContainer[i]->m_ownerID == ownerID) {
			return castContainer[i];
		}
	}
}

NatArmor_ptr& getNatArmorComp(ID ownerID) {
	for (int i = 0; i < natArmorContainer.size(); i++) {
		if (natArmorContainer[i]->m_ownerID == ownerID) {
			return natArmorContainer[i];
		}
	}
}


NatWeapon_ptr& getNatWeaponComp(ID ownerID) {
	for (int i = 0; i < natWeaponContainer.size(); i++) {
		if (natWeaponContainer[i]->m_ownerID == ownerID) {
			return natWeaponContainer[i];
		}
	}
}

void delArmorComp(ID ownerID) {
	for (auto it = armorContainer.begin(); it != armorContainer.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			armorContainer.erase(it);
		}
	}
}

void delRHandComp(ID ownerID) {
	for (auto it = rHandContainer.begin(); it != rHandContainer.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			rHandContainer.erase(it);
		}
	}
}

void delLHandComp(ID ownerID) {
	for (auto it = lHandContainer.begin(); it != lHandContainer.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			lHandContainer.erase(it);
		}
	}
}

void delCastComp(ID ownerID) {
	for (auto it = castContainer.begin(); it != castContainer.end(); it++) {
		if (it->get()->m_ownerID == ownerID) {
			castContainer.erase(it);
		}
	}
}

int getScoreMod(ID ownderID, ScoreList score) {

		switch (score)
		{
		case STR:
			return floor((getScoreComp(ownderID)->m_str - 10) / 2);
			break;
		case DEX:
			return floor((getScoreComp(ownderID)->m_dex - 10) / 2);
			break;
		case CON:
			return floor((getScoreComp(ownderID)->m_con - 10) / 2);
			break;
		case INT:
			return floor((getScoreComp(ownderID)->m_int - 10) / 2);
			break;
		case FTH:
			return floor((getScoreComp(ownderID)->m_fth - 10) / 2);
			break;
		case LCK:
			return floor((getScoreComp(ownderID)->m_lck - 10) / 2);
			break;
		}

}

int getSpeed (ID ownderID) {

	return (5 + getScoreMod(ownderID, DEX));

}