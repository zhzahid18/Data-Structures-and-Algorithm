//main.cpp (Driver File)

#include "BinarySearchTree.cpp"
#include <iostream>

using namespace std;

int main()
{
    BSTree<int> bt;
    int n;
    cout<<"\n  How much nodes you want to input: ";
    cin>>n;
    int arr[n];
    cout<<"  Enter Nodes: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        bt.InsertItem(arr[i]);

    }

    cout<<endl;

    cout<<"\n  Maximum Value: ";
    int x;
    bt.getMax(x);
    cout<<x;

    cout<<endl;

    cout<<"\n  Minimum Value: ";
    int y;
    bt.getMin(y);
    cout<<y;

    cout<<endl;

    cout<<"\n  Items in Sorted(Ascending) Order: ";
    bt.Sort(arr);

    cout<<endl;

    cout<<"\n  Items in Reverse Sorted(Descending) Order: ";
    bt.ReverseSort(arr);

    int temp=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
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

    cout<<"\n  Median Value: ";
    bt.getMedian(arr);

    cout<<endl;

    return 0;
}
