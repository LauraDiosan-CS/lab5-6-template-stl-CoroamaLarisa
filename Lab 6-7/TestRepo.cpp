#include "TestRepo.h"
#include <cassert>
#include "Produs.h"
#include "Repo.h"

void TestRepo::test_repo()
{

	this->test_get_all();
	this->test_add_elem();
	this->test_del_elem();
}

void TestRepo::test_get_all()
{
	Repo<Produs> r = Repo<Produs>();

	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);


	r.addElem(Produs_1);


	char* name_2 = new char[1 + strlen("nume_2")];
	strcpy_s(name_2, 1 + strlen("nume_2"), "nume_2");
	Produs Produs_2 = Produs(23, name_2, 50);

	r.addElem(Produs_2);


	assert(r.getSize() == 2);
	assert(r.getAll()[0] == Produs_1);
	assert(r.getAll()[1] == Produs_2);


	delete[] name;
	delete[] name_2;
}

void TestRepo::test_add_elem()
{

	Repo<Produs> r = Repo<Produs>();

	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);

	r.addElem(Produs_1);


	assert(r.getSize() == 1);
	assert(r.getAll()[0] == Produs_1);


	delete[] name;

}

void TestRepo::test_del_elem()
{

	Repo<Produs> r = Repo<Produs>();

	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);

	r.addElem(Produs_1);
	r.stergere(Produs_1);
	int(r.getSize() == 0);
}
