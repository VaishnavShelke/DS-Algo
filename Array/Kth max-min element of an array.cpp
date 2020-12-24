// A C++ program to find k'th smallest element using min heap
#include <climits>
#include <typeinfo>
#include <iostream>
using namespace std;



class MyMinHeap{
private:
    void MyHeapify(int i);      // Heapifyies the children of i

    //  Because we are designing the class such that as soon as the class is declared
    // It automatically forms the heap with the input array without the need to explicitly give commands in the main function

public:
    int *ptrheap;              // I am planning to make a pointer to array accessible to all sub functions of my class
    int heapsize;             // Why a pointer ?? why not an array itself ???
    int capacity;
// capacity stores the full potential of arr to store integers
                            /* First of all whatever variables you want to use repeatedly in the entire class and the functions / Methods
                            It is wise to make them global or accessible to all within the class.
                            Therefore you add all repeatedly used variables in public or private
 Now if you want to keep ptrheap as an array rather than pointer then the first problem which arises is that you dont know yet the
 size of the array;
 PLUS   due to higher memory demand of public variables it is wise to keep it a pointer.

 // Now lets list all the methods we want in our class
 // Lets begin with constructor first......*/
    MyMinHeap(int arr[],int arraysize);
                                          // We will pass a array into this from the main function
                                          // But...... See this class is not outsourcing the task of heapifying arr for main function
                                          // Array itself is a property of the calss


    // ... HE GOES TO PRIVATE...   void MyHeapify();
                            // This will heapify our class's arr, commonsense says thwt we should pass arr and size to this
                            // But rather than doing that we have made both of them global

    int MyExtract();        // Return and remove the smallest number in the min heap
    int MyGetmin();         // Return minimum from the heap
    int ShowSize();         // Show the size of the the heap
    // Basic functions
    int left(int i) {return 2*i + 1;}
    int right(int i) {return 2*i + 2;}
    int parent(int i) {return (i-1)/2;}
};

// ////////////////////// INHERITANCE AT WORK ////////////////////////////////////////////////////////////////// //
MyMinHeap :: MyMinHeap(int arr[],int arraysize){
                                           //Now since i have kept all the methods parameter less i will transfer the array to public ptrheap
    ptrheap = arr;
    heapsize = arraysize;
    capacity = heapsize;

    int i = (heapsize-1)/2;                     // Notice that i am taking heapsize not capacity
    while(i>=0){

        MyHeapify(i);
        i--;
    }
    // Made a heap and stored in place at ptrheap
    // Constructor hence no return
}

void MyMinHeap :: MyHeapify(int i){

    int parent = i;
    int leftchild = left(i);
    int rightchild = right(i);
    int smallest = parent;
    if (leftchild < heapsize && ptrheap[leftchild] < ptrheap[parent]){
        smallest = leftchild;
    }
    if (rightchild < heapsize && ptrheap[rightchild] < ptrheap[parent]){
        if (ptrheap[leftchild]>ptrheap[rightchild])
                smallest = rightchild;
    }
    if (smallest!= parent){swap(ptrheap[smallest],ptrheap[parent]);MyHeapify(smallest);}
    return;
}

int MyMinHeap :: MyGetmin(){
    return ptrheap[0];
}

int MyMinHeap :: MyExtract(){
    int result = ptrheap[0];
    ptrheap[0] = 1e6;
    MyHeapify(0);
    //heapsize--;
    return result;
}

int MyMinHeap :: ShowSize(){
    return heapsize;
}


int main(){
    int arr[] = {90,60,50,70,80};
    int arraysize = 5;
    MyMinHeap heap(arr,arraysize);
    for(int i = 0; i < 5;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < 5;i++){
        cout << heap.MyExtract() << " ";
        cout <<"\n\n";
        for(int j = 0; j< 5;j++){
            cout << arr[j] << " ";
        }
    }
    return 0;
}

