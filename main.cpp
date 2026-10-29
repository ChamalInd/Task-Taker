#include "linker.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Type " << argv[0] << " help for more information" << std::endl;
		return 0;
	}

	if (strcmp(argv[1], "help") == 0)
	{
		print_help(argv[0]);
	}
	else if (strcmp(argv[1], "add") == 0)
	{	
		if (argc != 3)
		{
			std::cout << "Incorrect format for the current option.\nSee help message for correct format." << std::endl;
			return 1;
		}
		create_task(argv[2]);
	}
	else if (strcmp(argv[1], "update") == 0)
	{	
		if (argc != 4)
		{
			std::cout << "Incorrect format for the current option.\nSee help message for correct format." << std::endl;
			return 1;
		}
		update_task(argv[2], argv[3]);

	}
	else if (strcmp(argv[1], "delete") == 0)
	{	
		if (argc != 3)
		{
			std::cout << "Incorrect format for the current option.\nSee help message for correct format." << std::endl;
			return 1;
		}
		delete_task(argv[2]);

	}
	else if (strcmp(argv[1], "mark-in-progress") == 0)
	{	

	}
	else if (strcmp(argv[1], "mark-done") == 0)
	{	

	}
	else if (strcmp(argv[1], "list") == 0)
	{	
		std::string option;
		
		if (argc == 3)
		{
			if (strcmp(argv[2], "done") == 0 || strcmp(argv[2], "todo") == 0 || strcmp(argv[2], "in-progress") == 0)
			{
				option = argv[2];
			}
			else {
				std::cout << "Incorrect format for the current option.\nSee help message for correct format." << std::endl;
				return 1;
			}
		} 
		else if (argc == 2) option = "all";
		else {
			std::cout << "Incorrect format for the current option.\nSee help message for correct format." << std::endl;
			return 1;
		}

		view_tasks(option);
	}
	else 
	{
		std::cout << "Type " << argv[0] << " help for more information" << std::endl;
	}
}
