#include "laundryBackend.cpp"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    //Read in the users file

    string path = "";
    cin >> path;
    ifstream inputFile(path);

    int n = 0;
    inputFile >> n;
    AVLTree userTree;
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

        
        // push that to the tree
        userTree.insertFromFile(userTree.getRoot(), gator1ID, name, phoneNum, roomNumber);
    }

    //Main Variables
    string userInput = "";
    bool running = true;
    vector<double> info(5, 0.0);
    while (running)
    {
        cin >> userInput;
        vector<int> commands = comprehend(userInput);
        int command = commands.at(0);
        switch (command)
        {
        case 1:
        {
            info.at(0) = totalAverageWashing(*userTree.getRoot());
            break;
        }
        case 2:
        {
            info.at(1) = totalAverageDrying(*userTree.getRoot());
            break;
        }
        case 3:
        {
            //User average washing
            int userToFind = commands.at(1);
            vector<AVLTree::UserNode*> nodes = userTree.inorderTraversal(userTree.getRoot(), 0);
            AVLTree::UserNode* userToCalc;

            for (int i = 0; i < nodes.size(); i++)
            {
                if(nodes.at(i)->getGator1ID() == userToFind)
                {
                    userToCalc = nodes.at(i);
                }
            }

            userToCalc->userAverageWashing(userToCalc);
            
        }




        default:
            break;
        }



    }


    



//Run the algorithms

    return 0;
}


vector<int> comprehend(string userInput)
{
    if(userInput == "Wash average")
    {
        return {1};
    }
    if(userInput == "Dry average")
    {
        return {2};
    }
    if(userInput == "Wash average - user")
    {
        int userToFind = 0;
        cin >> userToFind;
        return {3, userToFind};
        
    }
    if(userInput == "Dry average - user")
    {
        int userToFind = 0;
        cin >> userToFind;
        return {4, userToFind};
    }
    if(userInput == "Thresholds")
    {
        return {5};
    }

}