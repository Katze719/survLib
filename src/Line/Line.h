#pragma once
#include "../Point/Point.h"
namespace surv {

	class Line {
	public:
		Point A;
		Point B;

		Line() = default;

		Line(const Point& start, const Point& end)
			:A(start), B(end)
		{}

		Track get_distance() const {
			return surv::dist(A, B);
		}
	};
}
