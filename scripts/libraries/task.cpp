#include "../headers/task.h"


int Task::getID()
{
	return id; 
}

std::string Task::getDescription()
{
	return description;
}

std::string Task::getStatus()
{
	return status;
}
		
void Task::setDescription(std::string& newDesc)
{
	description = newDesc;
}

void Task::setStatus(std::string& newStat)
{
	status = newStat;
}

std::string Task::convertToString()
{
	std::string newString = std::to_string(id) + "|" + description + "|" + status;
	return newString;
}

void Task::convertToTask(std::string& line)
{
	std::vector<std::string> details;
	std::string word = "";

	for (char& c : line)
	{
		if (c == '|')
		{
			details.push_back(word);
			word = "";
			continue;
		}
		word += c;
	}
	details.push_back(word);

	id = stoi(details[0]);
	description = details[1];
	status = details[2];
}

