#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>

class Calatorie {
private:
	int const idCalatorie;
	char* numeDestinatie;
	float pretCalatorie;
	int durataZile;
	static int numarCalatorii;

public:

	// constructor default

	Calatorie() : idCalatorie(++numarCalatorii) {
		this->numeDestinatie = nullptr;
		this->pretCalatorie = 0.0f;
		this->durataZile = 0;

	}

	// constructor cu parametrii 

	Calatorie(int idCalatorie, const char* numeDestinatie, float pretCalatorie, int durataZile) : idCalatorie(idCalatorie) {
		
		if (numeDestinatie != nullptr) {
			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
			strcpy(this->numeDestinatie, numeDestinatie);
		}
		else {
			this->numeDestinatie = nullptr;
		}

		this->pretCalatorie = pretCalatorie;
		this->durataZile = durataZile;
	}

	// destructor

	~Calatorie() {
		delete[] numeDestinatie;
	}

};

void main() {

}