#pragma once
#include "LOG.h"

namespace surv::log {

	enum class level { DEBUG = 0, INFO, WARN, ERR };

	class advancedLOG : private LOG
	{
		level Lv = level(0);
		level comming_in = level(0);

		inline std::string getLabel(level type) const {
			switch (type) {
			case level::DEBUG: return "DEBUG"; break;
			case level::INFO: return "INFO"; break;
			case level::WARN: return "WARNING"; break;
			case level::ERR: return "ERROR"; break;
			default: return "SOME"; break;
			}
		}


	public:

		inline explicit advancedLOG(const std::string& str, level _Lv) : LOG(str), Lv(_Lv) {}

		template<Streamable T>
		void operator<<(const T& msg) {
			if (comming_in >= Lv)
				file << "[" + getLabel(comming_in) + "]" << std::chrono::system_clock::now() + std::chrono::hours(1) << "\t" << msg << "\n";
		}

		advancedLOG& operator()(level _Lv) {
			comming_in = _Lv;
			return *this;
		}
	};
}


