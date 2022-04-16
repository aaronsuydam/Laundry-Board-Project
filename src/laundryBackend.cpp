/* 
    Going to need the following types of information:
        User Variables:
            Principle identifier: 
                Gator ID
            Metadata:
                Name
                Room Number
                Phone Number
                UF Email
                Photo
        Linked (Calculated) Variables
            Number and which washers/dryers in use, and by whom, and for how long (map?);
        Machine Variables:
            Type Segregation: Washer/Dryer
            Machine Number
            Status: In use/Free/Out of Order
        
        Going to use Aaron's Code, will modify Andrew's removal methods as newvessary.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class AVLTree
{
    public:
    class UserNode
    {
        //UserNode Data
        bool isRoot;

        int Gator1ID;
        int phoneNumber;
        int roomNumber;
        int heightRight;
        int heightLeft;
        int balanceFactor;

        UserNode* left;
        UserNode* right;

        string NAME;
        string ufEmail;

        //image variable if we decide to do a gui
        
        public:
        //Constructors
        UserNode()
        {
            Gator1ID = -1;
            heightRight = 0;
            heightLeft = 0;
            balanceFactor = 0;
            isRoot = false;
            NAME = "";
            
            left = nullptr;
            right = nullptr;
        }

        UserNode(int inputGator1ID, string givenNAME)
        {
            Gator1ID = inputGator1ID;
            heightRight = 0;
            heightLeft = 0;
            balanceFactor = 0;
            NAME = givenNAME;
            left = nullptr;
            right = nullptr;
            isRoot = false;
        }

        //Destructor
        ~UserNode()
        {
            delete left;
            delete right;
        }


        //Setters
        void setGator1ID(int newGator1ID)
        {
            Gator1ID = newGator1ID;
        }

        void setUFEmail(string newEmail)
        {
            ufEmail = newEmail;
        }

        void setPhoneNumber(int newPhoneNumber)
        {
            phoneNumber = newPhoneNumber;
        }

        void setRoomNumber (int newRoomNumber)
        {
            roomNumber = newRoomNumber;
        }

        void setRightHeight(int newHeightRight)
        {
            heightRight = newHeightRight;
        }

        void setLeftHeight(int newHeightLeft)
        {
            heightLeft = newHeightLeft;
        }

        void setNAME(string newNAME)
        {
            NAME = newNAME;
        }

        void setRightChild(UserNode* newRightChild)
        {
            right = newRightChild;
        }

        void setLeftChild(UserNode* newLeftChild)
        {
            left = newLeftChild;
        }

        void setBalanceFactor(int newBalanceFactor)
        {
            balanceFactor = newBalanceFactor;
        }

        void setRoot(bool isReallyRoot)
        {
            isRoot = isReallyRoot;
        }

        //Getters
        int getGator1ID()
        {
            return Gator1ID;
        }

        int getPhoneNumber()
        {
            return phoneNumber;
        }

        int getRoomNumber()
        {
            return roomNumber;
        }

        int getRightHeight()
        {
            return heightRight;
        }
        
        int getLeftHeight()
        {
            return heightLeft;
        }

        UserNode* getRightChild()
        {
            return right;
        }

        UserNode* getLeftChild()
        {
            return left;
        }

        string getNAME()
        {
            return NAME;
        }
        
        string getUFEmail()
        {
            return ufEmail;
        }

        int getBalanceFactor()
        {
            return balanceFactor;
        }

        bool getRoot()
        {
            return isRoot;
        }


        //Caclulators
        int calculateBalanceFactor()
        {
            balanceFactor = heightLeft - heightRight;
            return balanceFactor;
        }

        int calcHeight(UserNode* root, int count)
        {
            if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr)
            {
                return count+=1;
            }
            
            if(root->getLeftChild() != nullptr)
            {
                root->setLeftHeight(root->calcHeight(root->getLeftChild(),0));
            }
            if(root->getRightChild() != nullptr)
            {
                root->setRightHeight(root->calcHeight(root->getRightChild(), 0));
            }       
            if(root->getRightHeight() > root->getLeftHeight())
            {
                int returnVal = root->getRightHeight();
                returnVal++;
                return returnVal;
            }
            else
            {
                int returnVal = root->getLeftHeight();
                returnVal++;
                return returnVal;
            }
        }
    };

    AVLTree()
    {
        root = nullptr;
        height = 0;
        numLevels = 0;
        numNodes = 0;
    }

    AVLTree(int rootGator1ID, string rootNAME)
    {
        root = new UserNode(rootGator1ID, rootNAME);
        height = 0;
        numLevels = 0;
        numNodes = 1;
    }

    UserNode* getRoot()
    {
        return root;
    }

    void setRoot(UserNode* newRoot)
    {
        root = newRoot;
    }

    void updateTreeData()
    {
        if(root->getRightHeight() > root->getLeftHeight())
        {
            height = root->getRightHeight();
        }
        else
        {
            height = root->getLeftHeight();
        }
    }

    AVLTree* getTree()
    {
        return this;
    }
    
    UserNode* insert(UserNode* root, int Gator1ID, string NAME);
    UserNode* insertHelper(UserNode* root, int Gator1ID, string NAME);

    UserNode* balanceNodes(UserNode* balancingNode);

    vector<int> inorderTraversal(UserNode* root);
    vector<UserNode*> inorderTraversal(UserNode* root, int count);

    vector<int> preorderTraversal(UserNode* root);
    vector<UserNode*> preorderTraversal(UserNode* root, int count);

    vector<int> postorderTraversal(UserNode* root);

    void printINOTraversal(UserNode* root);
    void printPRETraversal(UserNode* root);
    void printPOSTraversal(UserNode* root);
    
    UserNode* searchIDHelper(UserNode* root, int ID);
    void searchID(UserNode* root, int ID);
    bool searchIDBool(UserNode* root, int ID);

    void searchName(UserNode* root, string name);
    vector<UserNode*> searchNameHelper(UserNode* root, string name);

    int getLevels(UserNode* root);

    void printLevelCount(UserNode* root);

    private:
    UserNode* root;
    int height;
    int numLevels;
    int numNodes;
};




//input control
bool verifyInput(istringstream& nextLineOfUserInput);
void parseCommand(AVLTree* tree, istringstream& nextLineOfUserInput);
void executeRegularCommand(AVLTree* tree, string command, int ID, string Name, int NthRemoval);
void executeEmptyCommand(AVLTree* tree, string command);



AVLTree::UserNode* insert(AVLTree::UserNode* root, int Gator1ID, string NAME)
{
    bool preexisting = searchIDBool(root, Gator1ID);
    if(preexisting)
    {
        cout << "unsuccessful" << endl;
        return root;
    }
    else
    {
        AVLTree::UserNode* nodeToReturn = insertHelper(root, Gator1ID, NAME);
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


AVLTree::UserNode* insertHelper(AVLTree::UserNode* root, int Gator1ID, string NAME)
{
    if(root == nullptr)
    {
        AVLTree::UserNode* newStudentRoot = new AVLTree::UserNode(Gator1ID, NAME);
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


AVLTree::UserNode* balanceNodes(AVLTree::UserNode* balancingNode)
{
    balancingNode->calculateBalanceFactor();
    if (balancingNode->getBalanceFactor() > 1)
    {
        if(balancingNode->getLeftChild() != nullptr && balancingNode->getLeftChild()->getBalanceFactor() == 1) // Perform Right Rotation
        {
            AVLTree::UserNode* nodeToReturn = balancingNode->getLeftChild();
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
            AVLTree::UserNode* nodeToReturn = balancingNode->getLeftChild()->getRightChild();
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
            AVLTree::UserNode* nodeToReturn = balancingNode->getRightChild()->getLeftChild();
            balancingNode->getRightChild()->getLeftChild()->setRightChild(balancingNode->getRightChild());
            balancingNode->setRightChild(balancingNode->getRightChild()->getLeftChild());
            balancingNode->getRightChild()->getRightChild()->setLeftChild(nullptr);

            balancingNode->getRightChild()->setLeftChild(balancingNode); // Perform Left Rotation
            balancingNode->setRightChild(nullptr);    
            return nodeToReturn;
        }
        if(balancingNode->getRightChild() != nullptr && balancingNode->getRightChild()->getBalanceFactor() == -1) // Perform Left Rotation
        {
            AVLTree::UserNode* nodeToReturn = balancingNode->getRightChild();
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
vector<int> inorderTraversal(AVLTree::UserNode* root)
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

vector<AVLTree::UserNode*> inorderTraversal(AVLTree::UserNode* root, int count)
{
    vector<AVLTree::UserNode*> sortedData;
    vector<AVLTree::UserNode*> tempSortedData;
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
vector<int> preorderTraversal(AVLTree::UserNode* root)
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

vector<AVLTree::UserNode*> preorderTraversal(AVLTree::UserNode* root, int count)
{
    vector<AVLTree::UserNode*> preorderedData;
    vector<AVLTree::UserNode*> tempData;

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
vector<int> postorderTraversal(AVLTree::UserNode* root)
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

vector<AVLTree::UserNode*> postorderTraversal(AVLTree::UserNode* root, int count)
{
    vector<AVLTree::UserNode*> postorderedData;
    vector<AVLTree::UserNode*> tempData;
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

AVLTree::UserNode* searchIDHelper(AVLTree::UserNode* root, int ID)
{
    AVLTree::UserNode* nodeToReturn = nullptr;
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

void searchID(AVLTree::UserNode* root, int ID)
{
    AVLTree::UserNode* determinant = nullptr;
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

bool searchIDBool(AVLTree::UserNode* root, int ID)
{
    if(root == nullptr)
    {
        return false;
    }
    AVLTree::UserNode* determinant = nullptr;
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

vector<AVLTree::UserNode*> searchNameHelper(AVLTree::UserNode* root, string name)
{
    vector<AVLTree::UserNode*> preorderedData;
    vector<AVLTree::UserNode*> tempData;

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

void searchName(AVLTree::UserNode* root, string name)
{
    if(root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return;
    }
    vector<AVLTree::UserNode*> preorderSearchOfNames = searchNameHelper(root, name);
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

int getLevels(AVLTree::UserNode* root)
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

void printLevelCount(AVLTree::UserNode* root)
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


void printINOTraversal(AVLTree::UserNode* root)
{
    //calll the traversal

    vector<AVLTree::UserNode*> traversal = inorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void printPRETraversal(AVLTree::UserNode* root)
{
    //calll the traversal

    vector<AVLTree::UserNode*> traversal = preorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void printPOSTraversal(AVLTree::UserNode* root)
{
    //calll the traversal

    vector<AVLTree::UserNode*> traversal = postorderTraversal(root, 0);

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


void executeRegularCommand(AVLTree* tree, string command, int ID, string Name, int NthRemoval)
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

void executeEmptyCommand(AVLTree* tree, string command)
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


void parseCommand(AVLTree* tree, istringstream& nextLineOfUserInput)
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




