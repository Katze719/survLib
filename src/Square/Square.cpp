#include "Square.h"

namespace surv {

	Square::Square(const Triangle& T1, const Triangle& T2) :Triangle(T1) {
		if (is_near(A, T2.A) == false) {
			D = T2.A;
			//a = dist(C, D);
			//d = dist(B, D);
		}
		else if (is_near(B, T2.B) == false) {
			D = T2.B;
			//a = dist(C, D);
			//d = dist(B, D);
		}
		else if (is_near(C, T2.C) == false) {
			D = T2.C;
			//a = dist(C, D);
			//d = dist(B, D);
		}
		else
			throw std::invalid_argument("cant create Square");
	}
}