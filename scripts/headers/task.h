#pragma once
#include <iostream>

class Task
{
	private:
		int id;
		std::string description;
		std::string status;
	
	public:
		Task() : id(0), description("New Task"), status("ToDo") {}
		Task(int i, std::string d) : id(i), description(d), status("ToDo") {}

		int getID();
		std::string getDescription();
		std::string getStatus();
		
		void setDescription(std::string& newDesc);
		void setStatus(std::string& newStat);

		std::string convertToString();
		void convertToTask(std::string& line);
};
