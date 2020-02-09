#include <iostream>
using namespace std;
class node{
    public:
    node* nxt;
    int d;
    node(int s){
        d = s;
        nxt = NULL;
    }
    node(){
        d = -1;
        nxt = NULL;
    }

};
class HT{
    int n;
    node *t;
   
    public:
    HT(int n){
       t = new node[n];
        this->n  = n;
        for(int i =0;i<n;i++){
            t[i].d = -1;
            t[i].nxt = NULL;
        }
    }
    int hash(int k){
        return (k%n);
    }
    void insert(int no){
        if(t[hash(no)].d == -1){
            t[hash(no)].d = no;
        }else{
            node *nn = &t[hash(no)];
            while(nn->nxt!=NULL){
                nn = nn->nxt;
            } 
            nn->nxt = new node(no);
        }

    }
    int find(int k){
        node* tmp = &t[hash(k)];
        if(tmp->d==k){
           return hash(k);
        }else{
            while(tmp->d!=k){
                tmp = tmp->nxt;
            }
           return  hash(k);
        }
       return -1;
   
    }
    void show(){
        for(int i =0;i<n;i++){
            node* tmp = &t[i];
            cout<<tmp->d<<" : ";
            while(tmp->nxt!=NULL){
                tmp = tmp->nxt;
                cout<<tmp->d<<"-> ";
                
            }
            cout<<'\n';
        }
    }

};
int main(){
    int n;
    cin>>n;
    HT h1(n);
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        h1.insert(x);
    }
    h1.show();
    int h;
    cin>>h;
    cout<<h1.find(h);
    return 0;
}
