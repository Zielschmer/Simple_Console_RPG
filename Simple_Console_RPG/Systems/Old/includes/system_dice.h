#ifndef SYSTEM_DICE
#define SYSTEM_DICE

#include "..\..\utils.h"

Roll scoreCheck(ID& entity);

Roll attackRoll(ID& attacker, ID& target);

Roll damageRoll(ID& attacker, ID& target);

Roll savingThrow(ID& entity);

#endif