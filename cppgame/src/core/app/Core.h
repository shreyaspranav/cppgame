#pragma once

#ifdef GAME_PLATFORM_WINDOWS
	#ifdef GAME_BUILD_DLL

		#ifdef _MSC_VER
			#define CPPGAME_API __declspec(dllexport)

		#elif __GNUG__
			#define CPPGAME_API __attribute__((visibility("default")))

		#endif // _MSC_VER
	#endif // GAME_PLATFORM_WINDOWS

	#ifdef GAME_BUILD_EXE

		#ifdef _MSC_VER
			#define CPPGAME_API __declspec(dllimport)

		#elif __GNUG__
			#define CPPGAME_API

		#endif // _MSC_VER
	#endif

#else #error cppgame supports only Windows!

#endif

#define NO_PROBLEM 0
#define BIT(x) 1 << x