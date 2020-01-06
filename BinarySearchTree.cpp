#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class node
{
    
    public:
    node *l;
    node *r;
    int d;
     node(int x)
     {
         this->d= x;
         l = r = NULL;
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
     void create(int x)
     {
         node *nn = new node(x);
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
                if (nn->d<tmp->d)
                {
                    tmp = tmp->l;
                }
                else
                {
                    tmp = tmp->r;
                }

             }
             if (p->d>nn->d)
             {
                p->l = nn;
             }
             else
             {
                 p->r = nn;
             }
             
             
             
         }
         
         
     }
     void inorder()
     {
         node *tmp = root;
         stack<node*>s;
         while (tmp!=NULL)
         {
            s.push(tmp);
            tmp = tmp->l;
         }
         while (!s.empty())
         {
            tmp = s.top();
            
            cout<<tmp->d<<' ';
            s.pop();
            tmp = tmp->r;
            while (tmp!=NULL)
            {
                s.push(tmp);
                tmp = tmp->l;
            }
            
         }
     }
     void postorder(node *tmp)
     {
        if (tmp!=NULL)
        {
            postorder(tmp->l);
            postorder(tmp->r);
            cout<<tmp->d<<' ';
        }
        
     }
     void inorder(node *tmp)
     {
         if (tmp!=NULL)
         {
            inorder(tmp->l);
            cout<<tmp->d<<' ';
            inorder(tmp->r);
            
         }
         
     }
     void postorder()
     {
         node *t = root;
         stack<node*>s1;
         stack<node*>s2;
         s1.push(t);
         while (!s1.empty())
         {
             t = s1.top();
             s1.pop();
            if (t->l!=NULL)
            {
                s1.push(t->l);
            }
            if (t->r!=NULL)
            {
                s1.push(t->r);
            }
            s2.push(t);
         }
         while (!s2.empty())
         {
            cout<<s2.top()->d<<' ';
            s2.pop();
         }
         
         
     }
     void preorder(node *tmp)
     {
         if (tmp!=NULL)
         {
            cout<<tmp->d<<' ';
            preorder(tmp->l);
            preorder(tmp->r);
         }
         
     }
     bool search(int x)
     {
         node *t = root;
         bool y = 0;
         while (t!=NULL)
         {
            if (t->d==x)
            {
                y = 1;
                break;
            }
            else if(x<t->d)
            {
                t = t->l;
            }
            else
            {
                t = t->r;
            }
            
         }
         return y;
     }
     void search(node *tmp,int x)
     {
         if (tmp!=NULL)
         {
            if (x==tmp->d)
            {
                cout<<"found";
            }
            else if (x<tmp->d)
            {
                search(tmp->l,x);
            }
            else
            {
                search(tmp->r,x);
            }
            
         }
         else
         {
            cout<<"not found";
         }
         
         
     }
    inline node* getRoot()
    {
        return root;
    }
   
};
int main()
{
    tree t;
    int n;
    cout<<"Enter number of nodes "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter node val "<<endl;
        int x;
        cin>>x;
        t.create(x);
    }
   
   
    return 0;
}
