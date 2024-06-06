#pragma once

#include <string>

struct Song {

	std::string m_name;
	std::string m_description;
	bool m_isAlly;
	bool m_isAll;
	int m_type;
	int m_cost;

};

enum SongList {

	INSPIRATION,
	HASTE,
	MIGHTY,
	PRECISION,
	BULLSEYE,
	SLOW,
	WITHER,
	BLIND,
	SILENCE,
	HYPNOTIZE,
	DANCE

};

Song getSong(SongList songList);

std::string songLibrary(SongList songList);