#pragma once
#include "Service.h"
class Console {
private:
	Service service;
public:

	int console();
	Console();
	~Console();
	Console(const Service& s);
	void show_monede();
	void show_produse();
	void meniu();
};