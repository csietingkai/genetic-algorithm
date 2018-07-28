#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>

#include "ga.h"

using namespace std;

int main()
{
	srand(time(NULL));
	
	int length = 5;
	string keyword = generateRandomString(length);
	string answer = ga(keyword, 0.005);
	cout << answer << endl;
	
	return 0;
}
