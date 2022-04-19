#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <bitset>
#include <ctime> 
#include <string>
using namespace std;
std::ofstream outputFl("fullInput.txt");



int yeet()
{
    string input;
    cin >> input;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::ifstream file(input);
    std::string str;


    while (std::getline(file, str))
    {
        string name = " " + str;
        string nameID;
        string nameRm;
        string namePhn;
        nameID = nameID + name;
        for (int count = 0; count <= 7; count++)
        {

            int myRand = (rand() % 9);
            nameID = to_string(myRand) + nameID;

        }
        nameID = nameID + " ";// 12345678 John Smith 
        nameRm = nameID;
        for (int count = 0; count <= 2; count++)
        {

            int myRand = (rand() % 9);
            nameRm = nameRm + to_string(myRand);

        }
        nameRm = nameRm + " ";//12345678 John Smith 123
        namePhn = nameRm;
        for (int count = 0; count <= 9; count++)
        {
            
            int myRand = (rand() % 9);
            namePhn = namePhn + to_string(myRand);   //12345678 John Smith 123 1234567890        
        }



        outputFl << namePhn << endl;


    }




    return 1;
}
int main()
{
    yeet();
    return 1;
}