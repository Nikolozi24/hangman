/* Online C++ Compiler and Editor */
#include <iostream>
#include<stdlib.h>
#include<Windows.h>
#include<iterator>
#include<vector>
#include<random>
#include<ctime>
void swap(int *a , int *b);
void draw_Game(int errorNum);
bool find(std::string word, char simbol);
void printFilledWord(std::string word, int* indexs, int N);
int main()
{
   // srand(time(nullptr));
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once
    int N, i;
    int guinds=0;
    std::vector<char> usedChars;
    int errorNum = 0;
    std::string character ="";
    std::string::iterator it;
    
    std::cout << "please how much word do you want to fill?:\n";
    std::cin >> N;
    std::string* words = new std::string[N];
    int* GuessIndex = new int[N*4];
    for (i = 0; i < N; i++)
    {
        std::cout << "word[" << i << "]: ";
        std::cin >> words[i];
    }
    int randIndex = rand() % (N - 1);
    std::string chWord = words[randIndex];
    while (true){
        std::cout <<"\n";
        draw_Game(errorNum);
        std::cout << "\nplease Enter  character: ";
        std::cin >> character;
        if (character.size() > 1) {
            std::cout << "!!!you must Enter character not string!!!\n";
        }
        else {
            usedChars.push_back(character[0]);
            if (!find(chWord, character[0])) {
                ++errorNum;
             }
            else {
                for (it = chWord.begin(); it != chWord.end(); it++) {
                    if (chWord[*it] == character[0]) {
                        GuessIndex[guinds] = *(it);
                        guinds++;
                    }
                }
                printFilledWord(chWord, GuessIndex , guinds);
            }
        }
    }
    return 0;
}
void printFilledWord(std::string word, int* indexs ,int N) {
    std::string::iterator it;
    for (it = word.begin(); it != word.end(); it++) {
        for (int i = 0; i < N; i++) {
            if (indexs[i] == *it) {
                std::cout << word[*it];
                i = N + 7;
            }
            if (indexs[i] != *it && i == N) {
                std::cout << " __ ";
            }
        }
    }
    std::cout << "\n";
}
void draw_Game(int errorNum) {
    if (errorNum == 0) {
        std::cout << "\n";
    }
    if (errorNum == 1) {
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";

    }
    if (errorNum == 2) {
       std::cout << "       -------- |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";

    }
    if (errorNum == 3) {
       std::cout << "        ------- |\n";
       std::cout << "       |        |\n";
       std::cout << "       |        |\n";
       std::cout << "       O        |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";

    }
    if (errorNum == 4) {
       std::cout << "        ------- |\n";
       std::cout << "       |        |\n";
       std::cout << "       |        |\n";
       std::cout << "       O        |\n";
       std::cout << "       |        |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";

    }
    if (errorNum == 5) {
       std::cout << "        ------- |\n";
       std::cout << "       |        |\n";
       std::cout << "       |        |\n";
       std::cout << "       O        |\n";
       std::cout << "       |        |\n";
       std::cout << "      [[        |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";

    }
    if (errorNum == 6) {
       HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(color, 4);
       std::cout << "        ------- |\n";
       std::cout << "       |        |\n";
       std::cout << "       |        |\n";
       std::cout << "       O        |\n";
       std::cout << "      -|-       |\n";
       std::cout << "      [[        |\n";
       std::cout << "                |\n";
       std::cout << "      died!     |\n";
       std::cout << "                |\n";
       std::cout << "   GAME OVER!   |\n";
       std::cout << "                |\n";
       std::cout << "                |\n";

    }
}
bool find(std::string word, char simbol) {
    std::string::iterator it;
    for (it = word.begin(); it != word.end(); it++) {
        if (word[*it] == simbol)return true;
    }
    return false;
}