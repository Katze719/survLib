#pragma once
#include "../importDXF/importDXF.h"
#include <thread>

namespace surv {

	class DXF_STORAGE
	{
		std::vector<importDXF*> Files;
		std::vector<std::thread> threads;

		inline void wait_for_threads() { for (auto& elem : threads) elem.join(); }

	public:

		inline DXF_STORAGE(const std::vector<std::string>& File_Names) {
			for (auto& elem : File_Names) {
				importDXF* dxf = new importDXF;
				Files.push_back(dxf);
				threads.push_back(std::thread(&importDXF::set_filename_and_start, dxf, elem));
			}
			wait_for_threads();
		}

		inline importDXF& at(const int& i) { return *Files.at(i); }

		inline importDXF& at(const std::string& str) {
			for (auto& elem : Files)
				if (elem->get_Name().compare(str) == 0)
					return *elem;
			throw std::invalid_argument("no DXF file found with this name!");
		}

		inline size_t size() { return Files.size(); }

	};

}

