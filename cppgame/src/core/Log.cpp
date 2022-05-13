#include "Log.h"

namespace cppgame {
	inline void Log::ColorTest()
	{
		std::cout << RED << "L" << GREEN << "o" << YELLOW << "g "
			<< BLUE << "T" << MAGENTA << "e" << CYAN << "s" << WHITE << "t!" << RESET << std::endl;

		std::cout << BOLDRED << "L" << BOLDGREEN << "o" << BOLDYELLOW << "g "
			<< BOLDBLUE << "T" << BOLDMAGENTA << "e" << BOLDCYAN << "s" << BOLDWHITE << "t!" << RESET << std::endl;
	}

	inline void Log::Error(std::string message){  std::cout << RED << "Error: " << message << RESET << std::endl;  }
	inline void Log::ErrorSevere(std::string message){  std::cout << BOLDMAGENTA << "Error SEVERE: " << message << RESET << std::endl;  }
	inline void Log::Warn(std::string message){  std::cout << YELLOW << "Warning: " << message << RESET << std::endl;  }
	inline void Log::Info(std::string message){  std::cout << GREEN << "Info: " << message << RESET << std::endl;  }	
}
