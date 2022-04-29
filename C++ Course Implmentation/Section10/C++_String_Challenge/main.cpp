#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main() 
{
    
    string alphabet {"[ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {" [XZNLWEBGJHQDYVTKFUOMPICASRxznlwebgjhqdyvtkfuompciasr"};
    
    cout << "Enter your secret message: ";
    string secret_message {};
    getline(cin, secret_message);
    
    cout << "Encrypting message..." << endl << endl;
    
    string encrypted_message {};
    
    for (char const& character : secret_message)
    {
        size_t index = alphabet.find(character);
        if (index != string::npos)
        {
            encrypted_message += key.at(index);
        }
        else
        {
            encrypted_message += character;
        }
    }
    
    cout << "Encrypted message: " << encrypted_message << endl << endl;
    
    cout << "Decrypting message..." << endl << endl;
    
    
    string decrypted_message {};
    
    for (char const& character : encrypted_message)
    {
        size_t index = key.find(character);
        if (index != string::npos)
        {
            decrypted_message += alphabet.at(index);
        }
        else
        {
            decrypted_message += character;
        }
    }
    
    cout << "Decrypted message: " << decrypted_message << endl << endl;
    
    return 0;
}