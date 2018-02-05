#pragma once

#include <cmath>


#ifdef LOWP
#define RESIDUAL 1.0e-5
#elif MEDIUMP
#define RESIDUAL 1.0e-10
#elif HIGHP
#define RESIDUAL 1.0e-15
#else
#define RESIDUAL 1.0e-15
#endif

namespace gmath {
	/// 判断@v1和@v2是否相等
	inline bool equal(double v1, double v2)
	{
		return fabs(v1 - v2) < RESIDUAL;
	}

}