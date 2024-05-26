#include "includes\spell.h"

Spell& Flare::get() {
	static Flare flare;
	return flare;
}

Spell& Freeze::get() {
	static Freeze freeze;
	return freeze;
}

Spell& Shock::get() {
	static Shock shock;
	return shock;
}