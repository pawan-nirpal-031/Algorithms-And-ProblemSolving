#include <string>
#include <iostream>
using namespace std;

class Animal{
  int age;
  int numberoflegs;
  string sound;
  public:
    Animal();
    Animal(int,int,string);
    void MakeSound();
    string GetSound();
    void SetSound(string);
};

class Dog : public Animal{
    string name;
    string breed;
    public:
        string lox;
        Dog();
        Dog(string nm,string breed);
        void MakeSound();
};

class Cat : public Animal{
    string name;
    string breed;
    public:
        Cat();
        Cat(string nm,string breed);
        void MakeSound();
};

