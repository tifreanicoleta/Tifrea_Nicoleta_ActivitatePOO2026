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
	
	//constructor cu parametrii
	Magazin(int idMagazin, string denumire, int nrAngajati, float* salariiAngajati) : idMagazin(idMagazin) {
		this->denumire = denumire;
		this->nrAngajati = nrAngajati;
		this->salariiAngajati = new float[nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			this->salariiAngajati[i] = salariiAngajati[i];
		}
		delete[] salariiAngajati;

	}



	// functia de afisare a magazinului

	void afisareMagazin() {
		cout << endl << "ID: " << this->idMagazin;
		cout << endl << "Nume magazin : " << this->denumire;
		cout << endl << " Nr angajati: " << this->nrAngajati;

		if (this->nrAngajati>0) {
			cout << "\n Salarii: ";
			for (int i = 0; i < this->nrAngajati - 1; i++) {
				cout << this->salariiAngajati[i] << "lei, ";
			}
			cout << this->salariiAngajati[this->nrAngajati - 1] << " lei.";
			
		}
		
	}


};

int Magazin::nrMagazine = 0;

void main() {
	Magazin m1;
	m1.afisareMagazin();

	// testarea in main a constructorului cu parametrii 

	int nrAngajati = 2;
	float* salariiAngajati = new float[2] {2555.5, 30000.0};
	Magazin* m2 = new Magazin(2, "Altex Shop", nrAngajati, salariiAngajati);
	m2->afisareMagazin();
}