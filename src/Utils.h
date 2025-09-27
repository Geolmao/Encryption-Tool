#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

std::vector<char> ReadFile(const std::string& filepath);

void WriteFile(const std::string& filepath, const std::vector<char>& data);