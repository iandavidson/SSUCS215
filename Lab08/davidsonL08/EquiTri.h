#ifndef EQUITRI_H
#define EQUITRI_H

#include <iostream>
#include "Shape.h"
using namespace std;

class EquiTri : public Shape
{
	public:
		EquiTri();
		EquiTri(const EquiTri & S);
		EquiTri(float L);
		~EquiTri();
		EquiTri & operator = (const EquiTri & S);
		string GetType () const;
		float GetArea () const;
		float GetPerimeter () const;
		bool operator == (const EquiTri & S) const;
		bool operator < (const EquiTri & S) const;
	private:
	// length is the length of a side on the equi tri.
};

#endif
