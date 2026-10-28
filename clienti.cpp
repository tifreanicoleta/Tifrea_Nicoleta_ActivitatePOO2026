#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Client {
private:
	int const idClient;
	string nume;
	float bugetClient;
	char* observatiiClient;
	static int numarClienti;

public:

	// constructor default

	Client() : idClient(++numarClienti) {
		this->nume = "Fara nume!";
		this->bugetClient = 0;
		this->observatiiClient = nullptr;

	}

	// constructor cu parametrii

	Client(int idClient, string nume, float bugetClient, const char* observatiiClient) : idClient(idClient) {
		this->nume = nume;
		this->bugetClient = bugetClient;

		if (idClient > numarClienti) {
			numarClienti = idClient;
		}

		if (observatiiClient != nullptr) {
			this->observatiiClient = new char[strlen(observatiiClient) + 1];
			strcpy_s(this->observatiiClient, strlen(observatiiClient) + 1, observatiiClient);
		}
		else {
			this->observatiiClient = nullptr;
		}
	}

	// constructor de copiere 
	
	Client(const Client& copie) : idClient(++numarClienti) {
		//this->idClient = copie.idClient;
		this->nume = copie.nume;
		this->bugetClient = copie.bugetClient;
		if (copie.observatiiClient != nullptr) {
			this->observatiiClient = new char[strlen(copie.observatiiClient) + 1];
			strcpy(this->observatiiClient, copie.observatiiClient);
		}
		else {
			this->observatiiClient = nullptr;
			cout << " Nu exista observatii!!";
		}
	}

	// operator egal
	void operator=(const Client& copie) {

		if (observatiiClient != nullptr) {
			delete[] this->observatiiClient;
			this->observatiiClient = nullptr;
		}

		if (copie.observatiiClient != nullptr) {
			this->observatiiClient = new char[strlen(copie.observatiiClient) + 1];
			strcpy(this->observatiiClient, copie.observatiiClient);
		}
		else {
			this->observatiiClient = nullptr;
		}


		this->nume = copie.nume;
		this->bugetClient = copie.bugetClient;
		this->numarClienti = copie.numarClienti;
	}
	// destructor

	~Client() {

			delete[] observatiiClient;
		
	}

	//getteri 

	string getNume() {
		return this->nume;
	}

	float getBugetClient() {
		return this->bugetClient;
	}

	const char* getObservatiiClient() {
		return this->observatiiClient;
	}

	static int getNumarClienti() {
		return numarClienti;
	}


	// setteri
	
	void setNumeClient(string numeNou) {
		if (!this->nume.empty()) {
			this->nume = numeNou;
		}
		else {
			this->nume = nullptr;
			cout << "Numele nu a putut fi modificat!!!";
		}
	}

	void setBugetClient(float bugetNou) {
		if (this->bugetClient > 0) {
			this->bugetClient = bugetNou;
		}
		else {
			this->bugetClient = 0;
			cout << "Bugatul nu poate fi negativ sau 0" << endl;
		}
	}

	void setObservatiiClient(const char* observatiiModificate) {
		if (observatiiModificate != nullptr) {
			if (this->observatiiClient != nullptr) {
				delete[] this->observatiiClient;
			}
			this->observatiiClient = new char[strlen(observatiiModificate) + 1];
			strcpy(this->observatiiClient, observatiiModificate);
			cout << "\n Observatiile au fost modificate cu succes!!";
		}
		else {
			if (this->observatiiClient != nullptr) {
				delete[] this->observatiiClient;
				this->observatiiClient = nullptr;
			}
			cout << "Eroare la updatarea informatiilor legate de client!! Va rugam sa incercati din nou!!";
		}
	}
	// afisare client

	void afisareClient() {
		cout << "Client " << endl;
		cout << "ID: " << this->idClient << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Buget: " << this->bugetClient << endl;
		if (this->observatiiClient != nullptr) {
			cout << "Observatii client: " << this->observatiiClient << endl;
		}

		cout << "=================================================================" << endl;

	}

};

int Client::numarClienti = 0;

void main() {

	cout << "Test";

	Client c1;
	c1.afisareClient();

	
	Client* c2 = new Client(2, "Popescu Maria", 250.0f, "Nu exista observatii");
	c2->afisareClient();

	cout << "Constructorul de copiere: \n \n" << endl;
	Client c3(*c2);
	c2->afisareClient();
	
	
	Client c4 (3, "Avram Avramescu", 520.4f, "Doreste factura fiscala!!!!");
	c4.afisareClient();


	Client c5(4, "Popescu Adriana", 758.25f, "A se emite bon fiscal!");
	c5.afisareClient();

	cout << "Operatorul =:" << endl << endl;
	c5 = c4;
	c5.afisareClient();

	cout << "Getteri \n\n";
	cout<<"Nume client: "<< c5.getNume()<<endl;
	cout << "Buget client: " << c5.getBugetClient() <<endl;
	cout << "Observatii client: " << c5.getObservatiiClient()<<endl;
	cout << "Numar Clienti: " << c5.getNumarClienti() << endl <<endl;


	cout << "Setteri:\n\n";
	c5.setNumeClient("Stan Ion");
	cout << "Nume nou client: " << c5.getNume() <<endl;
	
	c5.setBugetClient(5875.25f);
	cout << "Buget nou client: " << c5.getBugetClient() << endl;

	c5.setObservatiiClient("Nu doreste factura fiscala!");
	cout << "\nObservatii client actualizate: " << c5.getObservatiiClient() <<endl;


	

}