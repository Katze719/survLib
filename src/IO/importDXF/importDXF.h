#pragma once
#include "../importPoints/importPoints.h"
#include "DXFStructs\Entitie.h"

namespace surv {
	// nicht fertig 
#define ON(x) Vstr->at(i + x)

	enum class SECTION { undefined = 0, HEADER, TABLE, BLOCKS, ENTITIES, OBJECTS };

	using Entities = std::vector<Entitie>;

	class importDXF
	{
	private:
		using Lines = std::vector<std::string>;
		using Tables = std::vector<std::string>;

		std::ifstream ifs;
		std::string line, str, name;
		Lines* Vstr = new Lines;
		Entities* Ents = new Entities;
		Tables* Tabls = new Tables;
		SECTION section = SECTION::undefined;

		// ändert section wenn s ein SECTION keyword enthält -> check_for_section
		void cfs(const std::string& s);

		// findet die entities
		void search_for_ents(size_t& i);

		// findet die Grafikeigenschaft in den LineTypeTables
		void search_for_LineTypeTables(size_t& i);

		// starting the process
		void getting_file();


	public:

		inline Entities get_Entities() { return *Ents; }
		inline Lines get_FileStrings() { return *Vstr; }
		inline Tables get_Tables() { return *Tabls; }
		inline std::string get_Name() { return name; }

		importDXF() {}
		inline void set_filename_and_start(const std::string& s) { ifs = std::ifstream(s); name = s; getting_file(); }


		inline importDXF(const std::string& File) :ifs(File), name(File) { getting_file(); }
		inline ~importDXF() { if (Vstr != nullptr) delete Vstr; if (Ents != nullptr) delete Ents; if (Tabls != nullptr) delete Tabls; }
	};
#undef ON
}
