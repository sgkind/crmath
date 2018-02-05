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
	inline void GetVector(const pnt2d start, const pnt2d end, vec2 vec)
	{
		vec[0] = end[0] - start[0];
		vec[1] = end[1] - start[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Add
	  Description: ��������ʸ��u��v����Ӻ��ʸ��
	  Calls:       ��
	  Input:       ʸ��@u��@v
	  Ouput:       ��ʸ��@sum
	  Return:      ��
	  Other:
	*---------------------------------------------------------------------------*/
	inline void Add(const vec2 u, const vec2 v, vec2 sum)
	{
		sum[0] = u[0] + v[0];
		sum[1] = u[1] + v[1];
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
	inline void Subtract(const vec2 u, const vec2 v, vec2 result)
	{
		result[0] = u[0] - v[0];
		result[1] = u[1] - v[1];
	}

	/*---------------------------------------------------------------------------
	  Function:    Angle
	  Description: ������ʸ����ļн�
	  Calls:       Length2d    Dot2d
	  Input:       @u��@v
	  Ouput:       ��
	  Return:      ʸ���ļн�
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
	  Description: �ж����������Ƿ�ƽ��
	  Calls:       Unitization2d    Dot2d
	  Input:       @u��@v
	  Ouput:       ��
	  Return:      ʸ���ļн�
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
	  Description: �ж����������Ƿ�ֱ
	  Calls:       Unitization2d    Dot2d
	  Input:       @u��@v
	  Ouput:       ��
	  Return:      ʸ���ļн�
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