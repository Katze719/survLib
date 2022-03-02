#pragma once
#ifndef DXF_H
#define DXF_H

#include "../importDXF/importDXF.h"
#include <thread>

namespace surv {

	class DXF_STORAGE
	{
		std::vector<importDXF*> Files;
		std::vector<std::jthread> threads;

		inline void wait_for_threads() { for (std::jthread& elem : threads) elem.join(); }

	public:

		DXF_STORAGE() = default;

		inline explicit DXF_STORAGE(const std::vector<std::string>& File_Names) {
			for (auto& elem : File_Names) {
				auto* dxf = new importDXF;
				Files.emplace_back(dxf);
				threads.emplace_back(&importDXF::set_filename_and_start, dxf, elem);
				delete dxf;
			}
			wait_for_threads();
		}

		inline importDXF& at(const int& i) { return *Files.at(i); }

		inline importDXF& at(std::string_view str) {
			for (auto& elem : Files)
				if (elem->get_Name().compare(str) == 0)
					return *elem;
			throw std::invalid_argument("no DXF file found with this name!");
		}

		inline size_t size() const { return Files.size(); }

	};
}
#endif // !DXF_H
