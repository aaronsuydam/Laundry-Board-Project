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
#include <ctime>
using namespace std;


class Session
{
    public:
    string user;
    int machinesUsed[2];
    int times[2];

    Session()
    {
        user = "";
    }

    Session(string user, int washerUsed, int dryerUsed, int washTime, int dryTime)
    {
        this->user = user;
        machinesUsed[1] = washerUsed;
        machinesUsed[2] = dryerUsed;
        times[1] = washTime;
        times[2] = dryTime;
    }
};

class AVLTree
{
    public:
    class UserNode
    {
        //Backend node data
        bool isRoot;
        int heightRight;
        int heightLeft;
        int balanceFactor;
        UserNode* left;
        UserNode* right;

        //Metadata
        string NAME;
        string ufEmail;
        int Gator1ID;
        int phoneNumber;
        int roomNumber;

        //Sessions
        vector<Session> sessions;

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
            phoneNumber = 0;
            roomNumber = 0;
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

        UserNode(int inputGator1ID, string givenNAME, int phone, int room)
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

        void addSession(string user, int washerUsed, int dryerUsed, int washTime, int dryTime)
        {
            Session toAdd(user, washerUsed, dryerUsed, washTime, dryTime);
            sessions.push_back(toAdd);
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

        Session getSession(int session)
        {
            return sessions.at(session);
        }

        //Caclulators

        double userAverageWashing(UserNode* user)
        {

        }
        double userAverageDrying(UserNode* user)
        {

        }

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

        double userAverageWashing(UserNode user);

        double userAverageDrying(UserNode user);

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
    void generate20Sesh(vector<UserNode> ugh)
    {
        srand( (unsigned)time( NULL ) );      
        for(int i=0; i<ugh.size();i++)
        {

            string name=ugh.at(i).getNAME();
            int washUsed=rand()%2; //1 for used
            int dryUsed=rand()%2;
            int washTime;
            int dryTime;
            if(washUsed==1)
            {
                washTime=(rand() % 24);                  
            }
            if(dryUsed==1)
            {
                dryTime=(rand() % 24);                               
            }
            for(int i=0; i<=19;i++)
            {
                    ugh.at(i).addSession(name,washUsed,dryUsed,washTime,dryTime);
            }
        }
    }

    
    UserNode* insert(UserNode* root, int Gator1ID, string NAME);
    UserNode* insertHelper(UserNode* root, int Gator1ID, string NAME);

    UserNode* insertFromFile(UserNode* root, int Gator1ID, string NAME, int phone, int room);
    UserNode* insertHelper(UserNode* root, int Gator1ID, string NAME, int phone, int room);

    UserNode* balanceNodes(UserNode* balancingNode);

    vector<int> inorderTraversal(UserNode* root);
    vector<UserNode*> inorderTraversal(UserNode* root, int count);

    vector<int> preorderTraversal(UserNode* root);
    vector<UserNode*> preorderTraversal(UserNode* root, int count);

    vector<int> postorderTraversal(UserNode* root);
    vector<UserNode*> postorderTraversal(UserNode* root, int count);

    void printINOTraversal(UserNode* root);
    void printPRETraversal(UserNode* root);
    void printPOSTraversal(UserNode* root);
    
    UserNode* searchIDHelper(UserNode* root, int ID);
    void searchID(UserNode* root, int ID);
    bool searchIDBool(UserNode* root, int ID);

    void searchName(UserNode* root, string name);
    vector<UserNode*> searchNameHelper(UserNode* root, string name);

    UserNode* removeID(UserNode* root ,int Gator1ID);
    UserNode* smallestNode(UserNode* node);

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



AVLTree::UserNode* AVLTree::insert(AVLTree::UserNode* root, int Gator1ID, string NAME)
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

AVLTree::UserNode* AVLTree::insertHelper(AVLTree::UserNode* root, int Gator1ID, string NAME)
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
        return root;
    }
}


AVLTree::UserNode* AVLTree::insertFromFile(AVLTree::UserNode* root, int Gator1ID, string NAME, int phone, int room)
{
    bool preexisting = searchIDBool(root, Gator1ID);
    if(preexisting)
    {
        cout << "unsuccessful" << endl;
        return root;
    }
    else
    {
        AVLTree::UserNode* nodeToReturn = insertHelper(root, Gator1ID, NAME, phone, room);
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

AVLTree::UserNode* AVLTree::insertHelper(AVLTree::UserNode* root, int Gator1ID, string NAME, int phone, int room)
{
    if(root == nullptr)
    {
        AVLTree::UserNode* newStudentRoot = new AVLTree::UserNode(Gator1ID, NAME, phone, room);
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
        return root;
    }
}


AVLTree::UserNode* AVLTree::balanceNodes(AVLTree::UserNode* balancingNode)
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


//THIS WORKED FIRST TRY!!!!!!! MMMMMMMMMMMHMMMMMMM LES GOOOOOOOOOOOO
vector<int> AVLTree::inorderTraversal(AVLTree::UserNode* root)
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

vector<AVLTree::UserNode*> AVLTree::inorderTraversal(AVLTree::UserNode* root, int count)
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
vector<int> AVLTree::preorderTraversal(AVLTree::UserNode* root)
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

vector<AVLTree::UserNode*> AVLTree::preorderTraversal(AVLTree::UserNode* root, int count)
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
vector<int> AVLTree::postorderTraversal(AVLTree::UserNode* root)
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

vector<AVLTree::UserNode*> AVLTree::postorderTraversal(AVLTree::UserNode* root, int count)
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

AVLTree::UserNode* AVLTree::searchIDHelper(AVLTree::UserNode* root, int ID)
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

void AVLTree::searchID(AVLTree::UserNode* root, int ID)
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

bool AVLTree::searchIDBool(AVLTree::UserNode* root, int ID)
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

vector<AVLTree::UserNode*> AVLTree::searchNameHelper(AVLTree::UserNode* root, string name)
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

void AVLTree::searchName(AVLTree::UserNode* root, string name)
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

AVLTree::UserNode* AVLTree::smallestNode(AVLTree::UserNode* node)//finds smallest node 
{
    AVLTree::UserNode* current = node;

    //loop down left to find smallest node
    while (current && current->getLeftChild() != NULL)
    {
        current = current->getLeftChild();
    }
    return current;
}

AVLTree::UserNode* AVLTree::removeID(AVLTree::UserNode* root ,int Gator1ID)
{
    if (root == nullptr)//base case
    {
        return root;
    }

    //if id is smaller than the root key, then it's in the left subtree
    if (Gator1ID < root->getGator1ID())
    {
    root->setLeftChild(AVLTree::removeID(root->getLeftChild(), Gator1ID));
    }
    else if (Gator1ID > root->getGator1ID())  //if id is greater than the root key, then it's in the right subtree
    {
        root->setRightChild(removeID(root->getRightChild(), Gator1ID));
    }
    else  // if id is same as root's id, then this is the node to be deleted
    {
        // node has no child
        if (root->getLeftChild()==nullptr && root->getRightChild()==nullptr)
        {
            return nullptr;
        }
        else if (root->getLeftChild() == nullptr) // node has one child 
        {
            AVLTree::UserNode* myNode = root->getRightChild();
            root=nullptr;
            return myNode;
        }
        else if (root->getRightChild() == nullptr) // node has one child 
        {
            AVLTree::UserNode* myNode = root->getLeftChild();
            root=nullptr;
            return myNode;
        }

        //if node with two children, get smallest in right subtree
        AVLTree::UserNode* myNode = smallestNode(root->getRightChild());

        // Copy temp to this node
        root->setGator1ID(myNode->getGator1ID());
        root->setNAME(myNode->getNAME());
        // Delete the inorder successor
        root->setRightChild(removeID(root->getRightChild(), myNode->getGator1ID()));
    }
    return root;
}

int AVLTree::getLevels(AVLTree::UserNode* root)
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

void AVLTree::printLevelCount(AVLTree::UserNode* root)
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


void AVLTree::printINOTraversal(AVLTree::UserNode* root)
{
    //calll the traversal

    vector<AVLTree::UserNode*> traversal = inorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void AVLTree::printPRETraversal(AVLTree::UserNode* root)
{
    //calll the traversal

    vector<AVLTree::UserNode*> traversal = preorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}

void AVLTree::printPOSTraversal(AVLTree::UserNode* root)
{
    //calll the traversal

    vector<AVLTree::UserNode*> traversal = postorderTraversal(root, 0);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal.at(i)->getNAME() << endl;
    }
    
}






double AVLTree::UserNode::userAverageWashing (AVLTree::UserNode* user)
{
    //1 washer 2 dryer
    double averageTime;
    vector<Session> myvec=user->sessions;
    double size;
    for(int i=0; i<user->sessions.size(); i++)
    {
        Session mysesh= user->getSession(i);
        if(mysesh.machinesUsed[i]==1)
        {
        averageTime= averageTime + (mysesh.times[i]);
        size++;
        }
    }
    averageTime =(averageTime/size);
    return averageTime;
}
double AVLTree::UserNode::userAverageDrying (AVLTree::UserNode* user)
{
    //1 washer 2 dryer
    double averageTime;
    vector<Session> myvec=user->sessions;
    double size;
    for(int i=0; i<user->sessions.size(); i++)
    {
        Session mysesh= user->getSession(i);
        if(mysesh.machinesUsed[i]==2)
        {
        averageTime= averageTime + (mysesh.times[i]);
        size++;
        }
    }

    averageTime =(averageTime/size);


    return averageTime;



}


vector<int> inorderTraversalWashingTimes(AVLTree::UserNode* root)
{
    vector<int> averageWashingTimes;
    vector<int> tempSortedData;
    if(root->getLeftChild() != nullptr)
    {
        tempSortedData = inorderTraversalWashingTimes(root->getLeftChild());
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            averageWashingTimes.push_back(root->userAverageWashing(root));
        }
        averageWashingTimes.push_back(root->userAverageWashing(root));
        if(root->getRightChild() != nullptr)
        {
            tempSortedData = inorderTraversalWashingTimes(root->getRightChild());
            for (int i = 0; i < tempSortedData.size(); i++)
            {
                averageWashingTimes.push_back(root->userAverageWashing(root));
            }
            return averageWashingTimes;
        }
        else
        {
            return averageWashingTimes;
        }

        
    }
    else if(root->getRightChild() != nullptr)
    {
        averageWashingTimes.push_back(root->userAverageWashing(root));
        tempSortedData = inorderTraversalWashingTimes(root->getRightChild());
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            averageWashingTimes.push_back(tempSortedData.at(i));
        }
        
        return averageWashingTimes;
    }
    else
    {
        //averageWashingTimes.push_back(root.getGator1ID()); ??don't understand purpose of this pushback
        return averageWashingTimes;
    }
}


double totalAverageWashing(AVLTree::UserNode* root)
{
   vector<int> myVec= inorderTraversalWashingTimes(root);
    double avg;
   for(int i=0;i<myVec.size();i++)
   {
       avg=avg+(myVec.at(i));
   }

   avg=avg/(myVec.size());
    return avg;
}




vector<int> inorderTraversalDrying(AVLTree::UserNode* root)
{
    vector<int> averageDryingTimes;
    vector<int> tempSortedData;
    if(root->getLeftChild() != nullptr)
    {
        tempSortedData = inorderTraversalDrying(root->getLeftChild());
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            averageDryingTimes.push_back(root->userAverageDrying(root));
        }
        averageDryingTimes.push_back(root->userAverageDrying(root));
        if(root->getRightChild() != nullptr)
        {
            tempSortedData = inorderTraversalDrying(root->getRightChild());
            for (int i = 0; i < tempSortedData.size(); i++)
            {
                averageDryingTimes.push_back(root->userAverageDrying(root));
            }
            return averageDryingTimes;
        }
        else
        {
            return averageDryingTimes;
        }

        
    }
    else if(root->getRightChild() != nullptr)
    {
        averageDryingTimes.push_back(root->userAverageDrying(root));
        tempSortedData = inorderTraversalDrying(root->getRightChild());
        for (int i = 0; i < tempSortedData.size(); i++)
        {
            averageDryingTimes.push_back(tempSortedData.at(i));
        }
        
        return averageDryingTimes;
    }
    else
    {
        //averageDryingTimes.push_back(root.getGator1ID()); ??don't understand purpose of this pushback
        return averageDryingTimes;
    }
}


double totalAverageDrying(AVLTree::UserNode* root)
{
   vector<int> myVec= inorderTraversalDrying(root);
    double avg;
   for(int i=0;i<myVec.size();i++)
   {
       avg=avg+(myVec.at(i));
   }

   avg=avg/(myVec.size());
    return avg;
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
            tree->setRoot(tree->insert(tree->getRoot(), ID, Name));
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
                tree->searchID(tree->getRoot(), ID);
            }
            else
            {
                tree->searchName(tree->getRoot(), Name);
            }
        }
    }

void executeEmptyCommand(AVLTree* tree, string command)
{
    if(command == "printLevelCount")
    {
        tree->printLevelCount(tree->getRoot());
    }
    if(command == "printInorder")
    {
        tree->printINOTraversal(tree->getRoot());
    }
    if(command == "printPreorder")
    {
        tree->printPRETraversal(tree->getRoot());
    }
    if(command == "printPostorder")
    {
        tree->printPOSTraversal(tree->getRoot());
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