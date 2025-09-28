#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include "Utils.h"
#include"feistel_cipher.h"

using namespace std;

char RoundF(char c , char k)
{
    return c ^ k;
}

vector<char> SubKeyGen(const string&masterKey , int rounds){
    vector<char> subkeys(rounds);
    for(int i = 0 ; i < rounds; i++)
    {
        char k = 0;
        for(char c : masterKey)
        {
            k+=c;
        }
        subkeys[i] = static_cast<char>((k+i)% 256);

    }
    return subkeys;
}

void FeistelEncrypt(const string& ifile, const string& ofile, const string& key) {
    vector<char> data = ReadFile(ifile);

    size_t half = data.size() / 2;
    bool padded = false;

    if (data.size() % 2 != 0) {
        data.push_back(0);  
        padded = true;
        half = data.size() / 2; 
    }

    vector<char> left(data.begin(), data.begin() + half);
    vector<char> right(data.begin() + half, data.end());
    vector<char> subKeys = SubKeyGen(key, 16);

    for (int i = 0; i < 16; i++) {
        char k = subKeys[i];
        vector<char> newLeft = right;
        vector<char> newRight(left.size());

        for (size_t j = 0; j < left.size(); j++) {
            char r = right[j % right.size()]; 
            newRight[j] = left[j] ^ RoundF(r, k);
        }

        left = newLeft;
        right = newRight;
    }

    vector<char> result;
    result.insert(result.end(), right.begin(), right.end());
    result.insert(result.end(), left.begin(), left.end());
    if (padded) 
    {
    result.pop_back();
    }
    WriteFile(ofile, result);
}

void FeistelDecrypt(const string& ifile, const string& ofile, const string& key) {
    vector<char> data = ReadFile(ifile);

   
    size_t half = data.size() / 2;
    bool padded = false;


    if (data.size() % 2 != 0) 
    {
        data.push_back(0);  
        padded = true;
        half = data.size() / 2;  
    }

vector<char> left(data.begin(), data.begin() + half);
vector<char> right(data.begin() + half, data.end());

    vector<char> subKeys = SubKeyGen(key, 16);
    reverse(subKeys.begin(), subKeys.end()); 

    for (int i = 0; i < 16; i++)
    {
        char k = subKeys[i];
        vector<char> newLeft = right;
        vector<char> newRight(left.size());

        for (size_t j = 0; j < left.size(); j++) 
        {
            char r = right[j % right.size()]; 
            newRight[j] = left[j] ^ RoundF(r, k);
        }

        left = newLeft;
        right = newRight;
    }

    vector<char> result;
    result.insert(result.end(), right.begin(), right.end());
    result.insert(result.end(), left.begin(), left.end());

    if (padded) 
    {
    result.pop_back();
    }
    WriteFile(ofile, result);
}