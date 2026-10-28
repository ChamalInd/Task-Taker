#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void print_help(std::string app_name);
void create_task(std::string task);

std::vector<std::string> read_tasks();

