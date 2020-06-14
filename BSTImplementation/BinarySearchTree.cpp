//BinarySearchTree.cpp File

#include "BinarySearchTree.h"
#include<iostream>
using namespace std;

template <class ItemType>
BSTree<ItemType>::BSTree()
{
    root = NULL;
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
{
    if (tree == NULL)
    {
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}

template <class ItemType>
void BSTree<ItemType>::InsertItem(ItemType item)
{
    Insert(root, item);
}

template<class ItemType>
void BSTree<ItemType>::getMax(ItemType& item)
{
    TreeNode<ItemType> *temp=new TreeNode<ItemType>;
    temp=getMaxItem(root);
    item=temp->info;
}

template<class ItemType>
TreeNode<ItemType> *getMaxItem(TreeNode<ItemType> *root)
{
    if(!root)
        return NULL;

	if(root->right==NULL)
		return root;

	else
        return getMaxItem(root->right);

}

template<class ItemType>
void BSTree<ItemType>::getMin(ItemType& item)
{
    TreeNode<ItemType> *temp=new TreeNode<ItemType>;
    temp=getMinItem(root);
    item=temp->info;
}

template<class ItemType>
TreeNode<ItemType> *getMinItem(TreeNode<ItemType> *root)
{
    if(!root)
        return NULL;

	if(root->left==NULL)
		return root;

	else
        return getMinItem(root->left);
}
/*
template <class ItemType>
void BSTree<ItemType>::Sort()
{
    SortedOrder(root);
}

template <class ItemType>
void SortedOrder(TreeNode<ItemType> *root)
{
    if(root!=NULL)
   {
       SortedOrder(root->left);
       cout<<root->info<<" ";
       SortedOrder(root->right);
   }
}

template <class ItemType>
void BSTree<ItemType>::ReverseSort()
{
    RvrsSortedOrder(root);
}

template <class ItemType>
void RvrsSortedOrder(TreeNode<ItemType> *root)
{
    if(root!=NULL)
   {
       RvrsSortedOrder(root->right);
       cout<<root->info<<" ";
       RvrsSortedOrder(root->left);
   }
}
*/
template <class ItemType>
void BSTree<ItemType>::Sort(ItemType arr[])
{
    int num=CountNode(root);
    int temp=0;
    for(int i=0;i<num;++i)
    {
        for(int j=i+1;j<num;++j)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        cout<<arr[i]<<" ";
    }

}

template <class ItemType>
void BSTree<ItemType>::ReverseSort(ItemType arr[])
{
    int num=CountNode(root);
    int temp=0;
    for(int i=0;i<num;++i)
    {
        for(int j=i+1;j<num;++j)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        cout<<arr[i]<<" ";
    }

}

template <class ItemType>
void BSTree<ItemType>::getMedian(ItemType arr[])
{
    cout<<getMedianValue(root,arr);
}

template <class ItemType>
float getMedianValue(TreeNode<ItemType> *root, ItemType arr[])
{
    int n=CountNode(root);
    if(n%2!=0)
        return arr[n/2];
    else if(n%2==0)
    {
        int a=arr[n/2]+arr[n/2-1];
        return a/2.0;
    }
}

template <class ItemType>
int CountNode(TreeNode<ItemType> *root)
{
    if(root==NULL)
        return 0;
    else
        return CountNode(root->left)+1+CountNode(root->right);
}
