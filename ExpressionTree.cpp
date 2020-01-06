#include <iostream>
using namespace std;
class node
{
    public:
    node *l;
    node *r;
    char c;
    node(char c)
    {
        this->c = c;
        l = r  = NULL;
    }
};
int priority(char op)
{
    if (op=='*' || op== '/')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
         
}
class stack
{
    public:
     int top;
     node* stk[100];
     
       stack()
       {
           top = -1;
       }
       void push(node *t)
       {
           if (top==-1)
           {
               top++;
               stk[top] = t;
           }
           else
           {
               if(top<=99)
               {
                  top++;
                  stk[top] = t;
               }
           }
           
       }
       node* pop()
       {
          node* t;
          if (top!=0)
          {
              t = stk[top];
              top-=1;
          }
          else 
           {
               t = stk[top];
               top = -1;
           }
            return t;
       }
       node* getTop()
       {
           if (top!=-1)
           {
               return stk[top];
           }
           else
           {
               return NULL;
           }

       }
       char Topdata()
       {
           
           return  stk[top]->c;
          
       }
       bool is_empty()
       {
           if (top==-1)
           {
               return true;
           }
           else
           {
               return false;
           }
    
       }
       int topCnt()
       {
           return top;
       }
};
class tree
{
    node*root;
    public:
     tree()
     {
         root = NULL;
     }
    node* create(string s)
     {
    
        stack oprnd;
        stack opter;
        for (int i = 0; i < s.length(); i++)
        {

            if ( (s[i]=='*') || (s[i]=='+') ||(s[i]=='/') || (s[i]=='-') )
            {
               if (opter.getTop()==NULL)
                {
                    
                    node*nn = new node(s[i]);
                    opter.push(nn);
                
                }
               else  if ( (priority(s[i])==priority(opter.Topdata())) || (priority(s[i])==1 && priority(opter.Topdata())==0) )
                {
                    node*nn = new node(s[i]);
                    opter.push(nn);
                }
                else if( (priority(s[i])==0 && priority(opter.Topdata())==1 ) )
                {
                    node *t = opter.pop();
                    node *rg = oprnd.pop();
                    node *lf = oprnd.pop();
                    t->r = rg;
                    t->l = lf;
                    node *nn = new node(s[i]);
                    opter.push(nn);
                    oprnd.push(t);
                 
                }
                
            }
            else
            {
                node*nn = new node(s[i]);
                oprnd.push(nn);
            }
            
            
        }



        while (!opter.is_empty())
        {
            node*t = opter.pop();
            node*rg = oprnd.pop();
            node*lf = oprnd.pop();
            t->l =lf;
            t->r = rg;
            oprnd.push(t);
        };
        root = oprnd.getTop();
        return root;
     }

     void postorder()
     {
         stack s1;
         stack s2;
         s1.push(root);
         node *t = root;
         while (!s1.is_empty())
         {
           
            t = s1.pop();
            if(t->l!=NULL) s1.push(t->l);
            if(t->r!=NULL) s1.push(t->r);
            s2.push(t);
         }
         while (!s2.is_empty())
         {
            t = s2.getTop();
            cout<<t->c;
            s2.pop();
         }
         
     }
     
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    tree t;
    cin>>s;
    t.create(s);   
    t.postorder();
    
   return 0;
}
