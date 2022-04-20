#pragma once
#include "laundryBackend.cpp"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <set>
#include <map>
using namespace std;


void thresHolds(vector<int>, vector<int>);
vector<int> comprehend(string userInput);



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
            info.at(0) = totalAverageWashing(userTree.getRoot());
            break;
        }
        case 2:
        {
            info.at(1) = totalAverageDrying(userTree.getRoot());
            break;
        }
        case 3:
        {
            //User average washing

            //Get the gatorID of the user you want to find
            int userToFind = commands.at(1);

            //Get all of the nodes in the tree
            vector<AVLTree::UserNode*> nodes = userTree.inorderTraversal(userTree.getRoot(), 0);
            AVLTree::UserNode* userToCalc = nullptr;

            //find the node that you want to calculate if it exists;
            for (int i = 0; i < nodes.size(); i++)
            {
                if(nodes.at(i)->getGator1ID() == userToFind)
                {
                    userToCalc = nodes.at(i);
                }
            }
            if(userToCalc != nullptr)
            {
                userToCalc->setWashAverage(userToCalc->userAverageWashing(userToCalc));
            }
            else
            {
                cout << "ERRRIRRRAGJKRGkenrgvabjlaejlaj" <<endl;
            }
            
            break;
        }

        case 4:
        {
            //User average drying

            //Get the gatorID of the user you want to find
            int userToFind = commands.at(1);

            //Get all of the nodes in the tree
            vector<AVLTree::UserNode*> nodes = userTree.inorderTraversal(userTree.getRoot(), 0);
            AVLTree::UserNode* userToCalc = nullptr;

            //find the node that you want to calculate if it exists;
            for (int i = 0; i < nodes.size(); i++)
            {
                if(nodes.at(i)->getGator1ID() == userToFind)
                {
                    userToCalc = nodes.at(i);
                }
            }
            if(userToCalc != nullptr)
            {
                userToCalc->setDryAverage(userToCalc->userAverageDrying(userToCalc));
            }
            else
            {
                cout << "ERRRIRRRAGJKRGkenrgvabjlaejlaj" <<endl;
            }
            break;
        }
        case 5:
        {
            vector<int> washingTimes = inorderTraversalWashingTimes(userTree.getRoot());
            vector<int> dryingTimes = inorderTraversalDrying(userTree.getRoot());

            thresHolds(washingTimes, dryingTimes);
            break;
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

    return {};
}

void thresHolds(vector<int> washing, vector<int> drying)
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

