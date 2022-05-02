class Point{
    private:
        int x,y;
    public:
        Point();
        Point(int,int);
        Point(float,float);
        void SetX(int);
        void SetY(int);
        void Display();
        void move(int,int);
        int& GetX();
        int& GetY();
};


class Vector{
        Point start,end;
    public:
        Vector();
        Vector(int,int,int,int);
        Vector(const Vector&);
        float ComputeDistance(Point&,Point&);
        Point& GetStart();
        Point& GetEnd();
        void OffSetVector(int,int);
        void Show();
};
