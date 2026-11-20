#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

class CosCumparaturi {
private:
	char* numeClient;
	int numarProduse;
	float* preturiProduse;
	const int codCos;

	// constructor default
public:
	CosCumparaturi() : codCos() {
		this->numeClient = nullptr;
		this->numarProduse = 0;
		this->preturiProduse = 0;

	}

	// constructorul cu 3 parametrii

	CosCumparaturi(const char* numeClient, int numarProduse, float* preturiProduse ) : codCos(codCos) {
		if (numeClient != nullptr) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy(this->numeClient, numeClient);
		}
		else {
			this->numeClient = nullptr;
		}

		if (preturiProduse != nullptr && numarProduse > 0) {
			this->numarProduse = numarProduse;
			this->preturiProduse = new float[(numarProduse)];
			for (int i = 0; i < numarProduse; i++) {
				this->preturiProduse[i] = preturiProduse[i];
			}
		}
		else {
			this->numarProduse = 0;
			this->preturiProduse = nullptr;
		}

		// constructorul de copiere

		

	}

	CosCumparaturi(const CosCumparaturi& copie) :codCos(copie.codCos) {

		if (copie.numeClient != nullptr) {
			this->numeClient = new char[strlen(copie.numeClient) + 1];
			strcpy(this->numeClient, copie.numeClient);
		}
		else {
			this->numeClient = nullptr;
		}

		if (copie.preturiProduse != nullptr && copie.numarProduse > 0) {
			this->numarProduse = copie.numarProduse;
			this->preturiProduse = new float[this->numarProduse];
			for (int i = 0; i < copie.numarProduse; i++) {
				this->preturiProduse[i] = copie.preturiProduse[i];
			}
		}
		else {
			this->preturiProduse = nullptr;
			this->numarProduse = 0;
		}
	}

	//operator =

	void operator=(const CosCumparaturi& copie) {
		if (this->numeClient != nullptr) {
			delete[] numeClient;
		}

		if (this->preturiProduse != nullptr) {
			delete[] preturiProduse;
		}

		if (copie.numeClient != nullptr) {
			this->numeClient = new char[strlen(copie.numeClient) + 1];
			strcpy(this->numeClient, copie.numeClient);
		}
		else {
			this->numeClient = nullptr;
		}

		if (copie.preturiProduse != nullptr && copie.numarProduse > 0) {
			this->numarProduse = copie.numarProduse;
			this->preturiProduse = new float[this->numarProduse];
			for (int i = 0; i < copie.numarProduse; i++) {
				this->preturiProduse[i] = copie.preturiProduse[i];
			}
		}
		else {
			this->preturiProduse = nullptr;
			this->numarProduse = 0;
		}
	}


	~CosCumparaturi() {
		delete[] numeClient;
		delete[] preturiProduse;
	}

	friend ostream& operator<<(ostream& out, const CosCumparaturi& cos);

	//setter pentru preturi produse

	void setPretProdus(int nrNou, const float* preturiNoi) {
		if (preturiNoi != nullptr && nrNou > 0) {
			this->numarProduse = nrNou;
			this->preturiProduse = new float[this->numarProduse];
			for (int i = 0; i <this-> numarProduse; i++) {
				this->preturiProduse[i] = preturiNoi[i];
			}
		}
		else {
			this->numarProduse = 0;
			this->preturiProduse = nullptr;
		}
	}

	// operator[]
	float operator[](int index) {
		if (index >= 0 && index < this->numarProduse && this->preturiProduse != nullptr) {
			return this->preturiProduse[index];
		}
		return -1;
	}

	// operator *= 
	void operator *=(float valoareTVA) {
		if (valoareTVA > 0) {
			for (int i = 0; i < this->numarProduse; i++) {
				this->preturiProduse[i] *= valoareTVA;
			}
		}
		else {
			throw exception();
		}

	}
};

ostream& operator<<(ostream& out, const CosCumparaturi& cos) {
	out << "Cod cos:" << cos.codCos << endl;
	if (cos.numeClient != nullptr) {
		out << "Nume client: " << cos.numeClient << endl;
	}
	else {
		out << "Numele clientului nu este existent!" << endl;
	}

	if (cos.preturiProduse != nullptr && cos.numarProduse>0) {
		out << "Numar produse: " << cos.numarProduse << endl;
		out << "Preturi produse: ";
		for (int i = 0; i < cos.numarProduse; i++) {
			out << cos.preturiProduse[i] << " lei ";
		}
		out << endl;
	}
	else {
		out << "Cosul nu contine produse! " << endl;
	}

	return out;

}

int main() {

	cout << "Constructor default" << endl;
	CosCumparaturi cos1;
	cout << cos1 << endl;

	int numarProduse = 3;
	float preturiProduse[] = { 254.0f, 128.0f, 65.5f };
	cout << "Constructorul cu parametrii"<<endl;
	CosCumparaturi cos2("Popescu Maria", numarProduse, preturiProduse);
	cout << cos2 << endl;

	cout << "Constructorul de copiere: " << endl;
	CosCumparaturi cos3(cos2);
	cout << cos3 << endl;


	cout << "Operator =" << endl;
	cos1 = cos3;
	cout << cos1 << endl;

	float preturiNoi[] = { 21.0f, 64.41f };
	cos3.setPretProdus(2, preturiNoi);
	cout << cos3 << endl;


	cout << "Operator[]" << endl;
	cout << "Pretul produsului de la pozitia 0: " << cos3[0] << endl;

	cout << "Operator *=: " << endl;
	cos3 *= 1.11;
	cout << cos3;




}