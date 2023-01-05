/* Online C++ Compiler and Editor */
#include <iostream>
#include<stdlib.h>
#include<Windows.h>
#include<iterator>
#include<vector>
#include<random>
#include<ctime>
#include<fstream>
void swap(int* a, int* b);
void draw_Game(int errorNum);
bool find(std::string word, char simbol);
void printFilledWord(std::string word, int* indexs, int N);
bool findInVector(std::vector<char> vc, char simbol);
void printUsedChars(std::vector<char> vc) {
    std::cout << "\nused characters: ";
    std::vector<char>::iterator it;
    for (it = vc.begin(); it != vc.end(); it++) {
        std::cout << " " << *it << " ";
    }
    std::cout << "\n";
}
int main()
{
     srand(time(nullptr));
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once
    int N =12, i;
    int guinds = 0;
    std::vector<char> usedChars;
    int errorNum = 0;
    std::string character = "";
    std::string::iterator it;
    std::ifstream ifs("words.txt");
    std::cout << "please how much word do you want to fill?:\n";
    std::string* words = new std::string[N];
    int* GuessIndex = new int[N];
    for (i = 0; i < N; i++)
    {
        ifs>> words[i];
    }
    int randIndex = rand() % (N - 1);
    std::string chWord = words[randIndex];
    while (true) {
        std::cout << "\n";
        std::cout << "\nplease Enter  character: ";
        std::cin >> character;
        if (character.size() > 1) {
            std::cout << "!!!you must Enter character not string!!!\n";
        }
        else {

            if (findInVector(usedChars, character[0])) {
                std::cout << "\n   this caracter is already used!\n";
                continue;

            }
            else
                if (!find(chWord, character[0]) && !findInVector(usedChars , character[0])) {
                ++errorNum;
            }
            else {
                    for (int it = 0;  it < chWord.length(); it++) {
                    if (chWord[it] == character[0] && !findInVector(usedChars, character[0]))
                    {
                        if (chWord.length() == guinds) return 0;
                        GuessIndex[guinds] = it;
                        ++guinds;
                    }
                }
                printFilledWord(chWord, GuessIndex, guinds);
                printUsedChars(usedChars);
            }
        }
        if((guinds+2)== chWord.length()) {
            std::cout << "you won game!\n";
            system("pause");
            return 0;
        }
        draw_Game(errorNum);
        if (errorNum == 6) { 
            system("pause");
            return 0;
        }
    }
    return 0; 
}
void printFilledWord(std::string word, int* indexs, int N) {
    std::string::iterator it;
    std::cout << "\nin printfiled function "<<N<<" f  \n";
    for (int i = 0; i < N + 1; i++)
    {
        std::cout << "\nit's opened\n";
        std::cout << indexs[i];
        std::cout << word[indexs[i]];
    }
    std::cout << "\n";
}
void draw_Game(int errorNum) {
    if (errorNum == 0) {
        std::cout << "startGame!";
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
        if (*it == simbol)return true;
    }
    return false;
}
bool findInVector(std::vector<char> vc , char simbol) {
        std::vector<char>::iterator it;
    for (it = vc.begin(); it != vc.end(); it++) {
        if (vc[*it] == simbol)return true;
    }
    return false;

}