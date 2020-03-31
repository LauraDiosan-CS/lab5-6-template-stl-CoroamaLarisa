#include <iostream>
#include "RepoSTL.h"
#include "Console.h"
#include "TestRepoProdus.h"
#include "TestRepo.h"
using namespace std;


int main() {
	TestRepo t_r;
	TestRepoProdus t;
	t_r.test_repo();
	t.testMain();

	RepoSTL<Produs> repo_prod("Produse.txt");

	RepoSTL<Monede> repo_monede("Monede.txt");
	
	Service s(repo_prod, repo_monede);
	
	Console c(s);

	c.console();

	return 0;

}