#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
	class Vector
	{
		enum Mode { RECT, POL };
	public:
		Vector();
		Vector(double n1, double n2, Mode = RECT);
		void reset(double n1, double n2, Mode = RECT);
		~Vector();
		double xval()const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector& v)const;
		Vector operator-(const Vector& v)const;
		Vector operator-()const;
		Vector operator*(double  mul)const;

		friend Vector operator*(double  mul, const Vector& v);
		friend std::ostream&
			operator <<(std::ostream& os, const Vector& v);

	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;

		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	};

}

#endif // !VECTOR_H_

