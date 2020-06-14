//BinarySearchTree.h File

#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include<iostream>

using namespace std;

template <class ItemType>
struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

template <class ItemType>
class BSTree
{
public:
    BSTree();
    void InsertItem(ItemType item);
    void getMax(ItemType& item);
    void getMin(ItemType& item);
    void Sort(ItemType arr[]);
    void ReverseSort(ItemType arr[]);
    void getMedian(ItemType arr[]);
private:
    TreeNode<ItemType>* root;
    ItemType *items;
    ItemType item;
};
#endif
