#pragma once
#include <ostream>
using namespace std;

class Cheltuieli_familie {
private:
	int zi;
	int suma_bani;
	char* tip;
public:
	Cheltuieli_familie();
	Cheltuieli_familie(int zi, int suma_bani, char* tip);
	~Cheltuieli_familie();
	Cheltuieli_familie(const Cheltuieli_familie& c);
	int get_zi();
	int get_suma_bani();
	char* get_tip();
	Cheltuieli_familie& operator=(const Cheltuieli_familie& c);
	bool operator==(const Cheltuieli_familie& c);
	void set_zi(int zi);
	void set_suma_bani(int suma_bani);
	void set_tip(char* tip);

	friend ostream& operator<<(ostream& os, const Cheltuieli_familie& c);


};
