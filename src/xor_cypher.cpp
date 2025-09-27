#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Utils.h"
#include"xor_cypher.h"

using namespace std;

void XOR(const string& ifile , const string& ofile , const string& key){
    vector<char> data = ReadFile(ifile);

    for(size_t i= 0; i< data.size(); i++)
    {
        data[i]^= key[i % key.size()];
    }

    WriteFile(ofile,data);

}