#include "../headers/task-manager.h"
#include <fstream>

int TaskManager::getNoOfTasks()
{
	return tasks.size();
}

void TaskManager::createNewTask(std::string description)
{
	int newId = getNoOfTasks() + 1;
	Task newTask(newId, description);
	tasks.push_back(newTask);
	std::cout << "New Task Created Successfully. [ID : " << newId << "]" << std::endl;
}

void TaskManager::deleteTask(int taskID)
{
	if (taskID < 0 || taskID > getNoOfTasks())
	{
		std::cout << "Enter a valid task ID." << std::endl;
	}
	
	tasks.erase(tasks.begin() + taskID - 1);
	
	int count = 1;
	for (Task& task : tasks)
	{
		task.setID(count);
		count++;
	}
	
	std::cout << "Task with ID " << taskID << " has been removed." << std::endl;
}

void TaskManager::updateTask(int taskID, std::string newDesc, std::string newStat)
{
	if (taskID < 0 || taskID > getNoOfTasks())
	{
		std::cout << "Enter a valid task ID." << std::endl;
	}

	if (newDesc == "same")
	{
		tasks.at(taskID - 1).setStatus(newStat);
		std::cout << "Task " << taskID << ": Marked as " << newStat << "." << std::endl;
	}
	else 
	{
		tasks.at(taskID - 1).setDescription(newDesc);
		std::cout << "Task " << taskID << ": Description changed as " << newDesc << "." << std::endl;
	}
}

void TaskManager::listTasks(std::string status)
{
	for (Task& task : tasks)
	{
		if (status == "all" || status == task.getStatus())
		{
			std::cout << task.getID() << ": " << std::endl;
			std::cout << "Description: " << task.getDescription() << std::endl;
			std::cout << "Status: " << task.getStatus() << std::endl << std::endl;
		}
	}
}

void TaskManager::taskHelper(std::string app_name)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "    " << app_name << " add \"<task>\" -- Adds a new task for the current directory." << std::endl;
	std::cout << "    " << app_name << " update <task-id> \"<new-task>\" -- Updates a task description specified by a task id." << std::endl;
	std::cout << "    " << app_name << " delete <task-id> -- Deletes a task specified by a task id.\n" << std::endl;
	std::cout << "    " << app_name << " mark-in-progress <task-id> -- Changes the status of a task specified by a task id to in-progress." << std::endl;
	std::cout << "    " << app_name << " mark-done <task-id> -- Changes the status of a task specified by a task id to done.\n" << std::endl;
	std::cout << "    " << app_name << " list -- List all the available tasks." << std::endl;
	std::cout << "        " << app_name << " list done -- List all the available tasks with the status done." << std::endl;
	std::cout << "        " << app_name << " list todo -- List all the available tasks with the status todo." << std::endl;
	std::cout << "        " << app_name << " list in-progress -- List all the available tasks with the status in-progress.\n" << std::endl;
	std::cout << "    " << app_name << " help -- Prints this help message." << std::endl;
}

void TaskManager::writeToFile()
{
	std::ofstream File(".tasks", std::ios::trunc);
	
	for (Task& task : tasks)
	{
		std::string line = task.convertToString();
		File << line << std::endl;
	}

	File.close();
}

void TaskManager::readFromFile()
{
	std::ifstream inFile(".tasks");
	if (!inFile.is_open())
	{
		std::ofstream outFile(".tasks");
		outFile.close();
		std::ifstream inFile(".tasks");
	}

	std::string line;
	
	while (std::getline(inFile, line))
	{
		Task newTask;
		newTask.convertToTask(line);
		tasks.push_back(newTask);
	}
	inFile.close();
}
