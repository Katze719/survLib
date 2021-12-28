#pragma once
#include "../../functionals/functionals.h"
#include <fstream>

namespace surv {

	class exportPoints
	{
		std::ofstream ofs;
		std::string file;
	public:
		exportPoints(const std::string& _File, const Points& Ps, const Type& t) {
			ofs.open(_File, std::ios::out);
			switch (t) {
			case Type::KOR:
				for (const auto& elem : Ps)
					ofs << elem.index << "\t" << elem.code << "\t" << elem.y << "\t" << elem.x << "\t" << elem.z << "\n";
				break;
			default:
				break;
			}
			ofs.close();
		}
	};

}
