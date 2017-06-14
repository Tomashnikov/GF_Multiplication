#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> modulus(std::vector<int> a);

void multiplication(std::vector<int> a, std::vector<int> b) {

	std::vector<int> c;
	c.resize(a.size() + b.size() - 1);

	for (int x = 0; x < b.size(); x++) {
		for (int y = 0; y < a.size(); y++) {
			c[x + y] += a[y] * b[x];
		}
	}

	for (int x = 0; x < c.size(); x++) {
		c[x] %= 2;
	}

	std::cout << std::endl << "\n\tIloczyn przed modulacja: \t\t";
	for (int x = 0; x < c.size(); x++) {
		std::cout << "" << c[x] << "";
	}


		c = modulus(c);
	

	std::cout << std::endl << "\tIloczyn po modulacji: \t\t";
	for (int x = 0; x < c.size(); x++) {
		std::cout << "" << c[x] << "";
	}
	std::cout << std::endl << std::endl;

}