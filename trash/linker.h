#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum ReturnStatus
{
	ERROR = -1000, OK = 0
};


struct ReturnType
{
	ReturnStatus return_status;
	int task_id;
	int no_of_tasks;
};


void print_help(std::string app_name);
void create_task(std::string task);
void view_tasks(std::string option);
void delete_task(std::string task);
void update_task(std::string task_id, std::string task);
void update_task_status(std::string status, std::string task);

std::vector<std::string> read_tasks();
std::vector<std::vector<std::string>> split_tasks(std::string option);
ReturnType validate_task_id(std::string task);
