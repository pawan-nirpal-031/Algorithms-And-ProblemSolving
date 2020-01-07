#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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
typedef long double ld;
#define MOD 1000000007;
#define pub(a) push_back(a);
#define mp(a,b) make_pair(a,b);
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro only
#define ain(a,n) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
typedef long long int ll;
class node
{
    public:
    node *left;
    node *right;
    string word;
    string meaning;
    node(string d,string m)
    {
        this->word = d;
        this->meaning = m;
        left = right = NULL;
    }

};
class tree
{
    node *root;
    public:
     tree()
     {
         root = NULL;
     }
     void cerate(string  w,string m)
     {
         node *nn = new node(w,m);
         if (root==NULL)
         {
            root = nn;
         }
         else
         {
             node *tmp = root;
             node *p = root;
             while (tmp!=NULL)
             {
                 p = tmp;
                if (nn->word<tmp->word)
                {
                    tmp = tmp->left;
                }
                else
                {
                    tmp = tmp->right;
                }
                
             }
             if (nn->word<p->word)
             {
                p->left = nn;
             }
             else
             {
                 p->right = nn;
             }
             
         }
         
     }

     void inorder(node *tmp)
     {
         if (tmp!=NULL)
         {
            inorder(tmp->left);
            cout<<"Word : "<<tmp->word<<", meaning : "<<tmp->meaning<<endl;
            inorder(tmp->right);
         }
         
     }

     void callIn()
     {
         inorder(root);
     }
     void search(string w)
     {
         node *tmp = root;
         int y =0;
         while (tmp!=NULL)
         {
            if (tmp->word == w)
            {
                y = 1;
                break;
            }
            else if (tmp->word<w)
            {
                tmp = tmp->left;
            }
            else
            {
                tmp = tmp->right;
            }
            
         }
        if (y==1)
        {
            cout<<"Found ";
        }
        else
        {
            cout<<"not found";
        }
        
        
         
         
     }
    
};
int main()
{
    ios_base::sync_with_stdio(false);
    tree t;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter word and meaning "<<endl;
        string w;
        string m;
        cin>>w>>m;
        t.cerate(w,m);
    }
    cout<<"Dict is "<<endl;
    t.callIn();
    cout<<"Enter word to b searched "<<endl;
    string w;
    cin>>w;
    t.search(w);
   return 0;
}
