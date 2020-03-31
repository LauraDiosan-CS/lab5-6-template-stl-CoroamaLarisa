#include "Console.h"
#include "Test.h"
#include "TestService.h"
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;


int main() {

	Test_Repo testRepo;
	TestService testService;

	testRepo.testMain();
	testService.testMain();

	const char* fileNameIn = "CheltuieliIn.txt";
	const char* fileNameOut = "CheltuieliOut.txt";

	Repo repo(fileNameIn,fileNameOut);
	
	Service service(repo);

	Console console(service);

	console.console_2();


	return 0;

}


