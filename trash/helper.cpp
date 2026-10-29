#include "linker.h"

std::vector<std::string> read_tasks()
{
	std::ifstream File(".tasks");
	if (!File.is_open())
	{
		std::ofstream File(".tasks");
		File << "0" << std::endl;
		File.close();
		return {"0"};
	}

	std::string line;
	std::vector<std::string> content;
	
	while (std::getline(File, line))
	{
		content.push_back(line);
	}
	File.close();
	return content;
}

std::vector<std::vector<std::string>> split_tasks(std::string option)
{
	std::vector<std::string> content = read_tasks();
	std::vector<std::vector<std::string>> seperated_content;
	
	for (int i = 1; i < content.size(); i++)
	{
		std::vector<std::string> list;
		std::string word;
		
		for (char c : content[i])
		{
			if (c != '|') word = word + c;
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

	return seperated_content;
}

ReturnType validate_task_id(std::string task)
{
	ReturnType return_type;
	return_type.return_status = OK;

	try 
	{
		return_type.task_id = stoi(task);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "Enter a valid task ID." << std::endl;
		return_type.return_status = ERROR;
	}

	std::vector<std::string> content = read_tasks();
	
	return_type.no_of_tasks = stoi(content.at(0));

	if (return_type.no_of_tasks == 0)
	{
		std::cout << "No tasks are available to delete.\nSee help message to know how to create new tasks." << std::endl;
		return_type.return_status = ERROR;
	}

	if (return_type.task_id < 1 || return_type.task_id > return_type.no_of_tasks)
	{
		std::cout << "The entered task ID is out of valid range." << std::endl;
		return_type.return_status = ERROR;
	}

	return return_type;
}
