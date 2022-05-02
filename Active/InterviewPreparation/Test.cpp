#include <bits/stdc++.h>
using namespace std; 


void FirstNonRepeatingChar(){
    string s;
    cin>>s;
    vector<int>hash(26,0);
    queue<char>process; 
    for(char c : s){
        process.push(c);
        hash[c-'a']+=1;
        while(not process.empty()){
            if(hash[process.front()-'a']>1) process.pop();
            else{
                cout<<process.front()<<' ';
                break;
            }
        }
        if(process.empty()) cout<<-1<<' ';
    }
}

class btreenode{
public:
    int val;
    btreenode* left;
    btreenode* right;

    btreenode(int x){
        val = x;
        left = right = NULL;
    }
};


class Binarytree{
public:
    btreenode *root; 
    Binarytree(){
        root = nullptr;
    }
    
    void preorder(btreenode *root){
        stack<btreenode*>table; 
        while(not table.empty() or root!=nullptr){
            while(root){
                cout<<root->val<<" ";
                table.push(root);
                root = root->left;
            }
            if(table.size()){
                root = table.top()->right;
                table.pop();
            }
        }
    }

    void inorder(btreenode *root){
        stack<btreenode*>table; 
        while(not table.empty() or root!=nullptr){
            while(root){
                table.push(root);
                root = root->left;
            }
            if(table.size()){
                cout<<table.top()->val<<' ';
                root = table.top()->right; 
                table.pop();
            }
        }
    }

    void postorder(btreenode *root){
        stack<btreenode*>table; 
        while(root!=nullptr or table.size()){
            if(root){
                table.push(root);
                root = root->left;
            }else{
                btreenode*tmp = nullptr;
                tmp = table.top()->right; 
                if(tmp==nullptr){
                    tmp = table.top();
                    cout<<tmp->val<<' ';
                    table.pop();
                    while(table.size() and tmp==table.top()->right){
                        tmp = table.top();
                        cout<<tmp->val<<' ';
                        table.pop();
                    }
                }else{
                    root = tmp;
                }
            }
        }
    }

    int height(btreenode *root){
        if(root==nullptr) return 0;
        return 1+max(height(root->left),height(root->right));
    }

    int daimter_of_tree =0;
    int daimeter(btreenode *root){
        if(root==nullptr) return 0; 
        int lefth = daimeter(root->left);
        int righth = daimeter(root->right);
        daimter_of_tree = max(daimter_of_tree,lefth+righth);
        return 1+max(lefth,righth);
    }

    btreenode* getbt1(){
        root = new btreenode(1);
        root->left = new btreenode(2);
        root->right = new btreenode(3);
        root->left->left = new btreenode(5);
        root->left->right = new btreenode(6);
        root->right->left = new btreenode(4);
        return root;
    }
};

int main(){
    Binarytree b; 
    cout<<b.daimeter(b.getbt1());
    return 0;
}