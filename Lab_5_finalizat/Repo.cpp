#include "Repo.h"
#include <cstddef>
#include <fstream>

Repo::Repo() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

Repo::Repo(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn)+1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn)+1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut)+1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut)+1, fileNameOut);
	this->loadFromFile();
}


Repo::~Repo() {

	this->cheltuieli.clear();
	delete[] this->fileNameIn;
	delete[] this->fileNameOut;

}

int Repo::getSize() {
	return this->cheltuieli.size();
}

void Repo::addElem(Cheltuieli_familie c) {

	this->cheltuieli.push_back(c);

	this->saveToFile();
}

vector<Cheltuieli_familie> Repo::getAll() {

	return this->cheltuieli;
}


void Repo::stergere(Cheltuieli_familie& c) {

	vector<Cheltuieli_familie>::iterator it;

	it = find(this->cheltuieli.begin(), this->cheltuieli.end(), c);
	if (!(it == this->cheltuieli.end())) {
		this->cheltuieli.erase(it);
	}

	this->saveToFile();
}

Cheltuieli_familie Repo::getElemAtPos(int pos)
{
	if (pos<0 || pos>this->cheltuieli.size() - 1)
		return Cheltuieli_familie();
	else
		return this->cheltuieli[pos];
}


void Repo::update(Cheltuieli_familie& c1, Cheltuieli_familie& c2) {

	vector<Cheltuieli_familie>::iterator it;

	it = find(this->cheltuieli.begin(), this->cheltuieli.end(), c1);

	if (!(it == this->cheltuieli.end())) {
		*it = c2;
	}

	this->saveToFile();


}

void Repo::loadFromFile()
{
	if (this->fileNameIn != NULL) {
		this->cheltuieli.clear();
		ifstream f(this->fileNameIn);
		int zi;
		int suma;
		char* tip = new char[30];
		while (!f.eof()) {
			f >> zi >> suma >> tip;
			if (strlen(tip) > 0) {

				this->cheltuieli.push_back(Cheltuieli_familie(zi, suma, tip));
			}
		}

		delete[] tip;
		f.close();
	}
	else
		this->cheltuieli.clear();


}

void Repo::saveToFile()
{	// TO DO: salveaza in fisier lista cu cheltuieli

	if (this->fileNameOut != NULL) {

		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->cheltuieli.size(); i++) {
			f << this->cheltuieli[i] << endl;
		}
		f.close();
	}
}

void Repo::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL) {
		delete[] this->fileNameIn;
	}
	if (fileNameIn != NULL) {
		this->fileNameIn = new char[strlen(fileNameIn) + 1];
		strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	}
	else
		this->fileNameIn = NULL;

}

void Repo::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL) {
		delete[] this->fileNameOut;
	}
	if (fileNameOut != NULL) {
		this->fileNameOut = new char[strlen(fileNameOut) + 1];
		strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	}
	else
		this->fileNameOut = NULL;

}


Repo& Repo::operator=(const Repo& repo)
{
	// TODO: insert return statement here


	this->setFileNameIn(repo.fileNameIn);
	this->setFileNameOut(repo.fileNameOut);
	this->loadFromFile();

	return *this;

}

