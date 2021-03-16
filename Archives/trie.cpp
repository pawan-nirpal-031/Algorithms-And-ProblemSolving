#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#include <chrono>
class node{
    public:
        int val;
        node*ptrs[26];
    public:
        node(){
            this->val =0;
            for(node* &nd : ptrs){
                nd = NULL;
            }
        }
       
};

class trie{
    private:
      node *root;
      int pass =0;
    public:
      trie(){
          root = new node();
      }
      void insert(string s){
          node* trv = root;
          for(int i =0;i<s.length();i++){
              if(trv->ptrs[s[i]-'A']==NULL){
                  trv->ptrs[s[i]-'A'] = new node();
                  trv->ptrs[s[i]-'A']->val = ++pass;
              }
              trv = trv->ptrs[s[i]-'A'];
          }
      }
      void visit(node* trv){
          for(int i=0;i<26;i++){
              if(trv->ptrs[i]!=NULL){
                  cout<<trv->val<<"->"<<trv->ptrs[i]->val<<":"<<(char(i+'A'))<<'\n';
                  visit(trv->ptrs[i]);
              }
          }
      }
      void call(){
          this->visit(root);
      }
      void search(node* trv){   
          
      }
      void search(char c){

      }
};





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int n;
    // cin>>n;
    // trie t;
    // while(n--){
    //     string s;
    //     cin>>s;
    //     t.insert(s);
    // }
    // char c;
    // cin>>c;
    // while(c!='#'){

    // }
    unsigned long d = 5000;
    _sleep(3000UL);
    cout<<"now hello";
    return 0;
}