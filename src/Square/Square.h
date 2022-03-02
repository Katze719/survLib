#pragma once
#include "../Triangle/Triangle.h"
namespace surv {

	class Square : public Triangle
	{
	public:
		Point D;

		Track d = 0;

		Angle delta = 0;

		Square() = default;

		Square(const Point& _A, const Point& _B, const Point& _C, const Point& _D)
			:Triangle(_A, _B, _C), D(_D)
		{}

		// TODO: erstellt 1 Viereck aus 2 Dreiecken
		Square(const Triangle& T1, const Triangle& T2);

		//void set_angles() override;

		//void set_sites() override;

		inline void set_area() override { area = c_area(Points{ A, B, C, D }); }

		void set_circumference() override { circumference = a + b + c + d; }

		~Square() override {}

	};

}

