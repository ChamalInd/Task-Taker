#pragma once
#include "task.h"
#include "includes.h"

class TaskManager
{
	private:
		std::vector<Task> tasks; 

	public:
		int getNoOfTasks();

		void createNewTask(std::string description);
		void deleteTask(int taskID);
		void updateTask(int taskID, std::string newDesc, std::string newStat);
		void listTasks(std::string status);
		void taskHelper(std::string app_name);

		void writeToFile();
		void readFromFile();
};
