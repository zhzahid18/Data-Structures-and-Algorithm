#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
#include "timestamp.h"
#include <iostream>
using namespace std;
const int MAX_ITEMS = 5;
class SortedType
{
public :
    SortedType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    bool InsertItem(timeStamp);
    bool DeleteItem(int ,int ,int );
    bool RetrieveItem(timeStamp&, int);
    void ResetList();
    bool GetNextItem(timeStamp&);
private:
    int length;
    timeStamp info[MAX_ITEMS];
    int currentPos;
};
#endif // SORTEDTYPE_H_INCLUDED
