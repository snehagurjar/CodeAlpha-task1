#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt the text
void encryptFile(const string &inputFileName, const string &outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Unable to open file(s)." << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Encrypt only alphabetic characters
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + key) % 26 + base;
        }
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();
    cout << "Encryption completed. Encrypted data saved to " << outputFileName << endl;
}

// Function to decrypt the text
void decryptFile(const string &inputFileName, const string &outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Unable to open file(s)." << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Decrypt only alphabetic characters
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base - key + 26) % 26 + base; // +26 ensures the result is always positive
        }
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();
    cout << "Decryption completed. Decrypted data saved to " << outputFileName << endl;
}

int main() {
    string inputFileName, outputFileName;
    int key, choice;

    cout << "Basic File Encryption/Decryption Program\n";
    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter your choice (1/2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the name of the file to encrypt: ";
        cin >> inputFileName;
        cout << "Enter the name of the output (encrypted) file: ";
        cin >> outputFileName;
        cout << "Enter the encryption key (integer): ";
        cin >> key;

        encryptFile(inputFileName, outputFileName, key);
    } else if (choice == 2) {
        cout << "Enter the name of the file to decrypt: ";
        cin >> inputFileName;
        cout << "Enter the name of the output (decrypted) file: ";
        cin >> outputFileName;
        cout << "Enter the decryption key (integer): ";
        cin >> key;

        decryptFile(inputFileName, outputFileName, key);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
