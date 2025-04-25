#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 1000

void correct_sentence(char ss[]);
int count_words(const char ss[]);
void word_frequency(const char ss[]);
void replaceWord(char* ss, const std::string& oldWord, const std::string& newWord);

int main() {
    char iswrong_sentence[N];

    std::cout << "Enter a sentence or paragraph:\n";
    fgets(iswrong_sentence, N, stdin);  // Safer than gets()

    correct_sentence(iswrong_sentence);

    puts("\nCorrected Sentence:");
    puts(iswrong_sentence);

    // Count the words
    int word_count = count_words(iswrong_sentence);
    printf("\nWord count: %d\n", word_count);

    // Count and print the word frequencies
    word_frequency(iswrong_sentence);

    // Word replacement
    std::string oldWord, newWord;
    std::cout << "\nEnter a word to replace: ";
    std::cin >> oldWord;
    std::cout << "Enter the new word: ";
    std::cin >> newWord;

    replaceWord(iswrong_sentence, oldWord, newWord);

    std::cout << "\nUpdated Paragraph:\n" << iswrong_sentence << std::endl;

    return 0;
}

void correct_sentence(char ss[]) {
    int i = 0, j = 0;
    char temp[N];

    // Remove unwanted characters and build cleaned string
    while (ss[i] != '\0') {
        if (isalnum(ss[i]) || isspace(ss[i]) || ss[i] == ',' || ss[i] == '.') {
            temp[j++] = ss[i];
        }
        i++;
    }
    temp[j] = '\0';

    // Copy cleaned string back to original
    strcpy(ss, temp);

    // Capitalize the first letter
    if (ss[0] >= 'a' && ss[0] <= 'z') {
        ss[0] -= 32;
    }

    // Convert the rest to lowercase
    for (i = 1; ss[i] != '\0'; i++) {
        if (ss[i] >= 'A' && ss[i] <= 'Z') {
            ss[i] += 32;
        }
    }
}

int count_words(const char ss[]) {
    int count = 0;
    bool in_word = false;

    for (int i = 0; ss[i] != '\0'; i++) {
        if (isspace(ss[i]) || ss[i] == ',' || ss[i] == '.') {
            if (in_word) {
                in_word = false;
                count++;
            }
        } else {
            in_word = true;
        }
    }

    if (in_word) {
        count++;
    }

    return count;
}

void word_frequency(const char ss[]) {
    std::istringstream stream(ss);
    std::map<std::string, int> frequency;
    std::string word;

    while (stream >> word) {
        // Remove punctuation from word
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); }), word.end());
        // Convert to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        ++frequency[word];
    }

    std::cout << "\nWord frequencies:\n";
    for (const auto& entry : frequency) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}

void replaceWord(char* ss, const std::string& oldWord, const std::string& newWord) {
    std::string str(ss);
    size_t pos = 0;

    while ((pos = str.find(oldWord, pos)) != std::string::npos) {
        str.replace(pos, oldWord.length(), "<" + newWord + ">");
        pos += newWord.length() + 2; // account for < and >
    }

    strcpy(ss, str.c_str());
}
