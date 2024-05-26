#include <iostream>

#include "model\includes\entity.h"
#include "model\includes\spell.h"

int main() {

	std::cout << "Flare: " << Flare::get().m_name << std::endl;
	std::cout << "Freeze: " << Freeze::get().m_name << std::endl;
	std::cout << "Shock: " << Shock::get().m_name << std::endl;
	std::cout << "Teleport: " << Teleport::get().m_name << std::endl;
	std::cout << "Flame: " << Flame::get().m_name << std::endl;
	std::cout << "Ice: " << Ice::get().m_name << std::endl;
	std::cout << "Lightning: " << Lightning::get().m_name << std::endl;
	std::cout << "Portal: " << Portal::get().m_name << std::endl;
	std::cout << "Inferno: " << Inferno::get().m_name << std::endl;
	std::cout << "Cocitus: " << Cocitus::get().m_name << std::endl;
	std::cout << "Tempest: " << Tempest::get().m_name << std::endl;

}