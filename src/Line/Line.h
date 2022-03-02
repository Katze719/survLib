#pragma once
#include "../Point/Point.h"
namespace surv {

	class Line {
	public:
		Point A;
		Point B;

		Track s = 0;

		Line() = default;

		Line(const Point& start, const Point& end)
			:A(start), B(end)
		{
			s = surv::dist(start, end);
		}
	};
}
