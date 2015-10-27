///////////////////////////////////////////////////////////////////
/* derived almost entirely from Dr. Ted Kim of Pixar 			 */
/* and UCSB Media Arts and Technology's VEC3F class              */
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>

using namespace std;

class VEC3F {
public:
	//constructors
	VEC3F(float x, float y, float z) { element[0] = x; element[1] = y; element[2] = z; };
	VEC3F(float f) { element[0] = element[1] = element[2] = f;};
	VEC3F() { element[0] = element[1] = element[2] = 0;};
	
	//copy constructors
	VEC3F(const VEC3F& v) { *this = v; };
	VEC3F(const float e[3]) { element[0] = e[0]; element[1] = e[1]; element[2] = e[2]; };
	
	//assignment operators
	VEC3F& operator=(const VEC3F& v) { element[0] = v[0]; element[1] = v[1]; element[2] = v[2]; };
	
	//magnitude
	float getMagnitude() {
		float l = element[0] * element[0] + element[1]* element[1] + element[2]*element[2];
		return sqrt(l);
	};
	
	//bracket access methods
	float& operator[](int i) { return element[i]; }
	float operator[](int i) const { return element[i]; }
	
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

private:
	float element[3];
};

//definitions of in-place operators
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
inline std::ostream &operator<<(std::ostream &out, const VEC3F& v) {
	return out << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
}

//other function definitions
inline VEC3F cross(const VEC3F& u, const VEC3F& v) {
	return VEC3F( u[1]*v[2] - u[2]*v[1],
				  u[2]*v[0] - u[0]*v[2],	
				  u[0]*v[1] - u[1]*v[0]
				);
}
inline float dot(const VEC3F& u, const VEC3F& v) {
	return (u[0]*v[0]+u[1]*v[1]+u[2]*v[2]);
}


