#include <iostream>
using namespace std;
class node
{
    public:
    int rth;
    node*rptr;
    int lth;
    node*lptr;
    int d;
    node(int d){
        this->d = d;
        rth = lth = 0;
        rptr = lptr = NULL;

    }
};
class tbt
{
    node*dummy;
    node*root;
    public:
        tbt(){
            dummy = new node(-100);
            root = NULL;
        }
        void create(int v){
            node*nn = new node(v);
            if(dummy->lptr==NULL){
                dummy->lptr = nn;
                root = nn;
                root->lptr = root->rptr = dummy;
            }else{
                node* tmp = root;
                node*par = root;
                while(tmp!=NULL){
                    par = tmp;
                    if(nn->d<tmp->d){
                        if(tmp->lth ==1){
                            tmp = tmp->lptr;
                        }else{
                            tmp = NULL;
                        }
                    }else{
                        if(tmp->rth==1){
                            tmp = tmp->rptr;
                        }else{
                            tmp = NULL;
                        }
                    }
                }
                if(nn->d<par->d){
                    par->lptr = nn;
                    nn->rptr = par;
                    nn->lptr = dummy;
                    par->lth = 1;

                }else{
                    nn->rptr = dummy;
                    nn->lptr = par;
                    par->rth = 1;
                    par->rptr = nn;
                }

            }


        }
        void inorder(){
            node*tmp=root;
            while(1){
                while(tmp->lptr!=dummy){
                    if(tmp->lth ==1){
                        tmp = tmp->lptr;
                    }
                        
                }
                cout<<tmp->d<<' ';

            }




        }

};