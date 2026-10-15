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
		

	}

	// constructorul de copiere

	Magazin(const Magazin& copie) :idMagazin(++nrMagazine) {
		this->denumire = copie.denumire;
		this->nrAngajati = copie.nrAngajati;

		if (copie.salariiAngajati != 0) {
			this->salariiAngajati = new float[this->nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salariiAngajati[i] = copie.salariiAngajati[i];
			}
		}
		else {
			this->salariiAngajati = nullptr;
		}
	}

	// getteri si setteri 

	// getter pentru numele magazinului

	string getNumeMagazin() {
		return this->denumire;
	}

	const int getIdMagazin() {
		return this->idMagazin;
	}

	float* getSalariiAngajati() {
		return this->salariiAngajati;
	}

	int getNumarAngajati() {
		return this->nrAngajati;
	}

	// setteri

	//setteri pentru numele magazinui

	void setNumeMagazin(string denumireNoua) {
		if (!denumireNoua.empty()) {
			this->denumire = denumireNoua;
		}
		else {
			cout << "Denumirea Magazinului nu a putut fi actualizata!" << endl;
		}
	}

	// operatorul =

	void operator=(const Magazin& copie) {
		this->denumire = copie.denumire;
		this->nrAngajati = copie.nrAngajati;

		if (this->salariiAngajati != nullptr) {
			delete[] this->salariiAngajati;
			this->salariiAngajati = nullptr;
		}

		if (copie.salariiAngajati != nullptr) {
			this->salariiAngajati = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salariiAngajati[i] = copie.salariiAngajati[i];
			}
		}
		else {
			this->salariiAngajati = nullptr;
		}
	}

	// destructorul

	~Magazin() {
		if (this->salariiAngajati != 0) {
			delete[] salariiAngajati;
		}
	}

	// functia de afisare a magazinului

	void afisareMagazin() {
		cout << endl << "ID: " << this->idMagazin;
		cout << endl << "Nume magazin : " << this->denumire;
		cout << endl << "Nr angajati: " << this->nrAngajati;

		if (this->nrAngajati>0) {
			cout << "\nSalarii: ";
			for (int i = 0; i < this->nrAngajati - 1; i++) {
				cout << this->salariiAngajati[i] << "lei, ";
			}
			cout << this->salariiAngajati[this->nrAngajati - 1] << " lei." << endl;
			
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

	cout << "\n Apelarea constructorului de copiere in main : " << endl <<endl;

	Magazin m3(*m2);
	m3.afisareMagazin();

	delete[] salariiAngajati;
	delete m2;

	cout << "\n Afisarea operatorului = in main: " << endl <<endl;

	m3 = m1;
	m3.afisareMagazin();

	// testare getteri in main: 

	 int nrAngajatiMagazin=10;
	float* salariiAngajatiMagazin= new float [10] { 2655, 5000, 1899, 2750.14, 3450, 7214.23, 2985.12, 1345.58, 3215.65, 3647.25};
	Magazin m4(10, "Mega Image", nrAngajatiMagazin, salariiAngajatiMagazin);


	cout<< "\n" << endl;
	cout << "============================================================Getteri==============================================" << endl << endl;
	cout << "Id magazin: " << m4.getIdMagazin() << endl;;
	cout << "Denumire magazin: " << m4.getNumeMagazin() << endl;
	cout << "Numar Angajati: " << m4.getNumarAngajati() << endl;
	cout << "Salarii angajati: ";
	salariiAngajatiMagazin = m4.getSalariiAngajati();

	if (salariiAngajatiMagazin != nullptr && m4.getNumarAngajati() > 0) {
		for (int i = 0; i < m4.getNumarAngajati(); i++) {
			cout << salariiAngajatiMagazin[i] << "lei";
			if (i < m4.getNumarAngajati() - 1) {
				cout << ", ";
			}
		}
	}
	else {
		cout << "Nu exista salarii inregistrate!!!!";
	}

	cout << "\n \n======================================================Setteri=====================================================" << endl << endl;

	m4.setNumeMagazin("Froo");
	cout << "Nume magazin nou: " << m4.getNumeMagazin() << endl;
	m4.afisareMagazin();
}