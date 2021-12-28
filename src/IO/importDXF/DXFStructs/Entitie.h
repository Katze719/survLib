#pragma once
#include "../../../Point/Point.h"

namespace surv {

	using GC_I = std::string; // Group-Code Information

	struct Entitie
	{
		GC_I C0;
		GC_I C5;
		GC_I C330;
		GC_I C100; // Objekt art
		GC_I C8; // Layer
		GC_I C6; // Grafik Eigenschaft
		//GC_I C2;
		GC_I C10;
		GC_I C20;
		GC_I C30;

		inline bool is_filled() { if (!C0.empty() && !C5.empty() && !C330.empty() && !C100.empty() && !C8.empty() && !C10.empty() && !C20.empty() && !C30.empty()) return true; else return false; }

		inline Point to_Point() { return Point(C5, "0", C10, C20, C30); }

		friend inline std::ostream& operator<<(std::ostream& os, const Entitie& Ent) {
			os << "MetaData:\t" << Ent.C0 << "\nLayer:\t" << Ent.C8 << "\nGrafik:\t" << Ent.C6 << "\nID:\t" << Ent.C5 << "\n";
			return os;
		}
	};

}

