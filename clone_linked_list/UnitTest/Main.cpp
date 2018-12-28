#include "TestHarness.h"
#include <iostream>

using namespace std;

int main()
{

	// random number generator used in some tests
	srand(::time_t(NULL));

    TestResult tr;
    TestRegistry::runAllTests(tr);

	// force console screen to hold
	char ch;
	std::cin >> ch;

    return 0;
}
