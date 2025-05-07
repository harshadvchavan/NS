// exp-2 code

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Global key and its column order (manually defined)
string key = "MEGABUCK";
vector<int> vec = {7, 4, 5, 1, 2, 8, 3, 6}; // Based on alphabetical order of key

// Function to encrypt a message
string encrypt(string message) {
    int keyLen = key.length();
    vector<vector<char>> matrix;
    vector<char> row;
    
    // Fill the matrix row-wise
    for (int i = 0; i < message.length(); i++) {
        row.push_back(message[i]);
        if (row.size() == keyLen) {
            matrix.push_back(row);
            row.clear();
        }
    }

    // Pad the last row if needed
    if (!row.empty()) {
        while (row.size() < keyLen)
            row.push_back('_');
        matrix.push_back(row);
    }

    // Create the encrypted message by reading column-wise
    map<int, string> columnMap;
    int rows = matrix.size();

    for (int i = 0; i < vec.size(); i++) {
        int col = i;
        for (int r = 0; r < rows; r++) {
            columnMap[vec[i]].push_back(matrix[r][col]);
        }
    }

    // Concatenate columns in key order
    string encrypted = "";
    for (auto col : columnMap) {
        encrypted += col.second;
    }

    return encrypted;
}

// Function to decrypt a message
string decrypt(string encrypted) {
    int keyLen = key.length();
    int rows = encrypted.length() / keyLen;

    map<int, string> columnMap;
    int pos = 0;

    // Reconstruct columns by known key order
    for (int i = 1; i <= keyLen; i++) {
        for (int j = 0; j < keyLen; j++) {
            if (vec[j] == i) {
                columnMap[j] = encrypted.substr(pos, rows);
                pos += rows;
                break;
            }
        }
    }

    // Rebuild matrix row-wise
    vector<vector<char>> matrix(rows, vector<char>(keyLen));
    for (int c = 0; c < keyLen; c++) {
        string col = columnMap[c];
        for (int r = 0; r < rows; r++) {
            matrix[r][c] = col[r];
        }
    }

    // Read row-wise to get decrypted message
    string decrypted = "";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < keyLen; c++) {
            if (matrix[r][c] != '_')
                decrypted += matrix[r][c];
        }
    }

    return decrypted;
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n=== Columnar Transposition Cipher ===\n";
        cout << "Key: " << key << endl;
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter message to encrypt (no spaces): ";
            cin >> input;
            cout << "Encrypted Message: " << encrypt(input) << endl;
            break;

        case 2:
            cout << "Enter encrypted message: ";
            cin >> input;
            cout << "Decrypted Message: " << decrypt(input) << endl;
            break;

        case 3:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 3);

    return 0;
}