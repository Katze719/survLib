#pragma once
#ifndef functionals_H
#define functionals_H

#include "../Line/Line.h"
#include "../Direction_angle/Direction_angle.h"
namespace surv {

	// erstellen einer [regel] für templates
	template<typename T>
	concept Iterable = requires(T a) {
		{a.size()} -> std::convertible_to<size_t>;
	};

	// sort(var), var muss die methode .size() haben
	template<Iterable Pakage>
	void sort(Pakage& var) {
		if (std::size(var) <= 0)
			return;
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
	template<Iterable T>
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
	void print(T var) {
		std::cout << var << "\n";
	}

	// surv::print() nur als schleife für alles was
	// die methode .size() besitzt
	template<Iterable T>
	void printl(T var) {
		for (auto& elem : var)
			surv::print(elem);
	}

	// löscht eine variable die == t ist aus einem vector
	template<typename T>
	void delInV(std::vector<T>& v, const T& t) {
		for (size_t i = 0; i < v.size(); i++)
			if (v.at(i) == t)
				v.erase(v.begin() + i);
	}

	// checkt ob eine variable in einem vector vorhanden ist
	template <typename T>
	bool isAvailInV(const std::vector<T>& v, const T& t) {
		for (const auto& elem : v)
			if (elem == t)
				return true;
		return false;
	}

	// schnittpunktberechnen
	Point intercept(const Line& L1, const Line& L2);

	// berechnet die Fläche, punkte müssen in richtiger reihenfolge im vector stehen
	// entweder im uhrzeigersinn oder gegen den uhrzeigersinn
	double c_area(Points Ps);

	// Pohlares-anhängen, winkel in GON angeben bitte
	Point Polar_attachment(const Point& P1, const Angle& A, const Track& S);

	enum class Type { undefined, KOR };

}
#endif // !functionals_H