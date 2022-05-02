#include "Vector.h"
#include <iostream>
#include <cmath>
using namespace std;

Point::Point(){
    this->x = this->y = 0;
}

Point::Point(int x,int y){
    this->x = x;
    this->y =y;
}

void Point::SetX(int x){
    this->x = x;
}

void Point::SetY(int y){
    this->y = y;
}

void Point::Display(){
    cout<<"("<<this->x<<","<<this->y<<")";
}

void Point::move(int i,int j){
    this->x+=i;
    this->y+=j;
}

int& Point::GetX(){
    return this->x;
}

int& Point::GetY(){
    return this->y;
}

Vector::Vector(){
    this->start = Point(0,0);
    this->end = Point(0,0);
}

Vector::Vector(int sx,int sy,int ex,int ey){
    this->start = Point(sx,sy);
    this->end = Point(ex,ey);
}

Vector::Vector(const Vector &v){
    this->start = v.start;
    this->end = v.end;
}

float Vector::ComputeDistance(Point &p1,Point &p2){
    int p1x = p1.GetX();
    int p1y = p1.GetY();
    int p2x = p2.GetX();
    int p2y = p2.GetY();
    float dist = sqrt((p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y));
    return dist;
}

Point& Vector::GetStart(){
    return this->start;
}

Point& Vector::GetEnd(){
    return this->end;
}

void Vector::OffSetVector(int xoffset=0,int yoffset=0){
    this->start.GetX()+=xoffset;
    this->end.GetX()+=xoffset;
    this->start.GetY()+=yoffset;
    this->end.GetY()+=yoffset;
}

void Vector::Show(){
    cout<<GetStart().GetX()<<','<<GetStart().GetY()<<" : "<<GetEnd().GetX()<<','<<GetEnd().GetY()<<"\n";
}

