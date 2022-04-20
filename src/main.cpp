#include "laundryBackend.cpp"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    /*
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
    AVLTree AVLTree;
    
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
*/

//Read in the users file

string path = "";
cin >> path;
ifstream inputFile(path);

int n = 0;
inputFile >> n;

for (int i = 0; i < n; i++)
{
    // read in the next line and parse it into a constructor for a user node
    string name = "";
    string phone = "";
    string gatorID = "";
    string roomNum = "";

    inputFile >> gatorID;
    inputFile >> name;
    inputFile >> roomNum;
    inputFile >> phone;

    int gator1ID = stoi(gatorID);
    int roomNumber = stoi(roomNum);
    int phoneNum = stoi(phone);

    AVLTree userTree;
    // push that to the tree
    userTree.insertFromFile(userTree.getRoot(), gator1ID, name, phoneNum, roomNumber);
}


//Run the algorithms








    return 0;
}
