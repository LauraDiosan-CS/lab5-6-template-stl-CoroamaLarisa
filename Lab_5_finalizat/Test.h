#pragma once
#include "Repo.h"


//void test_cheltuieli_familie();
//
//void test_repo_cheltuieli_familie();
//
//void test_service_cheltuieli_familie();
//
//


class Test_Repo {
private:
	Repo repo;
	vector<Cheltuieli_familie> cheltuieli_test;
	void testLoadFromFile();
	void testSaveToFile();
	void testGetSize();
	void testGetAll();
	void testStergere();
	void testAddElem();
	void testGetElemAtPos();
	void testUpdate();
	const char* fileNameIn = "TestCheltuieliIn.txt";
	const char* fileNameOut = "TestCheltuieliOut.txt";
public:
	Test_Repo();
	void testMain();
	~Test_Repo();
};
