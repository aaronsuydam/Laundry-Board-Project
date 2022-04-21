#include <string>
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
