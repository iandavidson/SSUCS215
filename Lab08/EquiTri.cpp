#include "EquiTri.h"
#include <cmath>
using namespace std;

EquiTri::EquiTri()
{
	length = 0;
}

EquiTri::EquiTri(const EquiTri & S)
{
	length = S.length;
}

EquiTri::EquiTri(float L)
{
	length = L;
}

EquiTri::~EquiTri()
{
}

EquiTri & EquiTri::operator = (const EquiTri & S)
{
	if(this== & S)
		return * this;
	length = S.length;
	return * this;
}

string EquiTri::GetType () const
{
	return "EquiTri";
}


float EquiTri::GetArea () const
{
	return (sqrt(3)/4)*(length * length);
}

float EquiTri::GetPerimeter () const
{
	return length * 3;
}

bool EquiTri::operator == (const EquiTri & S) const
{
	return length == S.length;
}

bool EquiTri::operator < (const EquiTri & S) const
{
	if (length < S.length)
		return true;
	return false;
}

