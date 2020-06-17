#include "timestamp.h"
#include <iostream>
using namespace std;

timeStamp::timeStamp()
{

}

timeStamp::timeStamp(int s,int m,int h)
{
    sec=s;
    mint=m;
    hrs=h;
}

void timeStamp::printTime()
{
    cout<<"s:"<<sec<<" m:"<<mint<<" h:"<<hrs<<endl;
}

int timeStamp::getSec()
{
    return sec;
}

int timeStamp::getMin()
{
    return mint;
}

int timeStamp::getHrs()
{
    return hrs;
}





