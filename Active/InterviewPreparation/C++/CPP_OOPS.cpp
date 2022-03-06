#include <bits/stdc++.h>
// using namespace std;
using std::cout;
using std::cin;
using std::string;
using std::endl;
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




class Animal{
    private:
        std::string name;
        double height;
        double weight;
        static int count_of_animals;
    public:

        string GetName(){
            return this->name;
        }
        
        void SetName(string name){
            this->name = name;
        }
        double GetHeight(){
            return this->height;
        }
        void SetHeight(double height){
            this->height = height;
        }
        double GetWeight(){
            return this->weight;
        }
        void SetWeight(double weight){
            this->weight = weight;
        }
        Animal();
        void SetAllFields(string name,double height,double weight);
        Animal(string name,double height,double weight);
        ~Animal();
        static int GetNumberOfAnimlas();
        void ToString();

};

int Animal::count_of_animals = 0;

Animal::Animal(){
    height = weight = 0;
    name = "default";
    Animal::count_of_animals++;
}

Animal::Animal(string name,double height,double weight){
    this->height = height;
    this->weight = weight;
    this->name = name;   
    Animal::count_of_animals++;
}

int Animal::GetNumberOfAnimlas(){
    return Animal::count_of_animals;
}

void Animal::SetAllFields(string name,double height,double weight){
    this->height = height;
    this->weight = weight;
    this->name = name;
    cout<<"All fields set"<<endl;
}

Animal::~Animal(){
    cout<<"Animal "<<this->name<<" removed "<<endl;
}

void Animal::ToString(){
    cout<<this->name<<" is our animal now, "<<this->name<<" is "<<this->height<<" cms tall and has a weight of "<<this->weight<<" say bye! "<<endl;
}

class Dog : public Animal{
    private:
        string sound;
    public:
        Dog(){
            sound = "woof";
        }
        void MakeSound(){
            cout<<this->sound<<"! "<<endl;
            
        }
        Dog(string n,double h,double w,string sound){
            this->SetName(n);
            this->SetHeight(h);
            this->SetWeight(w);
            this->sound = sound;
        }

        void ToString(){
             cout<<GetName()<<" is our animal now, "<<GetName()<<" is "<<GetHeight()<<" cms tall and has a weight of "<<GetWeight()<<" says  "<<this->sound<<endl;
        }
};

int main(){
  std::FastIO;
  Dog bunny("Bunny",10,12.34,"Woofyie");
  bunny.ToString();
  
  Animal hung("Pico",12,34.2);
  cout<<"We have "<<Animal().GetNumberOfAnimlas()<<" in our zoo curently"<<endl;
  return 0;
} 
