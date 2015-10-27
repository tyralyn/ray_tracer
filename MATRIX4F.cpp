#include "MATRIX4F.h"

MATRIX4F::MATRIX4F() {
	for(int i = 0; i < 4; i++) {
		column[i]=VEC4F();
		cout<<"setting up col "<<i<<endl;
	}
}