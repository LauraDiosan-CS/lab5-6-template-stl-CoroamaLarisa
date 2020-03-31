#pragma once
#include "Cheltuieli_familie.h"
#include <vector>

class Repo {
private:
	vector<Cheltuieli_familie> cheltuieli;
	char* fileNameIn;
	char* fileNameOut;
public:

	Repo();
	Repo(const char* fileNameIn, const char* fileNameOut);
	~Repo();
	void addElem(Cheltuieli_familie c);
	vector<Cheltuieli_familie> getAll();
	int getSize();
	void stergere(Cheltuieli_familie& c);
	Cheltuieli_familie getElemAtPos(int p);
	void update(Cheltuieli_familie &c1,Cheltuieli_familie &c2);
	void loadFromFile();
	void saveToFile();
	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameOut);
	Repo& operator=(const Repo& repo);
};
