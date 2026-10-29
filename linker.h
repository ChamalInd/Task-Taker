#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void print_help(std::string app_name);
void create_task(std::string task);
void view_tasks(std::string option);
void delete_task(std::string task);
void update_task(std::string task_id, std::string task);

std::vector<std::string> read_tasks();
std::vector<std::vector<std::string>> split_tasks(std::string option);

