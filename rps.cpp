#include <iostream>
#include <cstdlib>
#include "time.h"
using namespace std;

string stroll(string current, string choice1, string choice2) {
    if((choice1 == "p" && choice2 == "r") ||
       (choice1 == "r" && choice2 == "s") ||
       (choice1 == "s" && choice2 == "p")) {
        return current + " wins!";
    } else {
        return "";
    }
}
string full(string shortened) {
    if(shortened == "r") {
        return "Rock";
    } else if(shortened == "p") {
        return "Paper";
    } else if(shortened == "s") {
        return "Scissors";
    }
    return "<>";
}
int main()
{
    srand(time(0));
    
    cout << "What is your name? ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!\n\n";
    
    string cont = "y";
    
    while(cont == "y") {
        cout << "Do you pick rock, paper, or scissors? [r/p/s] ";
        string choice;
        cin >> choice;
        
        string choices[3] = { "r", "p", "s" };
        
        string cpuChoice = choices[rand() % 3];
        
        cout << "\nYou picked " + full(choice) + "\n";
        cout << "Computer picked " + full(cpuChoice) + "!\n";
        
        string result;
        
        result = stroll(name, choice, cpuChoice);
        if(result == "") {
            result = stroll("Computer", cpuChoice, choice);
        }
        if(result == "") {
            result = "It's a tie!";
        }
        cout << result + "\n\n";
        
        cout << "Wanna go again? [y/n] ";
        cin >> cont;
    }
    cout << "\nGoodbye, " + name + "!\n";
    
    return 0;
}
