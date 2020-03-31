#include "Service.h"

void Service::addBancnota(int bancnota)
{

	if (bancnote_adaugate.count(bancnota) > 0) {

		int original_count = bancnote_adaugate[bancnota];

		bancnote_adaugate[bancnota] = original_count + 1;
	}
	else
		bancnote_adaugate[bancnota] = 1;


}

Service::Service(const RepoSTL<Produs>& produse, const RepoSTL<Monede>& monede)
{
	this->repo_produse = produse;
	this->repo_monede = monede;

}

Service::Service(const Service& s)
{
	this->repo_produse = s.repo_produse;
	this->repo_monede = s.repo_monede;
	this->bancnote_adaugate = s.bancnote_adaugate;
}

int Service::canItGiveRest(int y)
{
	vector<Monede> monede = this->repo_monede.getAll();
	int n = monede.size();
	int rest = this->sumaBancAdaugate() - y;
	int rest_2 = rest;
	int nr_monede;
	if (rest < 0)
		return 0;
	else if (rest == 0) {
		this->if_true(rest_2);
		return 1;
	}
	else {

		for (int i = 0; i < n; i++) {
			while (rest >= monede[i].getValoare() && monede[i].getNumar() > 0) {
				rest -= monede[i].getValoare();
				nr_monede = monede[i].getNumar();
				monede[i].setNumar(nr_monede - 1);
			}
		}

		if (rest == 0)
		{
			this->if_true(rest_2);
			return 1;
		}
		else
			return -1;
	}
}

int Service::sumaBancAdaugate()
{
	int suma = 0;
	for (const auto& x : bancnote_adaugate) {
		int nr = x.second;
		int bancnota = x.first;
		suma = suma + nr * bancnota;
	}

	return suma;
}

void Service::clear()
{
	bancnote_adaugate.clear();
}

void Service::adaugaInMonede()
{
	int n = this->repo_monede.getAll().size();
	int valoare;
	int nr_precedent;
	for (int i = 0; i < n; i++) {
		valoare = this->repo_monede.getAll()[i].getValoare();
		if (bancnote_adaugate.count(valoare) > 0) {
			nr_precedent = this->repo_monede.getAll()[i].getNumar();
			this->repo_monede.setNumberAtPos(i,nr_precedent + bancnote_adaugate[valoare]);
		}
	}
}

int Service::searchProductByCodAndGivePrice(int cod)
{
	int n = this->repo_produse.getAll().size();
	for (int i = 0; i < n; i++)
		if (this->repo_produse.getAll()[i].getCod() == cod)
			return this->repo_produse.getAll()[i].getPret();
	return 0;
}

void Service::stergereBancnote(int rest)
{
	int nr_monede;
	int n = this->repo_monede.getAll().size();
	for (int i = 0; i <n; i++) {

		while (rest >= this->repo_monede.getAll()[i].getValoare() && this->repo_monede.getAll()[i].getNumar() > 0) {

			rest -= this->repo_monede.getAll()[i].getValoare();
			nr_monede = this->repo_monede.getAll()[i].getNumar();
			this->repo_monede.setNumberAtPos(i, nr_monede - 1);

		}
	}
}

vector<Monede> Service::getMonede()
{
	return this->repo_monede.getAll();
}

vector<Produs> Service::getProduse()
{
	return this->repo_produse.getAll();
}


void Service::if_true(int rest_2) {

	this->stergereBancnote(rest_2);
	this->adaugaInMonede();
	this->bancnote_adaugate.clear();
	this->repo_monede.saveToFile();

}