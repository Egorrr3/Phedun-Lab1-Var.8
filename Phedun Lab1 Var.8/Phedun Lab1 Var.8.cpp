#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
}

int countVowels(const string& word) {
    int vowelCount = 0;
    for (char c : word) {
        if (isVowel(c)) {
            vowelCount++;
        }
    }
    return vowelCount;
}

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        system("pause");
        return 1;
    }

    vector<string> words;

    string word;

    while (inputFile >> word) {
        words.push_back(word);
    }

    inputFile.close();

    if (words.empty()) {
        cout << "No words in the file." << endl;
        system("pause");
        return 0;
    }

    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());

    for (const string& word : words) {
        int vowelCount = countVowels(word);
        int consonantCount = word.size() - vowelCount;
        if (vowelCount > consonantCount) {
            cout << word << " ";
        }
    }

    cout << endl;

    system("pause");
    return 0;
}
