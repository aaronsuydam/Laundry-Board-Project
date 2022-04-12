#include <iostream>
#include <vector>
#include<queue>
#include <iterator>
#include <sstream>
#include<iomanip>

using namespace std;
//used skeleton structure from TA zoom
struct Node
{   //defines node struct
    string name;
    int id;
    Node *left;
    Node *right;
    int height;

    Node(): id(0), left(nullptr), right(nullptr),height(0){}
    
    Node(string name, int id)
    {

    }

   int getHeight(Node *head, int id,int height)//gets height of node
    {
        if(head==NULL) 
        {
            return 0;
        }
         if(head->id==id) 
         {
             return height;
         }
        
        //check if the node is present in the left sub tree
        int level = getHeight(head->left,id,height+1);
        if(level!=0) 
        {
        return level;
        }
        
        //check if the node is present in the right sub tree
        return getHeight(head->right,id,height+1);
    }



};

class AVLTree
{
   Node *head=nullptr;
    public:

    int maxDepth(Node* node)//gets the maximum depth of a tree
    {
       if (node == NULL)
        {
            return 0;
        }
        else
        {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);        
            if (lDepth > rDepth)
            {
                return(lDepth + 1);
            }           
            else 
            {
                return(rDepth + 1);
            }
            
        }
    }
    
    Node* returnHead()//helper method, returns head of tree
    {
        return head;
    
    }

    Node* rotateLeft(Node *node)//rotates tree using Left Left rotation
    {
        Node* newRoot = node->right;
	    Node* leftOfNewRoot = newRoot->left;
	    node->right = leftOfNewRoot;
	    newRoot->left = node;
        
    
	    return newRoot;
    }


    Node* rotateRight(Node *node)//rotates tree using right rotation
    {
        Node* newRoot = node->left;  
        Node* rightOfNewRoot = newRoot->right;
        node->left = rightOfNewRoot;
        newRoot->right = node;
        return newRoot;
       
    }

   Node* rotateRightLeft(Node* node)//rotates tree using right left rotation
    {
        Node* myNode = node;
        Node* tempNode= myNode->right;
        Node* tempNode2 =myNode->right->left;

        myNode -> right = tempNode2->left;
        tempNode ->left = tempNode2->right;
        tempNode2 ->left = myNode;
        tempNode2->right = tempNode; 
        
        return tempNode2; 
    }
    Node* rotateLeftRight(Node *node)//rotates tree using left right rotation
    {
        Node* myNode = node;
        Node* tempNode= myNode->left;
        Node* tempNode2 =myNode->left->right;

        myNode -> left = tempNode2->right;
        tempNode ->right = tempNode2->left;
        tempNode2 ->right = myNode;
        tempNode2->left = tempNode; 
        
        return tempNode2; 
    }


    int max(int a, int b)//returns greatest
    {
        return (a >= b) ? a : b;
    }
    int getLeftHeight(Node* root)
    {
        Node* temp=nullptr;
         Node* temp2=nullptr;
        while(root!=nullptr)
        {
            temp=root;
            root=root->left;
        }
        temp2=temp;
        if(temp->right!=nullptr&&temp->getHeight(head,temp->id,1)!=1)
        {
           
            while(temp!=nullptr)
            {
            temp2=temp;
            temp=temp->right;
            }
        }
        return temp2->getHeight(head,temp2->id,1);
    }
     int getRightHeight(Node* root)
    {
        Node* temp=nullptr;
        Node* temp2=nullptr;
        while(root!=nullptr)
        {
            temp=root;
            root=root->right;
        }
        temp2=temp;
        if(temp->left!=nullptr&&(temp->getHeight(head,temp->id,1))!=1)
        {
            while(temp!=nullptr)
            {
                temp2=temp;
                temp=temp->left;
            }
        }
        return temp2->getHeight(head,temp2->id,1);
    }


    int checkNodeBalance(AVLTree* myTree, Node* root)//checks if each node is blanced
    {
            if (root == nullptr ) //base case
            {
                return 0;
            }
    
        // get height of left subtree
        int left_height = myTree->getLeftHeight(root);
    
        // get height of right subtree
        int right_height =  myTree->getRightHeight(root);
    
        int rightBalance=checkNodeBalance(myTree,root->right);

        if (left_height - right_height <-2 && rightBalance>1)//if root is imbalanced perform rotation based on imbalance
        {
           head= rotateRight(root);
            head=rotateLeft(root);
        }
        if (left_height - right_height >2 && checkNodeBalance(myTree,root->left)<-1)
        {
             head= rotateLeft(root);
            head=rotateRight(root);
            
        }
        if (left_height - right_height > 1) //if root is imbalanced perfom rotation based on imbalance
        {
            head=myTree->rotateRight(root);
           
        }
        else if(left_height - right_height < -1)
        {
           
             head=myTree->rotateLeft(root);
           
        }

    
       
        return max(left_height, right_height) + 1;
    }

    bool isAVL(Node* root)//checks if tree is an AVL/balanced
    {
            int leftHeight;
            int rightHeight;
            if(root == NULL)//base case
            {
                return 1;
            }
            if(root->left!=nullptr&&root->right!=nullptr)//if left and right are not null continue to get height
            {
                leftHeight = root->left->height;
                rightHeight = root->right->height;
            }
            if(abs(leftHeight-rightHeight) <= 1 && isAVL(root->left) && isAVL(root->right))
            {
                return 1;
            }
            return 0;
    }


  
int count=0;
int depthCount=0;
    Node* insert(Node* rootN, string name, int ID)//insert function
    {
        if(rootN!=nullptr&&rootN->id==ID)
        {
            return nullptr;
        }
        if(rootN==nullptr)
        {
           
            Node* rNode=new Node;
            rNode->name=name;
            rNode->id=ID;
            if(count==0)//checks if this is first time inserting node
            {
                head=rNode;
                count++;
                return rNode;
            }
            rNode->height=rNode->getHeight(head,rNode->id,0);
            return rNode;
             
        }

        if (ID > rootN->id)//if id is greater than root id go into right subtree else, left
        {
         rootN->right = insert(rootN->right, name, ID);
        }
        else
        {
            rootN->left = insert(rootN->left, name,ID);
        }
       
        return rootN;
    }

     Node* smallestNode(Node* node)//finds smallest node 
    {
        Node* current = node;
 
        //loop down left to find smallest node
        while (current && current->left != NULL)
        {
            current = current->left;
        }
 
        return current;
    }

    Node* removeID(Node* root,int id)
    {
        if (root == nullptr)//base case
        {
            return root;
        }
 
        //if id is smaller than the root key, then it's in the left subtree
        if (id < root->id)
        {
        root->left = removeID(root->left, id);
        }
        else if (id > root->id)  //if id is greater than the root key, then it's in the right subtree
        {
            root->right = removeID(root->right, id);
        }
        else  // if id is same as root's id, then this is the node to be deleted
        {
            // node has no child
            if (root->left==nullptr && root->right==nullptr)
            {
                return nullptr;
            }
            else if (root->left == nullptr) // node has one child 
            {
                Node* myNode = root->right;
                root=nullptr;
                return myNode;
            }
            else if (root->right == nullptr) // node has one child 
            {
                Node* myNode = root->left;
                root=nullptr;
                return myNode;
            }
    
            //if node with two children, get smallest in right subtree
            Node* myNode = smallestNode(root->right);

            // Copy temp to this node
            root->id= myNode->id;
            root->name= myNode->name;
            // Delete the inorder successor
           root->right = removeID(root->right, myNode->id);
        }
        return root;
    }

    int inorderCounter=0;
    int removeInorder(Node* root,int numNode)//removes a node at position numNode in an inorder traversal
    {
        
        if (root != nullptr)
        {
           
            if(inorderCounter==numNode)//if position is reached delete node, reset counter
            {
                removeID(head,root->id);
                cout<<"successful"<<endl;
                inorderCounter=0;
                return 1;
            }
           
        removeInorder(root->left,numNode);
         inorderCounter++;
        removeInorder(root->right,numNode);
        }
        else
        {   
            if(inorderCounter>numNode)  
            { 
            return 0;   
            }        
        }
        return 1;
    }

   void searchID(Node* current, int id, Node* root)// search for ID return name
    {
        int treeHeight=maxDepth(head);
        int count=0;
            while (current != nullptr && current->id != id)
            {               
                root = current;

                if (id < current->id) //if id is less than current id go left, else go right
                {
                    current = current->left;
                }
                else 
                {
                    current = current->right;
                }
                count++;
            }
            if(current!=nullptr&&current->id==id)
            {
                 cout<<current->name<<endl;
            }
            else if(treeHeight==count)
            {
                cout<<"unsuccessful"<<endl;
            }
        
    }

    int searchNameLeft(Node* current, string name,Node* root)
    {
        int treeHeight=maxDepth(head);
        int count=0;
      
            while (current != nullptr && current->name.compare(name)!=0)
            {     
                 if(root!=nullptr&&root->right!=nullptr)
                {
                    current=current->right;
                    while (current != nullptr && current->name.compare(name)!=0)
                    {               
                    root = current;
                    current = current->right;   
                    count++;          
                    }

                    if(current!=nullptr&&current->name.compare(name)==0&&root!=nullptr)
                    {
                    cout<<std::internal<< std::setfill('0')<< std::setw(8)<<current->id<<endl;
                    return 1;
                    }
                }    
                if(current!=nullptr)
                {   
                root = current;
                current = current->left;   
                count++;
                }          
            }
            
          
            
            if(current!=nullptr&&current->name.compare(name)==0&&root!=nullptr)
            {
                cout<<std::internal<< std::setfill('0')<< std::setw(8)<<current->id<<endl;
                return 1;
            }
            return 0;
    }

   void searchName(Node* current, string name, Node* root)//search for name, return ID
    {
       int treeHeight=maxDepth(head);
         int count=0;
            int leftS=searchNameLeft(current,name,root);
            while (current != nullptr && current->name.compare(name)!=0)
            {            
                if(root!=nullptr&&root->right!=nullptr)
                {
                    current=current->right;
                    while (current != nullptr && current->name.compare(name)!=0)
                    {               
                    root = current;
                    current = current->right;   
                    count++;          
                    }

                    if(current!=nullptr&&current->name.compare(name)==0&&root!=nullptr)
                    {
                    cout<<std::internal<< std::setfill('0')<< std::setw(8)<<current->id<<endl;                   
                    }
                }     

                if(current!=nullptr)
                {
                root = current;
                current = current->right;   
                count++;       
                }   
            }

            


            if(current!=nullptr&&current->name.compare(name)==0)
            {
                cout<<std::internal<< std::setfill('0')<< std::setw(8)<<current->id<<endl;
            }
 	        else if(treeHeight==count&&leftS!=1)
            {
                cout<<"unsuccessful"<<endl;
            }
            
            
    }

    vector<string> ioVector;
    void printInorder(Node* root)//creates vector of name in inorder format
    {
       if (root != nullptr)
        {
        printInorder(root->left);
        ioVector.push_back(root->name);
        printInorder(root->right);
       
        }
        else
        {            
            return;           
        }
    }
    void printIOPrinter()//prints inorder vector
    {
        for(int i=0; i<ioVector.size();i++)
        {
            if(i<ioVector.size()-1)
            {
                cout<<ioVector.at(i)<<", ";
            }
            else{
                cout<<ioVector.at(i)<<endl;
            }
        }
        ioVector.clear();
    }

    vector<string> POVector;
    void printPreorder(Node* root)//creates vector of names is preorder format
    {
        if (root != NULL)
        {
         POVector.push_back(root->name);
        printPreorder(root->left);
        printPreorder(root->right);
        }
        else{
            return;
        }
    }

    void printPOPrinter()//prints pre order vector
    {
        for(int i=0; i<POVector.size();i++)
        {
            if(i<POVector.size()-1)
            {
                
                cout<<POVector.at(i)<<", ";
            }
            else{
                cout<<POVector.at(i)<<endl;
            }
        }
        POVector.clear();
    }

vector<string> POSTVector;
    void printPostorder(Node* root)//creates vector of names in postorder formation
    {
       if (root != NULL)
        {
        printPostorder(root->left);
        printPostorder(root->right);
        POSTVector.push_back(root->name);
        }
    }

    void printPOSTPrinter()//prints post order vector
    {
        for(int i=0; i<POSTVector.size();i++)
        {
            if(i<POSTVector.size()-1)
            {
                cout<<POSTVector.at(i)<<", ";
            }
            else{
                cout<<POSTVector.at(i)<<endl;
            }
        }
        POSTVector.clear();
    }


    void printLevelCount(Node* root)//prints number of levels in tree (starts with head level==1)
    {
      cout<< maxDepth(root)<<endl;
    }
    

   
    

};

void commandHelper(AVLTree* myTree, string command)
{
    string name;
    string idOrName;
        //following statements check the command inputted and match it to functions
        if(command.compare("printInorder")==0)
        {
            Node* head= nullptr;
            head=myTree->returnHead();
            myTree->printInorder(head);
            myTree->printIOPrinter();
        }

        if(command.compare("printPreorder")==0)
        {
            Node* head= nullptr;
            head=myTree->returnHead();
            myTree->printPreorder(head);
            myTree->printPOPrinter();
        }

        if(command.compare("printPostorder")==0)
        {
            Node* head= nullptr;
            head=myTree->returnHead();
             myTree->printPostorder(head);
            myTree->printPOSTPrinter();
        }

        if(command.compare("printLevelCount")==0)
        {
            Node* head= nullptr;
            head=myTree->returnHead();
            myTree->printLevelCount(head);
          
        }
    else if(command.compare("remove")==0||command.compare("search")==0)//checks if command is remove or search
    {
        
            Node* head= nullptr;
            head=myTree->returnHead();
            getline(cin,idOrName);
            
            char subString=idOrName[7];//grabs first character

            if(isdigit(subString)>0)//if input on line is an ID (based on first character)
            {
                idOrName=idOrName.substr(1);
                if(idOrName.length()==8)//checks if id is in fact 8 digits long
                {
                int id=stoi(idOrName);
                    if(command.compare("remove")==0)
                    {
                        
                        if(myTree->removeID(head,id)==nullptr)
                        {
                            cout<<"unsuccessful"<<endl;
                        }
                        else
                        {
                        cout<<"successful"<<endl;
                        }
                    }
                    else{
                        myTree->searchID(head,id,nullptr);
                    }
                }
                else
                {
                    cout<<"unsuccessful"<<endl;
                }
                
            }
            if(isdigit(subString)==0)//input on line is a name
            {
               string delimeter="\"";
           
                 string delimeter1="\" ";//does same as below, but instead finds ID
               size_t a=idOrName.find(delimeter); //finds first quote mark
                size_t b=idOrName.find(delimeter, a+1); //finds second quote mark
                idOrName=idOrName.substr(a + 1, b - a -1);


                if (idOrName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_ ") != std::string::npos)//checks to see if name contains non acceptable characters
                {
                        cout<<"unsuccessful"<<endl;
                }
                else
                {
                    myTree->searchName(head,idOrName,nullptr);       
                }             
            }
            

            
           
    }
    else if(command.compare("insert")==0)
    {
            string inputID;
            string delimeter="\"";

            getline(cin,name);

            string delimeter1="\" ";//does same as below, but instead finds ID
            size_t a1=name.find(delimeter1);
            inputID=name.substr(a1 + 2);

            size_t a=name.find(delimeter); //finds first quote mark
            size_t b=name.find(delimeter, a+1); //finds second quote mark
            name=name.substr(a + 1, b - a -1);//creates name from within quote marks

            Node* head= nullptr;
            head=myTree->returnHead();   
            
            if(inputID.length()==8)//checks if input id is correct length
            {
                if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_ ") != std::string::npos)//checks to see if name contains non acceptable characters
                {
                    cout<<"unsuccessful"<<endl;
                }
                else
                {
                    int intInput= stoi(inputID);
                    if(myTree->insert(head,name,intInput)!=nullptr)//insert
                    {
                        if(myTree->isAVL(head)==0)//checks if AVL, balances
                        {
                            myTree->checkNodeBalance(myTree,head);
                        }
                        cout<<"successful"<<endl;
                    }
                    else
                    {
                   
                        cout<<"unsuccessful"<<endl;
                    }
                    

                }
            } 
            else{
                cout<<"unsuccessful"<<endl;
            }
           
    }
    else if(command.compare("removeInorder")==0)
    {
            int inputID;
            cin>>inputID;

            Node* head= nullptr;
            head=myTree->returnHead(); 

            if(myTree->removeInorder(head,inputID)!=1)
            {
                cout<<"unsuccessful"<<endl;
            }
    }
}


int main()
{
    AVLTree* myTree=new AVLTree;//creates empty tree
    int commandCount;
    cin>>commandCount;
    int loopCount=0;
    while(loopCount<commandCount)
    {
        string name;
        string command;
        string idOrName;

        cin>>command;
        commandHelper(myTree,command);
    
        loopCount++;
    }

    delete myTree;//deletes tree
}