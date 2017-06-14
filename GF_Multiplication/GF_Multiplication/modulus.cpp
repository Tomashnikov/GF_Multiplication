#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "commonResources.h"

std::vector<int> addition(std::vector<int> a, std::vector<int> b);

std::vector<int> modulus(std::vector<int> a)
{
	std::vector<int> modulusVector;
	std::vector<int> solution;
	std::string modulusString;

	std::cout << "\nProsze podac dzielnik modulo postaci zerojedynkowej o stopniu  " << galoisFieldSize << " :" << std::endl;
	std::cout << "\n\t A = "; std::cin >> modulusString;
	modulusVector.resize(modulusString.length());

	for (unsigned int x = 0; x < modulusString.length(); x++) {
		modulusVector[x] = modulusString[x] - '0';
	}


	std::cout << std::endl << "\tModulus:\t\t";
	for (unsigned int x = 0; x < modulusString.length(); x++) {
		std::cout << modulusVector[x];
	}

	do {
		modulusVector.resize(a.size());
		std::cout << std::endl << "Nowy rozmiar modulu: " << modulusVector.size() << std::endl;
		
		for (unsigned int x = 0; x < a.size(); x++) {
			std::cout << a[x];
		}
		std::cout << " x " << std::endl;
		for (unsigned int x = 0; x < modulusVector.size(); x++) {
			std::cout << modulusVector[x];
		}
		std::cout << std::endl;

		a = addition(modulusVector, a);

		std::rotate(a.begin(), a.begin() + 1, a.end());
		a.resize(a.size() - 1);
	} while (a.size() >= galoisFieldSize);


	solution = a;

	//dwda
	return solution;
}