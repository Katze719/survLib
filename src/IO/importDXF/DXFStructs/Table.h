#pragma once
#include "../../../Point/Point.h"


namespace surv {

	using GC_I = std::string; // Group-Code Information

	struct Table
	{
		GC_I C2; // Layer Name
		GC_I C6; // Layer Grafik
		GC_I C62; // Farbe
		GC_I C70;
		GC_I C370;

		inline bool is_filled() const { if (!C2.empty() && !C6.empty() && !C62.empty() && !C70.empty()) return true; else return false; }
	};

}

