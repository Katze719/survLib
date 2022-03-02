#include "../functionals/functionals.h"

namespace surv {

	// klasse ist public!!!
	class Triangle {
	public:
		Point A;
		Point B;
		Point C;

		Track a = 0;
		Track b = 0;
		Track c = 0;

		Angle alpha = 0;
		Angle beta = 0;
		Angle gamma = 0;

		double area = 0;
		double circumference = 0;

		// bitte alle Punkte setzten und dannach die methode
		// calc() verwenden um das Dreick zu vollenden
		Triangle() = default;

		// erstellt ein komplettes dreieck
		Triangle(const Point& _A, const Point& _B, const Point& _C)
			:A(_A), B(_B), C(_C)
		{
			calc();
		}

		// vollendet das Dreieck wenn alle 3 Punkte vorhanden sind
		// damit der standard konstruktur verwendbar ist
		void virtual calc() { set_sites(); set_area(); set_circumference(); set_angles(); }

		// rechnet winkel
		void virtual set_angles();

		// rechnet seiten
		void virtual set_sites();

		// rechnet fläche
		void virtual set_area();

		// rechnet umfang
		void virtual set_circumference() { circumference = a + b + c; }

		virtual ~Triangle() = default;
	};

}
