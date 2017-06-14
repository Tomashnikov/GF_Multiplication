#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include "commonResources.h"

int galoisFieldSize = 0;

std::vector<int> addition(std::vector<int> a, std::vector<int> b);
void multiplication(std::vector<int> a, std::vector<int> b);

using namespace std;

int main(int argc, char *argv[]) {


	std::string firstNumber, secondNumber;
	std::vector<int> fnVector, snVector, solutionVector;
	int firstNumberLength, secondNumberLength, solutionLength;

	std::cout << "GF(2) Calculator" << std::endl;

	if (argc<3) {
		std::cout << "Prosze podac liczby A i B, oraz rozmiar ciala Galois w polach ponizej:" << std::endl;
		std::cout << "\n\tA = "; std::cin >> firstNumber;
		std::cout << "\tB = "; std::cin >> secondNumber;
		std::cout << "\tm = "; std::cin >> galoisFieldSize;

	}
	else {
		firstNumber = argv[1];
		secondNumber = argv[2];
		galoisFieldSize = atoi(argv[3]);
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
	std::cout << "\n\tRozmiar GF = " << galoisFieldSize << std::endl;
	std::cout << "\tA = " << firstNumber << "\tB = " << secondNumber << std::endl;
	std::cout << "\tlen(A) = " << firstNumberLength << "\tlen(B) = " << secondNumberLength << std::endl;



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
	std::cout << endl << "\tLiczba A:\t\t\t";
	for (int x = 0; x < firstNumberLength; x++) {
		std::cout << fnVector[x];
	}
	std::cout << endl << "\tLiczba B:\t\t\t";
	for (int x = 0; x < secondNumberLength; x++) {
		std::cout << snVector[x];
	}
	std::cout << endl << "\tWynik dodawania:\t\t";
	for (int x = 0; x < solutionLength; x++) {
		std::cout << solutionVector[x];
	}


	multiplication(fnVector, snVector);

	std::cout << std::endl;

	return 0;
}
