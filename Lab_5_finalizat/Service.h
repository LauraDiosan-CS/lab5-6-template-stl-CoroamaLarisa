#pragma once
#include "Repo.h"


class Service {
private:
	Repo repoCheltuialaFamilie;
	
public:
	Service();
	~Service();
	Service(Repo& repo);
	void setRepo(Repo& repo);
	template<class T>

	bool condition(T a, Cheltuieli_familie c, int b) {

		if (std::is_same<T, char*>::value)
			return (strcmp((char*)a, c.get_tip()) == 0);

		else if (std::is_same<T, int>::value)
			if (b == 0) {
				return (int)a == c.get_zi();
			}
			else
				return ((int)a <= c.get_zi() && c.get_zi() <= b);


	};

	template<class A>

	void delete_cheltuieli(A a, int b = 0) {

		for (int i = 0; i < this->repoCheltuialaFamilie.getSize();) {

			if (condition(a, this->getAll()[i], b) == true) {

				this->repoCheltuialaFamilie.stergere(this->getAll()[i]);

			}
			else
				i++;


		}

	};

	template<class B>

	bool condition_f(char* a, Cheltuieli_familie c, B b, char eq) {

		if (std::is_same<B, bool>::value)
			return (strcmp(a, c.get_tip()) != 0);

		else if (std::is_same<B, int>::value) {
			if (eq == '<')
				return ((strcmp(a, c.get_tip()) != 0) || ((strcmp(a, c.get_tip()) == 0) && c.get_suma_bani() >= (int)b));
			else if (eq == '=')
				return ((strcmp(a, c.get_tip()) != 0) || ((strcmp(a, c.get_tip()) == 0) && c.get_suma_bani() != (int)b));
		}

	};

	template<class C>

	bool condition_g(char* a, Cheltuieli_familie c, C b, char eq) {

		if (std::is_same<C, bool>::value)
			return (strcmp(a, c.get_tip()) == 0);

		else if (std::is_same<C, int>::value) {
			if (eq == '>')
				return ((strcmp(a, c.get_tip()) == 0) && c.get_suma_bani() > (int)b);
			else if (eq == '=')
				return ((strcmp(a, c.get_tip()) == 0) && c.get_suma_bani() == (int)b);
		}

	};

	template <class D>

	void filter(char* a, D b, char eq = '<') {

		int i = 0;

		while (i < this->repoCheltuialaFamilie.getSize()) {
			if (condition_f(a, this->getAll()[i], b, eq) == true)
			{
				this->repoCheltuialaFamilie.stergere(this->getAll()[i]);

			}
			else
				i++;
		}


	};

	template <class E>

	vector<Cheltuieli_familie> get_by_cond(char* a, E b, char eq = '>') {

		vector<Cheltuieli_familie> cheltuieli;

		for (int i = 0; i < this->repoCheltuialaFamilie.getSize(); i++) {
			if (condition_g(a, this->getAll()[i], b, eq) == true)
			{
				cheltuieli.push_back(this->getAll()[i]);

			}
		}

		return cheltuieli;


	}

	int getCurrentDay();
	vector<Cheltuieli_familie> getAll();
	int sumElemByType(char* tip);
	int maxDayBySum();
	vector<Cheltuieli_familie> sortBySumDesc();
	vector<Cheltuieli_familie> sortBySumAndType(char* tip);
	int getSizeRepo();
	void update(int day1, int sum1, char* tip1, int day2, int sum2, char* tip2);
	void addCheltuiala(int zi, int suma, char* tip);

};