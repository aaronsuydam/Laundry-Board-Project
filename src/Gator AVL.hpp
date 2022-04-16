#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class AVLTree
{
    public:
    class StudentNode
    {
        
        bool isRoot;
        StudentNode* left;
        StudentNode* right;
        int Gator1ID;
        int heightRight;
        int heightLeft;
        int balanceFactor;
        string NAME;
        
        public:
        StudentNode()
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

        StudentNode(int inputGator1ID, string givenNAME)
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

        /*StudentNode(int inputGator1ID, string givenNAME, int, StudentNode* givenLeft, StudentNode* givenRight)
        {
            Gator1ID = inputGator1ID;
            heightRight = givenHeight;
            NAME = givenNAME;
            left = givenLeft;
            right = givenRight;
        }*/

        ~StudentNode()
        {
            delete left;
            delete right;
        }


        int getGator1ID()
        {
            return Gator1ID;
        }

        void setGator1ID(int newGator1ID)
        {
            Gator1ID = newGator1ID;
        }

        int getRightHeight()
        {
            return heightRight;
        }

        void setRightHeight(int newHeightRight)
        {
            heightRight = newHeightRight;
        }

        int getLeftHeight()
        {
            return heightLeft;
        }

        void setLeftHeight(int newHeightLeft)
        {
            heightLeft = newHeightLeft;
        }

        StudentNode* getRightChild()
        {
            return right;
        }

        StudentNode* getLeftChild()
        {
            return left;
        }

        void setRightChild(StudentNode* newRightChild)
        {
            right = newRightChild;
        }

        void setLeftChild(StudentNode* newLeftChild)
        {
            left = newLeftChild;
        }

        string getNAME()
        {
            return NAME;
        }

        void setNAME(string newNAME)
        {
            NAME = newNAME;
        }

        int calculateBalanceFactor()
        {
            balanceFactor = heightLeft - heightRight;
            return balanceFactor;
        }

        int getBalanceFactor()
        {
            return balanceFactor;
        }

        void setBalanceFactor(int newBalanceFactor)
        {
            balanceFactor = newBalanceFactor;
        }

        bool getRoot()
        {
            return isRoot;
        }

        void setRoot(bool isReallyRoot)
        {
            isRoot = isReallyRoot;
        }

        int calcHeight(StudentNode* root, int count)
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
        root = new StudentNode(rootGator1ID, rootNAME);
        height = 0;
        numLevels = 0;
        numNodes = 1;
    }

    StudentNode* getRoot()
    {
        return root;
    }

    void setRoot(StudentNode* newRoot)
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
    StudentNode* root;
    int height;
    int numLevels;
    int numNodes;
};
    AVLTree::StudentNode* insert(AVLTree::StudentNode* root, int Gator1ID, string NAME);
    AVLTree::StudentNode* insertHelper(AVLTree::StudentNode* root, int Gator1ID, string NAME);
    AVLTree::StudentNode* balanceNodes(AVLTree::StudentNode* balancingNode);
    vector<int> inorderTraversal(AVLTree::StudentNode* root);
    vector<AVLTree::StudentNode*> inorderTraversal(AVLTree::StudentNode* root, int count);
    vector<int> preorderTraversal(AVLTree::StudentNode* root);
    vector<AVLTree::StudentNode*> preorderTraversal(AVLTree::StudentNode* root, int count);
    vector<int> postorderTraversal(AVLTree::StudentNode* root);
    void printINOTraversal(AVLTree::StudentNode* root);
    void printPRETraversal(AVLTree::StudentNode* root);
    void printPOSTraversal(AVLTree::StudentNode* root);
    

    
    AVLTree::StudentNode* searchIDHelper(AVLTree::StudentNode* root, int ID);
    void searchID(AVLTree::StudentNode* root, int ID);
    bool searchIDBool(AVLTree::StudentNode* root, int ID);
    void searchName(AVLTree::StudentNode* root, string name);
    vector<AVLTree::StudentNode*> searchNameHelper(AVLTree::StudentNode* root, string name);
    int getLevels(AVLTree::StudentNode* root);
    void printLevelCount(AVLTree::StudentNode* root);
    bool verifyInput(istringstream& nextLineOfUserInput);
    void parseCommand(AVLTree* tree, istringstream& nextLineOfUserInput);
    void executeRegularCommand(AVLTree* tree, string command, int ID, string Name, int NthRemoval);
    void executeEmptyCommand(AVLTree* tree, string command);
    


    


    









