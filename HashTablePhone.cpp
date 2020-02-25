#include <iostream>
using namespace std;
class node{
    public:
    node* nxt;
    int d;
    string name;
    bool y;
    node(int s,string nm,bool u){
        d = s;
        name = nm;
        y = u;
        nxt = NULL;
    }
    node(){
        d = -1;
        y =0;
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
            t[i].y =0;
            t[i].nxt = NULL;
        }
    }
    int hash(int k){
        return (k%n);
    }
    void insert(int no,string nm,bool s){
        
        if(t[hash(no)].d == -1){
            
            t[hash(no)].d = no;
            t[hash(no)].name = nm;
            t[hash(no)].y = s;

        }else{
            node *nn = &t[hash(no)];
            while(nn->nxt!=NULL){
                nn = nn->nxt;
            } 
            nn->nxt = new node(no,nm,s);
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
            cout<<tmp->d<<" : "<<" name : "<<tmp->name<<" status : "<<tmp->y<<" ";
            while(tmp->nxt!=NULL){
                tmp = tmp->nxt;
                cout<<tmp->d<<" : "<<" name : "<<tmp->name<<" status : "<<tmp->y<<" ";
                
            }
            cout<<'\n';
        }
    }
    void Remove(int no){
        if(t[hash(no%n)].nxt == NULL && t[hash(no%n)].d !=-1){
            t[hash(no%n)].d = -1;
            t[hash(no%n)].name = "";
            t[hash(no%n)].y  =0;
        }else{
            node* pre = &t[hash(no%n)];
            node* tmp = &t[hash(no%n)];
            while(tmp->d!=no){
                if(tmp->nxt!=NULL && tmp->nxt->d ==no){
                    pre = tmp;
                }
                tmp = tmp->nxt;

            }
            if(tmp->nxt == NULL){
                pre->nxt = NULL;
            }else{
                pre->nxt = tmp->nxt;
            }
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
        string nm;
        cin>>nm;
        bool st;
        cin>>st;
        h1.insert(x,nm,st);
    }
    h1.show();
    int h;
    cin>>h;
    cout<<h1.find(h);
    int r;
    cin>>r;
    h1.Remove(r);
    h1.show();
    return 0;
}