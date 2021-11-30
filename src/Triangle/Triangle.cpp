#include "Triangle.h"
namespace surv {

	void Triangle::set_angles() {
		alpha = (pow(b, 2) + pow(c, 2) - pow(a, 2)) / 2 * b * c;
		beta = (pow(c, 2) + pow(a, 2) - pow(b, 2)) / 2 * c * a;
		gamma = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / 2 * a * b;
	}

	void Triangle::set_sites() {
		a = dist(B, C);
		b = dist(C, A);
		c = dist(A, B);
	}

	void Triangle::set_area() {
		area = fabs(0.5 * ((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)));
	}
}