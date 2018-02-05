#pragma once

#include "objects.h"
#include "geometric.h"

namespace gmath {
	/*---------------------------------------------------------------------------
	  Function:    GetVector
	  Description: 获得两个点之间的向量
	  Calls:       无
	  Input:       @start起始点，@end终止点
	  Ouput:       @vec 结果向量
	  Return:      void
	  Other:
	*---------------------------------------------------------------------------*/
	inline void GetVector(const pnt2d start, const pnt2d end, vec2 vec)
	{
		vec[0] = end[0] - start[0];
		vec[1] = end[1] - start[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Add
	  Description: 计算两个矢量u和v的相加后的矢量
	  Calls:       无
	  Input:       矢量@u和@v
	  Ouput:       和矢量@sum
	  Return:      无
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Add(const vec2 u, const vec2 v, vec2 sum)
	{
		sum[0] = u[0] + v[0];
		sum[1] = u[1] + v[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Subtract
	  Description: 计算两个矢量u和v的相减后的矢量
	  Calls:       无
	  Input:       矢量@u和@v
	  Ouput:       结果矢量@result
	  Return:      无
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Subtract(const vec2 u, const vec2 v, vec2 result)
	{
		result[0] = u[0] - v[0];
		result[1] = u[1] - v[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Angle
	  Description: 计算两矢量间的夹角
	  Calls:       Length2d    Dot2d
	  Input:       @u和@v
	  Ouput:       无
	  Return:      矢量的夹角
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Angle(const vec2 u, const vec2 v)
	{
		double length_u = Length2d(u);
		double length_v = Length2d(v);
		double dot_product = Dot2d(u, v);
		if (dot_product > 1.0)
			dot_product = 1.0;
		else if (dot_product < -1.0)
			dot_product = -1.0;

		return acos(dot_product);
	}

	/*---------------------------------------------------------------------------
	  Function:    IsParallel2d
	  Description: 判断两个向量是否平行
	  Calls:       Unitization2d    Dot2d
	  Input:       @u和@v
	  Ouput:       无
	  Return:      矢量的夹角
	  Other:
	*---------------------------------------------------------------------------*/
	inline bool IsParallel2d(const vec2 u, const vec2 v)
	{
		vec2 unit_u, unit_v;
		Unitization2d(u, unit_u);
		Unitization2d(v, unit_v);
		double dot_product = Dot2d(unit_u, unit_v);
		return equal(abs(dot_product), 1.0);
	}

	/*---------------------------------------------------------------------------
	  Function:    IsVertical2d
	  Description: 判断两个向量是否垂直
	  Calls:       Unitization2d    Dot2d
	  Input:       @u和@v
	  Ouput:       无
	  Return:      矢量的夹角
	  Other:
	*---------------------------------------------------------------------------*/
	inline bool IsVertical2d(const vec2 u, const vec2 v)
	{
		vec2 unit_u, unit_v;
		Unitization2d(u, unit_u);
		Unitization2d(v, unit_v);
		double dot_product = Dot2d(unit_u, unit_v);
		return equal(abs(dot_product), 0.0);
	}
}