#include "unsortedtype.h"
#include "studentinfo.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

void UnsortedType ::MakeEmpty()
{
    length = 0;
}

bool UnsortedType ::IsFull()
{
    return (length == MAX_ITEMS);
}

int UnsortedType ::LengthIs()
{
    return length;
}

void UnsortedType ::ResetList()
{
    currentPos = -1;
}

bool UnsortedType ::GetNextItem(StudentInfo& item)
{
    if(currentPos<length-1)
    {
        currentPos++;
        item = info [currentPos] ;
        return true;
    }
    return false;
}

bool UnsortedType ::RetrieveItem(StudentInfo& item, int id)
{
    int location = 0;
    bool found = false;
    while ((location < length) && !found)
    {
        if(id == info[location].getID())
        {
            found = true;
            item = info[location];
        }
        else
        {
            location++;
        }
    }
    return found;
}

bool UnsortedType ::InsertItem(StudentInfo item)
{
    if(!IsFull())
    {
        info[length] = item;
        length++;
        return true;
    }
    return false;
}

bool UnsortedType ::DeleteItem(int id)
{
    int flag = 0;
    int location = 0;
    while (location < length )
    {
        if(id == info[location].getID())
        {
            flag = 1;
            break;
        }
        location++;
    }
    if(flag==1)
    {
        info[location] = info[length - 1];
        length--;
        return true;
    }
    return false;
}


