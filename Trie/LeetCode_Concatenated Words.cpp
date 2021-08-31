typedef vector<string> vvs;

class node{
public:
    bool lastletter;
    node* arr[26];
    node(){
        lastletter = false; 
        for(int i = 0; i<26 ; i++) arr[i] = NULL;
    }
};

void insert(node* root,string str){
    node* treenode = root;
    
    for(int i = 0; i<str.size() ; i++){
        if(treenode->arr[str[i]-'a'] == NULL){
            treenode->arr[str[i]-'a'] = new node();
        }
        treenode = treenode->arr[str[i]-'a'];
    }
    treenode->lastletter = true;
}


bool search1(node* root,string str){
    node* treenode = root;
    if(str.size() == 0) return true;
    for(int i = 0; i<str.size() ; i++){
        if(treenode->arr[str[i]-'a'] == NULL){
            return false;
        }
        treenode = treenode->arr[str[i]-'a'];
        if(treenode->lastletter == true){
            if(search1(root,str.substr(i+1))){
                return true;
            }
        }
    }
    if(treenode->lastletter == true)
        return true;
    else return false;
}

bool search(node* root,string str){
    node* treenode = root;
    if(str.size() == 0) return false;
    for(int i = 0; i<str.size() ; i++){
        if(treenode->arr[str[i]-'a'] == NULL){
            return false;
        }
        treenode = treenode->arr[str[i]-'a'];
        if(treenode->lastletter){
            if(i == str.size()-1) return false;
            if(search1(root,str.substr(i+1))){
                return true;
            }
        }
    }
    
    return false;
}





class Solution {
public:
    vvs findAllConcatenatedWordsInADict(vvs& words) {
       
        node* root = new node();
        for(string str: words){
            insert(root,str);
        }
        
        vvs ans;
        
        for(string str: words){
            if(search(root,str)){
                ans.push_back(str);
            }
        }
        
        return ans;
    }
};
