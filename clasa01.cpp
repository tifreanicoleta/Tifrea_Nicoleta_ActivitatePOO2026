#include <iostream>

using namespace std;

class Magazin {
private:
	int const idMagazin;
	string denumire;
	int nrAngajati;
	float* salariiAngajati;
	static int nrMagazine;
public:
	// constructor default - fara parametrii

	Magazin() : idMagazin(++nrMagazine) {
		
		this->denumire = "Magazin";
		this-> nrAngajati = 0;
		this->salariiAngajati = nullptr;
	}
	
	// functia de afisare a magazinului

	void afisareMagazin() {
		cout << endl << "ID: " << this->idMagazin;
		cout << endl << "Nume magazin : " << this->denumire;

		if (this->nrMagazine > 0) {
			cout << "\nNr. angajati: ";
			for (int i = 0; i < this->nrAngajati - 1; i++) {
				cout << this->salariiAngajati[i] << "lei, ";
			}
			
		}

	}


};

int Magazin::nrMagazine = 0;

void main() {
	Magazin m1;
	m1.afisareMagazin();
}