#include "Console.h"
#include <iostream>



void Console::meniu() {
	cout << "1. Afiseaza produsele disponibile"<< endl;
	cout << "2. Afiseaza monedele din tonomat"<<endl;
	cout << "3. Cumpara un produs"<<endl;
	cout << "x. Stop " << endl;
}
int Console::console()
{
	int bancnota, cod;
	char op[10];
	int ok;
	char optiune;
	while (true) {
		
		this->meniu();

		cin >> optiune;
		if (optiune == '1') {
			this->show_produse();
		}
		else if (optiune == '2')
		{
			this->show_monede();
		}
		else if (optiune == 'x') {
			return 0;
		}
		else {
			while (true) {
				cout << "Introdu o bancnota: ";
				cin >> bancnota;
				this->service.addBancnota(bancnota);

				cout << "Introdu codul produsului pe care doresti sa-l achizitionezi: ";

				cin >> cod;

				int pret_produs = this->service.searchProductByCodAndGivePrice(cod);

				ok = this->service.canItGiveRest(pret_produs);
				if (ok == 1)
				{
					cout << "Produsul a fost achizitionat" << endl;
					break;
				}
				else if (ok == 0)
					cout << "Bani insuficienti" << endl;
				else if (ok == -1)
					cout << "Tonomatul nu are sa va dea rest" << endl;

				cout << "Doriti sa incercati sa incercati inca o data sa achizitionati produsul? <da/nu)" << endl;
				cout << "Daca alegeti varianta da, banii introdusi vor fi lasati si puteti introduce alte bancnote" << endl;
				cout << "Daca alegeti varianta nu, veti primii banii inapoi"<<endl;
				cout << "Ati ales: ";
				cin >> op;

				if (strcmp(op, "nu") == 0) {
					this->service.clear();
					break;
				}
			}

		}

		


	}
}



Console::Console()
{
}

Console::~Console()
{
}

Console::Console(const Service& s)
{
	this->service = s;
}

void Console::show_monede()
{
	vector<Monede> m = this->service.getMonede();
	int n = m.size();

	for (int i = 0; i < n; i++) {
		cout<< "Sunt " << m[i].getNumar() << " monede de valoare " << m[i].getValoare()<<endl;
	}
}


void Console::show_produse() {
	vector<Produs> p = this->service.getProduse();
	int n = p.size();
	cout << "Produsele valabile sunt: "<<endl;
	for (int i = 0; i < n; i++) {
		cout << "Produsul " << p[i].getNume() << " cu codul " << p[i].getCod() << " si pretul: " << p[i].getPret() << endl;
	}
	
}