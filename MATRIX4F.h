///////////////////////////////////////////////////////////////////
/* derived almost entirely from Dr. Ted Kim of Pixar 			 */
/* and UCSB Media Arts and Technology's VEC3F class              */
///////////////////////////////////////////////////////////////////
#ifndef MATRIX4F_H
#define MATRIX4F_H
#include <iostream>
#include <math.h>
#include "VEC4F.h"


using namespace std;

struct tup {
	int i;
	int j;
};

class MATRIX4F {
public:
	//constructors
	MATRIX4F() {
	for(int i = 0; i < 4; i++) {
		column[i]=VEC4F();
		cout<<"setting up col "<<i<<endl;
	}
};
	MATRIX4F(float f);
	
	//bracket access methods
	//float& operator[](pair(int i,int j)) { return column[i][j]; }
	//float operator[](pair(int i,int j)) const { return column[i][j]; }
	VEC4F& operator[](int i) { cout<<"bracket op\n"; return column[i]; }
	VEC4F operator[](int i) const { cout<<"bracket op\n"; return column[i]; }

	/*//copy constructors
	VEC3F(const VEC3F& v) { *this = v; };
	VEC3F(const float e[3]) { element[0] = e[0]; element[1] = e[1]; element[2] = e[2]; };
	
	//assignment operators
	VEC3F& operator=(const VEC3F& v) { element[0] = v[0]; element[1] = v[1]; element[2] = v[2]; };
	
	//magnitude
	float getMagnitude() {
		float l = element[0] * element[0] + element[1]* element[1] + element[2]*element[2];
		return sqrt(l);
	};
	
	//in-place operator methods
	inline VEC3F& operator+= (const VEC3F& v);
	inline VEC3F& operator-= (const VEC3F& v);
	inline VEC3F& operator*= (float f);
	inline VEC3F& operator/= (float f);

	//normalize vector
	void normalize() {
		float l = element[0] * element[0] + element[1]* element[1] + element[2]*element[2];
		if ( l!= 0.0 && l!=1.0 ) *this /= sqrt(l);
	}

	VEC3F getNormalized() {
		VEC3F v(element[0], element[1], element[2]);
		float l = v[0] * v[0] + v[1]* v[1] + v[2]*v[2];
		if ( l!= 0.0 && l!=1.0 ) v /= sqrt(l);
		return v;
	}
	*/
private:
	VEC4F column[4];
};

/*//definitions of in-place operators
inline VEC3F& VEC3F::operator+= (const VEC3F& v) {
	element[0] += v[0]; element[1] += v[1]; element[2] +=v[2]; return *this; 
}
inline VEC3F& VEC3F::operator-= (const VEC3F& v) {
	element[0] -= v[0]; element[1] -= v[1]; element[2] -= v[2]; return *this; 
}
inline VEC3F& VEC3F::operator*= (float f) {
	element[0] *= f; element[1] *= f; element[2] *=f; return *this; 
}
inline VEC3F& VEC3F::operator/= (float f) {
	element[0] /= f; element[1] /= f; element[2] /=f; return *this; 
}


//definitions of operators
inline VEC3F operator+(const VEC3F& u, const VEC3F v) {
	return VEC3F(u[0]+v[0], u[1]+v[1], u[2]+v[2]);
}
inline VEC3F operator-(const VEC3F& u, const VEC3F v) {
	return VEC3F(u[0]-v[0], u[1]-v[1], u[2]-v[2]);
}
inline VEC3F operator-(const VEC3F& u) {
	return VEC3F(-u[0], -u[1], -u[2]);
}
inline VEC3F operator*(const VEC3F& u, const VEC3F v) {
	return VEC3F(u[0]*v[0], u[1]*v[1], u[2]*v[2]);
}
inline VEC3F operator*(float f, const VEC3F v) {
	return VEC3F(f*v[0], f*v[1], f*v[2]);
}
inline VEC3F operator/(const VEC3F v, float f) {
	return VEC3F(v[0]/f, v[1]/f, v[2]/f);
}

//other function definitions
inline VEC3F cross(const VEC3F& u, const VEC3F& v) {
	return VEC3F( u[1]*v[2] - u[2]*v[1],
				  u[2]*v[0] - u[0]*v[2],	
				  u[0]*v[1] - u[1]*v[2]
				);
}
inline float dot(const VEC3F& u, const VEC3F& v) {
	return (u[0]*v[0]+u[1]*v[1]+u[2]*v[2]);
}*/
inline std::ostream &operator<<(std::ostream &out, const MATRIX4F& m) {
	return out << "[ " << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << ", " << m[0][3] << endl
			   << "  " << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << ", " << m[1][3] << endl
			   << "  " << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << ", " << m[2][3] << endl
			   << "  " << m[3][0] << ", " << m[3][1] << ", " << m[3][2] << ", " << m[3][3] << endl;
}

#endif


