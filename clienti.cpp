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
	// destructor

	~Client() {

			delete[] observatiiClient;
		
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



}