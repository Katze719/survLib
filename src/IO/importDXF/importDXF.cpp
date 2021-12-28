#include "importDXF.h"

namespace surv {
#define ON(x) Vstr->at(i + x)

	void importDXF::cfs(const std::string& s) {
		if (s.compare("HEADER") == 0)
			section = SECTION::HEADER;
		else if (s.compare("TABLE") == 0)
			section = SECTION::TABLE;
		else if (s.compare("BLOCKS") == 0)
			section = SECTION::BLOCKS;
		else if (s.compare("ENTITIES") == 0)
			section = SECTION::ENTITIES;
		else if (s.compare("OBJECTS") == 0)
			section = SECTION::OBJECTS;
	}

	void importDXF::getting_file() {
		// getting the file
		while (!getline(ifs, line).eof()) {
			std::istringstream(line) >> str;
			Vstr->push_back(str);
		}
		for (size_t i = 0; i < Vstr->size(); i++) {
			cfs(ON(0));
			switch (section) {
			case SECTION::undefined:
				break;
			case SECTION::HEADER:
				break;
			case SECTION::TABLE:
				search_for_LineTypeTables(i);
				break;
			case SECTION::BLOCKS:
				break;
			case SECTION::ENTITIES:
				search_for_ents(i);
				break;
			case SECTION::OBJECTS:
				break;
			}
		}
	}


	void importDXF::search_for_ents(size_t& i) {

		Entitie Ent;
		bool found_one = false;

		if (ON(0) == "0")
			found_one = true;

		for (int Code = -1; found_one == true && i < Vstr->size(); i++) {

			cfs(ON(0));

			if (isDouble(ON(0)))
				Code = stoi(ON(0));
			else
				continue;

			switch (Code) {
			case 0:
				Ent.C0 = ON(1);
				break;
			case 5:
				Ent.C5 = ON(1);
				break;
			case 330:
				Ent.C330 = ON(1);
				break;
			case 100:
				Ent.C100 = ON(1);
				break;
			case 8:
				Ent.C8 = ON(1);
				break;
			case 6:
				Ent.C6 = ON(1);
				break;
			case 10:
				Ent.C10 = ON(1);
				break;
			case 20:
				Ent.C20 = ON(1);
				break;
			case 30:
				Ent.C30 = ON(1);
				break;
			default:
				break;
			}

			if (Ent.is_filled()) {
				found_one = false;
				Ents->push_back(Ent);
			}
		}
	}


	void importDXF::search_for_LineTypeTables(size_t& i) {

		if (ON(0).compare("AcDbLinetypeTableRecord") == 0)
			Tabls->push_back(ON(2));
	}
#undef ON
}