#pragma once
#include "RepoSTL.h"
#include "Produs.h"
#include <vector>
class TestRepoProdus {
private:
	RepoSTL<Produs> r_produse;
	vector<Produs> produse_test;
	void testRepo();
	void testAddElem();
	void testDelElem();
	void testProductsGets();
	void testProductsSets();
	void testGetAll();
public:
	TestRepoProdus();
	void testMain();
};