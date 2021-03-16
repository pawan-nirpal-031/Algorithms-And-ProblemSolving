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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


class FileProcessing{
    public:
        vector<string> Tokenize(string line){
            vector<string>token;
            stringstream stream(line);
            string word;
            while(getline(stream,word,' ')){
                token.push_back(word);
            }
            return token;
        }

        ifstream input_buffr;
        ofstream ouput_buffr;

        void OpenFiles(string inp,string outp){
            input_buffr.open(inp, ios::in);
            ouput_buffr.open(outp,ios::out);
        }

        void CloseFiles(){
            input_buffr.close();
            ouput_buffr.close();
        }

        int StringToInteger(string s){
            stringstream stream(s);
            int num =0;
            stream>>num;
            return num;
        }

};

class MathUtility{
  public:

    ull Gcd(ull a,ull b){
        return (a%b==0?b:Gcd(b,a%b));
    }

    ll Lcm(ll a,ll b){
        return (a*b)/Gcd(a,b);
    }

    ll Power(ll a,ll n){
      if(n==1) return a;
      ll half = Power(a,n>>1);
      return (n&1?half*half*a:half*half);
    }
    
    ll ModulorExponention(ll a,ll n,ll m){
      if(n==1) return a%m;
      ll half = ModulorExponention(a,n>>1,m)%m;
      return ((n&1)?(((half*half)%m)*(a%m))%m:(half*half)%m);
    }

    vector<ll> Factorization(ll x){
      vector<ll>factors;
      for(int i =1;i*i<=x;i++){
        if(x%i==0){
          if(i*i==x){
            factors.emplace_back(i);
          }else{
            factors.emplace_back(i);
            factors.emplace_back(x/i);
          }
        }
      }
      return factors;
    }

    vector<pair<int,int>> PrimeFactorization(ll n){
      vector<pair<int,int>> prime_factors;
      for(int i = 2;i*i<=n;i++){
        if(n%i==0){
          int frequency =0;
          while(n%i==0){
            n/=i;
            frequency+=1;
          }
          prime_factors.emplace_back(Pair(i,frequency));
        }
      }
      if(n>1){
        prime_factors.emplace_back(Pair(n,1));
      }
      return prime_factors;
    }

    vector<vector<ll>> FactorizationOfARangeOfNumbers(ll n){ // This could check prime and factors otherwise in O(Nlog(N)) for all numbers betwwen 1 to n
        vector<vector<ll>>Factors(n+1);
        for(int i = 1;i<=n;i++){
          for(int j = i; j<=n;j+=i) Factors[j].emplace_back(i);
        }
        return Factors;
    }

    vector<bool> SievePrimeFactorization(ll max_limit){
      vector<bool>primes(max_limit+1,1);
      primes[0] = primes[1] = 0;
      for(int i = 2;i*i<=max_limit;i++){
        if(primes[i]){
         for(int j = i*i;j<=max_limit;j+=i) primes[j] = 0;
        }
      }
      return primes;
    }
    
};

class StringUtility{
  public:
    bool IsSubsequnece(string s,string t){
        int p1,p2;
        for(p2 =0,p1=0;p2<t.length() and p1<s.length();){
          if(t[p2]==s[p1]){
            p2+=1;
            p1+=1;
          }else{
            p1+=1;
          }
        }
        return (p2==t.length());
      }
};

class GraphUtility{
  public:

    void DfsTreeFlattening(vector<int>&flattend_tree,vector<pair<int,int>>&range,int curr_node,int par_curr,vector<int>g[]){
      flattend_tree.push_back(curr_node);
      range[curr_node].first = flattend_tree.size();
      for(int &child : g[curr_node]){
        if(child!=par_curr){
          DfsTreeFlattening(flattend_tree,range,child,curr_node,g);
        }
      }
      range[curr_node].second = flattend_tree.size();
    } 

    void TreeFlattening(){
      int n = 100;
      cin>>n;
      vector<int>flattend_tree;
      vector<pair<int,int>>range(n+1,{0,0});
      vector<int>graph[n+1];
      int m = n-1;
      while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
      }
      GraphUtility().DfsTreeFlattening(flattend_tree,range,1,0,graph);
      for(int i =0;i<n;i++){
        cout<<"start of "<<i+1<<": "<<range[i+1].first<<", end position  : "<<range[i+1].second<<endl;
      }
    } 
};

class SegmentTree{
  public:
    int merge(int a,int b){
        return a+b;
    }

    void Build(int a[],vector<int>&tree,int seg_left,int seg_right,int tree_indx){
        if(seg_left==seg_right){
            tree[tree_indx] = a[seg_left];
            return;
        }
        int mid = (seg_left+seg_right)>>1;
        Build(a,tree,seg_left,mid,2*tree_indx);
        Build(a,tree,mid+1,seg_right,2*tree_indx+1);
        tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
    }

    void PointUpdate(int a[],vector<int>&tree,int seg_left,int seg_right,int tree_indx,int update_indx,int update_val){
        if(seg_left==seg_right and seg_left==update_indx){
            tree[tree_indx] = a[update_indx] = update_val;
            return;
        }
        int mid = (seg_left+seg_right)>>1;
        if(update_indx>mid){
            PointUpdate(a,tree,mid+1,seg_right,2*tree_indx+1,update_indx,update_val);
        }else{
            PointUpdate(a,tree,seg_left,mid,2*tree_indx,update_indx,update_val);
        }
        tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
    }

    void RangeUpdate(vector<int>&tree,vector<int>&lazy,int tree_indx,int seg_left,int seg_right,int update_left,int update_right,int update_val){
        if(lazy[tree_indx]>0){
            int update_val = lazy[tree_indx];
            tree[tree_indx]+=(seg_right-seg_left+1)*(update_val);
            lazy[tree_indx] =0;
            if(seg_left!=seg_right){
                lazy[2*tree_indx] +=update_val;
                lazy[2*tree_indx+1]+=update_val;
            }
        }
        if(seg_left>update_right or seg_right<update_left){
            return; 
        }
        if( update_left<=seg_left and seg_right<=update_right){
            int update = (seg_right-seg_left+1)*(update_val);
            tree[tree_indx]+=update;

            if(seg_left!=seg_right){
                lazy[2*tree_indx]+=update;
                lazy[2*tree_indx+1]+=update;
            }
            return;
        }
        int mid = (seg_left+seg_right)>>1;
        RangeUpdate(tree,lazy,2*tree_indx,seg_left,mid,update_left,update_right,update_val);
        RangeUpdate(tree,lazy,2*tree_indx+1,mid+1,seg_right,update_left,update_right,update_val);
        tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
    }

    int Query(vector<int>&tree,vector<int>&lazy,int seg_left,int seg_right,int tree_indx,int query_left,int query_right){
        if(lazy[tree_indx]>0){
            int update_val = lazy[tree_indx];
            tree[tree_indx]+=(seg_right-seg_left+1)*(update_val);
            lazy[tree_indx] =0;
            if(seg_left!=seg_right){
                lazy[2*tree_indx] +=update_val;
                lazy[2*tree_indx+1]+=update_val;
            }
        }
        if(query_left>=seg_left and query_right<=seg_right) return tree[tree_indx]; // Full overlap
        if(query_left>seg_right or query_right<seg_left)  return 0; // Return Identity elment as zero overlap
        int mid = (seg_left+seg_right)>>1;
        return merge(Query(tree,lazy,seg_left,mid,2*tree_indx,query_left,query_right),Query(tree,lazy,mid+1,seg_right,2*tree_indx+1,query_left,query_right));
    }

};


int main(int argc, char const *argv[]){
    FastIO;
    
    return 0;
}



