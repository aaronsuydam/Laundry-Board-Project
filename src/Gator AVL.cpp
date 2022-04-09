#include "Gator AVL.hpp"

//Function works for base test case.


//PSEUDOCODE FROM LECTURES WERE USED IN THE CREATION OF THIS PROJECT



GatorAVL::StudentNode* insert(GatorAVL::StudentNode* root, int Gator1ID, string NAME)
{
    bool preexisting = searchIDBool(root, Gator1ID);
    if(preexisting)
    {
        cout << "unsuccessful" << endl;
        return root;
    }
    else
    {
        GatorAVL::StudentNode* nodeToReturn = insertHelper(root, Gator1ID, NAME);
        bool found = searchIDBool(nodeToReturn, Gator1ID);
        if(found)
        {
            cout << "successful" << endl;
            return nodeToReturn;
        }
        else
        {
            cout << "unsuccessful" << endl;
            return nodeToReturn;
        }
    }
}


GatorAVL::StudentNode* insertHelper(GatorAVL::StudentNode* root, int Gator1ID, string NAME)
{
    if(root == nullptr)
    {
        GatorAVL::StudentNode* newStudentRoot = new GatorAVL::StudentNode(Gator1ID, NAME);
        return newStudentRoot;
    }
    else
    {
        if(Gator1ID > root->getGator1ID())
        {
            root->setRightChild(insertHelper(root->getRightChild(), Gator1ID, NAME));
            root->calcHeight(root, 0);
            root = balanceNodes(root);
        }
        else if(Gator1ID < root->getGator1ID())
        {
            root->setLeftChild(insertHelper(root->getLeftChild(), Gator1ID, NAME));
            root->calcHeight(root, 0);
            root = balanceNodes(root);
        }

        /*if(root->getRoot() == true) Determines success or failure of the insertion
        {
            if(boolSearched(Gator1ID))
            {
                cout << "successful" << endl;
            }
            else
            {
                cout << "unsucessful" << endl;
            }
        }*/
        return root;
    }
}


GatorAVL::StudentNode* balanceNodes(GatorAVL::StudentNode* balancingNode)
{
    balancingNode->calculateBalanceFactor();
    if (balancingNode->getBalanceFactor() > 1)
    {
        if(balancingNode->getLeftChild() != nullptr && balancingNode->getLeftChild()->getBalanceFactor() == 1) // Perform Right Rotation
        {
            GatorAVL::StudentNode* nodeToReturn = balancingNode->getLeftChild();
            if(balancingNode->getLeftChild()->getRightChild() != nullptr)
            {
                balancingNode->setLeftChild(balancingNode->getLeftChild()->getRightChild());
                nodeToReturn->setRightChild(balancingNode);
            }
            else
            {
                balancingNode->getLeftChild()->setRightChild(balancingNode);
                balancingNode->setLeftChild(nullptr);
            }
            
            return nodeToReturn;
        }
        else if(balancingNode->getLeftChild() != nullptr && balancingNode->getLeftChild()->getBalanceFactor() == -1) // Perform left right rotation
        {
            GatorAVL::StudentNode* nodeToReturn = balancingNode->getLeftChild()->getRightChild();
            balancingNode->getLeftChild()->getRightChild()->setLeftChild(balancingNode->getLeftChild());
            balancingNode->setLeftChild(balancingNode->getLeftChild()->getRightChild());
            balancingNode->getLeftChild()->getLeftChild()->setRightChild(nullptr);

            balancingNode->getLeftChild()->setRightChild(balancingNode); // Perform right rotation
            balancingNode->setLeftChild(nullptr);
            return nodeToReturn;

        }
    }
    if (balancingNode->getBalanceFactor() < -1)
    {
        if(balancingNode->getRightChild() != nullptr && balancingNode->getRightChild()->getBalanceFactor() == 1) // Perform right left rotation
        {
            GatorAVL::StudentNode* nodeToReturn = balancingNode->getRightChild()->getLeftChild();
            balancingNode->getRightChild()->getLeftChild()->setRightChild(balancingNode->getRightChild());
            balancingNode->setRightChild(balancingNode->getRightChild()->getLeftChild());
            balancingNode->getRightChild()->getRightChild()->setLeftChild(nullptr);

            balancingNode->getRightChild()->setLeftChild(balancingNode); // Perform Left Rotation
            balancingNode->setRightChild(nullptr);    
            return nodeToReturn;
        }
        if(balancingNode->getRightChild() != nullptr && balancingNode->getRightChild()->getBalanceFactor() == -1) // Perform Left Rotation
        {
            GatorAVL::StudentNode* nodeToReturn = balancingNode->getRightChild();
            if(balancingNode->getRightChild()->getLeftChild() != nullptr)
            {
                balancingNode->setRightChild(balancingNode->getRightChild()->getLeftChild());
                nodeToReturn->setLeftChild(balancingNode);
            }
            else
            {
                balancingNode->getRightChild()->setLeftChild(balancingNode); 
                balancingNode->setRightChild(nullptr);
            }
            return nodeToReturn;
        }
    }
    else
    {
        return balancingNode;
    }
}

//  THIS WORKED FIRST TRY!!!!!!! MMMMMMMMMMMHMMMMMMM LES GOOOOOOOOOOOO
vector<int> inorderTraversal(GatorAVL::StudentNode* root)
{
    vector<int> sortedData;
    vector<int> tempSortedData;
    if(root->getLeftChild() != nullptr)
    {
        tempSortedData = inorderTraversal(root->getLeftChild());
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            sortedData.push_back(tempSortedData.at(i));
        }
        sortedData.push_back(root->getGator1ID());
        if(root->getRightChild() != nullptr)
        {
            tempSortedData = inorderTraversal(root->getRightChild());
            for (int i = 0; i < tempSortedData.size(); i++)
            {
                sortedData.push_back(tempSortedData.at(i));
            }
            return sortedData;
        }
        else
        {
            return sortedData;
        }

        
    }
    else if(root->getRightChild() != nullptr)
    {
        sortedData.push_back(root->getGator1ID());
        tempSortedData = inorderTraversal(root->getRightChild());
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            sortedData.push_back(tempSortedData.at(i));
        }
        
        return sortedData;
    }
    else
    {
        sortedData.push_back(root->getGator1ID());
        return sortedData;
    }
}

vector<GatorAVL::StudentNode*> inorderTraversal(GatorAVL::StudentNode* root, int count)
{
    vector<GatorAVL::StudentNode*> sortedData;
    vector<GatorAVL::StudentNode*> tempSortedData;
    if(root->getLeftChild() != nullptr)
    {
        tempSortedData = inorderTraversal(root->getLeftChild(), 0);
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            sortedData.push_back(tempSortedData.at(i));
        }
        sortedData.push_back(root);
        if(root->getRightChild() != nullptr)
        {
            tempSortedData = inorderTraversal(root->getRightChild(), 0);
            for (int i = 0; i < tempSortedData.size(); i++)
            {
                sortedData.push_back(tempSortedData.at(i));
            }
            return sortedData;
        }
        else
        {
            return sortedData;
        }

        
    }
    else if(root->getRightChild() != nullptr)
    {
        sortedData.push_back(root);
        tempSortedData = inorderTraversal(root->getRightChild(), 0);
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            sortedData.push_back(tempSortedData.at(i));
        }
        
        return sortedData;
    }
    else
    {
        sortedData.push_back(root);
        return sortedData;
    }
}

//Worked First Try
vector<int> preorderTraversal(GatorAVL::StudentNode* root)
{
    vector<int> preorderedData;
    vector<int> tempData;

    preorderedData.push_back(root->getGator1ID());
    if(root->getLeftChild() != nullptr)
    {
        tempData = preorderTraversal(root->getLeftChild());
        for (int i = 0; i < tempData.size(); i++)
        {
            preorderedData.push_back(tempData.at(i));
        }
        if(root->getRightChild() != nullptr)
        {
            tempData = preorderTraversal(root->getRightChild());
            for (int i = 0; i < tempData.size(); i++)
            {
                preorderedData.push_back(tempData.at(i));
            }
            return preorderedData;
        }
        else
        {
            return preorderedData;
        }
    }
    else if(root->getRightChild() != nullptr)
    {
        tempData = preorderTraversal(root->getRightChild());
        for (int i = 0; i < tempData.size(); i++)
        {
            preorderedData.push_back(tempData.at(i));
        }
        
        return preorderedData;
    }
    else
    {
        return preorderedData;
    }
}

vector<GatorAVL::StudentNode*> preorderTraversal(GatorAVL::StudentNode* root, int count)
{
    vector<GatorAVL::StudentNode*> preorderedData;
    vector<GatorAVL::StudentNode*> tempData;

    preorderedData.push_back(root);
    if(root->getLeftChild() != nullptr)
    {
        tempData = preorderTraversal(root->getLeftChild(), 0);
        for (int i = 0; i < tempData.size(); i++)
        {
            preorderedData.push_back(tempData.at(i));
        }
        if(root->getRightChild() != nullptr)
        {
            tempData = preorderTraversal(root->getRightChild(), 0);
            for (int i = 0; i < tempData.size(); i++)
            {
                preorderedData.push_back(tempData.at(i));
            }
            return preorderedData;
        }
        else
        {
            return preorderedData;
        }
    }
    else if(root->getRightChild() != nullptr)
    {
        tempData = preorderTraversal(root->getRightChild(), 0);
        for (int i = 0; i < tempData.size(); i++)
        {
            preorderedData.push_back(tempData.at(i));
        }
        
        return preorderedData;
    }
    else
    {
        return preorderedData;
    }
}

//Worked First Try
vector<int> postorderTraversal(GatorAVL::StudentNode* root)
{
    vector<int> postorderedData;
    vector<int> tempData;
    if(root->getLeftChild() != nullptr)
    {
        tempData = postorderTraversal(root->getLeftChild());
        for (int i = 0; i < tempData.size(); i++)
        {
            postorderedData.push_back(tempData.at(i));
        }
        if(root->getRightChild() != nullptr)
        {
            tempData = postorderTraversal(root->getRightChild());
            for (int i = 0; i < tempData.size(); i++)
            {
                postorderedData.push_back(tempData.at(i));
            }
            postorderedData.push_back(root->getGator1ID());
            return postorderedData;
        }
        else
        {
            postorderedData.push_back(root->getGator1ID());
            return postorderedData;
        }
    }
    else if(root->getRightChild() != nullptr)
    {
        tempData = postorderTraversal(root->getRightChild());
        for (int i = 0; i < tempData.size(); i++)
        {
            postorderedData.push_back(tempData.at(i));
        }
        postorderedData.push_back(root->getGator1ID());
        return postorderedData;
    }
    postorderedData.push_back(root->getGator1ID());
    return postorderedData;
}

vector<GatorAVL::StudentNode*> postorderTraversal(GatorAVL::StudentNode* root, int count)
{
    vector<GatorAVL::StudentNode*> postorderedData;
    vector<GatorAVL::StudentNode*> tempData;
    if(root->getLeftChild() != nullptr)
    {
        tempData = postorderTraversal(root->getLeftChild(), 0);
        for (int i = 0; i < tempData.size(); i++)
        {
            postorderedData.push_back(tempData.at(i));
        }
        if(root->getRightChild() != nullptr)
        {
            tempData = postorderTraversal(root->getRightChild(), 0);
            for (int i = 0; i < tempData.size(); i++)
            {
                postorderedData.push_back(tempData.at(i));
            }
            postorderedData.push_back(root);
            return postorderedData;
        }
        else
        {
            postorderedData.push_back(root);
            return postorderedData;
        }
    }
    else if(root->getRightChild() != nullptr)
    {
        tempData = postorderTraversal(root->getRightChild(), 0);
        for (int i = 0; i < tempData.size(); i++)
        {
            postorderedData.push_back(tempData.at(i));
        }
        postorderedData.push_back(root);
        return postorderedData;
    }
    postorderedData.push_back(root);
    return postorderedData;
}

GatorAVL::StudentNode* searchIDHelper(GatorAVL::StudentNode* root, int ID)
{
    GatorAVL::StudentNode* nodeToReturn = nullptr;
    if(root->getGator1ID() == ID)
    {
        return root;
    }
    else
    {        
        if(root->getLeftChild() != nullptr)
        {
            nodeToReturn = searchIDHelper(root->getLeftChild(), ID);
        }
        if(root->getRightChild() != nullptr && nodeToReturn == nullptr)
        {
            nodeToReturn = searchIDHelper(root->getRightChild(), ID);
        }
    }
    return nodeToReturn;
}

void searchID(GatorAVL::StudentNode* root, int ID)
{
    GatorAVL::StudentNode* determinant = nullptr;
    if(root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return;
    }
    determinant = searchIDHelper(root, ID);
    if(determinant == nullptr)
    {
        cout << "unsuccessful" << endl;
    }
    else
    {
        cout << determinant->getNAME() << endl;
    }
}

bool searchIDBool(GatorAVL::StudentNode* root, int ID)
{
    if(root == nullptr)
    {
        return false;
    }
    GatorAVL::StudentNode* determinant = nullptr;
    determinant = searchIDHelper(root, ID);
    if(determinant == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<GatorAVL::StudentNode*> searchNameHelper(GatorAVL::StudentNode* root, string name)
{
    vector<GatorAVL::StudentNode*> preorderedData;
    vector<GatorAVL::StudentNode*> tempData;

    if(root->getNAME() == name)
    {
        preorderedData.push_back(root);
    }
    else
    {
        preorderedData.push_back(nullptr);
    }
    if(root->getLeftChild() != nullptr)
    {
        tempData = searchNameHelper(root->getLeftChild(), name);
        for (int i = 0; i < tempData.size(); i++)
        {
            preorderedData.push_back(tempData.at(i));
        }
        if(root->getRightChild() != nullptr)
        {
            tempData = searchNameHelper(root->getRightChild(), name);
            for (int i = 0; i < tempData.size(); i++)
            {
                preorderedData.push_back(tempData.at(i));
            }
            return preorderedData;
        }
        else
        {
            return preorderedData;
        }
    }
    else if(root->getRightChild() != nullptr)
    {
        tempData = searchNameHelper(root->getRightChild(), name);
        for (int i = 0; i < tempData.size(); i++)
        {
            preorderedData.push_back(tempData.at(i));
        }
        
        return preorderedData;
    }
    else
    {
        return preorderedData;
    }
}

void searchName(GatorAVL::StudentNode* root, string name)
{
    if(root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return;
    }
    vector<GatorAVL::StudentNode*> preorderSearchOfNames = searchNameHelper(root, name);
    bool foundName = false;
    for (int i = 0; i < preorderSearchOfNames.size(); i++)
    {
        if(preorderSearchOfNames.at(i) != nullptr)
        {
            cout << preorderSearchOfNames.at(i)->getGator1ID() << endl;
            foundName = true;
        }
    }
    if(foundName == false)
    {
        cout << "unsuccessful" << endl;
    }
    
}

int getLevels(GatorAVL::StudentNode* root)
{
    root->calcHeight(root, 0);
    if(root->getRightHeight() > root->getLeftHeight())
    {
        int levels = root->getRightHeight();
        levels++;
        return levels;
    }
    else
    {
        int levels = root->getLeftHeight();
        levels++;
        return levels++;
    }
}

void printLevelCount(GatorAVL::StudentNode* root)
{
    if(root == nullptr)
    {
        cout << 0 << endl;
    }
    else
    {
        int levels = getLevels(root);
        cout << levels << endl;
    }
}


void printINOTraversal(GatorAVL::StudentNode* root)
{
    //calll the traversal

    vector<GatorAVL::StudentNode*> traversal = inorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void printPRETraversal(GatorAVL::StudentNode* root)
{
    //calll the traversal

    vector<GatorAVL::StudentNode*> traversal = preorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void printPOSTraversal(GatorAVL::StudentNode* root)
{
    //calll the traversal

    vector<GatorAVL::StudentNode*> traversal = postorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}


bool verifyInput(istringstream& nextLineOfUserInput)
{
    bool validInput = true;
    string unverifiedInput;
    nextLineOfUserInput >> unverifiedInput;
    for (int i = 0; i < unverifiedInput.size(); i++) //loop through the line of input and make sure that each character in the line is alphanumeric
    {
        if(!isalpha(unverifiedInput.at(i)))
        {
            if(!isdigit(unverifiedInput.at(i)))
            {
                validInput = false;
                return validInput;
            }
        }
    }
    return validInput;
}


void executeRegularCommand(GatorAVL* tree, string command, int ID, string Name, int NthRemoval)
    {
        if(command == "insert")
        {
            tree->setRoot(insert(tree->getRoot(), ID, Name));
        }
        if(command == "remove")
        {
            cout << "Functionality remove not implemented yet" << endl;
        }
        if(command == "removeInorder")
        {
            cout << "Functionality removeInorder not implemented yet" << endl;
        }
        if(command == "search")
        {
            if(ID != -1)
            {
                searchID(tree->getRoot(), ID);
            }
            else
            {
                searchName(tree->getRoot(), Name);
            }
        }
    }

void executeEmptyCommand(GatorAVL* tree, string command)
{
    if(command == "printLevelCount")
    {
        printLevelCount(tree->getRoot());
    }
    if(command == "printInorder")
    {
        printINOTraversal(tree->getRoot());
    }
    if(command == "printPreorder")
    {
        printPRETraversal(tree->getRoot());
    }
    if(command == "printPostorder")
    {
        printPOSTraversal(tree->getRoot());
    }
}


void parseCommand(GatorAVL* tree, istringstream& nextLineOfUserInput)
{
    string command = "";
    string parameters = "";
    string Name = "";
    string intParse = "";
    int ID = -1;
    int removeNthNode = -1;
    
    getline(nextLineOfUserInput, command, ' '); //Figure out what the command is
    
    getline(nextLineOfUserInput, parameters); // Load the rest of the input into the parameters string.
    if(parameters.empty()) // If there are no parameters, run the command.
    {
        executeEmptyCommand(tree, command);
    }
    else // otherwise, separate out the parameters
    {
        istringstream parametersStream(parameters);           

        //deal with strings first
        string parameter1;
        
        string parameter2;
        getline(parametersStream, parameter1, ' '); //get the first parameter
        istringstream parameter1Stream(parameter1);
        char test;
        if(ispunct(parameter1.at(0)))
        {
            test = parameter1.at(2);
        }
        else
        {
            test = parameter1.at(0);
        }
        if(isalpha(test)) //if it is a character, then you know that it must be a name
        {
            getline(parameter1Stream, Name, '\"'); //get rid of the first quotation marks
            getline(parameter1Stream, Name, '\"'); //make it the name
            getline(parametersStream, parameter2); //get the second parameter if it exists
            if(!parameter2.empty()) //if the second parameter exists you know it is an integer, make it the ID
            {
                ID = stoi(parameter2);
            }
        }
        else //if it isnt a character, the first parameter must be used!!!!
        {
            if(command == "removeInorder")
            {
                removeNthNode = stoi(parameters);
            }
            else
            {
                ID = stoi(parameter1);
            }
        }  
        executeRegularCommand(tree, command, ID, Name, removeNthNode);         
    } 
}


