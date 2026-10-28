#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void print_help(std::string app_name);
void create_task(std::string task);
void view_tasks(std::string option);

std::vector<std::string> read_tasks();

