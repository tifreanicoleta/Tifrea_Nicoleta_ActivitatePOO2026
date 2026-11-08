//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Calatorie {
//private:
//	int const idCalatorie;
//	char* numeDestinatie;
//	float pretCalatorie;
//	int durataZile;
//	static int numarCalatorii;
//
//public:
//
//	// constructor default
//
//	Calatorie() : idCalatorie(++numarCalatorii) {
//		//this->idCalatorie = 0;
//		this->numeDestinatie = nullptr;
//		this->pretCalatorie = 0.0f;
//		this->durataZile = 0;
//
//	}
//
//	// constructor cu parametrii 
//
//	Calatorie(int idCalatorie, const char* numeDestinatie, float pretCalatorie, int durataZile) : idCalatorie(idCalatorie) {
//		
//		if (numeDestinatie != nullptr) {
//			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
//			strcpy(this->numeDestinatie, numeDestinatie);
//		}
//		else {
//			this->numeDestinatie = nullptr;
//		}
//
//		this->pretCalatorie = pretCalatorie;
//		this->durataZile = durataZile;
//	}
//
//	// constructorul de copiere
//
//	Calatorie(const Calatorie& copie): idCalatorie(++numarCalatorii){
//		if (copie.numeDestinatie != nullptr) {
//			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
//			strcpy(this->numeDestinatie, copie.numeDestinatie);
//		}
//		else {
//			this->numeDestinatie = nullptr;
//		}
//		this->pretCalatorie = copie.pretCalatorie;
//		this->durataZile = copie.durataZile;
//
//	}
//	
//
//	// destructor
//
//	~Calatorie() {
//		delete[] numeDestinatie;
//	}
//
//
//	void operator=(const Calatorie& copie) {
//		if (this->numeDestinatie != nullptr) {
//			delete[] this->numeDestinatie;
//			this->numeDestinatie = nullptr;
//		}
//
//		if (copie.numeDestinatie != nullptr) {
//			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
//			strcpy(this->numeDestinatie, copie.numeDestinatie);
//		}
//		else {
//			this->numeDestinatie = nullptr;
//		}
//
//		this->pretCalatorie = copie.pretCalatorie;
//		this->durataZile = copie.durataZile;
//	}
//
//	//getteri si setteri
//	// 
//	//getteri pentru destinatie
//
//	char* getNumeDestinatie() {
//		return  numeDestinatie;
//	}
//
//	// getter pret calatorie
//
//	float getPretCalatorie() {
//		return pretCalatorie;
//	}
//
//	//getter durata zile
//
//	int getDuarataCalatorie() {
//		return durataZile;
//	}
//
//	// setter pentru numele destinatiei
//
//	void setNumeDestinatie( const char* destinatieNoua) {
//		if (destinatieNoua != nullptr) {
//			this->numeDestinatie = new char[strlen(destinatieNoua) + 1];
//			strcpy(this->numeDestinatie, destinatieNoua);
//		}
//		else {
//			this->numeDestinatie = nullptr;
//			cout << "Destinatia nu a putut fi gasita.";
//		}
//		
//	}
//	
//	// setteri pentru modificarea pretului
//
//	void setPretCalatorie(float pretCalatorieNou) {
//		if (pretCalatorieNou > 0) {
//			this->pretCalatorie = pretCalatorieNou;
//			cout << "Pretul calatoriei a fost modificat cu succes!!!!!" << endl;
//
//		}
//		else {
//			cout << "Pretul calatoriei nu poate fi negativ!!!!!! Modifica din nou" << endl;
//		}
//	}
//
//
//
//
//	// afisarea calatoriei
//
//	void afisare() {
//		cout << "id: " << this->idCalatorie << endl;
//		if (this->numeDestinatie != nullptr) {
//			cout << "Nume destinatie: " << getNumeDestinatie() << endl;
//		}
//		else {
//			cout << "Nu exista destinatie!!!"<< endl;
//		}
//		cout << "Pret calatorie: " << this->pretCalatorie << endl;
//		cout << "Durata zile: " << this->durataZile << endl << endl;
//		
//	}
//
//	
//
//};
//
//int Calatorie::numarCalatorii = 0;
//
//void main() {
//	Calatorie calatorieGenerala;
//	calatorieGenerala.afisare();
//
//
//	Calatorie calatorie(5, "Budapesta", 1500, 4);
//	calatorie.afisare();
//
//	Calatorie calatorie1(6, "Egipt", 2544.22, 6);
//
//
//	//testare getters in main
//
//	cout << "Getteri: " << endl;
//	cout << "Nume destinatie: " << calatorie1.getNumeDestinatie();
//	cout << "\n Pret Calatorie: " << calatorie1.getPretCalatorie();
//	cout << "\n Durata zile: " << calatorie1.getDuarataCalatorie() << endl;
//
//	//setteri
//	
//	calatorie1.setNumeDestinatie("Maldive");
//	calatorie1.afisare();
//
//	calatorie1.setPretCalatorie(8540);
//	calatorie1.afisare();
//
//}