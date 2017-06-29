#include "LogManager.h"

LogManager *LogManager::instance;

LogManager::LogManager() {
	//const unsigned short physicsDoc = 0, graphicsDoc= 1, soundDoc = 2, eventDoc = 3, bFlagDoc = 4, enemyDoc = 5, bossDoc = 6;
	this->target = ERWARNING;
	this->booke.open("log.txt", std::ios::out | std::ios::app);
}

LogManager::~LogManager() {

	//if the booke is SOMEHOW still up and running, kill it
	if (this->booke.is_open())
		this->booke.close();

	if (instance) {

		delete instance;
		instance = 0;

	}
}

LogManager* LogManager::GetInstance() {

	if (instance == 0) instance = new LogManager();
	return instance;

}

//method sending the message to the appropriate file
void LogManager::InfoToFile(std::string message, errorLevel error) {

	//only print the message if it is at or above our target message value
	if (error >= target) {
		//writing the message with it's own ID into the file
		booke.write(message.c_str(), message.length());
		booke << std::endl;
		
		booke.flush();
	}
}

void LogManager::ChangeFile(std::string name) {

	if (booke.is_open()) {

		booke.close();
		booke.open(name, std::ios::out | std::ios::app);

	}

}

void LogManager::SetErrorLevel(errorLevel lv) {

	if (lv == ERINFO || lv == ERTRACE || lv == ERWARNING || lv == ERERROR)
		this->target = lv;

	else
		this->target = ERWARNING;

}

const errorLevel LogManager::GetErrorLevel() { return this->target; }