#include "includes\cast_song.h"

Song getSong(SongList songList) {

	Song newSong;

	switch (songList)
	{
	case INSPIRATION:
		newSong.m_name = "Inspiration";
		newSong.m_description = "Increase allies rolls.";
		newSong.m_isAlly = true;
		newSong.m_isAll = true;
		newSong.m_type = 6;
		newSong.m_cost = 0;
		break;
	case HASTE:
		newSong.m_name = "Haste";
		newSong.m_description = "Increase speed and AC to one ally.";
		newSong.m_isAlly = true;
		newSong.m_isAll = false;
		newSong.m_type = 0;
		newSong.m_cost = 1;
		break;
	case MIGHTY:
		newSong.m_name = "Mighty";
		newSong.m_description = "Give an advantage on damage roll to one ally.";
		newSong.m_isAlly = true;
		newSong.m_isAll = false;
		newSong.m_type = 1;
		newSong.m_cost = 1;
		break;
	case PRECISION:
		newSong.m_name = "Precision";
		newSong.m_description = "Give an advantage on attack roll to one ally.";
		newSong.m_isAlly = true;
		newSong.m_isAll = false;
		newSong.m_type = 2;
		newSong.m_cost = 1;
		break;
	case BULLSEYE:
		newSong.m_name = "Bullseye";
		newSong.m_description = "Give an advantage on magic roll to one ally.";
		newSong.m_isAlly = true;
		newSong.m_isAll = false;
		newSong.m_type = 3;
		newSong.m_cost = 1;
		break;
	case SLOW:
		newSong.m_name = "Slow";
		newSong.m_description = "Decrease speed, and DC of one enemy.";
		newSong.m_isAlly = false;
		newSong.m_isAll = false;
		newSong.m_type = 0;
		newSong.m_cost = 1;
		break;
	case WITHER:
		newSong.m_name = "Wither";
		newSong.m_description = "Give a disadvantage on damage roll to one enemy.";
		newSong.m_isAlly = false;
		newSong.m_isAll = false;
		newSong.m_type = 1;
		newSong.m_cost = 1;
		break;
	case BLIND:
		newSong.m_name = "Blind";
		newSong.m_description = "Give a disadvantage on attack roll to one enemy.";
		newSong.m_isAlly = false;
		newSong.m_isAll = false;
		newSong.m_type = 2;
		newSong.m_cost = 1;
		break;
	case SILENCE:
		newSong.m_name = "Silence";
		newSong.m_description = "Give silence condition to one enemy.";
		newSong.m_isAlly = false;
		newSong.m_isAll = false;
		newSong.m_type = 3;
		newSong.m_cost = 1;
		break;
	case HYPNOTIZE:
		newSong.m_name = "Hypnotize";
		newSong.m_description = "The hypnotized enemy will attack its allies.";
		newSong.m_isAlly = false;
		newSong.m_isAll = false;
		newSong.m_type = 4;
		newSong.m_cost = 2;
		break;
	case DANCE:
		newSong.m_name = "Dance";
		newSong.m_description = "All enemies will spend their turn dancing.";
		newSong.m_isAlly = false;
		newSong.m_isAll = true;
		newSong.m_type = 5;
		newSong.m_cost = 3;
		break;
	default:
		break;
	}

	return newSong;

}

std::string songLibrary(SongList songList) {

	switch (songList)
	{
	case INSPIRATION:
		return "Inspiration";
		break;
	case HASTE:
		return "Haste";
		break;
	case MIGHTY:
		return "Mighty";
		break;
	case PRECISION:
		return "Precision";
		break;
	case BULLSEYE:
		return "Bullseye";
		break;
	case SLOW:
		return "Slow";
		break;
	case WITHER:
		return "Wither";
		break;
	case BLIND:
		return "Blind";
		break;
	case SILENCE:
		return "Silence";
		break;
	case HYPNOTIZE:
		return "Hypnotize";
		break;
	case DANCE:
		return "Dance";
		break;
	default:
		break;
	}

}