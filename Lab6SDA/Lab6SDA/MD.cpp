#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;


MD::MD() {
	Tabela.resize(max_cap);
}


void MD::adauga(TCheie c, TValoare v) {
	int key = hash(c); //indicele vectorului de cheie c
	TElem element;
	vector <TElem>& Bucket = Tabela[key]; // acel vector este BUCKET
	element.first = c; 
	element.second = v; //setez elementul meu cu valorile potrivite
	Bucket.push_back(element); // il aduag
	size++; //cresc size-ul
}


bool MD::sterge(TCheie c, TValoare v) {
	int key = hash(c);
	vector <TElem>& Bucket = Tabela[key];
	for(int i=0;i<Bucket.size();i++) //parcurg vectorul in care am elementele cu cheia c
		if (Bucket[i].first == c && Bucket[i].second == v) //verific daca elementul se gaseste si il sterg
		{
			Bucket.erase(Bucket.begin() + i);
			size--;
			return true;
		}
	return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
	int key = hash(c);
	const vector <TElem>& Bucket = Tabela[key]; 
	vector <TValoare> valori;
	for (int i = 0; i < Bucket.size(); i++)
		if (Bucket[i].first == c) //daca elementul din vector are cheia c
//(in hash folosesc abs deci cheile -12/12 se pun pe acelasi vector sau daca cheia depaseste dupa abs capacitatea maxima cu 12)
			valori.push_back(Bucket[i].second); //adaug valoarea in vectorul valori
	return valori;
}


int MD::dim() const {
	return size;
	return 0;
}


bool MD::vid() const {
	return size == 0;
	return true;
}

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}


MD::~MD() {
	/* de adaugat */
}

int MD::hash(int cheie) const
{
	return abs(cheie)%max_cap; //hash primeste cheia si returneaza indicele vectorului pe care se va adauga cheia
}

int MD::diferentaCheieMaxMin() const {
	if (vid())
		return -1;
	else
	{
		int min = 1000000000;
		int max = -1;
		for (int i = 0; i < max_cap; i++)
		{
			for (int j = 0; j < Tabela[i].size(); j++)
			{
				if (Tabela[i][j].first < min)
					min = Tabela[i][j].first;
				if (Tabela[i][j].first > max)
					max = Tabela[i][j].first;

			}
		}
		return max - min;
	}
}
