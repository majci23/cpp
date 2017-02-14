#include "Stanica.h"

Stanica::Stanica(int id, string nazov)
{
	this->id = id;
	this->nazov = nazov;
}

Stanica::~Stanica()
{
}

void Stanica::pridajKolaj(int cislo)
{
	kolaje.push_back(cislo);
}

vector<int> & Stanica::getKolaje()
{
	return kolaje;
}

void Stanica::zoradKolaje()
{
	/*
		parne a neparne
	*/
	for (int i = 0; i < kolaje.size(); i++) {
		for (int j = i; j < kolaje.size(); j++) {
			if (kolaje[j] % 2 == 1) {
				int tmp = kolaje[i];
				kolaje[i] = kolaje[j];
				kolaje[j] = tmp;
			}
		}
	}

	/*
		neparne od najvacieho
	*/
	for (int i = 0; i < kolaje.size(); i++) {
		for (int j = i; j < kolaje.size(); j++) {
			if (kolaje[j] % 2 == 1 && kolaje[i] % 2 == 1 && kolaje[j] > kolaje[i]) {
				int tmp = kolaje[i];
				kolaje[i] = kolaje[j];
				kolaje[j] = tmp;
			}
		}
	}

	/*
	parne od najmensieho
	*/
	for (int i = 0; i < kolaje.size(); i++) {
		for (int j = i; j < kolaje.size(); j++) {
			if (kolaje[j] % 2 == 0 && kolaje[i] % 2 == 0 && kolaje[j] < kolaje[i]) {
				int tmp = kolaje[i];
				kolaje[i] = kolaje[j];
				kolaje[j] = tmp;
			}
		}
	}
}
