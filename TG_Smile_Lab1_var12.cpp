#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//cout << fixed;
	//cout.precision(2);

	double x1, x2, d, y, a;
	x1 = -10;
	x2 = 5;
	d = 1.5;

	cout << "Enter a: ";
	cin >> a;

	int i = 1;

	cout << " _________________________________________________ " << "\n";
	printf("| %2s | %5s | %15s | %15s  |\n", "No", "x=", "a=", "y="); //("| № | x = | a = | y = |\n");

	while (x1 <= x2) {
		if (x1<0) {
			printf("|----|-------|-----------------|------------------|\n");
			printf("| %2i | %5.1f | %15.6f | %16s |\n", i, x1, a, "no solution");
			i++;
			x1 += d;
		}
		else if (((a * (sin(x1 / a) + log(x1))) != 0) && a != 0) {
			y = 0.5 / (a * (sin(x1 / a) + log(x1)));

			printf("|----|-------|-----------------|------------------|\n");
			printf("| %2i | %5.1f | %15.6f | %16f |\n", i, x1, a, y);
			i++;
			x1 += d;
		}
		else {

			printf("|----|-------|-----------------|------------------|\n");
			printf("| %2i | %5.1f | %15.6f |              nun |\n", i, x1, a);
			x1 += d;
			i++;
		}
	}

	cout << "---------------------------------------------------" << "\n";

	return 0;
}
