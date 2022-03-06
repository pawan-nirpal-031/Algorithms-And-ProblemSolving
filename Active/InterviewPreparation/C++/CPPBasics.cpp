#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

void FoolingAround(){
    string s = "world";
    char x[] = {'h','e','l','l','o','\0'};
    cout<<x+s;

    string name;
    cout<<"your name : ";
    getline(cin,name);

    string dog = "dog";
    string cat = "cat";
    cout<<dog.compare(cat);
    cout<<'\n'<<cat.compare("cat");
    cout<<'\n'<<dog.compare(dog);

    string whole_name = name.assign(name);
    int first_name_indx = whole_name.find(' ');
    string first_name = whole_name.substr(0,first_name_indx);
    int last_name_indx = whole_name.find("Wang",0);
    string last_name = whole_name.substr(last_name_indx,whole_name.size());
    cout<<"Your Last name : "<<last_name<<" let\'s change it to something else, give me a good last name : \n";
    getline(cin,last_name);
    cout<<" Ok, Cool we will change it to "<<first_name+" "+last_name<<endl;
}


void FileIO(){
    string quote = "An apple a day keeps the Plumber away!";
    string file_name = "Quote.txt";
    ofstream writer(file_name);
    if(not writer){
        cout<<"Can\'t open the file "<<file_name<<endl;
    }else{
        writer.write(&quote[0],37);
        cout<<"Successful";
    }
}


void DiffrancePointerAndRefrence(){
    int *ptr = NULL;
    int x = 7;
    int foo = 21;
    ptr = &x;
    int &ref = x;
    ptr = &x;
    cout<<((ref==x) and (ref==*ptr));
}



int b1 = 1;
int b2 = 2;
int *gptr;

void DiffPassByPtr(int *ptr){

}

void DiffPassByPtrRef(int *&ptr_ref){
    
}





void PassByVal(int val){
     val = 10;
     cout<<"Val in Fun is "<<val<<endl;
}

void PassByRef(int &ref){
    ref = 20;
    cout<<"ref in Fun is "<<ref<<endl;
}

void PassByPtr(int *ptr){
    *ptr = 30;
    cout<<"*ptr in Fun is "<<*ptr<<endl;
}



void PassByDiffrentWays(){
    int val = 5;
    cout<<"val is initally : "<<val<<endl;
    PassByVal(val);
    cout<<"val after PassByVal fun : "<<val<<endl;
    PassByRef(val);
    cout<<"val after PassByRef fun : "<<val<<endl;
    PassByPtr(&val);
    cout<<"val after PassByPtr fun : "<<val<<endl;
}



int main(){
    
    return 0;
}