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

	}
	else if (strcmp(argv[1], "delete") == 0)
	{	

	}
	else if (strcmp(argv[1], "mark-in-progress") == 0)
	{	

	}
	else if (strcmp(argv[1], "mark-done") == 0)
	{	

	}
	else if (strcmp(argv[1], "list") == 0)
	{	

	}
	else 
	{
		std::cout << "Type " << argv[0] << " help for more information" << std::endl;
	}
}
