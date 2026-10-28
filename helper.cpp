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

	return seperated_content;
}
