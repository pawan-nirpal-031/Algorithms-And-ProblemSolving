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
                    nn->lptr = par->lptr;
                    par->lth = 1;
                    cout<<nn->d<<" attached to left of "<<par->d<<endl;

                }else{
                    nn->rptr = par->rptr;
                    nn->lptr = par;
                    par->rth = 1;
                    par->rptr = nn;
                    cout<<nn->d<<" attached to right of "<<par->d<<endl;
                }

            }


        }
        void inorder(){
            node*tmp=root;
            while(1){
                while(tmp->lth ==1){
                    
                    tmp = tmp->lptr;
                       
                }
                int flg =0;
                cout<<tmp->d<<' ';
                while(tmp->rth==0){
                    if(tmp->rptr==dummy){
                        flg =1;
                        break;
                    }
                    tmp = tmp->rptr;
                    cout<<tmp->d<<' ';
                }
                tmp = tmp->rptr;
                if(flg==1){
                    break;
                }
            }




        }

};
int main(){
    tbt t;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter val"<<endl;
        int x;
        cin>>x;
        t.create(x);
    }
    t.inorder();
    return 0;
}
