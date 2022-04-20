/*
ok so

need a way to represent a blob of users in a map
so 
users need to have 
    Name
    GatorID
    phone
    room

    average washing
    average drying

    vector<sessions>


*/
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include "Sessions.cpp"
using namespace std;


class MapImplementation
{

    
    public:
    class MapUser
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
        MapUser()
        {
            Gator1ID = -1;
            NAME = "";
            phoneNumber = 0;
            roomNumber = 0;
            avgDryTime = 0;
            avgWashTime = 0;
        }

        MapUser(int inputGator1ID, string givenNAME)
        {
            Gator1ID = inputGator1ID;
            NAME = givenNAME;
            phoneNumber = 0;
            roomNumber = 0;
            avgDryTime = 0;
            avgWashTime = 0;
            
        }

        MapUser(int inputGator1ID, string givenNAME, int phone, int room)
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
        double userAverageWashing (MapUser* user)
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

        double userAverageDrying (MapUser* user)
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

    unordered_map<int, MapUser> map;


    void generate20Sesh(vector<MapUser> ugh)
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

    vector<MapUser*> generateMapVector()
    {
        vector<MapUser*> mapVector;
        for (unordered_map<int, MapUser>::iterator iter = map.begin(); iter != map.end(); iter++)
        {
            MapUser temp = iter->second;
            MapUser* tempPtr = &temp;
            mapVector.push_back(tempPtr);
        }
        return mapVector;
    }

    //Basically just get a vector of all of the washing times.
    vector<int> generateWashingTimesVector(vector<MapUser*> mapUsers)
    {
        vector<int> averageWashingTimes;
        for (int i = 0; i < mapUsers.size(); i++)
        {
            averageWashingTimes.push_back(mapUsers.at(i)->getWashAverage());
        }
        return averageWashingTimes;
    }

    vector<int> generateDryingTimesVector(vector<MapUser*> mapUsers)
    {
        vector<int> averageDryingTimes;
        for (int i = 0; i < mapUsers.size(); i++)
        {
            averageDryingTimes.push_back(mapUsers.at(i)->getWashAverage());
        }
        return averageDryingTimes;
    }

    double totalAverageWashing(MapUser* root)
    {
        vector<MapUser*> mapUsers = generateMapVector();
        vector<int> myVec= generateWashingTimesVector(mapUsers);
            double avg;
        for(int i=0;i<myVec.size();i++)
        {
            avg=avg+(myVec.at(i));
        }

        avg=avg/(myVec.size());
            return avg;
    }

    double totalAverageDrying(MapUser* root)
    {
        vector<MapUser*> mapUsers = generateMapVector();
        vector<int> myVec= generateDryingTimesVector(mapUsers);
        double avg;

        for(int i=0;i<myVec.size();i++)
        {
            avg=avg+(myVec.at(i));
        }

        avg=avg/(myVec.size());
        
        return avg;
    }

};