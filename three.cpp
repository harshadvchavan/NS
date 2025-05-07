// exp - 3

#include <iostream>
#include <string>
using namespace std;

string encryption(string text, int key)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
            continue;

        if (islower(text[i]))
            text[i] = char((text[i] - 'a' + key) % 26 + 'a');
        else if (isupper(text[i]))
            text[i] = char((text[i] - 'A' + key) % 26 + 'A');
    }
    return text;
}

string decryption(string text, int key)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
            continue;

        if (islower(text[i]))
            text[i] = char((text[i] - 'a' - key + 26) % 26 + 'a');
        else if (isupper(text[i]))
            text[i] = char((text[i] - 'A' - key + 26) % 26 + 'A');
    }
    return text;
}

int main()
{
    int key;
    cout << "Enter key: ";
    cin >> key;
    cin.ignore(); // clear input buffer

    string plaintext;
    cout << "Enter sentence: ";
    getline(cin, plaintext);

    string ciphertext = encryption(plaintext, key);
    string decrypted = decryption(ciphertext, key);

    cout << "Plain Text: " << plaintext << endl;
    cout << "Cipher Text: " << ciphertext << endl;
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}