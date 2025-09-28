#pragma once
#include<string>
void FeistelEncrypt(const std::string& ifile , const std::string& ofile, const std::string& key);
void FeistelDecrypt(const std::string& ifile , const std::string& ofile, const std::string& key);