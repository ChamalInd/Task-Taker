#pragma once
#include "includes.h"

class Task
{
	private:
		int id;
		std::string description;
		std::string status;
	
	public:
		Task() : id(0), description("New Task"), status("todo") {}
		Task(int i, std::string d) : id(i), description(d), status("todo") {}

		int getID();
		std::string getDescription();
		std::string getStatus();
		
		void setID(int newId);
		void setDescription(std::string& newDesc);
		void setStatus(std::string& newStat);

		std::string convertToString();
		void convertToTask(std::string& line);
};
