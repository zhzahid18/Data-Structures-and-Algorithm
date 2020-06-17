#include "sortedtype.h"
#include "sortedtype.cpp"
#include "timestamp.h"
#include "timestamp.cpp"
#include <iostream>
using namespace std;

int main()
{
    SortedType st;

    cout<<"Enter the number of time objects to store: ";
    int len;
    cin>>len;

    timeStamp info[len];

    int f=1;
    for(int i=0;i<len;i++)
    {
        cout<<"Enter second for "<<f<<" time: ";
        int t_s;
        cin>>t_s;

        cout<<"Enter minute for "<<f<<" time: ";
        int t_m;
        cin>>t_m;

        cout<<"Enter hours for "<<f<<" time: ";
        int t_h;
        cin>>t_h;

        timeStamp ts(t_s,t_m,t_h);
        info[i]=ts;
        st.InsertItem(ts);
        f=f+1;
    }


    cout<<endl;
    cout<<"Printing list of Time: "<<endl;
    timeStamp obj2;
    for(int i=0;i<len;i++)
    {
        if(st.GetNextItem(obj2))
        {
            obj2.printTime();
        }
    }
    cout<<endl;
    cout<<"Enter time(second minute hour) to delete: ";
    int t1_s,t1_m,t1_h;
    cin>>t1_s>>t1_m>>t1_h;


    while(!st.DeleteItem(t1_s,t1_m,t1_h))
    {
        st.DeleteItem(t1_s,t1_m,t1_h);
    }
    st.ResetList();
    cout<<endl;
    cout<<"Printing List: "<<endl;

    for(int i=0;i<len;i++)
    {
        if(st.GetNextItem(obj2))
        {
            obj2.printTime();
        }
    }


}
