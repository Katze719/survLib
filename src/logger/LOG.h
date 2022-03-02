#pragma once
#ifndef LOG_H
#define LOG_H
#include "../functionals/functionals.h"
#include <iostream>
#include <fstream>
#include <chrono>

namespace surv::log {

	class LOG
	{
	protected:
		std::string filename;
		std::ofstream file;

	public:

		inline explicit LOG(const std::string& str, bool append = true) :filename(str) {
			if (append)
				file.open(filename, std::ios::app);
			else
				file.open(filename);
		}

		template<Streamable T>
		void operator<<(const T& msg) {
			file << msg << "\n";
		}
		~LOG() { file.close(); }
	};

}
#endif // !LOG_H