// Problem Link : https://www.codechef.com/COOK128C/problems/OROFAND
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


/*

2] Chocklate Mongor

Problem Statement : 
There are n chocolates, and you are given an array of n numbers where the i-th number Ai is the flavour type of the i-th chocolate. Sebrina wants to eat as many different types of chocolates as possible, but she also has to save at least x number of chocolates for her little brother.
Find the maximum possible number of distinct flavour types Sebrina can have.
*/

/*

Remarks : Overthinking for a simple probelem, Ans = min(total-x,no_of_uniqe_candies) made it complicated implementation and wastage of time this implementation took almost an hour where as better one had only 5 min and was very fast 

*/

void SolveCase(){
    int n,x;
    cin>>n>>x;
    map<ll,int>data; // (type,freq);
    multimap<int,ll>rev; // (freq,type);
    for(int i =0;i<n;i++){
        ll t;
        cin>>t;
        auto it = data.find(t);
        if(it==data.end()) data.insert({t,1});
        else it->second+=1;
    }
    for(auto it= data.begin();it!=data.end();it++) rev.insert({it->second,it->first});
    for(auto it= rev.rbegin();it!=rev.rend();it++){
        auto st = data.find(it->second);
        int freq = st->second;
        if((freq)>=x){
            if(freq>x){
                st->second-=x;
                x = 0;
                break;
            }else{
                st->second  = x = 1;
            }
        }else{
            if(freq>0){
                st->second = 1;
                x = x - freq + 1;
            }
        }
    }
    if(x>0){
        for(auto it= data.begin();it!=data.end();it++){
            if(x==0) break;
            if(it->second==1 and x>0){
                it->second =0;
                x-=1;
            }
        }

    }
    int cnt = 0;
    for(auto it= data.begin();it!=data.end();it++){
        if(it->second>0) cnt+=1;
    }
    cout<<cnt<<'\n';
}



/*
Problem Statement : 

3] BodyBuilder

After solving programming problems for years, Chef has become lazy and decided to get a better physique by doing some weight lifting exercises.

On any regular day, Chef does N exercises at times A1,A2,…,AN (in minutes, all distinct) and each exercise provides a tension of B1,B2,…,BN units. In the period between two consecutive exercises, his muscles relax R units of tension per minute.

More formally, Chef's tension is described by a number x. Before any workouts, x=0. When he does a workout at time Ai, the tension x instantly increases by Bi. Between workouts, the number x decreases by R units per minute, maximized with 0.

Considering the time of exercise and hence tension to be negligible, find the maximum tension he will be feeling in his muscles during the entire period of his workout.

*/

/*
 Remarks : 

lack of clairity of thought was a big mistake on the highlighted line (max_tension should be updated as soon as current tension is added ie. b[i] is added because the below line (line  47) misses the first updation and directly reduces tension )

*/

void BodyBuilder(){
    int n,r;
    cin>>n>>r;
    ll max_tension = 0, curr_tension =0;
    ll a[n],b[n];
    for(int i =0;i<n;i++) cin>>a[i];
    for(int i =0;i<n;i++) cin>>b[i];
    for(int i =0;i<n;i++){
        curr_tension+=b[i];
        max_tension = max(max_tension,max(0LL,(ll)curr_tension));
        if(i<n-1) curr_tension=max(0LL,(curr_tension-((a[i+1]-a[i])*r)));
    }
    cout<<max_tension<<'\n';
}







/*

4] OR_OF_ANDS 

Problem Statement : 

You are given an array A with N integers. An array's score is defined as the bitwise AND of all its elements. You need to find the bitwise OR of the scores of all possible non-empty subarrays of A.

Furthermore, there are Q queries. Each query consists of two integers X and V. You need to change the value of the element at index X to V. After each query, you again need to find the bitwise OR of the scores of all possible non-empty subarrays.

See the example for more clarification.

*/


void BuildTree(int seg_left,int seg_right,int tree_indx,int a[],vector<int>&tree){
  if(seg_left==seg_right){
    tree[tree_indx] = a[seg_left];
    return;
  }
  int mid = ((seg_left+seg_right)>>1);
  BuildTree(seg_left,mid,2*tree_indx,a,tree);
  BuildTree(mid+1,seg_right,2*tree_indx+1,a,tree);
  tree[tree_indx] =(tree[2*tree_indx] | tree[2*tree_indx+1]);
}

void Update(int seg_left,int seg_right,int tree_indx,vector<int>&tree,int updt_indx,int updt_val){
  if((seg_left==seg_right) and (seg_left==updt_indx)){
    tree[tree_indx] = updt_val;
    return;
  }
  int mid = ((seg_left+seg_right)>>1);
  if(updt_indx>mid){
    Update(mid+1,seg_right,2*tree_indx+1,tree,updt_indx,updt_val);
  }else{
    Update(seg_left,mid,2*tree_indx,tree,updt_indx,updt_val);
  }
  tree[tree_indx] = (tree[2*tree_indx] | tree[2*tree_indx+1]);
}

void OrOfAndsSegmentTreeSolution(){
  int n,q;
  cin>>n>>q;
  int a[n+1];
  for(int i =1;i<=n;i++) cin>>a[i];
  vector<int>tree(4*n+5,0);
  BuildTree(1,n,1,a,tree);
  cout<<tree[1]<<'\n';
  while(q--){
    int indx,val;
    cin>>indx>>val;
    Update(1,n,1,tree,indx,val);
    cout<<tree[1]<<'\n';
  }
}

void OrOfAndsBitManipulationSolution(){
  int n,q;
  cin>>n>>q;
  int a[n+1];
  for(int i =1;i<=n;i++) cin>>a[i];
  int count[32];
  for(int i =0;i<32;i++) count[i] =0; // count[i] : count/number of elements which have ith bit as set
  

}

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => [1]

