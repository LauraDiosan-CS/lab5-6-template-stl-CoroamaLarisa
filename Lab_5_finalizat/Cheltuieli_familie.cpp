#include "Cheltuieli_familie.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Cheltuieli_familie::Cheltuieli_familie() {

	this->zi = 0;
	this->suma_bani = 0;
	this->tip = NULL;

}

Cheltuieli_familie::Cheltuieli_familie(const Cheltuieli_familie& c) {
	this->zi = c.zi;
	this->suma_bani = c.suma_bani;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}

Cheltuieli_familie::~Cheltuieli_familie() {
	this->zi = 0;
	this->suma_bani = 0;
	if (this->tip != NULL) {
		delete[] this->tip;
		this->tip = NULL;
	}
}

Cheltuieli_familie::Cheltuieli_familie(int zi, int suma_bani, char* tip) {
	this->zi = zi;
	this->suma_bani = suma_bani;

	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

bool Cheltuieli_familie::operator==(const Cheltuieli_familie& c) {
	return (this->zi == c.zi) && (this->suma_bani == c.suma_bani) && (strcmp(this->tip, c.tip) == 0);
}

int Cheltuieli_familie::get_zi() {
	return this->zi;
}

int Cheltuieli_familie::get_suma_bani() {
	return this->suma_bani;
}

char* Cheltuieli_familie::get_tip() {
	return this->tip;
}

void Cheltuieli_familie::set_zi(int zi) {
	this->zi = zi;
}

void Cheltuieli_familie::set_suma_bani(int suma_bani) {
	this->suma_bani = suma_bani;
}

void Cheltuieli_familie::set_tip(char* tip) {

	if (this->tip != NULL) {
		delete[] this->tip;
	}

	if (tip != NULL) {
		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	}
	else
		this->tip = NULL;
}

Cheltuieli_familie& Cheltuieli_familie::operator=(const Cheltuieli_familie& c) {

	this->set_zi(c.zi);
	this->set_suma_bani(c.suma_bani);
	this->set_tip(c.tip);

	return *this;

}

ostream& operator<<(ostream& os, const Cheltuieli_familie& c) {
	os << c.zi << " " << c.suma_bani << " " << c.tip;
	return os;
}