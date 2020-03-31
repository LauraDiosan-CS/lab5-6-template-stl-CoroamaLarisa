#include <ctime>
#include "Service.h"


int Service::getCurrentDay() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_mday;
}

void Service::addCheltuiala(int zi, int suma, char* tip) {

	if (zi == -1)
		zi = this->getCurrentDay();

	Cheltuieli_familie newCheltuiala(zi, suma, tip);
	this->repoCheltuialaFamilie.addElem(newCheltuiala);
}

Service::Service()
{
}

Service::~Service()
{
}

Service::Service(Repo& repo)
{
	this->repoCheltuialaFamilie = repo;
}

void Service::setRepo(Repo& repo)
{
	this->repoCheltuialaFamilie = repo;
}

/*get All cheltuieli*/

vector<Cheltuieli_familie> Service::getAll() {

	return this->repoCheltuialaFamilie.getAll();
}

/* ex. suma mâncare - suma tuturor cheltuielilor din categoria mâncare*/

int Service::sumElemByType(char* tip) {
	int sum = 0;

	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0) {
			sum += this->getAll()[i].get_suma_bani();
		}
	}

	return sum;

}

/*ex. max zi - afișarea zilei cu cele mai mari cheltuieli */


int Service::maxDayBySum() {
	int v[32] = { 0 };
	int max = -1;
	int max_zi = -1;
	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {

		v[this->getAll()[i].get_zi()] += this->getAll()[i].get_suma_bani();

		if (v[this->getAll()[i].get_zi()] > max) {
			max = v[this->getAll()[i].get_zi()];
			max_zi = this->getAll()[i].get_zi();

		}

	}

	return max_zi;

}

/* ex. sortare zi - afișarea sumelor cheltuite zilnic în ordine descrescătoare
*/

vector<Cheltuieli_familie> Service::sortBySumDesc() {

	int done = 1;
	int resultlen = 0;
	vector<Cheltuieli_familie> cheltuieli;


	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++)
		cheltuieli.push_back(this->getAll()[i]);

	resultlen = cheltuieli.size();

	while (done == 1) {
		done = 0;
		for (int i = 0; i < resultlen - 1; i++)
			if (cheltuieli[i].get_suma_bani() < cheltuieli[i + 1].get_suma_bani())
			{
				Cheltuieli_familie aux;
				aux = cheltuieli[i];
				cheltuieli[i] = cheltuieli[i + 1];
				cheltuieli[i + 1] = aux;

				done = 1;
			}
	}

	return cheltuieli;

}


/*ex. sortează mâncare - afișarea sumelor cheltuite zilnic pentru mâncare,
ordonate crescător */

vector<Cheltuieli_familie> Service::sortBySumAndType(char* tip) {

	int done = 1;
	int resultlen = 0;


	vector<Cheltuieli_familie> cheltuieli;

	for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++)
		if (strcmp(this->getAll()[i].get_tip(), tip) == 0)
			cheltuieli.push_back(this->getAll()[i]);

	resultlen = cheltuieli.size();

	while (done == 1) {
		done = 0;
		for (int i = 0; i < resultlen - 1; i++)
			if (cheltuieli[i].get_suma_bani() > cheltuieli[i + 1].get_suma_bani())
			{
				Cheltuieli_familie aux;
				aux = cheltuieli[i];
				cheltuieli[i] = cheltuieli[i + 1];
				cheltuieli[i + 1] = aux;

				done = 1;
			}

	}

	return cheltuieli;
}

/*lungimea lui repo*/

int Service::getSizeRepo() {
	return this->repoCheltuialaFamilie.getSize();
}

/*update la o cheltuiala*/

void Service::update(int day1, int sum1, char* tip1, int day2, int sum2, char* tip2) {
	Cheltuieli_familie c1(day1, sum1, tip1);
	Cheltuieli_familie c2(day2, sum2, tip2);

	this->repoCheltuialaFamilie.update(c1, c2);
}