#include "functionals.h"
namespace surv {

	Point intercept(const Line& L1, const Line& L2)
	{
		Direction_angle t3_1(L2.A, L1.A);
		Direction_angle t3_4(L2.A, L2.B);
		Direction_angle t1_2(L1.A, L1.B);

		Track s_1_s = dist(L1.A, L2.A) * (sin(t3_1.get_value() - t3_4.get_value()) / sin(t3_4.get_value() - t1_2.get_value()));

		Point P;
		P.y = L1.A.y + s_1_s * sin(t1_2.get_value());
		P.x = L1.A.x + s_1_s * cos(t1_2.get_value());

		Direction_angle s(L1.A, P);

		return P;
	}

	double c_area(Points Ps)
	{
		double F = 0.0;
		if (Ps.size() > 2) {
			Ps.insert(Ps.begin(), 1, Ps.at(Ps.size() - 1)); // copies last point to begin
			Ps.push_back(Ps.at(1));							// copies first point to end
			for (size_t i = 1; i < Ps.size() - 1; i++)
				F += Ps.at(i).x * (Ps.at(i + 1).y - Ps.at(i - 1).y);
		}
		return fabs(F / 2);
	}

	Point Polar_attachment(const Point& Start, const Angle& A, const Track& S)
	{
		return Start + Point(S * gcos(A), S * gsin(A));
	}
}
