#include "linker.h"

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

void create_task(std::string task)
{
	if (task.length() < 1)
	{
		std::cout << "Task description is too small." << std::endl;
		return;
	}

	std::vector<std::string> content = read_tasks();
	
	int no_of_tasks = stoi(content.at(0)) + 1;
	
	std::string new_task = std::to_string(no_of_tasks) + "," + task + ",todo";
	content.push_back(new_task);

	std::ofstream File(".tasks", std::ios::trunc);
	if (!File.is_open())
	{
		std::cout << "Error occurred while trying to open the file." << std::endl;
	}

	content[0] = std::to_string(no_of_tasks);

	for (std::string line : content)
	{
		File << line << std::endl;
	}
	
	File.close();

	std::cout << "Task added successfully (ID: " << no_of_tasks << ")" << std::endl;
}

void view_tasks(std::string option)
{
	std::vector<std::string> content = read_tasks();
	std::vector<std::vector<std::string>> seperated_content;

	for (int i = 1; i < content.size(); i++)
	{
		std::vector<std::string> list;
		std::string word;
		
		for (char c : content[i])
		{
			if (c != ',') word = word + c;
			else 
			{
				list.push_back(word);
				word = "";
			}
		}
		
		if (option == "all" || option == word)
		{
			list.push_back(word);
			seperated_content.push_back(list);
		}
	}
	
	std::cout << "Total of " << seperated_content.size() << " tasks displayed.\n" << std::endl;

	for (int i = 0; i < seperated_content.size(); i++)
	{
		std::cout << seperated_content[i][0] << ": " << seperated_content[i][1] << std::endl;
		std::cout << "Status: " << seperated_content[i][2] << std::endl << std::endl;
	}
}
