#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"vigenere_cipher.h"
#include"Utils.h"

using namespace std;

void VigenereEncrypt(const string& ifile, const string& ofile, const string& key ){
    vector<char> data= ReadFile(ifile);
    
    for(size_t i = 0; i < data.size(); i++){
        unsigned char k = static_cast<unsigned char>(key[i % key.size()]);
        data[i] = static_cast<unsigned char>((data[i] + k) % 256);
    }

    WriteFile(ofile,data);
}

void VigenereDecrypt(const string& ifile , const string& ofile, const string& key){
    vector<char> data = ReadFile(ifile);

    for(size_t i = 0; i< data.size() ; i++){
        unsigned char k = static_cast<unsigned char>(key[i % key.size()]);
        data[i] = static_cast<unsigned char>((data[i] - k + 256) % 256);
    }

    WriteFile(ofile,data);
}