#pragma once

#include <iostream>
#include <fstream>
#include <string>


void print_help(std::string app_name)
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


