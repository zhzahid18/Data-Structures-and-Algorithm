#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED
#include <iostream>
using namespace std;

class timeStamp
{
public:
    int sec, mint, hrs;
public:
    timeStamp();

    timeStamp(int ,int ,int );

    void printTime();
    int getSec();

    int getMin();

    int getHrs();



} ;


#endif // TIMESTAMP_H_INCLUDED
