#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<stdio.h>
#include <string.h>

using namespace std;

class Prajitura {
private: 
	char* denumire;
	int nrCalorii;
	float* gramajIngrediente;
	bool esteVegana;
	float pret;
	static float numarPrajituri;

public:

	// constructor fara parametrii

	Prajitura() {
		this->denumire = nullptr;
		this->nrCalorii = 0;
		this->gramajIngrediente = nullptr;
		this->esteVegana = false;
		this->pret = 0.0f;
		numarPrajituri++;
	}

	// constructorul cu parametrii

	Prajitura(const char* denumire, int nrCalorii, float* gramajIngrediente, bool esteVegana, float pret) {
		if (this->denumire != nullptr) {
			this->denumire - new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else {
			this->denumire = nullptr;
		}

		this->nrCalorii = nrCalorii;
		if (this->gramajIngrediente != 0) {
			this->gramajIngrediente = new float[numarPrajituri];
			for (int i = 0; i < numarPrajituri; i++) {
				this->gramajIngrediente = gramajIngrediente;
			}
		}
		else {
			this->gramajIngrediente = 0;
		}
	}


	// constructorul de copiere

	Prajitura(const Prajitura& copie) {

		if (copie.denumire != nullptr) {
			this->denumire = new char[strlen(copie.denumire) + 1];
			strcpy(this->denumire, copie.denumire);
		}
		else {
			this->denumire = nullptr;
		}

		this->nrCalorii = copie.nrCalorii;

		if (copie.gramajIngrediente != 0) {
			this->gramajIngrediente = new float[numarPrajituri];
			for (int i = 0; i < numarPrajituri; i++) {
				this->gramajIngrediente = copie.gramajIngrediente;
			}

		}
		else {
			this->gramajIngrediente = 0;
		}

		this->esteVegana = copie.esteVegana;
		this->pret = copie.pret;

	}

	// operator egal

	void operator=(const Prajitura& copie) {

		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}

		if (this->gramajIngrediente = 0) {
			delete[] this->gramajIngrediente;
			this->gramajIngrediente = 0;
		}

		if (copie.denumire != nullptr) {
			this->denumire = new char[strlen(copie.denumire) + 1];
			strcpy(this->denumire, copie.denumire);
		}
		else {
			this->denumire = nullptr;
		}

		this->nrCalorii = copie.nrCalorii;

		if (copie.gramajIngrediente != 0) {
			this->gramajIngrediente = new float[numarPrajituri];
			for (int i = 0; i < numarPrajituri; i++) {
				this->gramajIngrediente = copie.gramajIngrediente;
			}

		}
		else {
			this->gramajIngrediente = 0;
		}

		this->esteVegana = copie.esteVegana;
		this->pret = copie.pret;



	}

	// destructor

	~Prajitura() {
		delete[] denumire;
		delete[] gramajIngrediente;
	}

	// sa se implementeze metoda get gramaj total care sa returneze gramajul total din care este compusa prajitura

	float* getGramajTotal() {
		cout << "Gramajul total este: ";
		return this->gramajIngrediente;
	}


};


	

void main() {

	
}