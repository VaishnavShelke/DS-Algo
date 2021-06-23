// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;
int counter = 0;

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inOrder(int* tree,int* sortedArr,int parent,int size,unordered_map<int,int>& posInTree){

    static int index = 0;
    if(parent>=size) return;
    inOrder(tree,sortedArr,2*parent+1,size,posInTree);

    if(sortedArr[index] == tree[parent]){
        index++;
    }
    else{
        int expPos = posInTree[sortedArr[index]];
        posInTree[sortedArr[index]] = parent;
        posInTree[tree[parent]] = expPos;
        counter = counter + 1;
        swap(&tree[parent],&tree[expPos]);
        index++;
    }

    inOrder(tree,sortedArr,2*parent+2,size,posInTree);
    return;
}

void swapsDone(int* tree,int size){
    
    int sortedArr[size];
    int index = 0;
    unordered_map<int,int> posInTree;
    for(int i = 0; i<size ; i++){
        sortedArr[i] = tree[i];
        posInTree[tree[i]] = i;
    } 
    sort(sortedArr,sortedArr+size);
    
    inOrder(tree,sortedArr,0,size,posInTree);

}

void printInOrder(int* tree,int parent,int size){


    if(parent>=size) return;
    printInOrder(tree,2*parent+1,size);
    cout << tree[parent] << " ";
    printInOrder(tree,2*parent+2,size);
    return;
}
int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    swapsDone(a,n);
    printInOrder(a,0,n);
    cout << "\n";
    cout << "Minimum Swaps Required ... " << counter;
    return 0;
}
