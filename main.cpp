// main.cpp (driver file)

#include <iostream>
#include "quetype.cpp"
using namespace std;

int main()
{

    int n;
    QueueType<int> q;
    while(1)
    {
    cout<<"  Enter N: ";
    cin>>n;
    if(n==0)
        break;
    int arr[n];
    cout<<"  Enter values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int temp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    cout<<endl;

    int c=0,t;
    for(int i=0;i<n;i++)
    {
        c=c+arr[i];
        if(c==arr[0])
            t=0;
        else
            t=t+c;
    }
    q.EnQueue(t);
    }

    cout<<"  Minimum Cost: "<<endl;
    while(!q.IsEmpty())
    {
        int t;
        q.DeQueue(t);
        cout<<"  "<<t<<endl;
    }

    return 0;
}

