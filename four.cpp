#include <iostream>
#include <vector>
using namespace std;

string decrypt(string cipher)
{
    int total = cipher.length();
    int half = total / 2;

    string v1 = cipher.substr(0, half);
    string v2 = cipher.substr(half);

    string ans = "";

    for(int i = 0; i < half; i++)
    {
        if(v1[i] != '_')
            ans.push_back(v1[i]);
        if(v2[i] != '_')
            ans.push_back(v2[i]);
    }

    return ans;
}

int main()
{
    string str;

    cout << "Enter the message without space: ";
    cin >> str;

    vector<string> vec;
    string v1, v2;

    for(int i = 0; i < str.size(); i++)
    {
        if(i % 2 == 0)
            v1.push_back(str[i]);
        else
            v2.push_back(str[i]);
    }

    // Padding to make both parts equal
    while(v2.size() < v1.size())
    {
        v2.push_back('_');
    }

    vec.push_back(v1);
    vec.push_back(v2);

    string cipher = vec[0] + vec[1];

    cout << "You entered Plain Text - " << str << endl;
    cout << "Encrypted text is - " << cipher << endl;

    string decrypted = decrypt(cipher);
    cout << "Decrypted text is - " << decrypted << endl;

    return 0;
}