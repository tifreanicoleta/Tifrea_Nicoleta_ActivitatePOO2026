#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


class Cofetarie {
private: // atributele clasei se vor pune la private
	int const id; //const se aplica pt variabilele nemodificabile
	string denumire;
	int nrProduse;
	float* preturi;
	/*static int nrCofetarii;*/ // nu apartine obiectului, dar apartine clasei, putem sa il folosim pe post de contor, atribute utilitare
public: // metodele vor fi publice

	static int nrCofetarii;
	//constructor default - se face cu valori default, cat mai generale

	Cofetarie() : id(++nrCofetarii) {
		//this->id = 0; ASA NU!!!!

		this->denumire = "Cofetarie generala";
		this->nrProduse = 0;
		this->preturi = nullptr;
	}

	// constructor cu toti parametrii

	Cofetarie(int id, string denumire, int nrProduse, float* preturi) : id(id) {
		this->denumire = denumire;
		this->nrProduse = nrProduse;

		this->preturi = new float[nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;
	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;

		if (this->nrProduse > 0) {
			cout << "cu urmatoarele preturi: ";
			for (int i = 0; i < this->nrProduse - 1; i++) {
				cout << this->preturi[i] << "lei, ";
			}
			cout << this->preturi[this->nrProduse - 1] << " lei.";
		}
	}

};

int Cofetarie::nrCofetarii = 0;

void main() {
	Cofetarie cofetarieGenerala;
	cofetarieGenerala.afisare();

	int nrProduse = 3;
	float* preturi = new float[nrProduse]{18.5f, 24.0f, 15.5f};
	Cofetarie* cofetarieRomana = new Cofetarie(7, "CofetarieRomana", 3, preturi);
	cofetarieRomana->afisare();
	delete cofetarieRomana;

	cout << endl << "Numar cofetarii: " << Cofetarie::nrCofetarii;


}