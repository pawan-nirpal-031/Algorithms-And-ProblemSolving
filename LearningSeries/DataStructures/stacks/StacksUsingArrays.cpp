#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

int n;
int top = -1;

void Push(int stack[],int v){
    top++;
    if(top<n) stack[top] = v;
}

void Pop(int stack[]){
    if(top>-1) top--;
}

bool IsEmpty(){
    return top==-1;
}

bool IsFull(){
    return top==n;
}

int NumberOFElements(){
    return top+1;
}

int Peek(int stack[]){
    if(top>-1 and top<n) return stack[top];
    return -INT_MAX;
}

void Show(int stack[]){
    for(int i =0;i<=top;i++) cout<<stack[i]<<' ';
}

int main(){
  FastIO;
  cin>>n;
  int stack[n];
  int q;
  cin>>q;
  while(q--){
      int opcode;
      cout<<"Enter opcode"<<endl;
      cin>>opcode;
      switch (opcode)
      {
      case 1: {
          int e;
          cin>>e;
          Push(stack,e);
      }break;
      
      case 2:{
          Pop(stack);
      }break;
      
      case 3:{
          Status(IsEmpty());
      }break;

      case 4:{
          Status(IsFull());
      }break;

      case 5:{
          cout<<Peek(stack);
      }break; 

      case 6:{
          Show(stack);
      }break; 

      case 7:{
          cout<<NumberOFElements();
      }break;

      default:
        cout<<"Inavlid opcode"<<endl;
        break;
      }
      cout<<'\n';
  }
  return 0;
} 
