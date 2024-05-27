#pragma once

#include <iostream>

struct Melody {

	std::string m_name;
	std::string m_description;
	bool m_isAlly;
	bool m_isAll;
	int m_type;
	int m_cost;

	Melody(std::string name, std::string description, bool isAlly, bool isAll, int type, int cost);

};

struct Haste : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Mighty : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Precision : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Bullseye : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Slow : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Wither : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Blind : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Silence : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Hypnotize : public Melody {

	static Melody& get();

	using Melody::Melody;

};

struct Dance : public Melody {

	static Melody& get();

	using Melody::Melody;

};