#pragma once

#include "objects.h"

namespace gmath {
	/*---------------------------------------------------------------------------
	  Function:    Length2d
	  Description: 获得矢量的长度
	  Calls:       无
	  Input:       @vec需要计算的矢量
	  Ouput:       无
	  Return:      矢量的长度
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Length2d(const vec2 vec)
	{
		return sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
	}

	/*---------------------------------------------------------------------------
	Function:    Length3d
	Description: 获得矢量的长度
	Calls:       无
	Input:       @vec需要计算的矢量
	Ouput:       无
	Return:      矢量的长度
	Other:
	*---------------------------------------------------------------------------*/
	inline double Length3d(const vec3 vec)
	{
		return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	}

   /*---------------------------------------------------------------------------
	  Function:    Distance2d
	  Description: 计算两个点之间的距离
	  Calls:       无
	  Input:       两个点@point1和@point2
	  Ouput:       无
	  Return:      两个点之间的距离
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Distance2d(const pnt2d point1, const pnt2d point2)
	{
		return sqrt(pow(point2[0] - point1[0], 2.0)  + pow(point2[1] - point1[1], 2.0));
	}

    /*---------------------------------------------------------------------------
	  Function:    distance3d
	  Description: 计算两个点之间的距离
	  Calls:       无
	  Input:       两个点@point1和@point2
	  Ouput:       无
	  Return:      两个点之间的距离
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Distance3d(const pnt3d point1, const pnt3d point2)
	{
		return sqrt(pow(point2[0] - point1[0], 2.0) + pow(point2[1] - point1[1], 2.0) + pow(point2[2] - point1[2], 2.0));
	}

	/*---------------------------------------------------------------------------
	  Function:    Dot2d
	  Description: 计算两个矢量u和v的点乘
	  Calls:       无
	  Input:       矢量@u和@v
	  Ouput:       无
	  Return:      点乘的结果
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Dot2d(const vec2 u, const vec2 v)
	{
		return u[0] * v[0] + u[1] * v[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Dot3d
	  Description: 计算两个矢量u和v的点乘
	  Calls:       无
	  Input:       矢量@u和@v
	  Ouput:       无
	  Return:      点乘的结果
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Dot3d(const vec3 u, const vec3 v)
	{
		return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
	}

	/*---------------------------------------------------------------------------
	  Function:    Cross3d
	  Description: 计算两个矢量u和v的叉乘
	  Calls:       无
	  Input:       矢量@u和@v
	  Ouput:       结果矢量@result
	  Return:      无
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Cross3d(const vec3 u, const vec3 v, vec3 result)
	{
		result[0] = u[1] * v[2] - v[1] * u[2];
		result[1] = u[2] * v[0] - v[2] * u[0];
		result[2] = u[0] * v[1] - v[0] * u[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Unitization2d
	  Description: 向量单位化
	  Calls:       Length
	  Input:       需要单位化的向量@vec
	  Ouput:       单位化后的向量@vec
	  Return:      无
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Unitization2d(vec2 vec)
	{
		double length = Length2d(vec);
		vec[0] /= length;
		vec[1] /= length;
	}

	/*---------------------------------------------------------------------------
	  Function:    Unitization2d
	  Description: 向量单位化
	  Calls:       Length
	  Input:       需要单位化的向量@vec
	  Ouput:       单位化后的向量@result
	  Return:      无
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Unitization2d(const vec2 vec, vec2 result)
	{
		double length = Length2d(vec);
		result[0] = vec[0] / length;
		result[1] = vec[1] / length;
	}

	/*---------------------------------------------------------------------------
	  Function:    Unitization3d
	  Description: 向量单位化
	  Calls:       Length
	  Input:       需要单位化的向量@vec
	  Ouput:       单位化后的向量@vec
	  Return:      无
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Unitization3d(vec3 vec)
	{
		double length = Length3d(vec);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
	}

	/*---------------------------------------------------------------------------
	  Function:    Unitization3d
	  Description: 向量单位化
	  Calls:       Length
	  Input:       需要单位化的向量@vec
	  Ouput:       单位化后的向量@result
	  Return:      无
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Unitization3d(const vec3 vec, vec3 result)
	{
		double length = Length3d(vec);
		result[0] = vec[0] / length;
		result[1] = vec[1] / length;
		result[2] = vec[2] / length;
	}
}
