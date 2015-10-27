#include "MATRIX4F.h"

using namespace std;

int main() {
	MATRIX4F m();
	VEC4F g;
	g = VEC4F(9.1);
	cout<<g<<endl;
	cout<<m<<endl;
	/*VEC3F c(1.0,0.5,0.25);
	float f = 0.5;
	cout<<"first vector: "<<v<<endl;
	cout<<"second vector: "<<c<<endl;
	cout<<v<<" + "<<c<<" = "<<v+c<<endl;
	cout<<v<<" - "<<c<<" = "<<v-c<<endl;
	cout<<v<<" * "<<c<<" = "<<v*c<<endl;
	cout<<c<<" * "<<f<<" = "<<c*f<<endl;
	cout<<c<<" / "<<f<<" = "<<c/f<<endl;
	cout<<v<<" cross "<<c<<" = "<<cross(v,c)<<endl;
	cout<<v<<" dot "<<c<<" = "<<dot(v,c)<<endl;
	cout<<v<<" normalized = "<<v.getNormalized()<<endl;
	cout<<v<<" normalized = ";
	v.normalize();
	cout<<v<<endl;
	cout<<v<<" magnitude = "<<v.getMagnitude()<<endl;
	cout<<c<<" magnitude = "<<c.getMagnitude()<<endl;*/
};