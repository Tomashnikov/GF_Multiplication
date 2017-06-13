#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>



std::vector<int> addition(std::vector<int> a, std::vector<int> b);
void multiplication(std::vector<int> a, std::vector<int> b);

using namespace std;

int main(int argc, char *argv[]) {


	std::string firstNumber, secondNumber;
	std::vector<int> fnVector, snVector, solutionVector;
	int firstNumberLength, secondNumberLength, solutionLength;

	std::cout << "GF(2) Calculator" << std::endl;

	if (argc<2) {
		std::cout << "Prosze podac liczbe A i B ponizej:" << std::endl;
		std::cout << "\n\t A = "; std::cin >> firstNumber;
		std::cout << "\t B = "; std::cin >> secondNumber;

	}
	else {
		firstNumber = argv[1];
		secondNumber = argv[2];
	}

	firstNumberLength = firstNumber.length();
	secondNumberLength = secondNumber.length();

	/*Inicjalizacja przestrzeni w wektorach*/

	if (firstNumberLength >= secondNumberLength) {
		solutionLength = firstNumberLength;
	}
	else {
		solutionLength = secondNumberLength;
	}
	std::cout << "\n\t Rozmiar GF = " << solutionLength << std::endl;
	std::cout << "\tA = " << firstNumber << " B = " << secondNumber << std::endl;
	std::cout << "\tlen(A) = " << firstNumberLength << " len(B) = " << secondNumberLength << std::endl;



	fnVector.resize(firstNumberLength);
	snVector.resize(secondNumberLength);
	solutionVector.resize(solutionLength);

	/*Inicjalizacja wektorów wartoœciami*/

	for (int x = firstNumberLength - 1; x >= 0; x--) {
		fnVector[x] = 0;
	}

	for (int x = secondNumberLength - 1; x >= 0; x--) {
		snVector[x] = 0;
	}

	for (int x = solutionLength - 1; x >= 0; x--) {
		solutionVector[x] = 0;
	}

	for (int x = 0; x < firstNumberLength; x++) {
		fnVector[x] = firstNumber[x] - '0';
	}

	for (int x = 0; x < secondNumberLength; x++) {
		snVector[x] = secondNumber[x] - '0';
	}

	/*Funkcja dodaj¹ca A + B*/
	solutionVector = addition(fnVector, snVector);
	std::cout << endl << "Liczba A:\t\t";
	for (int x = 0; x < firstNumberLength; x++) {
		std::cout << fnVector[x];
	}
	std::cout << endl << "Liczba B:\t\t";
	for (int x = 0; x < secondNumberLength; x++) {
		std::cout << snVector[x];
	}
	std::cout << endl << "Wynik obl.:\t\t";
	for (int x = 0; x < solutionLength; x++) {
		std::cout << solutionVector[x];
	}


	multiplication(fnVector, snVector);

std:cout << std::endl;

	return 0;
}
