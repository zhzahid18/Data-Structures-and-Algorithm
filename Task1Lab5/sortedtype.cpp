#include "sortedtype.h"
#include "timestamp.h"
#include <iostream>
using namespace std;

SortedType::SortedType()
{
    length = 0;
    currentPos = - 1;
}
 void SortedType::MakeEmpty()
{
    length = 0;
}

bool SortedType::IsFull()
{
    return (length == MAX_ITEMS);
}
 int SortedType::LengthIs()
{
    return length;
}
 void SortedType::ResetList()
{
    currentPos = - 1;
}

bool SortedType::GetNextItem(timeStamp& time)
{
    if(currentPos<length-1)
    {
        currentPos++;
        time = info [currentPos];
        return true;
    }
    return false;
}

bool SortedType::InsertItem(timeStamp time)
{
    if(IsFull())
        return false;
    int location = 0;
    while (location < length)
    {
        if(time.getSec() >= info[location].getSec())
        {
            location++;
        }
        else if(time.getSec() < info[location].getSec())
            break;
    }
    for (int index = length; index > location; index--)
        info[index] = info[index - 1];
    info[location] = time;
    length++;
    return true;
}

bool SortedType::DeleteItem(int a,int b,int c)
{
    int location = 0;
    bool deleted = false;
    while (location < length)
    {
        if(a == info[location].getSec() && b==info[location].getMin() && c==info[location].getHrs())
        {
            deleted = true;
            break;
        }
        location++;
    }
    if(!deleted)
        return deleted;
    for (int index = location + 1; index < length; index++)
        info[index - 1] = info[index];
    length--;
    return deleted;
}

bool SortedType::RetrieveItem(timeStamp& time, int sec)
{
    int midPoint, first = 0, last = length - 1;
    bool found = false;
    while ((first <= last) && !found)
    {
        midPoint = (first + last) / 2;
        if(sec < info[midPoint].getSec())
        {
            last = midPoint - 1;
        }
        else if(sec > info[midPoint].getSec())
        {
            first = midPoint + 1;
        }
        else
        {
            found = true;
            time = info[midPoint];
        }
    }
    return found;
}

