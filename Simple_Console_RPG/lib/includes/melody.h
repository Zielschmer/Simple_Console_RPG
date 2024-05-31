#pragma once

#include <string>

struct Melody {

	std::string m_name;
	std::string m_description;
	bool m_isAlly;
	bool m_isAll;
	int m_type;
	int m_cost;

};

enum MelodyList {

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

Melody getMelody(MelodyList melodyList);

std::string melodyLibrary(MelodyList melodyList);