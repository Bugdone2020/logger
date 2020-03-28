#include "func.h"
#include "Logger.h"
#include <iostream>

extern Logger<std::fstream> global_logger_file;
extern Logger<std::ostream> global_logger_consol;


void my_func()
{
	global_logger_file.log("my_func : global_logger_file ", log_mode::Debug);
	global_logger_consol.log("my_func : global_logger_consol ", log_mode::Debug);
}
