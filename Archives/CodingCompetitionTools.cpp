#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a) x=0;
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAns(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x



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


  /*

                                  Number Theory notes

   1) Gcd(x,1) = 1;
      Lcm(x,1)  = x

   2) Gcd(x,y) = g;
      Lcm(x,y) = l;
      -> l*g = x*y;
    
   3) Gcd(a,b,c) = Gcd(a,Gcd(b,c)) = Gcd(Gcd(a,b),c) it is associative but Lcm is not.

   4) For any number N total number of factors is of the order O(n^(1/3)) cube root order
   
   5) For count of number of primes in range (1,N) it is of  the order O(N/ln(N)) -> ln(N) is log base e
    
   6) (a-b)%m = (a%m - b%m + m)%m careful with overflow and modulo with negetive nums

   7) Any postitive int >=2 can be written as product of it's prime factors
      N = (Pf1^x1)*(Pf2^x2)*..(Pfk^xk) -> Pfi is the ith prime factor of N and xi is it's freqency

   8) Perfect squares have exactly 3 divisors only (1,x,x^2) for x^2,
      Perfect cube has exactly 4 divisors (1,x,x^2,x^3) for some x^3,
      Genrerally for kth power of x it has exactly k+1 divisors (1,x,x^2,x^3 ... x^k) 
      
   9) Proprties of Primes 
        * Total no of distinct prime factors are very less
        * product of smallest 8 primes is larger than 1e6   
        
        * Ex x<=1e7 and (l,r) <=1e18 print total number of numbers in the
          range (l,r) which are not co-prime to x, ie count of y's such that Gcd(x,y) not 1
          say x = 6 and l,r = (13,23) = [13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23] 
          the not co-primes to 6 are the numbers in this range that are multiples of 2 or 3
          say count of multiples in this range of 2 denoted by m2 and of 3 by m3, then our answer is 
          m2 + m3 - m6 ( Inclusion-exlclusion principle ) and getting mx in range [l,r] is easy ie, mx = floor(r/x) - floor((l-1)/x) 
          now see for x = 30 Pfs(30) -> (2,3,5) then we count the expression m2 + m3 + m5 - m6 - m15 - m10 + m30
          then you can generate subsets and add the odd len subsets ie (2,3,5, (2,3,5)) and subtract even len subsets 
          such as ((2,3). (3,5), (2,5)) m value's
          
          Algorithm : Get prime factors of x say (p1,p2,p3..pk) and get all subsets of those and if len of subset is 
          even then subtract it's m else add it's m value, this will work because for x=1e7 distinct Pf's will be utmost 8 

        

  */