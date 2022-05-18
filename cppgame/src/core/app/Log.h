#pragma once

#include <iostream>
#include <string>

#include "Core.h"

#ifdef GAME_PLATFORM_WINDOWS
	#include <windows.h>
#endif // GAME_PLATFORM_WINDOWS


#define RESET		"\033[0m"
#define BLACK		"\033[30m"			   /* Black */
#define RED			"\033[31m"			   /* Red */
#define GREEN		"\033[32m"			   /* Green */
#define YELLOW		"\033[33m"			   /* Yellow */
#define BLUE		"\033[34m"			   /* Blue */
#define MAGENTA		"\033[35m"			   /* Magenta */
#define CYAN		"\033[36m"			   /* Cyan */
#define WHITE		"\033[37m"			   /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

namespace cppgame {
	class CPPGAME_API Log
	{

	public:
		inline static void ColorTest();

		inline static void Error(std::string message);
		inline static void ErrorSevere(std::string message);
		inline static void Warn(std::string message);
		inline static void Info(std::string message);

	};
}

#ifdef LOG_ON

#define LOG_ERROR_SEVERE(...)		cppgame::Log::ErrorSevere(__VA_ARGS__)
#define LOG_ERROR(...)				cppgame::Log::Error(__VA_ARGS__)
#define LOG_WARN(...)				cppgame::Log::Warn(__VA_ARGS__)
#define LOG_INFO(...)				cppgame::Log::Info(__VA_ARGS__)

#define LOG_COLOR_TEST				cppgame::Log::ColorTest()

#else 

#define LOG_ERROR_SEVERE(...)
#define LOG_ERROR(...)		
#define LOG_WARN(...)		
#define LOG_INFO(...)		

#define LOG_COLOR_TEST		


#endif // LOG_ON






