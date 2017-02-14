#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Stanica.h"

using namespace std;

int main()
{
	vector<Stanica *> stanice;

	/*
		Stanice
	*/
	ifstream suborStanice("stanice.txt");

	while (!suborStanice.eof()) {
		int id;
		string nazov;
		
		suborStanice >> id;
		suborStanice >> nazov;

		stanice.push_back(new Stanica(id, nazov));
	}

	suborStanice.close();

	/*
		Kolaje
	*/
	ifstream suborKolaje("kolaje.txt");

	while (!suborKolaje.eof()) {
		int idStanice;
		int id;

		suborKolaje >> idStanice;
		suborKolaje >> id;

		for (int i = 0; i < stanice.size(); i++) {
			if (stanice[i]->getId() == idStanice) {
				stanice[i]->pridajKolaj(id);
				break;
			}
		}
	}

	suborKolaje.close();

	/*
		Zorad kolaje
	*/
	for (int i = 0; i < stanice.size(); i++) {
		stanice[i]->zoradKolaje();
	}

	/*
		Vypis kolaje
	*/
	for (int i = 0; i < stanice.size(); i++) {
		cout << stanice[i]->getNazov() << endl;
		cout << "---------------------------" << endl;

		for (int j = 0; j < stanice[i]->getKolaje().size(); j++) {
			cout << "\t" << stanice[i]->getKolaje()[j] << endl;
		}
	}
}