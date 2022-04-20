#include "Gator AVL.cpp"
#include "iostream"
#include <regex>
#include <string>
using namespace std;

void thresHolds(vector<double>, vector<double>);



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
    return 0;
}

void thresHolds(vector<double> washing, vector<double> drying)
{
      ///24 hours ==bad
    //Green 2 hrs
    //Yellow 4 hrs
    //Red >4 hrs
    double dryingT, washingT;
    for(int i=0; i<washing.size();i++)
    {
        dryingT=dryingT+washing.at(i);
    }
    for(int i=0; i<drying.size();i++)
    {
        washingT=washingT+drying.at(i);
    }
    double avg= (dryingT+washingT)/(washing.size()+drying.size());
    //drying
    if(dryingT<=2.0)
    {
        cout<<"Total Average Dryer use time is within GREEN threshold";
    }
    if(dryingT>2.0&&dryingT<=4.0)
    {
        cout<<"Total Average Dryer use time is within YELLOW threshold";
    }
    if(dryingT>4.0)
    {
        cout<<"Total Average Dryer use time is within RED threshold";
    }
    //washing
    if(washingT<=2.0)
    {
        cout<<"Total Average Washing use time is within GREEN threshold";
    }
    if(washingT>2.0&&washingT<=4.0)
    {
        cout<<"Total Average Washing use time is within YELLOW threshold";
    }
    if(washingT>4.0)
    {
        cout<<"Total Average Washing use time is within RED threshold";
    }


    if(avg<=2.0)
    {
        cout<<"Total Average use time is within GREEN threshold";
    }
    if(avg>2.0&&avg<=4.0)
    {
        cout<<"Total Average use time is within YELLOW threshold";
    }
    if(avg>4.0)
    {
        cout<<"Total Average use time is within RED threshold";
    }
    


    ///will code in after deciding on final threshold/data stuff
}
