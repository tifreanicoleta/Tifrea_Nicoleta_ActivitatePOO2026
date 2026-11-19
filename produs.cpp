#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

using namespace std;

class Produs {
private:
	char* denumireProdus;
	const int codProdus;

public:
	// constructorul default

	Produs() : codProdus() {
		this->denumireProdus = nullptr;

	}

	// constructor cu un parametru

	Produs(const char* denumireProdus):codProdus(1) {
		if (denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(denumireProdus) + 1];
			strcpy(this->denumireProdus, denumireProdus);
		}
		else {
			this->denumireProdus = nullptr;
		}
	}

	// constructor de copiere

	Produs(const Produs& copie) : codProdus(1) {
		if (copie.denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(copie.denumireProdus) + 1];
			strcpy(this->denumireProdus, copie.denumireProdus);
		}
		else {
			this->denumireProdus = nullptr;
		}
	}

	//operator =

	void operator=(const Produs& copie) {
		if (this->denumireProdus != nullptr) {
			delete[] this->denumireProdus;
		}
		

		if (copie.denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(copie.denumireProdus) + 1];
			strcpy(this->denumireProdus, copie.denumireProdus);
		}
		else {
			this->denumireProdus = nullptr;
		}
	}

	void afisareProdus() {
		if (this->denumireProdus != nullptr) {
			cout << "Denumire Produs: " << this->denumireProdus<<endl <<endl;
		}
		else {
			cout << "Denumire produs: Nespecificat" << endl;
		}
	}

	~Produs() {
		delete[] denumireProdus;
	}

	//getter

	int getCodProdus() const {
		return this->codProdus;
	}

	// setteri pentru atributul alocat dinamic

	void setnumeProdus(const char* numeNou) {
		if (numeNou != nullptr) {
			if (denumireProdus != nullptr) {
				delete[] denumireProdus;
			}
			denumireProdus = new char[strlen(numeNou) + 1];
			strcpy(denumireProdus, numeNou);
		}
		else {
			cout << "Numele nu a putut fi modificat! Va rugam sa incercati din nou";
		}
	}

	void operator()(const char* numeNou) {
		return this->setnumeProdus(numeNou);
	}
};

void main() {

	cout << "Constructor default" << endl << endl;

	Produs produs1;
	produs1.afisareProdus();

	cout << "Constructor cu un parametru" << endl << endl;
	Produs produsPanificatie("Paine");
	produsPanificatie.afisareProdus();

	cout << "Constructor de copiere" << endl;
	
	Produs produs3(produsPanificatie);
	produs3.afisareProdus();

	cout << "Operator =" << endl;
	produs1 = produsPanificatie;
	produs1.afisareProdus();

	cout << "Getter pentru atributul constant" << endl;

	cout  <<"Cod produs: "<<produsPanificatie.getCodProdus() << endl;

	produsPanificatie.setnumeProdus("Paine cu semminte");
	 produsPanificatie.afisareProdus();

	 cout << "Operator(): " << endl << endl;
	 produsPanificatie("Cozonac");
	 produsPanificatie.afisareProdus();

	


}