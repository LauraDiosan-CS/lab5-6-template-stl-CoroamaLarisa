#include "TestService.h"
#include <cassert>

void TestService::testAddCheltuiala()
{
	Repo repo;
	this->service_cheltuieli_familie.setRepo(repo);
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");



	this->service_cheltuieli_familie.addCheltuiala(-1, 100, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(11, 100, tip_2);

	int currentday = service_cheltuieli_familie.getCurrentDay();

	assert(this->service_cheltuieli_familie.getAll()[0].get_zi() == currentday);
	assert(this->service_cheltuieli_familie.getAll()[1].get_zi() == 11);
	assert(this->service_cheltuieli_familie.getAll()[0].get_suma_bani() == 100);
	assert(this->service_cheltuieli_familie.getAll()[1].get_suma_bani() == 100);
	assert(strcmp(this->service_cheltuieli_familie.getAll()[0].get_tip(), "haine") == 0);
	assert(strcmp(this->service_cheltuieli_familie.getAll()[1].get_tip(), "mancare") == 0);


	delete[] tip_1;
	delete[] tip_2;
}

void TestService::testDeleteCheltuieli()
{
	Repo repo;
	this->service_cheltuieli_familie.setRepo(repo);

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	char* tip_3 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	strcpy_s(tip_3, strlen("menaj") + 1, "menaj");

	this->service_cheltuieli_familie.addCheltuiala(1, 10, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(2, 20, tip_3);
	this->service_cheltuieli_familie.addCheltuiala(3, 30, tip_2);
	this->service_cheltuieli_familie.addCheltuiala(4, 40, tip_2);
	this->service_cheltuieli_familie.addCheltuiala(5, 50, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(6, 60, tip_3);
	this->service_cheltuieli_familie.addCheltuiala(7, 70, tip_3);
	this->service_cheltuieli_familie.addCheltuiala(8, 80, tip_3);

	assert(this->service_cheltuieli_familie.getSizeRepo() == 8);
	this->service_cheltuieli_familie.delete_cheltuieli(tip_1);
	assert(this->service_cheltuieli_familie.getSizeRepo() == 6);
	this->service_cheltuieli_familie.delete_cheltuieli(2);
	assert(this->service_cheltuieli_familie.getSizeRepo() == 5);
	this->service_cheltuieli_familie.delete_cheltuieli(6,8);
	assert(this->service_cheltuieli_familie.getSizeRepo() == 2);

	delete[] tip_1;
	delete[] tip_2;
	delete[] tip_3;
}

void TestService::testGetByCond()
{
	Repo repo;
	this->service_cheltuieli_familie.setRepo(repo);

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	this->service_cheltuieli_familie.addCheltuiala(-1,100, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(11, 150, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(12, 200, tip_2);
	this->service_cheltuieli_familie.addCheltuiala(13, 250, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(14, 100, tip_2);
	this->service_cheltuieli_familie.addCheltuiala(30, 100, tip_2);



	vector<Cheltuieli_familie> rezultat = this->service_cheltuieli_familie.get_by_cond(tip_1,false);

	assert(rezultat.size() == 3);
	assert(rezultat[1].get_zi() == 11);
	assert(rezultat[2].get_zi() == 13);

	rezultat.clear();

	rezultat = this->service_cheltuieli_familie.get_by_cond(tip_1,120,'>');

	assert(rezultat.size() == 2);
	assert(rezultat[0].get_zi() == 11);
	assert(rezultat[1].get_zi() == 13);
	
	rezultat.clear();

	rezultat=this->service_cheltuieli_familie.get_by_cond(tip_2,100,'=');

	assert(rezultat.size() == 2);
	assert(rezultat[0].get_zi() == 14);
	assert(rezultat[1].get_zi() == 30);

	rezultat.clear();

	delete[] tip_1;
	delete[] tip_2;
}

void TestService::testPropBasedOnSublist()
{
	Repo repo;
	this->service_cheltuieli_familie.setRepo(repo);

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	char* tip_3 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	strcpy_s(tip_3, strlen("internet") + 1, "internet");

	this->service_cheltuieli_familie.addCheltuiala(11, 150, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(12, 200, tip_2);
	this->service_cheltuieli_familie.addCheltuiala(13, 250, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(14, 100, tip_3);
	this->service_cheltuieli_familie.addCheltuiala(30, 120, tip_3);


	int sum = this->service_cheltuieli_familie.sumElemByType(tip_1);
	assert(sum == 400);
	int max_zi = this->service_cheltuieli_familie.maxDayBySum();
	assert(max_zi == 13);

	vector<Cheltuieli_familie> rezultat= this->service_cheltuieli_familie.sortBySumDesc();
	
	assert(rezultat.size() == 5);
	assert(rezultat[0].get_zi() == 13);
	assert(rezultat[1].get_zi() == 12);
	assert(rezultat[4].get_zi() == 14);

	rezultat.clear();

	rezultat= this->service_cheltuieli_familie.sortBySumAndType(tip_3);
	
	assert(rezultat.size());
	assert(rezultat[0].get_zi() == 14);
	assert(rezultat[0].get_suma_bani() == 100);
	assert(rezultat[1].get_zi() == 30);
	assert(rezultat[1].get_suma_bani() == 120);
	
	rezultat.clear();
	
	delete[] tip_1;
	delete[] tip_2;
	delete[] tip_3;


}

void TestService::testFilterByCond()
{
	Repo repo;
	this->service_cheltuieli_familie.setRepo(repo);
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	char* tip_3 = new char[10];
	
	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	strcpy_s(tip_3, strlen("internet") + 1, "internet");
	

	this->service_cheltuieli_familie.addCheltuiala(11, 150, tip_1);
	this->service_cheltuieli_familie.addCheltuiala(12, 200, tip_2);
	this->service_cheltuieli_familie.addCheltuiala(13, 250, tip_3);
	this->service_cheltuieli_familie.addCheltuiala(14, 100, tip_3);
	this->service_cheltuieli_familie.addCheltuiala(30, 120, tip_2);
	
	this->service_cheltuieli_familie.filter(tip_2,false);
	
	assert(this->service_cheltuieli_familie.getAll()[0].get_zi() == 12);
	assert(this->service_cheltuieli_familie.getAll()[1].get_zi() == 30);
	assert(this->service_cheltuieli_familie.getSizeRepo() == 2);
	
	this->service_cheltuieli_familie.filter(tip_2,150,'<');
	assert(this->service_cheltuieli_familie.getAll()[0].get_zi() == 30);
	assert(this->service_cheltuieli_familie.getAll()[0].get_suma_bani() == 120);
	
	this->service_cheltuieli_familie.addCheltuiala(11, 140, tip_2);
	this->service_cheltuieli_familie.addCheltuiala(12, 150, tip_2);
	
	this->service_cheltuieli_familie.filter(tip_2,120,'=');
	
	assert(this->service_cheltuieli_familie.getAll()[0].get_zi() == 30);
	assert(this->service_cheltuieli_familie.getAll()[0].get_suma_bani() == 120);
	
	
	delete[] tip_1;
	delete[] tip_2;
	delete[] tip_3;
}


void TestService::testMain()
{
	this->testAddCheltuiala();
	this->testDeleteCheltuieli();
	this->testGetByCond();
	this->testPropBasedOnSublist();
	this->testFilterByCond();
}
