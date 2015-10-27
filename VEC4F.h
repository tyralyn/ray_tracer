///////////////////////////////////////////////////////////////////
/* derived almost entirely from Dr. Ted Kim of Pixar 			 */
/* and UCSB Media Arts and Technology's VEC4F class              */
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include "VEC3F.h"

using namespace std;

class VEC4F {
public:
	//constructors
	VEC4F(float x, float y, float z) { element[0] = x; element[1] = y; element[2] = z; element[3] = 0;};
	VEC4F(float x, float y, float z, float a) { element[0] = x; element[1] = y; element[2] = z; element[3] = a;};
	VEC4F(float f) { element[0] = element[1] = element[2] = f; element[3] = 0;};
	VEC4F() {};
	
	//copy constructors
	VEC4F(const VEC4F& v) { *this = v; };
	VEC4F(const VEC3F& v) { element[0] = v[0]; element[1] = v[1]; element[2] = v[2]; element[3] = 0;}
	VEC4F(const VEC3F& v, float a) { element[0] = v[0]; element[1] = v[1]; element[2] = v[2]; element[3] = a;}
	VEC4F(const float e[4]) { element[0] = e[0]; element[1] = e[1]; element[2] = e[2]; element[3] = e[3];};
	
	//assignment operators
	VEC4F& operator=(const VEC4F& v) { element[0] = v[0]; element[1] = v[1]; element[2] = v[2]; element[3] = v[3];};
	
	//bracket access methods
	float& operator[](int i) { return element[i]; }
	float operator[](int i) const { return element[i]; }
	
	//in-place operator methods
	inline VEC4F& operator+= (const VEC4F& v);
	inline VEC4F& operator-= (const VEC4F& v);
	inline VEC4F& operator*= (const VEC4F& v);
	inline VEC4F& operator*= (float f);
	inline VEC4F& operator/= (const VEC4F& v);
	inline VEC4F& operator/= (float f);

	//normalize vector
	void normalize() {
		float l = element[0] * element[0] + element[1]* element[1] + element[2]*element[2] + element[3]*element[3];
		if ( l!= 0.0 && l!=1.0 ) *this /= sqrt(l);
	}

	VEC4F getNormalized() {
		VEC4F v(element[0], element[1], element[2], element[3]);
		float l = v[0] * v[0] + v[1]* v[1] + v[2]*v[2] + v[3]*v[3];
		if ( l!= 0.0 && l!=1.0 ) v /= sqrt(l);
		return v;
	}

		//magnitude
	float getMagnitude() {
		float l = element[0] * element[0] + element[1]* element[1] + element[2]*element[2] + element[3]*element[3];
		return sqrt(l);
	};

	VEC3F getVEC3F(){
		return VEC3F(element[0],element[1],element[2]);
	}

private:
	float element[4];
};

//definitions of in-place operators
inline VEC4F& VEC4F::operator+= (const VEC4F& v) {
	element[0] += v[0]; element[1] += v[1]; element[2] +=v[2]; element[3] += v[3]; return *this; 
}
inline VEC4F& VEC4F::operator-= (const VEC4F& v) {
	element[0] -= v[0]; element[1] -= v[1]; element[2] -= v[2]; element[3] -= v[3]; return *this; 
}
inline VEC4F& VEC4F::operator*= (const VEC4F& v) {
	element[0] *= v[0]; element[1] *= v[1]; element[2] *= v[2]; element[3] *= v[3]; return *this; 
}
inline VEC4F& VEC4F::operator*= (float f) {
	element[0] *= f; element[1] *= f; element[2] *=f; element[3] *= f; return *this; 
}
inline VEC4F& VEC4F::operator/= (const VEC4F& v) {
	element[0] /= v[0]; element[1] /= v[1]; element[2] /= v[2]; element[3] /= v[3]; return *this; 
}
inline VEC4F& VEC4F::operator/= (float f) {
	element[0] /= f; element[1] /= f; element[2] /=f; element[3] /= f; return *this; 
}


//definitions of operators
inline VEC4F operator+(const VEC4F& u, const VEC4F v) {
	return VEC4F(u[0]+v[0], u[1]+v[1], u[2]+v[2], u[3] + v[3]);
}
inline VEC4F operator-(const VEC4F& u, const VEC4F v) {
	return VEC4F(u[0]-v[0], u[1]-v[1], u[2]-v[2], u[3] - v[3]);
}
inline VEC4F operator-(const VEC4F& u) {
	return VEC4F(-u[0], -u[1], -u[2], -u[3]);
}
inline VEC4F operator*(const VEC4F& u, const VEC4F v) {
	return VEC4F(u[0]*v[0], u[1]*v[1], u[2]*v[2], u[3] * v[3]);
}
inline VEC4F operator*(float f, const VEC4F v) {
	return VEC4F(f*v[0], f*v[1], f*v[2], f*v[3]);
}
inline VEC4F operator/(const VEC4F& u, const VEC4F v) {
	return VEC4F(u[0]/v[0], u[1]/v[1], u[2]/v[2], u[3]/v[3]);
}
inline VEC4F operator/(const VEC4F v, float f) {
	return VEC4F(v[0]/f, v[1]/f, v[2]/f, v[3]/f);
}
inline std::ostream &operator<<(std::ostream &out, const VEC4F& v) {
	return out << "(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ")";
}



