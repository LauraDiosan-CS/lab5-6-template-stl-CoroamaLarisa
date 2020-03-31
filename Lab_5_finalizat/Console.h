#pragma once
#include "Service.h"

class Console {
private:
	Service service_cheltuieli;
public:
	Console(Service& s);
	void show_cheltuieli_familie(vector<Cheltuieli_familie>);
	void modify_cheltuiala();
	vector<char*> get_command();
	int console_2();

};