#include "stdafx.h"
#include <iostream>
using namespace std;


struct vec
{
	float x;
	float y;
	float z;
};
class Vector
{
	vec A;

public:	

	Vector()
	{
		this->A.x=0;
		this->A.y=0;
		this->A.z=0;

	}
	Vector(float q,float w,float e)
	{
		this->A.x=q;
		this->A.y=w;
		this->A.z=e;
	}


	float Lenth();
	bool operator=(Vector &v);
	Vector operator+(Vector &v);
	float operator*(Vector &v);
	
	friend ostream &operator<<(ostream &output,const Vector& v);
	friend istream &operator>>(istream &input, Vector& v);


};

float Vector::Lenth()
{
	return abs(pow(this->A.x,2)+pow(this->A.y,2)+pow(this->A.z,2));
}
Vector Vector::operator+(Vector &v)
{
	Vector temp;

	temp.A.x=(this->A.x+v.A.x);
	temp.A.y=(this->A.y+v.A.y);
	temp.A.z=(this->A.z+v.A.z);

	return temp;
}
float Vector::operator*(Vector &v)
{
	return (this->A.x*v.A.x+this->A.y*v.A.y+this->A.z*v.A.z);
}
bool Vector::operator=(Vector &v)
{
	if ((this->Lenth()==v.Lenth())&&(this->operator*(v)==this->Lenth()*v.Lenth())) true;
	else return false;
}

ostream &operator<<(ostream &output,const Vector& v)
{
	output<<"("<<v.A.x<<","<<v.A.y<<","<<v.A.z<<")"<<endl;
	cout<<endl;
	return output;
}
istream &operator>>(istream &input, Vector& v)
{
	cout<<"X: ";
	input>>v.A.x;
	cout<<"Y: ";
	input>>v.A.y;
	cout<<"Z: ";
	input>>v.A.z;
	

	cout<<endl;
	return input;
}

void main()
{
	setlocale(LC_ALL,"RUS");

	Vector v1;
	Vector v2(4,8,6);
	
	cin>>v1;

	cout<<v1<<v2;

	cout<<"Сложение векторов: "<<v1+v2<<endl;
	
	cout<<"Длина:"<<v1.Lenth()<<endl;
	
	cout<<"Скалярное произведение:"<<v1*v2<<endl;

	if (v1=v2) cout<<"Равны"<<endl;
	else cout<<"Не Равны"<<endl;
}