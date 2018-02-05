#pragma once

#include "objects.h"
#include "geometric.h"

namespace gmath {
	/*---------------------------------------------------------------------------
	  Function:    GetVector
	  Description: ���������֮�������
	  Calls:       ��
	  Input:       @start��ʼ�㣬@end��ֹ��
	  Ouput:       @vec �������
	  Return:      void
	  Other:
	*---------------------------------------------------------------------------*/
	inline void GetVector(const pnt3d start, const pnt3d end, vec3 vec)
	{
		vec[0] = end[0] - start[0];
		vec[1] = end[1] - start[1];
		vec[2] = end[2] - start[2];
	}

	/*---------------------------------------------------------------------------
	   Function:    Add
	   Description: ��������ʸ��u��v����Ӻ��ʸ��
	   Calls:       ��
	   Input:       ʸ��@u��@v
	   Ouput:       ��ʸ��
	   Return:      ��
	   Other:
	 *---------------------------------------------------------------------------*/
	inline void Add(const vec3 u, const vec3 v, vec3 sum)
	{
		sum[0] = u[0] + v[0];
		sum[1] = u[1] + v[1];
		sum[2] = u[2] + v[2];
	}

	/*---------------------------------------------------------------------------
	  Function:    Subtract
	  Description: ��������ʸ��u��v��������ʸ��
	  Calls:       ��
	  Input:       ʸ��@u��@v
	  Ouput:       ���ʸ��@result
	  Return:      ��
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Subtract(const vec3 u, const vec3 v, vec3 result)
	{
		result[0] = u[0] - v[0];
		result[1] = u[1] - v[1];
		result[2] = u[2] - v[2];
	}

	/*---------------------------------------------------------------------------
	  Function:    Angle3d
	  Description: ������ʸ����ļн�
	  Calls:       Length3d    Dot3d
	  Input:       @u��@v
	  Ouput:       ��
	  Return:      ʸ���ļн�
	  Other:
	*---------------------------------------------------------------------------*/
	inline double Angle3d(const vec3 u, const vec3 v)
	{
		double length_u = Length3d(u);
		double length_v = Length3d(v);
		double dot_product = Dot3d(u, v);
		if (dot_product > 1.0)
			dot_product = 1.0;
		else if (dot_product < -1.0)
			dot_product = -1.0;

		return acos(dot_product);
	}

	/*---------------------------------------------------------------------------
	  Function:    IsParallel3d
	  Description: �ж����������Ƿ�ƽ��
	  Calls:       Unitization3d    Dot3d
	  Input:       @u��@v
	  Ouput:       ��
	  Return:      ʸ���ļн�
	  Other:
	*---------------------------------------------------------------------------*/
	inline bool IsParallel3d(const vec3 u, const vec3 v)
	{
		vec3 unit_u, unit_v;
		Unitization3d(u, unit_u);
		Unitization3d(v, unit_v);
		double dot_product = Dot3d(unit_u, unit_v);
		return equal(abs(dot_product), 1.0);
	}

	/*---------------------------------------------------------------------------
	  Function:    IsVertical3d
	  Description: �ж����������Ƿ�ֱ
	  Calls:       ��
	  Input:       @u��@v
	  Ouput:       ��
	  Return:      ʸ���ļн�
	  Other:
	*---------------------------------------------------------------------------*/
	inline bool IsVertical3d(const vec3 u, const vec3 v)
	{
		vec3 unit_u, unit_v;
		Unitization3d(u, unit_u);
		Unitization3d(v, unit_v);
		double dot_product = Dot3d(unit_u, unit_v);
		return equal(abs(dot_product), 0.0);
	}
}
