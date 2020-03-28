#include "logger.h"
// <std::fstream>:
Logger<std::fstream>::Logger(std::string path)
{
	_stream.open(path, std::fstream::in | std::fstream::out | std::fstream::app); // возможно читать, записать, дописать до того что уже есть

	if (!_stream.is_open())
	{
		std::cout << "Error of file opening!" << std::endl;
	}
	else
	{
		std::cout << "File is opened" << std::endl; // что делать если файл не открылся???
		time_t t = time(nullptr);
		tm* cur_t = localtime(&t);
		char tmp[100];
		strftime(tmp, 99, "%Y-%m-%d %H:%M:%S", cur_t);

		_stream << "Program Start Time : " << tmp << std::endl;
	}
}

void Logger<std::fstream>::log(std::string message, log_mode mode)
{
	if (log_mode::Debug == mode)
	{
		_stream << "Debug: \" " << message << " \"" << std::endl;
	}
	else if (log_mode::Error == mode)
	{
		_stream << "Error: \" " << message << " \"" << std::endl;
	}
	else
	{
		std::cout << "Mode of log is not correct" << std::endl;
		std::cout << "Message: " << message << std::endl;
	}
}

Logger<std::fstream>::~Logger()
{
	time_t t = time(nullptr);
	tm* cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%Y-%m-%d %H:%M:%S", cur_t);

	_stream << "Program End Time : " << tmp << std::endl;

	_stream.close();
}

// <std::ostream>:
void Logger<std::ostream>::log(std::string message, log_mode mode)
{


	if (log_mode::Debug == mode)
	{
		std::cout << "Debug: \" " << message << " \"" << std::endl;
	}
	else if (log_mode::Error == mode)
	{
		std::cout << "Error: \" " << message << " \"" << std::endl;
	}
	else
	{
		std::cout << "Mode of log is not correct" << std::endl;
		std::cout << "Message: " << message << std::endl;
	}
}