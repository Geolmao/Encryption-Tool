#include<iostream>
#include<string>
#include"xor_cypher.h"
#include"vigenere_cipher.h"
#include"feistel_cipher.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 6)
    {
        cout<< "Usage : encryptor.exe <encrypt/decrypt> <input> <output> <algorithm> <key>\n";
        return 1;
    }
    string mode = argv[1];
    string input =argv[2]; 
    string output = argv[3];
    string alg = argv[4];
    string key = argv[5];

    if(mode == "encrypt")
    {
        if(alg =="xor")
        {
            XOR(input,output,key);
        }else if(alg == "vigenere")
        {
            VigenereEncrypt(input,output,key);
        }else if(alg == "feistel")
        {
            cout << "Running Feistel Encrytp \n";
            FeistelEncrypt(input,output,key);
        }
        else 
        {
            cout<<"Not a valid algorithm\n";
            return 1;
        }
    }
    else if(mode =="decrypt")
    {
        if(alg == "xor")
        {
            XOR(input,output,key);
        }
        else if(alg == "vigenere")
        {
            VigenereDecrypt(input,output,key);
        }
        else if(alg == "feistel")
        {
            cout << "Running FeistelDecrypt \n";
            FeistelDecrypt(input,output,key);
        }
        else{
            cout<<"Not a valid algorithm\n";
            return 1;
        }
    }
    else{
        cout <<"Unknown mode , use encrypt/decrypt\n";
        return 1;
    }

    cout<<"Operation succesful\n";
    return 0;

}