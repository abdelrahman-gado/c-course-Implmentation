#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


int main() 
{
    char alphabet[] {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char key[] {"XZNLWEBGJHQDYVTKFUOMPICASRxznlwebgjhqdyvtkfuompciasr"};
    
    int alphabet_length = strlen(alphabet);
    size_t key_length = strlen(key);
    
    cout << "Enter your secret message: ";
    char secret_message[200] {};
    cin.getline(secret_message, 200);
    
    cout << "Encrypting message..." << endl << endl;
    
    unsigned int secret_message_length {strlen(secret_message)};
    
    char encrypted_message[200] {};
    for (unsigned int j {0}; j < secret_message_length; j++)
    {
        if (isalpha(secret_message[j]))
        {
            int index {};
            for (int i {0}; i < alphabet_length; i++)
            {
                if (secret_message[j] == alphabet[i])
                {
                    index = i;
                    break;
                }
            }
            
            encrypted_message[j] = key[index];
            
        }
        else
        {
            encrypted_message[j] = secret_message[j];
        }
    }
    
    cout << "Encrypted message: " << encrypted_message << endl << endl;
    
    cout << "Decrypting message..." << endl << endl;
    
    unsigned int encrypted_message_length {strlen(encrypted_message)};
    
    char decrypted_message[200] {};
    
    for (unsigned int j {0}; j < encrypted_message_length; j++)
    {
        if (isalpha(encrypted_message[j]))
        {
            int index {};
            for (size_t i {0}; i < key_length; i++)
            {
                if (encrypted_message[j] == key[i])
                {
                    index = i;
                    break;
                }
            }
            
            decrypted_message[j] = alphabet[index];
            
        }
        else
        {
            decrypted_message[j] = encrypted_message[j];
        }
    }
    
    cout << "Decrypted message: " << decrypted_message << endl << endl;
    
    return 0;
}