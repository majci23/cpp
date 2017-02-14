#pragma once

#include <string>
#include <vector>

using namespace std;

class Stanica
{
private:
	int id;
	string nazov;
	vector<int> kolaje;
public:
	Stanica(int id, string nazov);
	~Stanica();

	inline int getId() { return id; }
	inline string getNazov() { return nazov; }

	void pridajKolaj(int cislo);
	vector<int> & getKolaje();
	void zoradKolaje();
};

