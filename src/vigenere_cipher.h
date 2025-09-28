#pragma once
#include<string>


void VigenereEncrypt(const std::string& ifile, const std::string& ofile, const std::string& key );
void VigenereDecrypt(const std::string& ifile , const std::string& ofile, const std::string& key);