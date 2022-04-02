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

	Track Point::distance3D(const Point& P) const
	{
		return Track(sqrt(pow(x - P.x, 2) + pow(y - P.y, 2) + pow(z - P.z, 2)));
	}

	Track Point::distance2D(const Point& P) const
	{
		return Track(sqrt(pow(x - P.x, 2) + pow(y - P.y, 2)));
	}

	Angle Point::angle(const Point& P) const
	{
		Angle value{ 0 };
		// Delta y und x sind größer als 0
		if ((P.y - y) >= 0 && (P.x - x >= 0))
			value = atan((P.y - y) / (P.x - x));

		// Delta y ist kleiner und x ist größer als 0
		else if ((P.y - y) <= 0 && (P.x - x) >= 0)
			value = atan((P.y - y) / (P.x - x)) + to_rad(400);

		// rest der möglichkeiten
		else
			value = atan((P.y - y) / (P.x - x)) + to_rad(200);

		if (value > to_rad(400))
			value -= to_rad(400);

		return value;
	}


}