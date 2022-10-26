#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <list>
#include <sstream>
using namespace std;


void display() {
    cout << "-------------------------" << endl;
    cout << "|               }         " << endl;
    cout << "|               O         " << endl;
    cout << "|               |         " << endl;
    cout << "|             / | \\       " << endl;
    cout << "|            /  |  \\       " << endl;
    cout << "|              / \\       " << endl;
    cout << "|             /   \\       " << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "-----------" << endl;
}



int main(int argc, const char * argv[]) {
    
    // list of words
    string words [] = {"awkward", "buffalo", "flopping", "haphazard", "jaywalk", "jogging", "microwave", "transgress", "whiskey", "zombie"};
    
    list<string> mylist;
    for (int i = 0; i < 10; i++) {
        mylist.push_back(words[i]);
    }

    // a gallows and person

    // choose a random word in the list
    srand( static_cast<unsigned int>(time(nullptr)));
    string word = words[1 + rand() % 9];
    

    // define answer size
    string answer;
    for(int i = 0; i < word.size(); i++) {
        answer += "_";
    }
    cout << endl;cout << endl;cout << endl;
    int tries = 0;
    int correct = 0;
    int incorrect = 0;
    char guess;
    system("clear");
    cout << "Welcome to the Hangman !!!!" << endl;
    while(true) {
        
        display();

        cout << "There are " << word.size() << " letters in the word" << endl;
        cout << answer << endl;
        
        cout << "Guess a word: ";
        cin >> guess;
        int a = 0;
        if (word != answer) {
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == guess) {
                    answer[i] = guess;
                    a = 1;
                }
            }
        
            if (a == 1) {
                correct += a;
            }
            
            cout << answer;
            cout << endl;
            cout << endl;
            tries += 1;
            if (answer == word) {
                incorrect = tries - correct;
                system("clear");
                display();
                cout << answer << endl;
                cout << "Congrat! You got the answer!!" << endl;
                cout << "You tries " << tries << " times and correct: " << correct << " incorrect: "<< incorrect<< endl;
                tries = 0;
                correct = 0;
                incorrect = 0;
                string ans;
                cout << "Do you want to play more? (y/n)";
                cin >> ans;
                if (ans == "y" || ans == "Y") {
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    srand( static_cast<unsigned int>(time(nullptr)));
                    word = words[1 + rand() % 9];
                    cout << word << endl;
                    answer = "";
                    for(int i = 0; i < word.size(); i++) {
                        answer += "_";
                    }
                }
                else {
                    cout << "Thank you for playing!" << endl;
                    return true;
                }
            }
        }
        system("clear");
        }
        
    
    return 0;
}
