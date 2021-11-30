#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <concepts>
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>


#define to_gon(x) ((x) * (200 / M_PI))
#define to_rad(x) ((x) / (200 / M_PI))

#define gcos(x) (cos((x)*M_PI/200))
#define gsin(x) (sin((x)*M_PI/200))
#define gtan(x) (tan((x)*M_PI/200))
#define gasin(x) (asin(x)*200/M_PI)
#define gatan(x) (atan(x)*200/M_PI)
#define gacos(x) (acos(x)*200/M_PI)

#ifndef IS_NEAR
#define IS_NEAR 1
#endif // !IS_NEAR

namespace surv {

	// Winkel
	typedef double Angle;
	// Koordinate
	typedef double Coordinate;
	// Strecke
	typedef double Track;

	__declspec(selectany) size_t g_index = 0;

	// überprüft ob ein string zu einem double konvertierbar ist
	bool isDouble(const std::string& s);

	class Point {
	public:
		Coordinate x = 0;
		Coordinate y = 0;
		Coordinate z = 0;

		// jeder punkt hat einen eigennen index der geändert werden kann
		size_t index;

		Point() :index(g_index++) {}

		// 2D Punkt (x, y)
		Point(const Coordinate& _x, const Coordinate& _y)
			:x(_x), y(_y), index(g_index++)
		{}

		// normal Punkt (x, y, z)
		Point(const Coordinate& _x, const Coordinate& _y, const Coordinate& _z)
			:x(_x), y(_y), z(_z), index(g_index++)
		{}

		// 2D Punkt mit Strings (x, y)
		Point(const std::string& _x, const std::string& _y)
			:index(g_index++)
		{
			if (isDouble(_x) && isDouble(_y)) {
				x = std::stod(_x);
				y = std::stod(_y);
			}
			else
				throw std::invalid_argument("can't create Point, this string is not convertable to double!");
		}

		// normal Punkt mit Strings (x, y, z)
		Point(const std::string& _x, const std::string& _y, const std::string& _z)
			:index(g_index++)
		{
			if (isDouble(_x) && isDouble(_y) && isDouble(_z)) {
				x = std::stod(_x);
				y = std::stod(_y);
				z = std::stod(_z);
			}
			else
				throw std::invalid_argument("can't create Point, this string is not convertable to double!");
		}

		// operator +
		inline Point operator+(const Point& P1) const {
			return Point(x + P1.x, y + P1.y, z + P1.z);
		}

		// operator +=
		inline void operator+=(const Point& P1) {
			x += P1.x; y += P1.y; z += P1.z;
		}

		// operator -
		inline Point operator-(const Point& P1) const {
			return Point(x - P1.x, y - P1.y, z - P1.z);
		}

		// operator -=
		inline void operator-=(const Point& P1) {
			x -= P1.x; y -= P1.y; z -= P1.z;
		}

		// index > index_
		inline bool operator>(const Point& P1) const {
			return (index > P1.index) ? true : false;
		}

		// index < index_
		inline bool operator<(const Point& P1) const {
			return (index < P1.index) ? true : false;
		}

		// operator <<, für std::ostream
		inline friend std::ostream& operator<<(std::ostream& os, const Point& P1) {
			os << "\nx:\t" << std::to_string(P1.x) << "\ny:\t" << std::to_string(P1.y) << "\nz:\t" << std::to_string(P1.z) << "\nindex:\t" << P1.index;
			return os;
		}
	};

	// berechnet die distanz zwischen 2 Punkten
	Track dist(const Point& P1, const Point& P2);

	// sagt ob punkte soziemlich die selben sind oder nicht
	// um präzisere is_near werte zu bekommen:
	// einfach IS_NEAR {WERT} definieren
	// example:
	// #define IS_NEAR 0.1 
	bool is_near(const Point& P1, const Point& P2);
}