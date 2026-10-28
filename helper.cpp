#include "linker.h"

std::vector<std::string> read_tasks()
{
	std::ifstream File(".tasks");
	if (!File.is_open())
	{
		std::ofstream File(".tasks");
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
