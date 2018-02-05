#pragma once

#include "objects.h"

namespace gmath {
	/*---------------------------------------------------------------------------
	  Function:    Length2d
	  Description: ���ʸ���ĳ���
	  Calls:       ��
	  Input:       @vec��Ҫ�����ʸ��
	  Ouput:       ��
	  Return:      ʸ���ĳ���
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Length2d(const vec2 vec)
	{
		return sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
	}

	/*---------------------------------------------------------------------------
	Function:    Length3d
	Description: ���ʸ���ĳ���
	Calls:       ��
	Input:       @vec��Ҫ�����ʸ��
	Ouput:       ��
	Return:      ʸ���ĳ���
	Other:
	*---------------------------------------------------------------------------*/
	inline double Length3d(const vec3 vec)
	{
		return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	}

   /*---------------------------------------------------------------------------
	  Function:    Distance2d
	  Description: ����������֮��ľ���
	  Calls:       ��
	  Input:       ������@point1��@point2
	  Ouput:       ��
	  Return:      ������֮��ľ���
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Distance2d(const pnt2d point1, const pnt2d point2)
	{
		return sqrt(pow(point2[0] - point1[0], 2.0)  + pow(point2[1] - point1[1], 2.0));
	}

    /*---------------------------------------------------------------------------
	  Function:    distance3d
	  Description: ����������֮��ľ���
	  Calls:       ��
	  Input:       ������@point1��@point2
	  Ouput:       ��
	  Return:      ������֮��ľ���
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Distance3d(const pnt3d point1, const pnt3d point2)
	{
		return sqrt(pow(point2[0] - point1[0], 2.0) + pow(point2[1] - point1[1], 2.0) + pow(point2[2] - point1[2], 2.0));
	}

	/*---------------------------------------------------------------------------
	  Function:    Dot2d
	  Description: ��������ʸ��u��v�ĵ��
	  Calls:       ��
	  Input:       ʸ��@u��@v
	  Ouput:       ��
	  Return:      ��˵Ľ��
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Dot2d(const vec2 u, const vec2 v)
	{
		return u[0] * v[0] + u[1] * v[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Dot3d
	  Description: ��������ʸ��u��v�ĵ��
	  Calls:       ��
	  Input:       ʸ��@u��@v
	  Ouput:       ��
	  Return:      ��˵Ľ��
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Dot3d(const vec3 u, const vec3 v)
	{
		return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
	}

	/*---------------------------------------------------------------------------
	  Function:    Cross3d
	  Description: ��������ʸ��u��v�Ĳ��
	  Calls:       ��
	  Input:       ʸ��@u��@v
	  Ouput:       ���ʸ��@result
	  Return:      ��
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
	  Description: ������λ��
	  Calls:       Length
	  Input:       ��Ҫ��λ��������@vec
	  Ouput:       ��λ���������@vec
	  Return:      ��
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
	  Description: ������λ��
	  Calls:       Length
	  Input:       ��Ҫ��λ��������@vec
	  Ouput:       ��λ���������@result
	  Return:      ��
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
	  Description: ������λ��
	  Calls:       Length
	  Input:       ��Ҫ��λ��������@vec
	  Ouput:       ��λ���������@vec
	  Return:      ��
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
	  Description: ������λ��
	  Calls:       Length
	  Input:       ��Ҫ��λ��������@vec
	  Ouput:       ��λ���������@result
	  Return:      ��
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
