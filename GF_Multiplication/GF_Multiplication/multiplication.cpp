#include <vector>
#include <iostream>
#include <algorithm>

void multiplication(std::vector<int> a, std::vector<int> b) {

	std::vector<int> c;
	std::cout << "Rozmiar A: " << a.size() << std::endl;
	std::cout << "Rozmiar B: " << a.size() << std::endl;
	c.resize(a.size() + b.size() - 1);

	std::cout << "Rozmiar docelowy: " << c.size() << std::endl;

	for (int x = 0; x < b.size(); x++) {
		for (int y = 0; y < a.size(); y++) {
			c[x + y] += a[y] * b[x];
		}
	}

	for (int x = 0; x < c.size(); x++) {
		c[x] %= 2;
	}

	std::cout << std::endl;
	for (int x = 0; x < c.size(); x++) {
		std::cout << "" << c[x] << "";
	}

}