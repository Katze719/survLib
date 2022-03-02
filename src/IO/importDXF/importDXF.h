#pragma once
#include "../importPoints/importPoints.h"
#include "DXFStructs/Entitie.h"
#include "DXFStructs/Table.h"

namespace surv {
	// nicht fertig 
#define ON(x) Vstr->at(i + x)

	enum class SECTION { undefined = 0, HEADER, TABLE, BLOCKS, ENTITIES, OBJECTS };

	using Entities = std::vector<Entitie>;
	using Tables = std::vector<Table>;

	class importDXF
	{
		using Lines = std::vector<std::string>;

		std::ifstream ifs;
		std::string line;
		std::string str;
		std::string name;
		std::unique_ptr<Lines> Vstr = std::make_unique<Lines>();
		std::unique_ptr<Entities> Ents = std::make_unique<Entities>();
		std::unique_ptr<Tables> Tabls = std::make_unique<Tables>();
		SECTION section = SECTION::undefined;

		size_t size_objects = 0;

		// ändert section wenn s ein SECTION keyword enthält -> check_for_section
		void cfs(std::string_view s);

		// findet die entities
		void search_for_ents(size_t& i);

		// findet die Grafikeigenschaft in den LineTypeTables
		void search_for_LineTypeTables(size_t& i);

		// zählt die anzahl der objekte
		void count_objects();

		// starting the process
		void getting_file();


	public:

		inline Entities get_Entities() const { return *Ents; }
		inline Lines get_FileStrings() const { return *Vstr; }
		inline Tables get_Tables() const { return *Tabls; }
		inline std::string get_Name() const { return name; }
		inline size_t get_size_objects() const { return size_objects; }

		importDXF() = default;
		inline void set_filename_and_start(const std::string& s) { ifs = std::ifstream(s); name = s; getting_file(); count_objects(); }


		inline explicit importDXF(const std::string& File) :ifs(File), name(File) { getting_file(); count_objects(); }
	};
#undef ON
}
