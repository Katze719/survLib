#include "Point.h"
namespace surv {

	Track dist(const Point& P1, const Point& P2) {
		return Track(sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2) + pow(P1.z - P2.z, 2)));
	}

	bool is_near(const Point& P1, const Point& P2) {
		return (dist(P1, P2) < IS_NEAR) ? true : false;
	}

	bool isDouble(const std::string& s)
	{
		if (s.empty())
			return false;
		char* p;
		strtod(s.c_str(), &p);
		return (*p == 0);
	}

}