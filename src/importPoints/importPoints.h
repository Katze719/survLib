#pragma once
#include "../functionals/functionals.h"
#include <fstream>


namespace surv {

	class importPoints
	{
		std::ifstream ifs;
		std::string line;

	public:
		// TODO:
		// PS: Koennte man auch als Funktion schreiben :D
		// der �bergebene std::vector<Points> wird mit punkten gef�llt, es gibt keinen return wert
		importPoints(const std::string& File, std::vector<Point>& Points) :ifs(File) {
			while (!getline(ifs, line).eof()) {

			}
		}
	};

}
