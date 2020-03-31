#include "TestRepoProdus.h"
#include <cassert>

void TestRepoProdus::testRepo()
{
	this->r_produse.setFileName("TestProduse.txt");
	this->r_produse.loadFromFile();

	int n = this->r_produse.getAll().size();

	for (int i = 0; i < n; i++) {
		assert(this->r_produse.getAll()[i] == this->produse_test[i]);
	}
}

void TestRepoProdus::testAddElem()
{
	this->r_produse.setFileName("TestProduse.txt");
	this->r_produse.loadFromFile();

	int n = this->r_produse.getAll().size();

	char* nume_1 = new char[strlen("Poiana") + 1];
	strcpy_s(nume_1, strlen("Poiana") + 1, "Poiana");
	Produs p1(5, nume_1, 3);

	this->r_produse.addElem(p1);

	assert(this->r_produse.getAll().size() == n + 1);
	assert(this->r_produse.getAll()[n] == p1);

	delete[] nume_1;
}

void TestRepoProdus::testDelElem()
{
	this->r_produse.setFileName("TestProduse.txt");
	this->r_produse.loadFromFile();

	int n = this->r_produse.getAll().size();

	char* nume_1 = new char[strlen("Twix") + 1];
	strcpy_s(nume_1, strlen("Twix") + 1, "Twix");
	Produs p1(123, nume_1, 4);

	this->r_produse.delElem(p1);

	assert(this->r_produse.getAll().size() == n - 1);

	delete[] nume_1;

}

TestRepoProdus::TestRepoProdus()
{
	char* nume_1 = new char[strlen("Twix")+1];
	strcpy_s(nume_1, strlen("Twix") + 1, "Twix");
	Produs p1(123, nume_1, 4);
	char* nume_2 = new char[strlen("Mars") + 1];
	strcpy_s(nume_2, strlen("Mars") + 1, "Mars");
	Produs p2(23, nume_2, 5);
	char* nume_3 = new char[strlen("Milka") + 1];
	strcpy_s(nume_3, strlen("Milka") + 1, "Milka");
	Produs p3(15, nume_3, 6);

	this->produse_test.push_back(p1);
	this->produse_test.push_back(p2);
	this->produse_test.push_back(p3);

	delete[] nume_1;
	delete[] nume_2;
	delete[] nume_3;
}



void TestRepoProdus::testMain()
{
	this->testRepo();
	this->testAddElem();
	this->testDelElem();
	this->testProductsGets();
	this->testProductsSets();
	this->testGetAll();
}


void TestRepoProdus::testProductsGets()
{
	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);

	assert(Produs_1.getCod() == 23);
	assert(strcmp(Produs_1.getNume(), name) == 0);
	assert(Produs_1.getPret() == 25);

	delete[] name;
}


void TestRepoProdus::testProductsSets()
{
	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);

	char* name_2 = new char[1 + strlen("nume_2")];
	strcpy_s(name_2, 1 + strlen("nume_2"), "nume_2");

	Produs_1.setCod(24);
	Produs_1.setNume(name_2);
	Produs_1.setPret(45);


	assert(Produs_1.getCod() == 24);
	assert(strcmp(Produs_1.getNume(), name_2) == 0);
	assert(Produs_1.getPret() == 45);

	delete[] name;
	delete[] name_2;
}

void TestRepoProdus::testGetAll()
{

	this->r_produse.setFileName("TestProduse.txt");
	this->r_produse.loadFromFile();

	int n = this->r_produse.getAll().size();

	assert(n == 3);
}


