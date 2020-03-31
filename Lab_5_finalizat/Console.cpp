#include "Console.h"
#include <boost/algorithm/string.hpp> 
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Console::Console(Service& s)
{
	this->service_cheltuieli = s;
}

void Console::show_cheltuieli_familie(vector<Cheltuieli_familie> c)
{
	int size = c.size();
	for (int i = 0; i < size; i++) {
		cout << c[i] << endl;

	}


}

vector<char*> Console::get_command()
{
	string input;
	getline(cin, input);
	vector<string> result;

	boost::split(result, input, boost::is_any_of(" "));

	vector<char*> cuvinte;
	char* cuvant;
	int len;
	for (int i = 0; i < result.size(); i++) {

		len = result[i].length();

		cuvant = new char[len + 1];

		strcpy_s(cuvant, len + 1, result[i].c_str());
		cuvinte.push_back(cuvant);

	}

	return cuvinte;



}

int Console::console_2()
{
	vector<Cheltuieli_familie> rezultate;
	int suma, zi, zi2;



	while (true) {
		vector<char*> op = this->get_command();


		if (strcmp(op[0], "adauga") == 0) {
			suma = atoi(op[1]);

			this->service_cheltuieli.addCheltuiala(-1, suma, op[2]);
		}
		else if (strcmp(op[0], "insereaza") == 0) {
			zi = atoi(op[1]);
			suma = atoi(op[2]);

			this->service_cheltuieli.addCheltuiala(zi, suma, op[3]);
		}
		else if (strcmp(op[0], "elimina") == 0) {
			zi = atoi(op[1]);
			if (op.size() == 2) {
				if (zi > 31 || zi < 0) {
					this->service_cheltuieli.delete_cheltuieli(op[1]);
				}
				else
					this->service_cheltuieli.delete_cheltuieli(zi);
			}
			else {
				zi2 = atoi(op[3]);
				this->service_cheltuieli.delete_cheltuieli(zi, zi2);

			}
		}
		else if (strcmp(op[0], "listeaza") == 0) {
			if (op.size() == 1) {
				rezultate = this->service_cheltuieli.getAll();
			}
			else if (op.size() == 2) {
				rezultate = this->service_cheltuieli.get_by_cond(op[1], false);

			}
			else {
				suma = atoi(op[3]);

				if (strcmp(op[2], ">") == 0)
					rezultate = this->service_cheltuieli.get_by_cond(op[1], suma, '>');
				else
					rezultate = this->service_cheltuieli.get_by_cond(op[1], suma, '=');
			}

			this->show_cheltuieli_familie(rezultate);
			rezultate.clear();
		}
		else if (strcmp(op[0], "suma") == 0) {
			cout << this->service_cheltuieli.sumElemByType(op[1]) << endl;
		}
		else if (strcmp(op[0], "max") == 0 && strcmp(op[1], "zi") == 0) {
			cout << this->service_cheltuieli.maxDayBySum()<< endl;
		}
		else if (strcmp(op[0], "sortare") == 0) {

			if (strcmp(op[1], "zi") == 0) {
				rezultate = this->service_cheltuieli.sortBySumDesc();
			}
			else
				rezultate = this->service_cheltuieli.sortBySumAndType(op[1]);
			for (int i = 0; i < rezultate.size(); i++)
				cout << rezultate[i].get_suma_bani()<<" ";
			cout << endl;
			rezultate.clear();
		}
		else if (strcmp(op[0], "filtrare") == 0) {
			if (op.size() == 2) {
				this->service_cheltuieli.filter(op[1], false);
			}
			else {
				suma = atoi(op[3]);
				if (strcmp(op[2], "<") == 0)
					this->service_cheltuieli.filter(op[1], suma, '<');
				else
					this->service_cheltuieli.filter(op[1], suma, '=');
			}
		}
		else if (strcmp(op[0], "stop") == 0)
			return 0;
	}
}
