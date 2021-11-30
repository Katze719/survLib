#pragma once
#include "../Line/Line.h"
#include "../Direction_angle/Direction_angle.h"
namespace surv {

	// erstellen einer [regel] für templates
	template<typename T>
	concept iterable = requires(T a) {
		{a.size()};
	};

	// sort(var), var muss die methode .size() haben
	template<iterable Pakage>
	void sort(Pakage& var) {
		for (size_t i = 0; i < std::size(var); i++) {
			for (size_t ii = 0; ii < std::size(var); ii++) {
				if (var[i] < var[ii]) {
					auto temp = var[i];
					var[i] = var[ii];
					var[ii] = temp;
				}
			}
		}
	}

	// invertiert eine liste, P muss .size() besitzen
	template<iterable T>
	void reverse(T& P) {
		auto v = P;
		for (size_t i = 0; i < P.size(); i++)
			P[i] = v[v.size() - i - 1];
	}

	// erstellen einer [regel] für templates
	template<typename T>
	concept Streamable = requires(std::ostream & os, T a) {
		{os << a} -> std::convertible_to<std::ostream&>;
	};

	// print für alles das konvertierbar ist in
	// einen std::ostream
	template<Streamable T>
	void print(T& var) {
		std::cout << var << "\n";
	}

	// surv::print() nur als schleife für alles was
	// die methode .size() besitzt
	template<iterable T>
	void printl(T& var) {
		for (auto& elem : var)
			surv::print(elem);
	}

	// schnittpunktberechnen
	Point intercept(const Line& L1, const Line& L2);

	// berechnet die Fläche, punkte müssen in richtiger reihenfolge im vector stehen
	// entweder im uhrzeigersinn oder gegen den uhrzeigersinn
	double c_area(std::vector<Point> Ps);

	// Pohlares-anhängen, winkel in GON angeben bitte
	Point Polar_attachment(const Point& P1, const Angle& A, const Track& S);

}