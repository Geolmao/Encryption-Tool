#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Utils.h"

using namespace std;

vector<char> ReadFile(const string& filepath){
    ifstream file(filepath, ios::binary);
    
    if(!file) throw runtime_error("Cannot open file");
    vector<char> buffer ((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());

    return buffer;
}

void WriteFile(const string&filepath, const vector<char>& data){
    ofstream file(filepath,ios::binary);

    if(!file) throw runtime_error("Cannt write file");
    file.write(data.data(),data.size());
}