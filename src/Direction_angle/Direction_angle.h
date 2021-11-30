#pragma once
#include "../Point/Point.h"
namespace surv {

	// Richtungs Winkel
	class Direction_angle {
		Angle value;

	public:

		const Point P1;
		const Point P2;

		Direction_angle(const Point& _P1, const Point& _P2);

		Angle get_value() { return value; }

		friend inline std::ostream& operator<<(std::ostream& os, const Direction_angle& D) {
			os << "gon:\t" << to_gon(D.value) << "\n";
			return os;
		}
	};

}