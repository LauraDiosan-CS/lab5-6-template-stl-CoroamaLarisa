#include "Test.h"
#include <cassert>

void Test_Repo::testLoadFromFile()
{
	this->repo.setFileNameIn(this->fileNameIn);
	this->repo.loadFromFile();
	assert(this->repo.getSize() == 3);

	vector<Cheltuieli_familie> cheltuieli_to_test = this->repo.getAll();

	for (int i = 0; i < this->repo.getSize(); i++) {

		assert(cheltuieli_to_test[i] == this->cheltuieli_test[i]);
	}

}

void Test_Repo::testSaveToFile()
{
	this->repo.setFileNameIn(this->fileNameIn);
	this->repo.setFileNameOut(this->fileNameOut);
	this->repo.loadFromFile();
	int initiallen = this->repo.getSize();

	char* tip = new char[strlen("mancare") + 1];
	strcpy_s(tip, strlen("mancare") + 1, "mancare");
	Cheltuieli_familie c1(5, 60, tip);
	this->repo.addElem(c1);
	this->repo.setFileNameIn(this->fileNameOut);
	this->repo.loadFromFile();
	assert(this->repo.getSize() == initiallen + 1);

	vector<Cheltuieli_familie> cheltuieli_to_test = this->repo.getAll();

	for (int i = 0; i < this->repo.getSize() - 1; i++)
	{
		assert(cheltuieli_to_test[i] == this->cheltuieli_test[i]);
	}

	assert(cheltuieli_to_test[initiallen] == c1);
	


}

void Test_Repo::testGetSize()
{
	this->repo.setFileNameIn(this->fileNameIn);
	this->repo.loadFromFile();
	assert(this->repo.getSize() == 3);
}

void Test_Repo::testGetAll()
{
	this->repo.setFileNameIn(this->fileNameIn);
	this->repo.loadFromFile();
	vector<Cheltuieli_familie> cheltuieli_to_test= this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		assert(this->cheltuieli_test[i] == cheltuieli_to_test[i]);
	}
}

void Test_Repo::testStergere()
{
	this->repo.setFileNameIn(this->fileNameIn);
	this->repo.loadFromFile();
	int initiallen = this->repo.getSize();
	char* tip = new char[strlen("mancare") + 1];
	strcpy_s(tip, strlen("mancare") + 1, "mancare");
	Cheltuieli_familie c1(1, 10, tip);
	this->repo.stergere(c1);
	assert(initiallen - 1 == this->repo.getSize());
	this->repo.stergere(this->cheltuieli_test[1]);
	assert(initiallen - 2 == this->repo.getSize());
}

void Test_Repo::testAddElem()
{
	this->repo.setFileNameIn(this->fileNameIn);
	this->repo.loadFromFile();
	char* tip = new char[strlen("mancare") + 1];
	strcpy_s(tip, strlen("mancare") + 1, "mancare");
	Cheltuieli_familie c1(10, 100, tip);
	Cheltuieli_familie c2(20, 300, tip);
	this->repo.addElem(c1);
	this->repo.addElem(c2);

	assert(this->repo.getSize() == 5);
}

void Test_Repo::testGetElemAtPos()
{
	this->repo.setFileNameIn(fileNameIn);
	this->repo.loadFromFile();
	assert(this->repo.getElemAtPos(0) == this->cheltuieli_test[0]);
	
}

void Test_Repo::testUpdate()
{
	this->repo.setFileNameIn(this->fileNameIn);
	this->repo.loadFromFile();
	char* tip = new char[strlen("mancare") + 1];
	strcpy_s(tip, strlen("mancare") + 1, "mancare");
	Cheltuieli_familie c1(1, 10, tip);
	char* tip_2 = new char[strlen("internet") + 1];
	strcpy_s(tip_2, strlen("internet") + 1, "internet");
	Cheltuieli_familie c2(20, 300, tip_2);
	this->repo.update(c1, c2);
	assert(this->repo.getElemAtPos(0) == c2);

}


Test_Repo::Test_Repo()
{
	char* tip = new char[strlen("mancare") + 1];
	strcpy_s(tip, strlen("mancare") + 1, "mancare");
	Cheltuieli_familie c1(1, 10, tip);
	Cheltuieli_familie c2(2, 30, tip);
	char* tip_2 = new char[strlen("internet") + 1];
	strcpy_s(tip_2, strlen("internet") + 1, "internet");
	Cheltuieli_familie c3(4, 60, tip_2);


	cheltuieli_test.push_back(c1);
	cheltuieli_test.push_back(c2);
	cheltuieli_test.push_back(c3);

}

void Test_Repo::testMain()
{
	this->testLoadFromFile();
	this->testSaveToFile();
	this->testGetSize();
	this->testGetAll();
	this->testAddElem();
	this->testStergere();
	this->testGetElemAtPos();
	this->testUpdate();

}

Test_Repo::~Test_Repo()
{
	this->cheltuieli_test.clear();
}
