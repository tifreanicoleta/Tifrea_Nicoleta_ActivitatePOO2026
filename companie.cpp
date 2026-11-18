#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include <iostream>

using namespace std;

class Companie {
private:
	char* numeCompanie;
	const int idCompanie;
	float cifraAfaceri;
public:

	// constructor default

	Companie() : idCompanie() {
		this->numeCompanie = nullptr;
		this->cifraAfaceri = 0;
	}

	// constructor cu un parametru

	Companie(const char* numeCompanie) : idCompanie() {
		if (numeCompanie != nullptr) {
			this->numeCompanie = new char[strlen(numeCompanie) + 1];
			strcpy(this->numeCompanie, numeCompanie);
		}
		else {
			this->numeCompanie = nullptr;
		}

		this->cifraAfaceri = cifraAfaceri;

	}

	// constructor de copiere

	Companie(const Companie& copie) : idCompanie() {
		if (copie.numeCompanie != nullptr) {
			this->numeCompanie = new char[strlen(copie.numeCompanie) + 1];
			strcpy(this->numeCompanie, copie.numeCompanie);
		}
		else {
			this->numeCompanie = nullptr;
		}

		this->cifraAfaceri = cifraAfaceri;
	}
	
	// operator egal

	void operator=(Companie const& copie) {
		if (this->numeCompanie != nullptr) {
			delete[] this->numeCompanie;
		}

		if (copie.numeCompanie != nullptr) {
			this->numeCompanie = new char[strlen(numeCompanie) + 1];
			strcpy(this->numeCompanie, copie.numeCompanie);
		}
		else {
			this->numeCompanie = nullptr;
		}

		this->cifraAfaceri = copie.cifraAfaceri;
	}

	// getteri pt atributul constant

	int getidCompanie() const{
		return this->idCompanie;
	}

	// setter pentru atributul alocat dinamic 

	void setNumeCompanie(const char* numeCompanieNou) {
		if (this->numeCompanie != nullptr) {
			delete[] this->numeCompanie;
		}
		if (numeCompanieNou != nullptr) {
			this->numeCompanie = new char[strlen(numeCompanieNou) + 1];
			strcpy(this->numeCompanie, numeCompanieNou);
		} else {
			this->numeCompanie = nullptr;
		}
	}



	// functie de afisare

	void afisare() {
		cout << "Companie: " << endl;
		if (this->numeCompanie != nullptr) {
			cout << "Denumire: " << this->numeCompanie <<endl;
		}
		else {
			cout << "Denumire: Nespecificat" <<endl;
		}
		cout << "Cifra de afaceri: " << this->cifraAfaceri<<endl<<endl;

	}

	~Companie() {
		delete[] numeCompanie;
	}

	friend ostream& operator<<(ostream& out, const Companie& c);
};

ostream& operator<<(ostream& out, const Companie& c) {
	out << "Companie:" << endl;
	
	if (c.numeCompanie != nullptr) {
		out << "Denumire:" << c.numeCompanie <<endl;
	}
	else {
		out << "Nume de companie invalid";
	}

	out << "Cifra de afaceri: " << c.cifraAfaceri << endl << endl;

	return out;
}



void main() {

	Companie companieGenerala;
	companieGenerala.afisare();

	cout << "Constructorul cu parametrii" << endl;
	Companie companieTesla("Tesla");
	companieTesla.afisare();

	cout << "Constructorul de copiere" << endl;

	Companie c2(companieTesla);
	c2.afisare();
	cout << "Operatorul =" << endl<<endl;

	c2 = companieGenerala;
	c2.afisare();

	companieGenerala.getidCompanie();
	companieGenerala.afisare();

	companieGenerala.setNumeCompanie("General");
	companieGenerala.afisare();

	Companie companieDeck("Deck");
	cout << companieDeck << endl;

	Companie companieBitwire("Bitwire SRL");
	cout << companieBitwire<<endl<<endl;
	



}