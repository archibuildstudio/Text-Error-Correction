#include<stdio.h>
#include<string.h>
#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<string>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000
void correct_sentence(char ss[]);
int count_words(const char ss[]);
void word_frequency(const char ss[]);
 void replaceWord(char* ss, const std:: string& oldWord, const std::string& newWord);
int main(){
    char iswrong_sentence[N];
    gets(iswrong_sentence);
    correct_sentence(iswrong_sentence);
    puts(" ");
    puts(iswrong_sentence);
    puts(" ");


    //count the words
    int word_count = count_words(iswrong_sentence);
    printf("Word count: %d\n", word_count);

    //count and print the word frequencies
    word_frequency(iswrong_sentence);

    //Word replacement
    std::string oldWord, newWord;
    std::cout << "\nEnter a word to replace: ";
    std::cin >> oldWord;
    std::cout << "Enter the new word: ";
    std::cin >> newWord;

    replaceWord(iswrong_sentence, oldWord, newWord);

    std::cout << "\nUpdated Paragraph:\n" << iswrong_sentence << std::endl;

    return 0;
}
void correct_sentence(char ss[]){
    int i=0;
    int j=0;
    char temp[N];


    //converting the first letter to uppercase if its a lower case
    if (ss[0]>='a' && ss[0]<='z'){
        ss[0]=ss[0]-32;

    // remove special characters except for 'space', 'commas', and periods
        while (ss[i]!='\0'){
            if(isalnum(ss[i]) || isspace(ss[i]) || ss[i]==',' || ss[i]=='.'){
                temp[j++]=ss[i];}
            i++;
    }
    temp[j]='\0'; // terminate the temporary string

    //copying the clean string to the original
    strcpy(ss,temp);}

    //converting the rest of the string to lowercase if it is in uppercase
    else{
        for (i=1;ss[i]!='\0';i++){
            if(ss[i]>='A' && ss[i]<='Z'){
                ss[i]=ss[i]+32;}}
           }}

    //count the words in the paragraph
    int count_words(const char ss[]){
        int count=0;
        bool in_word = false;

        for (int i =0;ss[i]!='\0';i++){
                if(isspace(ss[i]) || ss[i]==',' || ss[i]=='.'){
                    if (in_word){
                        in_word=false;
                        count++;
                    }
                }
                else{
                    in_word = true;
                }
        }
        if (in_word){
            count++;
        }
        return count;
        }
void word_frequency(const char ss[]){
    std::istringstream stream(ss);  // Create a string stream from the input string
    std::map<std::string, int> frequency;  // Create a map to store word frequencies
    std::string word;

    while (stream >> word) {  // Read each word from the stream
        // Remove punctuation from the word
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); }), word.end());

        // Convert word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        ++frequency[word];  // Increment the frequency count for the word
    }

    // Output the word frequencies
    std::cout << "Word frequencies:\n";
    for (const auto &entry : frequency) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }}

    //find the old word and replace it with the new word
    void replaceWord(char* ss, const std:: string& oldWord, const std::string& newWord){
     std::string str(ss);
    size_t pos = 0;
    while ((pos = str.find(oldWord, pos)) != std::string::npos) {
    //Replace the word with the new word wrapped in the underline tags
        str.replace(pos, oldWord.length(), "<" + newWord + ">");
        pos += newWord.length();
    }
    //copy the modified string back to the original character array
    strcpy(ss, str.c_str());
}
