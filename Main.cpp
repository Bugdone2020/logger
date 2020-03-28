#include "logger.h"
#include "func.h"
#include <windows.h>

Logger<std::fstream> global_logger_file("Logger.txt");
Logger<std::ostream> global_logger_consol;

int main()
{
	
	global_logger_file.log("main : global_logger_file ", log_mode::Debug);
	global_logger_consol.log("main : global_logger_consol ", log_mode::Debug);

	Sleep(3000);

	my_func();

	global_logger_file.log("main : global_logger_file ", log_mode::Error);
	global_logger_consol.log("main : global_logger_consol ", log_mode::Error);
	
return 0;
}






///////
	//Logger log("Log.txt");

	//log.log("Hello", "D");

	/*global_logger.log("World", log_mode::Debug);
	global_logger1.log("global_logger1  -1", log_mode::Debug);

	Sleep(3000);

	global_logger1.log("global_logger1  -2", log_mode::Debug);*/

	//Logger::log("Hii","D");


	//if (const char* env_p = std::getenv("PATH"))
	//	std::cout << "Your PATH is: " << env_p << '\n';

	//std::cout << %PATH% << std::endl;
	//system("%PATH%");



	//char* HOME = getenv("HOME");
	//char* USER = getenv("USER");

	//printf("Home directory: \"%s\"\n", HOME);
	//printf("User name: \"%s\"\n", USER);


	//global_logger.log("global_log : main", log_mode::Error);

	//my_func();