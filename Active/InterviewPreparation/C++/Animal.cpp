#include <string>
#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(){
    age = numberoflegs =0;
    sound = "null";
}

Animal::Animal(int age,int legs,string sound){
    this->age = age;
    this->numberoflegs = legs;
    this->sound = sound;
}

void Animal::SetSound(string snd){
    this->sound = snd;
}

string Animal::GetSound(){
    return this->sound;
}

void Animal::MakeSound(){
    cout<<"Making animal sound "<<this->sound<<'\n';
}


Dog::Dog(){
    name = breed = "null";
    this->SetSound("bark!");
}


Dog::Dog(string nm,string breed){
    this->name = nm;
    this->breed = breed;
    this->SetSound("bark!");
}

void Dog::MakeSound(){
    cout<<"Doggy : "<<this->name<<" go "<<this->GetSound()<<endl;
}

Cat::Cat(){
    name = breed = "null";
    this->SetSound("meau");
}

Cat::Cat(string nm,string breed){
    this->name = nm;
    this->breed = breed;
    this->SetSound("meau");
}

void Cat::MakeSound(){
     cout<<"Kitty : "<<this->name<<" go "<<this->GetSound()<<endl;
}

