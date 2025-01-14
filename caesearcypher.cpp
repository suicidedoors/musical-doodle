#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

string caesarCipher(string text, int shift);
string openFile(const string& fileName);

int main() {
    string filename;
    int shift;

    cout << "file name: ";
    getline(cin, filename);
    cout << "shift: ";
    cin >> shift;

    string text = openFile(filename);
    cout << caesarCipher(text, shift) << endl;

    return 0;
}


string openFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }

    string text;
    char c;
    while (file.get(c)) {
        text += c;
    }

    return text;
}

string caesarCipher(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char start = islower(c) ? 'a' : 'A';
            result += char((c - start + shift + 26) % 26 + start);
        } else {
            result += c;
        }
    }
    return result;
}

