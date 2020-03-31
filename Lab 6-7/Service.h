#pragma once
#include "RepoSTL.h"
#include "Produs.h"
#include "Monede.h"
#include <map>
using namespace std;

class Service {
private:
	RepoSTL<Produs> repo_produse;
	RepoSTL<Monede> repo_monede;
	map<int, int> bancnote_adaugate;
public:

	void addBancnota(int bancnota);

	Service() {};
	~Service() {
		bancnote_adaugate.clear();
	};
	Service(const RepoSTL<Produs>& produse, const RepoSTL<Monede>& monede);

	Service(const Service& s);

	int canItGiveRest(int y);

	int sumaBancAdaugate();

	void clear();

	void adaugaInMonede();

	int searchProductByCodAndGivePrice(int cod);

	void stergereBancnote(int rest);
	
	vector<Monede> getMonede();

	vector<Produs> getProduse();

	void if_true(int rest);
};