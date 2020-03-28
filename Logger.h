#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum log_mode
{
	Error = 0,
	Debug = 1
};

template<typename T>
class Logger{};

template<>
class Logger<std::fstream>
{
	std::fstream _stream;
public:
	Logger(std::string path);
	void log(std::string message, log_mode mode);
	~Logger();
};

template<>
class Logger<std::ostream>
{
public:
	void log(std::string message, log_mode mode);
};