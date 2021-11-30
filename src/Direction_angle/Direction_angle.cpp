#include "Direction_angle.h"
namespace surv {

	Direction_angle::Direction_angle(const Point& _P1, const Point& _P2) :P1(_P1), P2(_P2)
	{
		// Delta y und x sind größer als 0
		if ((_P2.y - _P1.y) >= 0 && (_P2.x - _P1.x >= 0))
			value = atan((_P2.y - _P1.y) / (_P2.x - _P1.x));

		// Delta y ist kleiner und x ist größer als 0
		else if ((_P2.y - _P1.y) <= 0 && (_P2.x - _P1.x) >= 0)
			value = atan((_P2.y - _P1.y) / (_P2.x - _P1.x)) + to_rad(400);

		// rest der möglichkeiten
		else
			value = atan((_P2.y - _P1.y) / (_P2.x - _P1.x)) + to_rad(200);

		if (value > to_rad(400))
			value -= to_rad(400);
	}
}