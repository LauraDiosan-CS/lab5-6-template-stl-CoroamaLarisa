#pragma once
#include "Service.h"

class TestService {
private:
	Service service_cheltuieli_familie;
	void testAddCheltuiala();
	void testDeleteCheltuieli();
	void testGetByCond();
	void testPropBasedOnSublist();
	void testFilterByCond();
public:
	void testMain();

};