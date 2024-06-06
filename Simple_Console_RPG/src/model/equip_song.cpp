#include "includes\equip_song.h"

#include "includes\system_components.h"

bool chkSong(ID entityID, SongList song) {

	for (auto member : getCastComp(entityID)->m_songs) {
		if (member.m_name == songLibrary(song)) {
			return false;
		}
		return true;
	}

}

void equipSong(Entity& entity, SongList song) {

	if (getRHandComp(entity.getID())->m_name == "Harp")
	{
		if (chkSong(entity.getID(), song)) {
			getCastComp(entity.getID())->m_songs.emplace_back(getSong(song));
		}
	}

}