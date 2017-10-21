#include "Circle.h"


using namespace std;

Circle::Circle()
{
    length = 0;
}

Circle::Circle(const Circle & S)
{
    length = S.length;
}

Circle::Circle(float L)
{
    length = L;
}

Circle::~Circle()
{
}

Circle & Circle::operator = (const Circle & C)
{
    if(this== & C)
        return * this;
    length = C.length;
    return * this;
}

string Circle::GetType () const
{
    return "Circle";
}

float Circle::GetArea () const
{
    float radius = length * 1/2;
    return PI *  radius * radius;
}

float Circle::GetPerimeter () const
{
    return length * PI;
}

bool Circle::operator == (const Circle & S) const
{
    return length == S.length;
}

bool Circle::operator < (const Circle & S) const
{
    if (length < S.length)
        return true;
    return false;
}