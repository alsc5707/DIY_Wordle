#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <cctype>
using namespace std;
void header();
int checkWord(string);
void display(int);
void loseScreen();
void winScreen();
int line = 0;
bool win = false;
string guess;
string wordBank[] = {
"abroad"	,"casual"	,"around"	,"couple",
"accept"	,"caught"	,"arrive"	,"course",
"access"	,"centre"	,"artist"	,"covers",
"across"	,"centum"	,"aspect"	,"create",
"acting"	,"chance"	,"assess"	,"credit",
"action"	,"change"	,"assist"	,"crisis",
"active"	,"charge"	,"assume"	,"custom",
"actual"	,"choice"	,"attack"	,"damage",
"advice"	,"choose"	,"attend"	,"danger",
"advise"	,"chosen"	,"august"	,"dealer",
"affect"	,"church"	,"author"	,"debate",
"afford"	,"circle"	,"avenue"	,"decade",
"afraid"	,"client"	,"backed"	,"decide",
"agency"	,"closed"	,"barely"	,"defeat",
"agenda"	,"closer"	,"battle"	,"defend",
"almost"	,"coffee"	,"beauty"	,"define",
"always"	,"column"	,"became"	,"degree",
"amount"	,"combat"	,"become"	,"demand",
"animal"	,"coming"	,"before"	,"depend",
"annual"	,"common"	,"behalf"	,"deputy",
"answer"	,"comply"	,"behind"	,"desert",
"anyone"	,"copper"	,"belief"	,"design",
"anyway"	,"corner"	,"belong"	,"desire",
"appeal"	,"costly"	,"beaker"	,"detail",
"appear"	,"county"	,"better"	,"detect",
"beyond"	,"budget"	,"during"	,"device",
"bishop"	,"burden"	,"easily"	,"differ",
"border"	,"bureau"	,"eating"	,"dinner",
"bottle"	,"button"	,"editor"	,"direct",
"bottom"	,"camera"	,"effect"	,"doctor",
"bought"	,"cancer"	,"effort"	,"dollar",
"branch"	,"cactus"	,"eighth"	,"domain",
"breath"	,"carbon"	,"either"	,"double",
"bridge"	,"career"	,"eleven"	,"driven",
"bright"	,"castle"	,"emerge"	,"driver"
};
int arrSize = sizeof(wordBank)/sizeof(wordBank[0]);
string word = " ";
string displayWord[6][6] = {
{" "," "," "," "," "," "},
{" "," "," "," "," "," "},
{" "," "," "," "," "," "},
{" "," "," "," "," "," "},
{" "," "," "," "," "," "},
{" "," "," "," "," "," "},
};
bool l1 = false;
bool l2 = false;
bool l3 = false;
bool l4 = false;
bool l5 = false;
bool l6 = false;
string finalWord2;
string finalWord3;
string finalWord4;
string finalWord5;
string finalWord6;
string finalWord;
int valid;
int var;
int start = 0;
void game(int);
void randWord();
int main (){
    var = 0;
    if (var == 0){
        randWord();
    }
    header();
    cout << endl;
    game(0);
}
void randWord(){
    srand(time(0));
    int len = *(&wordBank + 1) - wordBank;
    int wordNum = rand() % len;
    word = wordBank[wordNum];
    var = 1;
}
void game(int line){
    guess = " ";
    cin >> guess;
    checkWord(guess);
    if (valid == 1){
        display(line);
    } else {
        system("clear");
        header();
        display(line - 1);
        game(line - 1);
    }
}
void header(){
    system("clear");
    cout << "-------------------------------" << endl;
    cout << "        6 Letter Wordle        " << endl;
    cout << " Letters Will Display if Right " << endl;
    cout << "        Guess the Word!        " << endl;
    cout << "-------------------------------" << endl;
    if (start == 0){
        finalWord = "      >|" + displayWord[0][0] + "|" + displayWord[1][0] + "|" + displayWord[2][0] + "|" + displayWord[3][0] + "|" + displayWord[4][0] + "|" + displayWord[5][0] + "|" + "\n" +
                    "       |" + displayWord[0][1] + "|" + displayWord[1][1] + "|" + displayWord[2][1] + "|" + displayWord[3][1] + "|" + displayWord[4][1] + "|" + displayWord[5][1] + "|" + "\n" +
                    "       |" + displayWord[0][2] + "|" + displayWord[1][2] + "|" + displayWord[2][2] + "|" + displayWord[3][2] + "|" + displayWord[4][2] + "|" + displayWord[5][2] + "|" + "\n" +
                    "       |" + displayWord[0][3] + "|" + displayWord[1][3] + "|" + displayWord[2][3] + "|" + displayWord[3][3] + "|" + displayWord[4][3] + "|" + displayWord[5][3] + "|" + "\n" +
                    "       |" + displayWord[0][4] + "|" + displayWord[1][4] + "|" + displayWord[2][4] + "|" + displayWord[3][4] + "|" + displayWord[4][4] + "|" + displayWord[5][4] + "|" + "\n" +
                    "       |" + displayWord[0][5] + "|" + displayWord[1][5] + "|" + displayWord[2][5] + "|" + displayWord[3][5] + "|" + displayWord[4][5] + "|" + displayWord[5][5] + "|";
        cout << finalWord + "\n" << endl << endl;
        start += 1;
    }
    
}

int checkWord(string guess){
    if (guess.length() == 6){
        valid = 1;
        if (guess == word){
            win = true;
        } else {
            l1 = false;
            l2 = false;
            l3 = false;
            l4 = false;
            l5 = false;
            l6 = false;
            if (guess[0] == word[0]){
                l1 = true;
            }
            if (guess[1] == word[1]){
                l2 = true;
            }
            if (guess[2] == word[2]){
                l3 = true;
            }
            if (guess[3] == word[3]){
                l4 = true;
            }
            if (guess[4] == word[4]){
                l5 = true;
            }
            if (guess[5] == word[5]){
                l6 = true;
            }
        }
    } else if (guess.length() < 6) {
        valid = 0;
    } else if (guess.length() > 6) {
        valid = 0;
    } else {
        valid = 0;
    }
    return valid;
}
//string displayWord[] , l1-6 
void display(int line){
    if (win == true){
        winScreen();
    } else {
        /*
        for (int i = 0; i >6; i++){
            displayWord[0][line] = " ";
            displayWord[1][line] = " ";
            displayWord[2][line] = " ";
            displayWord[3][line] = " ";
            displayWord[4][line] = " ";
            displayWord[5][line] = " ";

        }qert
        */
        if (l1 == true){
            displayWord[0][line] = word[0];
        }
        if (l2 == true){
            displayWord[1][line] = word[1];
        }
        if (l3 == true){
            displayWord[2][line] = word[2];
        }
        if (l4 == true){
            displayWord[3][line] = word[3];
        }
        if (l5 == true){
            displayWord[4][line] = word[4];
        }
        if (l6 == true){
            displayWord[5][line] = word[5];
        }
        string ar1 = " ";
        string ar2 = " ";
        string ar3 = " ";
        string ar4 = " ";
        string ar5 = " ";
        string ar6 = " ";
        switch (line){
            case 0:
                ar2 = ">";
                break;
            case 1:
                ar3 = ">";
                break;
            case 2:
                ar4 = ">";
                break;
            case 3:
                ar5 = ">";
                break;
            case 4:
                ar6 = ">";
                break;
            case 5:
                ar6 = ">";
                break;
            default:
                ar1 = ">";
        }
        finalWord = "       " + ar1 + "|" + displayWord[0][0] + "|" + displayWord[1][0] + "|" + displayWord[2][0] + "|" + displayWord[3][0] + "|" + displayWord[4][0] + "|" + displayWord[5][0] + "|" + "\n" +
                    "       " + ar2 + "|" + displayWord[0][1] + "|" + displayWord[1][1] + "|" + displayWord[2][1] + "|" + displayWord[3][1] + "|" + displayWord[4][1] + "|" + displayWord[5][1] + "|" + "\n" +
                    "       " + ar3 + "|" + displayWord[0][2] + "|" + displayWord[1][2] + "|" + displayWord[2][2] + "|" + displayWord[3][2] + "|" + displayWord[4][2] + "|" + displayWord[5][2] + "|" + "\n" +
                    "       " + ar4 + "|" + displayWord[0][3] + "|" + displayWord[1][3] + "|" + displayWord[2][3] + "|" + displayWord[3][3] + "|" + displayWord[4][3] + "|" + displayWord[5][3] + "|" + "\n" +
                    "       " + ar5 + "|" + displayWord[0][4] + "|" + displayWord[1][4] + "|" + displayWord[2][4] + "|" + displayWord[3][4] + "|" + displayWord[4][4] + "|" + displayWord[5][4] + "|" + "\n" +
                    "       " + ar6 + "|" + displayWord[0][5] + "|" + displayWord[1][5] + "|" + displayWord[2][5] + "|" + displayWord[3][5] + "|" + displayWord[4][5] + "|" + displayWord[5][5] + "|";
        system("clear");
        cout << line << endl;

        header();
        cout << finalWord + "\n" << endl << endl;
        line +=  1;
        if (line == 6){
            loseScreen();
            exit(0);
        }
        //tests
        
        cout << line<< endl;
        /*
        cout << word[2];
        cout << l1;
        cout << l2;
        cout << l3;
        cout << l4;
        cout << l5;
        cout << l6;
        */
        //
        game(line);
    }
}


//end game conditions, fix wrong # of letters, maybe change colors?
void winScreen(){
    system("clear");
    cout << "-------------------------------" << endl;
    cout << "        6 Letter Wordle        " << endl;
    cout << "       You got the Word!       " << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << "   The word was: " << word << "   " << endl;
    cout << endl;
}

void loseScreen(){
    system("clear");
    cout << "-------------------------------" << endl;
    cout << "        6 Letter Wordle        " << endl;
    cout << "           You Lost!           " << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << "   The word was: " << word << "   " << endl;
    cout << endl;
}