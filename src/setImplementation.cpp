
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include "Sessions.cpp"
using namespace std;


class SetImplementation
{

    
    public:
    class SetUser
    {
        //Metadata
        string NAME;
        string ufEmail;
        int Gator1ID;
        int phoneNumber;
        int roomNumber;

        //Sessions
        vector<Session> sessions;

        //Averages
        double avgWashTime;
        double avgDryTime;
        
        public:
        //Constructors
        SetUser()
        {
            Gator1ID = -1;
            NAME = "";
            phoneNumber = 0;
            roomNumber = 0;
            avgDryTime = 0;
            avgWashTime = 0;
        }

        SetUser(int inputGator1ID, string givenNAME)
        {
            Gator1ID = inputGator1ID;
            NAME = givenNAME;
            phoneNumber = 0;
            roomNumber = 0;
            avgDryTime = 0;
            avgWashTime = 0;
            
        }

        SetUser(int inputGator1ID, string givenNAME, int phone, int room)
        {
            Gator1ID = inputGator1ID;
            NAME = givenNAME;
            phoneNumber = phone;
            roomNumber = room;
            avgDryTime = 0;
            avgWashTime = 0;
            
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

        void setWashAverage(double average)
        {
            avgWashTime = average;
        }

        void setDryAverage(double average)
        {
            avgDryTime = average;
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

        string getNAME()
        {
            return NAME;
        }
        
        string getUFEmail()
        {
            return ufEmail;
        }

        Session getSession(int session)
        {
            return sessions.at(session);
        }

        double getWashAverage()
        {
            return avgWashTime;
        }

        double getDryAverage()
        {
            return avgDryTime;
        }

        //Calculate Averages on a per User Basis
        double userAverageWashing (SetUser* user)
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

        double userAverageDrying (SetUser* user)
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


    };

    set<SetUser> mset;


    void generate20Sesh(vector<SetUser*> ugh)
    {
        srand( (unsigned)time( NULL ) );      
        for(int i=0; i<ugh.size();i++)
        {

            string name=ugh.at(i)->getNAME();
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
                    ugh.at(i)->addSession(name,washUsed,dryUsed,washTime,dryTime);
            }
        }
    }

    vector<SetUser*> generateSetVector()
    {
        vector<SetUser*> setVector;
        set<SetUser>::iterator iter;

        for (iter = mset.begin(); iter != mset.end(); iter++)
        {
            SetUser temp = *iter;
            SetUser* tempPtr = &temp;
            setVector.push_back(tempPtr);
        }
        return setVector;
    }

    //Basically just get a vector of all of the washing times.
    vector<int> generateWashingTimesVector(vector<SetUser*> setUsers)
    {
        vector<int> averageWashingTimes;
        for (int i = 0; i < setUsers.size(); i++)
        {
            averageWashingTimes.push_back(setUsers.at(i)->getWashAverage());
        }
        return averageWashingTimes;
    }

    vector<int> generateDryingTimesVector(vector<SetUser*> setUsers)
    {
        vector<int> averageDryingTimes;
        for (int i = 0; i < setUsers.size(); i++)
        {
            averageDryingTimes.push_back(setUsers.at(i)->getWashAverage());
        }
        return averageDryingTimes;
    }

    double totalAverageWashing()
    {
        vector<SetUser*> setUsers = generateSetVector();
        vector<int> myVec= generateWashingTimesVector(setUsers);
            double avg;
        for(int i=0;i<myVec.size();i++)
        {
            avg=avg+(myVec.at(i));
        }

        avg=avg/(myVec.size());
            return avg;
    }

    double totalAverageDrying()
    {
        vector<SetUser*> setUsers = generateSetVector();
        vector<int> myVec= generateDryingTimesVector(setUsers);
        double avg;

        for(int i=0;i<myVec.size();i++)
        {
            avg=avg+(myVec.at(i));
        }

        avg=avg/(myVec.size());
        
        return avg;
    }

};