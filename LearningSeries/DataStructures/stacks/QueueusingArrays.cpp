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
int rear=-1;
int front=-1;


bool IsEmpty(){
    return ((front==-1 and rear==-1) or (front==rear+1));
}

bool IsFull(){
    return ((not IsEmpty()) and (rear-front+1==n));
}

void Enqueue(int q[],int e){
    if(IsFull()) return;
    else if(IsEmpty()){
        front = rear = 0;
        q[rear] = e;
    }else{
        q[++rear] = e;
    }
}

void Dequeue(){
    if(not IsEmpty()) front++;
}



int Peek(int q[]){
    if(not IsEmpty()) return q[rear];
    return -INT_MAX;
}


void Show(int q[]){
   if(not IsEmpty()) for(int i = front;i<=rear;i++) cout<<q[i]<<" ";
}

int NumberOfElements(){
    if(not IsEmpty()) return rear-front+1;
    return 0;
}

int main(){
  FastIO;
  n;
  cin>>n;
  int queue[n];
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
            Enqueue(queue,e);
        }break;
        
        case 2:{
            Dequeue();
        }break;
        
        case 3:{
            Status(IsEmpty());
        }break;

        case 4:{
            Status(IsFull());
        }break;

        case 5:{
            cout<<Peek(queue);
        }break; 

        case 6:{
            Show(queue);
        }break; 
        
        case 7:{
            cout<<NumberOfElements();
        }break;
        default:
            cout<<"Inavlid opcode"<<endl;
            break;
        }
        cout<<'\n';
    }
    return 0;
}
