#pragma once
#include "../../functionals/functionals.h"
#include <fstream>


namespace surv {

	class importPoints
	{
		std::ifstream ifs;
		std::string file;
		std::string line;

		inline void kor(Points& Ps) {
			if (file.find(".kor") == std::string::npos && file.find(".KOR") == std::string::npos)
				throw std::invalid_argument("wrong file ending!");
			std::vector<std::string> words;
			while (!getline(ifs, line).eof()) {
				std::string word;
				for (std::istringstream iss(line); iss >> word;)
					words.push_back(word);
			}
			for (size_t i = 0; i < words.size(); i += 5)
				Ps.emplace_back(words.at(i + 2), words.at(i + 3), words.at(i + 4));
		}

	public:
		// der übergebene std::vector<Points> wird mit punkten gefüllt, es gibt keinen return wert
		// hollt werte aus einer normalen .KOR datei die vom Tachymeter exportiert wird
		// aufbau: Punktnummer {abstand} Punktcode {abstand} x {abstand} y {abstand} z 
		inline importPoints(const std::string& File, Points& Ps, const Type& t) :ifs(File), file(File) {
			switch (t) {
			case Type::KOR:
				kor(Ps);
				break;
			default:
				break;
			}
		}
	};
}
