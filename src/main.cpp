#include "Gator AVL.cpp"
#include "iostream"
#include <regex>
#include <string>
using namespace std;
    
int main()
{
    //Main Variables
    stringstream userInputString;

    string userInput = "";
    string intParse = "";
    string command = " ";
    string parameters = " ";
    string Name = "";
 
    int ID = -1;
    int linesOfInput = 0;
    int removeNthNode = -1;
    GatorAVL AVLTree;
    
    //Begin Program Control Flow
    getline(cin, intParse); //get the first line of input, which should be the number of lines of input, noninclusive
    linesOfInput = stoi(intParse);
    for (int i = 0; i < linesOfInput; i++)
    {
        getline(cin, userInput); //get the ith line of input
        istringstream nextLineOfUserInputValidation(userInput); // create a string stream out of that line for validation purposes
        istringstream nextLineOfUserInput(userInput);
        if(verifyInput(nextLineOfUserInputValidation))
        {
            parseCommand(AVLTree.getTree(), nextLineOfUserInput);
        }
        else
        {
            cout << "unsuccessful" << endl;
        }
    }
    return 0;
}
