#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                   Implement LRU Chache                                       
 * *                                               
 **/

class LRUChache{
private:
    int maxSize;
    list<int> dllChache;
    unordered_map<int,list<int> :: iterator> hashT;
public:
    LRUChache(int vol){ maxSize = vol;}

    void refer(int key){
        if(hashT.find(key) != hashT.end()){
            dllChache.erase(hashT[key]);
            hashT.erase(key);
        }
        else{
            if(dllChache.size() == maxSize){
                hashT.erase(dllChache.back());
                dllChache.pop_back();
            }
        }
        dllChache.push_front(key);
        hashT[key] = dllChache.begin();
    }

    int get(int key){
        if(hashT.find(key) != hashT.end()){
            dllChache.erase(hashT[key]);
            hashT.erase(key);
            dllChache.push_front(key);
            hashT[key] = dllChache.begin(); 
            return key;
        }
        else{
            return -1;
        }
    }

    void display(){
        for(auto a : dllChache){
            cout << a << " ";
        }
    }
};

int main()
{
    LRUChache ca(4);
  
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
  
    return 0;
}
