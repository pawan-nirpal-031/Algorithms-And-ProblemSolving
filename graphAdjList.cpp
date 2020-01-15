#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define setA0(a) for(ll i =0;i<1005;i++){a[i] = 0;}
class node{
    public:
    node*nxt;
    int v;
    node(int k){
        v = k;
        nxt = NULL;
    }
};
class graph{
    public:
    int n;
    node **g;
    graph(int k){
        n = k;
        g = new node *[n];
        for (int i = 0; i < n; i++)
        {
            g[i] = NULL;
        }
    }
    void create(int s,int d){
        node*cn = new node(d);
        if(g[s]==NULL){
            g[s] = cn;
        }
        else{
            node* t = g[s];
            while (t->nxt!=NULL)
            {
                t = t->nxt;
            }
            t->nxt = cn;
        }
    }
    void show(){
        for (int i = 0; i < n; i++)
        {
            cout<<"For vertex no ("<<i<<')';
            node* tmp = g[i];
            while (tmp!=NULL)
            {
                cout<<" -> "<<tmp->v<<' ';
                tmp = tmp->nxt;
            }
            cout<<endl;
        }
        
    }
    

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    graph g(n);
    for (int i = 0; i <n ; i++)
    {
        cout<<"enetr no of nodes connected to node "<<i<<endl;
        int k;
        cin>>k;
        for (int j = 0; j < k; j++)
        {
            cout<<"Enter value "<<endl;
            int x;
            cin>>x;
            g.create(i,x);
        }
        
    }
    g.show();


    return 0;
}