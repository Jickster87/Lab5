#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

using namespace std;

int main() {
	cout << "SHORT Test start\n" << endl;
	testAll();
	cout << "SHORT Test end\n" << endl;
	cout << "EXTENDED Test start\n" << endl;
	testAllExtended();

	cout << "ALL Test end\n" << endl;
	system("pause");
}