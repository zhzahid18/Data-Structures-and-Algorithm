#include "unsortedtype.h"
#include "unsortedtype.cpp"
#include "studentinfo.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    UnsortedType ut;

    cout<<"Enter the number of student record to store: ";
    int len;
    cin>>len;

    StudentInfo info[len];

    int f=1;
    for(int i=0;i<len;i++)
    {
        cout<<"Enter name of "<<f<<" student: ";
        string s_n;
        cin>>s_n;

        cout<<"\nEnter id of "<<f<<" student: ";
        int s_id;
        cin>>s_id;

        cout<<"\nEnter cgpa of "<<f<<" student: ";
        double s_cg;
        cin>>s_cg;

        StudentInfo si(s_id,s_n,s_cg);
        info[i]=si;
        ut.InsertItem(si);
        f=f+1;
    }

    cout<<endl;
    StudentInfo obj2;
    cout<<"Student Records are: "<<endl;
    for(int i=0;i<len;i++)
    {
        if(ut.GetNextItem(obj2))
        {
            obj2.printStudent();
        }
    }

    cout<< "\nEnter an id number to delete : " <<endl;
    int d_id;
    cin>>d_id;

    while(!ut.DeleteItem(d_id))
    {
        ut.DeleteItem(d_id);
    }
    ut.ResetList();

    cout<<"\nAfter deletion, Student Records are: "<<endl;
    for(int i=0;i<len;i++)
    {
        if(ut.GetNextItem(obj2))
        {
            obj2.printStudent();
        }

    }

    cout<< "\nEnter an id number to retrieve : " <<endl;
    int r_id;
    cin>>r_id;

   for(int i=0;i<len;i++)
   {
       StudentInfo obj1=info[i];
       if(ut.RetrieveItem(obj1,r_id))
       {
           cout<<"Record is found."<<endl;
           obj1.printStudent();
           break;
       }
       else
       {
           cout<<"Rcord is Not Found.";
           break;
       }
   }


}

