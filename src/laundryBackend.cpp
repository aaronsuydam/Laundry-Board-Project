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
    class Node
    {
        //UserNode Data
        protected:
        bool isRoot;

        int heightRight;
        int heightLeft;
        int balanceFactor;

        Node* left;
        Node* right;

        public:
        //Constructors
        Node()
        {
            heightRight = 0;
            heightLeft = 0;
            balanceFactor = 0;
            isRoot = false;
            
            left = nullptr;
            right = nullptr;
        }

        //Destructor
        ~Node()
        {
            delete left;
            delete right;
        }

        void setRightHeight(int newHeightRight)
        {
            heightRight = newHeightRight;
        }

        void setLeftHeight(int newHeightLeft)
        {
            heightLeft = newHeightLeft;
        }

        void setRightChild(Node* newRightChild)
        {
            right = newRightChild;
        }

        void setLeftChild(Node* newLeftChild)
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
        int getRightHeight()
        {
            return heightRight;
        }
        
        int getLeftHeight()
        {
            return heightLeft;
        }

        Node* getRightChild()
        {
            return right;
        }

        Node* getLeftChild()
        {
            return left;
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

        int calcHeight(Node* root, int count)
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
    class UserNode : public Node
    {
        //UserNode Data

        int Gator1ID;
        int phoneNumber;
        int roomNumber;

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

        /*UserNode(int inputGator1ID, string givenNAME, int, UserNode* givenLeft, UserNode* givenRight)
        {
            Gator1ID = inputGator1ID;
            heightRight = givenHeight;
            NAME = givenNAME;
            left = givenLeft;
            right = givenRight;
        }*/

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

        void setNAME(string newNAME)
        {
            NAME = newNAME;
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

        string getNAME()
        {
            return NAME;
        }
        
        string getUFEmail()
        {
            return ufEmail;
        }

    };

    class MachineNode : public Node
    {
        //MachineNode Data

        int machineNumber;
        int status; // 0 for free, 1 for in use, two for out of order;

        string type;


        //image variable if we decide to do a gui
        
        public:
        //Constructors
        MachineNode()
        {
            isRoot = false;

            heightRight = 0;
            heightLeft = 0;
            balanceFactor = 0;
            status = 0;
            machineNumber = 0;

            type = "Unknown";

            left = nullptr;
            right = nullptr;
        }

        MachineNode(int inputMachineNumber, string inputType)
        {
            isRoot = false;
            
            machineNumber = inputMachineNumber;
            status = 0;
            heightRight = 0;
            heightLeft = 0;
            balanceFactor = 0;

            type = inputType;

            left = nullptr;
            right = nullptr;
        }

        /*MachineNode(int inputGator1ID, string givenNAME, int, MachineNode* givenLeft, MachineNode* givenRight)
        {
            Gator1ID = inputGator1ID;
            heightRight = givenHeight;
            NAME = givenNAME;
            left = givenLeft;
            right = givenRight;
        }*/

        //Destructor
        ~MachineNode()
        {
            delete left;
            delete right;
        }


        //Setters
        
        void setMachineNumber(int newMachineNumber)
        {
            machineNumber = newMachineNumber;
        }
        
        void setStatus(int newStatus)
        {
            status = newStatus;
        }

        void setType(string newType)
        {
            type = newType;
        }


        //Getters
        
        int getMachineNumber()
        {
            return machineNumber;
        }

        int getStatus()
        {
            return status;
        }

        string getType()
        {
            return type;
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
    
    
    private:
    UserNode* root;
    int height;
    int numLevels;
    int numNodes;
};




AVLTree::Node* insert(AVLTree::Node* root, int Gator1ID, string NAME);
AVLTree::Node* insertHelper(AVLTree::Node* root, int Gator1ID, string NAME);
AVLTree::Node* balanceNodes(AVLTree::Node* balancingNode);
vector<int> inorderTraversal(AVLTree::Node* root);
vector<AVLTree::Node*> inorderTraversal(AVLTree::Node* root, int count);
vector<int> preorderTraversal(AVLTree::Node* root);
vector<AVLTree::Node*> preorderTraversal(AVLTree::Node* root, int count);
vector<int> postorderTraversal(AVLTree::Node* root);
void printINOTraversal(AVLTree::Node* root);
void printPRETraversal(AVLTree::Node* root);
void printPOSTraversal(AVLTree::Node* root);
    

    
AVLTree::Node* searchIDHelper(AVLTree::Node* root, int ID);
void searchID(AVLTree::Node* root, int ID);
bool searchIDBool(AVLTree::Node* root, int ID);
void searchName(AVLTree::Node* root, string name);
vector<AVLTree::Node*> searchNameHelper(AVLTree::Node* root, string name);
int getLevels(AVLTree::Node* root);
void printLevelCount(AVLTree::Node* root);
bool verifyInput(istringstream& nextLineOfUserInput);
void parseCommand(AVLTree* tree, istringstream& nextLineOfUserInput);
void executeRegularCommand(AVLTree* tree, string command, int ID, string Name, int NthRemoval);
void executeEmptyCommand(AVLTree* tree, string command);



AVLTree::Node* insert(AVLTree::Node* root, int Gator1ID, string NAME)
{
    bool preexisting = searchIDBool(root, Gator1ID);
    if(preexisting)
    {
        cout << "unsuccessful" << endl;
        return root;
    }
    else
    {
        AVLTree::Node* nodeToReturn = insertHelper(root, Gator1ID, NAME);
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


AVLTree::Node* insertHelper(AVLTree::Node* root, int Gator1ID, string NAME)
{
    if(root == nullptr)
    {
        AVLTree::Node* newStudentRoot = new AVLTree::Node(Gator1ID, NAME);
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


AVLTree::Node* balanceNodes(AVLTree::Node* balancingNode)
{
    balancingNode->calculateBalanceFactor();
    if (balancingNode->getBalanceFactor() > 1)
    {
        if(balancingNode->getLeftChild() != nullptr && balancingNode->getLeftChild()->getBalanceFactor() == 1) // Perform Right Rotation
        {
            AVLTree::Node* nodeToReturn = balancingNode->getLeftChild();
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
            AVLTree::Node* nodeToReturn = balancingNode->getLeftChild()->getRightChild();
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
            AVLTree::Node* nodeToReturn = balancingNode->getRightChild()->getLeftChild();
            balancingNode->getRightChild()->getLeftChild()->setRightChild(balancingNode->getRightChild());
            balancingNode->setRightChild(balancingNode->getRightChild()->getLeftChild());
            balancingNode->getRightChild()->getRightChild()->setLeftChild(nullptr);

            balancingNode->getRightChild()->setLeftChild(balancingNode); // Perform Left Rotation
            balancingNode->setRightChild(nullptr);    
            return nodeToReturn;
        }
        if(balancingNode->getRightChild() != nullptr && balancingNode->getRightChild()->getBalanceFactor() == -1) // Perform Left Rotation
        {
            AVLTree::Node* nodeToReturn = balancingNode->getRightChild();
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
vector<int> inorderTraversal(AVLTree::Node* root)
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

vector<AVLTree::Node*> inorderTraversal(AVLTree::Node* root, int count)
{
    vector<AVLTree::Node*> sortedData;
    vector<AVLTree::Node*> tempSortedData;
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
vector<int> preorderTraversal(AVLTree::Node* root)
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

vector<AVLTree::Node*> preorderTraversal(AVLTree::Node* root, int count)
{
    vector<AVLTree::Node*> preorderedData;
    vector<AVLTree::Node*> tempData;

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
vector<int> postorderTraversal(AVLTree::Node* root)
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

vector<AVLTree::Node*> postorderTraversal(AVLTree::Node* root, int count)
{
    vector<AVLTree::Node*> postorderedData;
    vector<AVLTree::Node*> tempData;
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

AVLTree::Node* searchIDHelper(AVLTree::Node* root, int ID)
{
    AVLTree::Node* nodeToReturn = nullptr;
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

void searchID(AVLTree::Node* root, int ID)
{
    AVLTree::Node* determinant = nullptr;
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

bool searchIDBool(AVLTree::Node* root, int ID)
{
    if(root == nullptr)
    {
        return false;
    }
    AVLTree::Node* determinant = nullptr;
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

vector<AVLTree::Node*> searchNameHelper(AVLTree::Node* root, string name)
{
    vector<AVLTree::Node*> preorderedData;
    vector<AVLTree::Node*> tempData;

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

void searchName(AVLTree::Node* root, string name)
{
    if(root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return;
    }
    vector<AVLTree::Node*> preorderSearchOfNames = searchNameHelper(root, name);
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

int getLevels(AVLTree::Node* root)
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

void printLevelCount(AVLTree::Node* root)
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


void printINOTraversal(AVLTree::Node* root)
{
    //calll the traversal

    vector<AVLTree::Node*> traversal = inorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void printPRETraversal(AVLTree::Node* root)
{
    //calll the traversal

    vector<AVLTree::Node*> traversal = preorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void printPOSTraversal(AVLTree::Node* root)
{
    //calll the traversal

    vector<AVLTree::Node*> traversal = postorderTraversal(root, 0);

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




