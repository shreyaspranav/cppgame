#pragma once
#include "spdlog/spdlog.h"
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Core.h"

namespace cppgame {

	class CPPGAME_API Log
	{
	public:
		static void InitLoggger();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}


#ifdef LOG_ON
	#define INIT_LOGGER				cppgame::Log::InitLoggger()
	
	//Core Logger
	#define LOG_ERROR_SEVERE(...)   ::cppgame::Log::GetCoreLogger()->critical(__VA_ARGS__)
	#define LOG_ERROR(...)			::cppgame::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define LOG_WARN(...)			::cppgame::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define LOG_INFO(...)			::cppgame::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define LOG_TRACE(...)			::cppgame::Log::GetCoreLogger()->trace(__VA_ARGS__)

	#else
#define VT_INIT_LOGGER

	//Core Logger
	#define LOG_ERROR(...) 
	#define LOG_WARN(...)  
	#define LOG_INFO(...)  
	#define LOG_TRACE(...) 


#endif