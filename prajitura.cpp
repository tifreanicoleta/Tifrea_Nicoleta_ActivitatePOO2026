#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<stdio.h>
#include <string.h>

using namespace std;

class Prajitura {
private: 
	char* denumire;
	int nrCalorii;
	int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	float pret;
	static float numarPrajituri;

public:

	// constructor fara parametrii

	Prajitura() {
		this->denumire = nullptr;
		this->nrCalorii = 0;
		this->nrIngrediente = 0;
		this->gramajIngrediente = nullptr;
		this->esteVegana = false;
		this->pret = 0.0f;
		this->nrIngrediente = 0;
		numarPrajituri++;
	}

	// constructorul cu parametrii

	Prajitura(const char* denumire, int nrCalorii, int nrIngrediente, float* gramajIngrediente, bool esteVegana, float pret) {
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else {
			this->denumire = nullptr;
		}

		this->nrCalorii = nrCalorii;
		if (gramajIngrediente != nullptr && nrIngrediente >0) {
			this->nrIngrediente = nrIngrediente;
			this->gramajIngrediente = new float[nrIngrediente];
			for (int i = 0; i < nrIngrediente; i++) {
				this->gramajIngrediente[i] = gramajIngrediente[i];
			}
		}
		else {
			this->nrIngrediente = 0;
			this->gramajIngrediente = 0;
		}
		this->esteVegana = esteVegana;
		this->pret = pret;
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

		if (copie.gramajIngrediente != nullptr && copie.nrIngrediente>0) {
			this->nrIngrediente = nrIngrediente;
			this->gramajIngrediente = new float[copie.nrIngrediente];
			for (int i = 0; i < copie.nrIngrediente; i++) {
				this->gramajIngrediente[i] = copie.gramajIngrediente[i];
			}

		}
		else {
			this->gramajIngrediente = nullptr;
			this->gramajIngrediente = nullptr;
		}

		this->esteVegana = copie.esteVegana;
		this->pret = copie.pret;
		numarPrajituri++;

	}

	// operator egal

	void operator=(const Prajitura& copie) {

		if (this != &copie) { // Evităm auto-atribuirea (p1 = p1)
			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			if (this->gramajIngrediente != nullptr) { // "!=" nu "=" !
				delete[] this->gramajIngrediente;
				this->gramajIngrediente = nullptr;
			}

			if (copie.denumire != nullptr) {
				this->denumire = new char[strlen(copie.denumire) + 1];
				strcpy(this->denumire, copie.denumire);
			}

			this->nrCalorii = copie.nrCalorii;

			if (copie.gramajIngrediente != nullptr && copie.nrIngrediente > 0) {
				this->nrIngrediente = copie.nrIngrediente;
				this->gramajIngrediente = new float[copie.nrIngrediente];
				for (int i = 0; i < copie.nrIngrediente; i++) {
					this->gramajIngrediente[i] = copie.gramajIngrediente[i];
				}
			}
			else {
				this->nrIngrediente = 0;
				this->gramajIngrediente = nullptr;
			}

			this->esteVegana = copie.esteVegana;
			this->pret = copie.pret;
		}


	}

	// destructor

	~Prajitura() {
		delete[] denumire;
		delete[] gramajIngrediente;
	}

	// sa se implementeze metoda get gramaj total care sa returneze gramajul total din care este compusa prajitura

	float* getGramajTotal() {
		return this->gramajIngrediente;
	}

	// operator << 
	
	friend ostream& operator<<(ostream& out, const Prajitura& p);
	
	//operator >>
	friend istream& operator>>(istream& in, Prajitura& p);

};

ostream& operator<<(ostream& out, const Prajitura& p) {
	out << "Denumire: " << (p.denumire != nullptr ? p.denumire : "") << endl;
		
	out << "Nr calorii: " << p.nrCalorii << endl;
	if (p.gramajIngrediente != nullptr && p.nrIngrediente > 0) {
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << p.gramajIngrediente[i] << "g ";
		}
	}
	else {
		out << "Fara ingrediente" << endl;;
	}
	out << "Vegana: ";
	if (p.esteVegana == true) {
		out << "DA" << endl;
	}
	else {
		out << "NU" << endl;
	}
	out << "Pret: " << p.pret << endl;
	return out;
}


istream& operator>>(istream& in, Prajitura& p) {
	char buffer[100];
	cout << "Denumire: ";
	in >> buffer;
	delete[] p.denumire;
	p.denumire = new char[strlen(buffer) + 1];
	strcpy(p.denumire, buffer);

	cout << "Nr calorii: ";
	in >> p.nrCalorii;

	cout << "Nr ingrediente: ";
	in >> p.nrIngrediente;
	delete[] p.gramajIngrediente;
	p.gramajIngrediente = new float[p.nrIngrediente];
	for (int i = 0; i < p.nrIngrediente; i++) {
		cout << "Gramaj " << i + 1 << ": ";
		in >> p.gramajIngrediente[i];
	}

	cout << "Este vegana. Introduceti 0 daca nu este vegana, si 1 daca este: ";
	in >> p.esteVegana;

	cout << "Pret: ";
	in >> p.pret;

	return in;




}
float Prajitura::numarPrajituri = 0;
	

void main() {
	// constructir default
	Prajitura prajituraClasica;
	cout << prajituraClasica << endl;

	// costructor cu parametrii

	float gramajIngrediente[] = {150.5f, 200.f, 50.f};
	Prajitura prajituraTiramisu("Tiramisu", 254, 3, gramajIngrediente, true, 25.0f);
	cout << prajituraTiramisu << endl;


	// operator = 
	Prajitura p2;
	p2 = prajituraTiramisu;
	cout << p2;

	// operator >>

	Prajitura prajituraAlbinuta;
	cin >> prajituraAlbinuta;
	cout << prajituraAlbinuta<<endl;

	
}