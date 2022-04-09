#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class GatorAVL
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

    GatorAVL()
    {
        root = nullptr;
        height = 0;
        numLevels = 0;
        numNodes = 0;
    }

    GatorAVL(int rootGator1ID, string rootNAME)
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

    GatorAVL* getTree()
    {
        return this;
    }
    private:
    StudentNode* root;
    int height;
    int numLevels;
    int numNodes;
};
    GatorAVL::StudentNode* insert(GatorAVL::StudentNode* root, int Gator1ID, string NAME);
    GatorAVL::StudentNode* insertHelper(GatorAVL::StudentNode* root, int Gator1ID, string NAME);
    GatorAVL::StudentNode* balanceNodes(GatorAVL::StudentNode* balancingNode);
    vector<int> inorderTraversal(GatorAVL::StudentNode* root);
    vector<GatorAVL::StudentNode*> inorderTraversal(GatorAVL::StudentNode* root, int count);
    vector<int> preorderTraversal(GatorAVL::StudentNode* root);
    vector<GatorAVL::StudentNode*> preorderTraversal(GatorAVL::StudentNode* root, int count);
    vector<int> postorderTraversal(GatorAVL::StudentNode* root);
    void printINOTraversal(GatorAVL::StudentNode* root);
    void printPRETraversal(GatorAVL::StudentNode* root);
    void printPOSTraversal(GatorAVL::StudentNode* root);
    

    
    GatorAVL::StudentNode* searchIDHelper(GatorAVL::StudentNode* root, int ID);
    void searchID(GatorAVL::StudentNode* root, int ID);
    bool searchIDBool(GatorAVL::StudentNode* root, int ID);
    void searchName(GatorAVL::StudentNode* root, string name);
    vector<GatorAVL::StudentNode*> searchNameHelper(GatorAVL::StudentNode* root, string name);
    int getLevels(GatorAVL::StudentNode* root);
    void printLevelCount(GatorAVL::StudentNode* root);
    bool verifyInput(istringstream& nextLineOfUserInput);
    void parseCommand(GatorAVL* tree, istringstream& nextLineOfUserInput);
    void executeRegularCommand(GatorAVL* tree, string command, int ID, string Name, int NthRemoval);
    void executeEmptyCommand(GatorAVL* tree, string command);
    


    


    









