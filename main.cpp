#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>

//returns content of word.txt file
std::string getTextFromFile() {
    std::ifstream file("word.txt");
    if(!file.bad()) {
        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string word = buffer.str();
        
        //Prevents capital and lowercase letters from being counted as different letters
        std::transform(word.begin(), word.end(), word.begin(), 
            [](unsigned char c) {return std::tolower(c); });
        return word;
    } else {
        std::cout << "I/O error while reading" << std::endl;
        exit(0);
    }
}

//Prints out the number of occurrencies of each letter
void countLetters(const char* str) { 
    std::map<char, int> count;
    int wordLength = strlen(str);
    for(int i=0; i<wordLength; i++) {
        count[str[i]]++;
    }
    for(const auto kvp : count) {
        if(kvp.second == 1) std::cout << kvp.first << " pojawia sie raz" << std::endl;
        else std::cout << kvp.first << " pojawia sie " << kvp.second << " razy" << std::endl; 
        /*
        English translation:
            if(kvp.second == 1) std::cout << kvp.first << " occurrs" << kvp.second << " times" << std::endl;
            else std::cout << kvp.first << " occurrs" << kvp.second << " times" << std::endl;
        */
    }      
}

std::string word;

int main() {
    word = getTextFromFile();
     
    const char* wordAsCharArr; //goofy ah variable name
    wordAsCharArr = &word[0];
    countLetters(wordAsCharArr);
}
