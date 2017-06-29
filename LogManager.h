#ifndef LOG_FILE_MANAGER_H
#define LOG_FILE_MANAGER_H

#include <fstream>
#include <iostream>
#include <string>

//enum for error types
enum errorLevel { ERINFO, ERTRACE, ERWARNING, ERERROR };


/* this class is for managing multiple log files in the debugging process of the program
each document has it's own ID for the class to use for refrence	*/

class LogManager {

public:

	static LogManager* GetInstance();
	~LogManager();
	//method to send info to file, returns bool to notify whether or not things went well or not
	void InfoToFile(std::string message, errorLevel error);
	void ChangeFile(std::string name);
	void SetErrorLevel(errorLevel lv);
	const errorLevel GetErrorLevel();

private:

	static LogManager *instance;
	LogManager();
	errorLevel target;
	std::ofstream booke;

};

#endif