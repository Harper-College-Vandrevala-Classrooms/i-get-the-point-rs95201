#include <cmath>
#include <iostream>
#include <cassert>

class Point
{
    private:

    double x,y;

    public:

    Point(double x, double y);
    double operator-(Point A);
    Point operator/(Point A);
    bool operator==(Point A);
    bool operator!=(Point A);
    void pretty_print();
    


};
Point::Point(double x, double y): x(x),y(y){}

double Point::operator-(Point A)
{
   double x_square = std::pow(this->x - A.x, 2);
   double y_square = std::pow(this->y - A.y, 2); 
   double distance = sqrt(x_square + y_square);
   return distance;
}
Point Point::operator/(Point A)
{
    return Point((this->x + A.x)/2, (this->y + A.y)/2);
}
bool Point::operator==(Point A)
{
    return (this->x == A.x && this->y == A.y);
}
bool Point::operator!=(Point A)
{
   return(this->x != A.x && this->y != A.y);
}
void Point::pretty_print()
{
    std::cout << '(' << this->x << ',' << this->y << ')' << std::endl; 
}
int main()
{
    Point a(2,3);
    Point b(3,2);
    
    double c = b - a;
    std::cout << "Distance:  " << c << std::endl;
    
    Point d = b / a;
    std::cout << "Midpoint:  ";
    d.pretty_print();
    
    bool e = a == b;
    std::cout << "Point a == Point b:  " << e << std::endl;
    
    bool f = a != b;
    std::cout << "Point a != Point b:  " << f << std::endl;
    assert(fabs(c - 1.41421) < 1e-5);
    assert(d == Point(2.5,2.5));
    assert(e == 0);
    assert(f == 1);
    std::cout << "All assertion passed!" << std::endl;
    

    return 0;

}
