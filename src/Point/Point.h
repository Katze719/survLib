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


namespace surv {

	// Winkel
	using Angle = double;
	// Koordinate
	using Coordinate = double;
	// Strecke
	using Track = double;

	__declspec(selectany) int IS_NEAR = 1;

	inline void setprecision_IS_NEAR(const int& v) { IS_NEAR = v; }
	
	__declspec(selectany) size_t g_index = 0;

	// überprüft ob ein string zu einem double konvertierbar ist
	bool isDouble(const std::string& s);

	struct Point {
		Coordinate x{0.0};
		Coordinate y{0.0};
		Coordinate z = NULL;

		// jeder punkt hat einen eigennen index der geändert werden kann
		// index kann auch nur eine Punktnummer mit Buchstaben sein
		// wen kein index mit angeführt wird, wird der standart index weiter geführt
		std::string index = std::to_string(g_index++);

		std::string code;

		Point() = default;
		

		// strecke von Punkt zu Punkt
		Track distance2D(const Point& p) const;
		
		Track distance3D(const Point& p) const;
		
		// richtungswinkel von diesem Punkt zu Punkt
		Angle angle(const Point& p) const;


		// 2D Punkt (x, y)
		inline Point(const Coordinate& _x, const Coordinate& _y)
			: x(_x), y(_y)
		{}




		// normal Punkt (x, y, z)
		inline Point(const Coordinate& _x, const Coordinate& _y, const Coordinate& _z)
			: x(_x), y(_y), z(_z)
		{}




		// 2D Punkt mit Strings (x, y)
		inline Point(const std::string& _x, const std::string& _y)
		{
			if (isDouble(_x) && isDouble(_y)) {
				x = std::stod(_x);
				y = std::stod(_y);
			}
			else
				throw std::invalid_argument("can't create Point, this string is not convertable to double!");
		}




		// normal Punkt mit Strings (x, y, z)
		inline Point(const std::string& _x, const std::string& _y, const std::string& _z)
		{
			if (isDouble(_x) && isDouble(_y) && isDouble(_z)) {
				x = std::stod(_x);
				y = std::stod(_y);
				z = std::stod(_z);
			}
			else
				throw std::invalid_argument("can't create Point, this string is not convertable to double!");
		}




		// TODO
		inline Point(const std::string& Pktn, const std::string& Pktc, const std::string& _x, const std::string& _y, const std::string& _z)
			: index(Pktn), code(Pktc)
		{
			if (isDouble(_x) && isDouble(_y) && isDouble(_z)) {
				x = std::stod(_x);
				y = std::stod(_y);
				z = std::stod(_z);
			}
			else
				throw std::invalid_argument("can't create Point, this string is not convertable to double!");
		}





		/*
		*
		* Operators
		*
		*/

		// operator +
		inline Point operator+(const Point& P1) const {
			return Point(x + P1.x, y + P1.y, z + P1.z);
		}

		// operator +=
		inline Point& operator+=(const Point& P1) {
			x += P1.x; y += P1.y; z += P1.z;
			return *this;
		}

		// operator -
		inline Point operator-(const Point& P1) const {
			return Point(x - P1.x, y - P1.y, z - P1.z);
		}

		// operator -=
		inline Point& operator-=(const Point& P1) {
			x -= P1.x; y -= P1.y; z -= P1.z;
			return *this;
		}
		
		// operator <<, für std::ostream
		inline friend std::ostream& operator<<(std::ostream& os, const Point& P1) {
			os << "\nx:\t" << std::to_string(P1.x) << "\ny:\t" << std::to_string(P1.y) << "\nz:\t" << std::to_string(P1.z) << "\nindex:\t" << P1.index;
			return os;
		}
	};

	using Points = std::vector<Point>;

	// berechnet die distanz zwischen 2 Punkten
	Track dist(const Point& P1, const Point& P2);

	// sagt ob punkte soziemlich die selben sind oder nicht
	// um präzisere is_near werte zu bekommen:
	// einfach surv::setprecision_IS_NEAR(WERT) verwenden
	bool is_near(const Point& P1, const Point& P2);
}