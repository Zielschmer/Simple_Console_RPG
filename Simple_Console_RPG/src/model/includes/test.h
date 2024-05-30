#pragma once

#include <vector>
#include <iostream>

struct House {

	int m_ownerID;
	int m_adress;
	int m_rooms;
	std::string m_color;

};

struct Car {

	int m_ownerID;
	std::string m_plate;
	int m_speed;
	std::string m_color;

};

std::vector<std::unique_ptr<House>> existHouse;
std::vector<std::unique_ptr<Car>> existCar;

template <typename T>
std::vector<std::unique_ptr<T>>& getVector() {
	return T();
}

template <>
std::vector<std::unique_ptr<House>>& getVector() {
	return existHouse;
}

template <>
std::vector<std::unique_ptr<Car>>& getVector() {
	return existCar;
}

template <typename T>
void addExist(std::unique_ptr<T>& newExist) {

	getVector<T>().emplace_back(std::move(newExist));

}

template <typename T>
void removeExist(int ownerID) {

	for(auto it = getVector<T>().begin(); it->get()->m_ownerID != ownerID; it++) {
		if (it->get()->m_ownerID == ownerID)
			getVector<T>().erase(it);
	}

}

template <typename T>
void printExist(int ownerID) {
			T();
}

template <>
void printExist<House>(int ownerID) {
	for (auto it = getVector<House>().begin(); it->get()->m_ownerID == ownerID; it++) {
		if (it->get()->m_ownerID == ownerID) {
				std::cout << "Adress: " << it->get()->m_adress << std::endl;
				std::cout << "Rooms: " << it->get()->m_rooms << std::endl;
				std::cout << "Color: " << it->get()->m_color << std::endl;
		}
	}
}

template <>
void printExist<Car>(int ownerID) {
	for (auto it = getVector<Car>().begin(); it->get()->m_ownerID == ownerID; it++) {
		if (it->get()->m_ownerID == ownerID) {
			std::cout << "Plate: " << it->get()->m_plate << std::endl;
			std::cout << "Speed: " << it->get()->m_speed << std::endl;
			std::cout << "Color: " << it->get()->m_color << std::endl;
		}
	}
}
