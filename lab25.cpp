#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag) ,(c.real*imag)+(real*c.imag));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double under=(c.real*c.real)+(c.imag*c.imag);
	ComplexNumber a(real,imag),b(c.real,-(c.imag));
	ComplexNumber W = a*b;
	return ComplexNumber(W.real/under,W.imag/under);
}

double ComplexNumber::abs(){
	double R=pow(real,2),I=pow(imag,2);
	return pow(R+I,0.5);
}

double ComplexNumber::angle()
{
	double A=atan(imag/real)*180 / M_PI;
	if(imag>=0&&real>=0)
	{
		return A;
	}
	else if(imag>=0&&real<0)
	{
		return -(A-90);
	}
	else if(imag<0&&real>=0)
	{
		return A;
	}
	else 
	{
		return -A-90;
	}

}

bool ComplexNumber::operator==(const ComplexNumber &c)
{
	if(real==c.real&&imag==c.imag)
	{
		return true;
	}
	return false;

}

bool operator==(double i, ComplexNumber c)
{
		if(i==c.real&&0==c.imag)
	{
		return true;
	}
	return false;


}



ComplexNumber operator+(double i,const ComplexNumber &c){
	return ComplexNumber(c.real+i,c.imag);
}

ComplexNumber operator-(double i,const ComplexNumber &c){
	return ComplexNumber(i-c.real,-c.imag);
}

ComplexNumber operator*(double i,const ComplexNumber &c){
	return ComplexNumber(c.real*i,c.imag*i);
}

ComplexNumber operator/(double i,const ComplexNumber &c){
	double under=(c.real*c.real)+(c.imag*c.imag);
	return ComplexNumber((i*c.real)/under,-(i*c.imag)/under);
}


ostream & operator<<(ostream & os , ComplexNumber num)
{
	if(num.real==0&&num.imag==0)
	{
		return os<<"0";
	}
	else if(num.real!=0&&num.imag==0)
	{
		return os<<num.real;
	}
	else if(num.real==0&&num.imag!=0)
	{
		return os<<num.imag<<"i";	
	}
	
	else if(num.real!=0&&num.imag<0)
	{
		return os<<num.real<<num.imag<<"i";
	}
	else 
	{
		return os<<num.real<<"+"<<num.imag<<"i";
	}
}
//Write your code here

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
	
	return 0;
}





