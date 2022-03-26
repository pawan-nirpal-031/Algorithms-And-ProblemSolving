#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
        int x,y;
    public:
        Point(){
            x = y = 0;
        }
        Point(int x,int y){
            this->x = x;
            this->y = y;
        }
        Point(float x,float y){
            this->x = x;
            this->y = y;
        }
        void SetX(int x){
            this->x = x;
        }
        
        void SetY(int y){
            this->y = y;
        }
        void Display(){
            cout<<"("<<this->x<<','<<this->y<<")\n";
        }
        void move(int i=0,int j=0){
            this->x+=i;
            this->y+=j;
        }

        int& GetX(){
            return (this->x);
        }

        int& GetY(){
            return this->y;
        }
};

class Vector{
    Point start,end;
    public:
    Vector(){
        this->start = Point(0,0);
        this->end = Point(1,1);
    }
    Vector(int sx,int sy,int ex,int ey){
        this->start = Point(sx,sy);
        this->end = Point(ex,ey);
    }
    float ComputeDistance(Point,Point);
    Point& GetStart();
    Point& GetEnd();
    void OffSetVector(Point&,int,int);
    void Show();
};

float Vector::ComputeDistance(Point p1,Point p2){
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

void Vector::OffSetVector(Point& p,int xoffset,int yoffset){
    p.GetX()+=xoffset;
    p.GetY()+=yoffset;
    
}


void Vector::Show(){
    cout<<GetStart().GetX()<<','<<GetStart().GetY()<<" : "<<GetEnd().GetX()<<','<<GetEnd().GetY()<<"\n";
}


int main(){
    Vector v(1,1,3,3);
    v.Show();
    v.OffSetVector(v.GetStart(),1,9);
    v.OffSetVector(v.GetEnd(),1,9);
    v.Show();
    return 0;
}

