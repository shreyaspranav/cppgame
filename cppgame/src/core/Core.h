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
#endif

#ifdef GAME_PLATFORM_LINUX
	#ifdef GAME_BUILD_SO

		#ifdef __GNUG__
			#define CPPGAME_API
		#endif

	#endif // GAME_BUILD_SL

	#ifdef GAME_BUILD_EXEC

		#ifdef __GNUG__
			#define CPPGAME_API
		#endif // __GNUG__

	#endif // GAME_BUILD_EXEC

#endif // GAME_PLATFORM_LINUX

#ifdef GAME_PLATFORM_APPLE
	#ifdef GAME_BUILD_SL

		#ifdef __clang__
			#define CPPGAME_API
		#endif

	#endif // GAME_BUILD_SL

	#ifdef GAME_BUILD_EXEC

		#ifdef __clang__
			#define CPPGAME_API
		#endif // __clang__

	#endif // GAME_BUILD_EXEC
#endif //GAME_PLATFORM_APPLE


#define NO_PROBLEM 0