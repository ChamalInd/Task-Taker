#pragma once
#include <iostream>

class Task
{
	private:
		int id;
		std::string description;
		std::string status;
	
	public:
		Task(int i, std::string d) : id(1), description(d), status("ToDo") {}
		Task(int i, std::string d, std::string s) : id(1), description(d), status(s) {}

		int getID();
		std::string getDescription();
		std::string getStatus();
		
		void setDescription(std::string& newDesc);
		void setStatus(std::string& newStat);

		std::string convertToString();
		Task convertToTask(std::string& line);
};
