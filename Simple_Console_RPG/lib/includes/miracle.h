#pragma once

#include <iostream>

struct Miracle {

	std::string m_name;
	std::string m_description;
	bool m_isRevive;
	bool m_isHeal;
	bool m_isCure;
	bool m_isRestore;
	bool m_isArea;
	bool m_isAll;
	int m_cost;

	Miracle(std::string name, std::string description, bool isRevive, bool isHeal, bool isCure, bool isRestore, bool isArea, bool isAll, int cost);

};

struct Heal : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Cure : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Revive : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Pray : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct MassHeal : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct MassCure : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Smite : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Restore : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Rejuvenate : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Reincarnate : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};

struct Judgment : public Miracle {

	static Miracle& get();

	using Miracle::Miracle;

};