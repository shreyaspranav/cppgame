#include "Log.h"

namespace cppgame
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

	void Log::InitLoggger()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("cppgame");
		s_CoreLogger->set_level(spdlog::level::trace);

	}
}