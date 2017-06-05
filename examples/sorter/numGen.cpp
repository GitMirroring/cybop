#include <fstream>
#include <cstring>
#include <random>

using namespace std;

int main() 
{
    int elements = 1000;
    ofstream out;
    string txt = "";
    string filename = "./unsorted.txt";
    out.open(filename);

    random_device ranDev;
    mt19937 randNumGen(ranDev());
    uniform_int_distribution<int> numb(0, 1000);
    
    for(int i = 0; i < elements; i++)
    {
        int randNum = numb(randNumGen);
        txt += to_string(randNum);
        if(i < (elements - 1))
            txt += ",";
    }
    out << txt;
    out.close();
}