#include "VEC4F.h"

using namespace std;

int main() {
	float f(0.5);
	VEC4F v(3.0);
	VEC4F t(VEC3F(4.0,.8,1.6), 3.2);
	VEC4F y(t);
	VEC4F c(1.0,0.5,0.25,0.65);
	VEC3F a = v.getVEC3F();
	VEC3F b = y.getVEC3F();

	cout<<"first vector v: "<<v<<endl;
	cout<<"second vector t: "<<t<<endl;
	cout<<"third vector y: "<<y<<endl;
	cout<<"fourth vector c "<<c<<endl;
	cout<<"fifth vector a: "<<a<<endl;
	cout<<"sixth vector b: "<<b<<endl<<endl;
	
	cout<<"item 3 of vector "<<y<<" is "<<y[3]<<endl;
	cout<<"change this item to "<<y[0]<<": ";
	y[3]=y[0];
	cout<<y<<endl<<endl;
	
	cout<<v<<" + "<<c<<" = "<<v+c<<endl;
	cout<<v<<" - "<<c<<" = "<<v-c<<endl;
	cout<<"-"<<v<<" = "<<-v<<endl;
	cout<<v<<" * "<<c<<" = "<<v*c<<endl;
	cout<<f<<" * "<<c<<" = "<<f*c<<endl;
	cout<<v<<" / "<<c<<" = "<<v/c<<endl;
	cout<<c<<" / "<<f<<" = "<<c/f<<endl<<endl;

	cout<<v<<" += "<<c<<" : ";
	v+=c;
	cout<<v<<endl;
	cout<<v<<" -= "<<c<<" : ";
	v-=c;
	cout<<v<<endl;
	cout<<v<<" *= "<<c<<" : ";
	v*=c;
	cout<<v<<endl;
	cout<<c<<" *= "<<f<<" : ";
	c*=f;
	cout<<c<<endl;
	cout<<v<<" /= "<<c<<" : ";
	v/=c;
	cout<<v<<endl;
	cout<<c<<" /= "<<f<<" : ";
	c/=f;
	cout<<c<<endl<<endl;
	
	cout<<a<<" cross "<<b<<" = "<<cross(a,b)<<endl;
	cout<<a<<" dot "<<b<<" = "<<dot(a,b)<<endl;
	cout<<a<<" normalized = "<<a.getNormalized()<<endl;
	cout<<"normalized "<<a<<" = ";
	a.normalize();
	cout<<a<<endl;
	cout<<a<<" magnitude = "<<a.getMagnitude()<<endl;
	cout<<b<<" magnitude = "<<b.getMagnitude()<<endl;
};