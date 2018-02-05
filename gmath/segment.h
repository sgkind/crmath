#pragma once

#include "objects.h"

namespace gmath {
	/*---------------------------------------------------------------------------
	  Function:    MinDistancePointToSegment
	  Description: ����㵽�߶ε���̾���
	  Calls:       ��
	  Input:       @pointΪ�㣬@p1@p2Ϊ�߶�2
	  Ouput:       ��
	  Return:      �㵽�߶ε���̾���
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistancePointToSegment(const pnt3d point, const pnt3d p1, const pnt3d p2);

	/*---------------------------------------------------------------------------
	  Function:    MinDistancePointToSegment
	  Description: ����㵽�߶ε���̾��뼰��̾������ڵ�������
	  Calls:       ��
	  Input:       @pointΪ�㣬@p1@p2Ϊ�߶�2
	  Ouput:       @pointsΪ�ؼ��������
	  Return:      �㵽�߶ε���̾���
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistancePointToSegment(const pnt3d point, const pnt3d p1, const pnt3d p2, double points[2][3]);

	/*---------------------------------------------------------------------------
	  Function:    MinDistancePointToSegmentInDirection
	  Description: �������ĳ�������߶εľ���
	  Calls:       ��
	  Input:       @pointΪ�㣬@p1@p2Ϊ�߶�2, @direction����ʸ��
	  Ouput:       ��
	  Return:      ����ĳ�������߶ε���̾���
	  Other:       �����ͷ���ʸ���γɵ�ֱ�����߶β��뽻�򷵻����doubleֵ
	*---------------------------------------------------------------------------*/
	double MinDistancePointToSegmentInDirection(const pnt3d point, const vec3 direction, const pnt3d p1, const pnt3d p2);

	/*---------------------------------------------------------------------------
	  Function:    MinDistanceSegmentToSegment
	  Description: ���������߶�֮�����̾���
	  Calls:       ��
	  Input:       @p11@p12Ϊ�߶�1��@p21@p22Ϊ�߶�2
	  Ouput:       ��
	  Return:      �����߶ε���̾���
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistanceSegmentToSegment(const pnt3d p11, const pnt3d p12, const pnt3d p21, const pnt3d p22);

	/*---------------------------------------------------------------------------
	  Function:    MinDistanceSegmentToSegment
	  Description: ���������߶�֮�����̾��뼰��̾������ڵ�������
	  Calls:       ��
	  Input:       @p11@p12Ϊ�߶�1��@p21@p22Ϊ�߶�2
	  Ouput:       @pointsΪ�ؼ��������
	  Return:      �����߶ε���̾���
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistanceSegmentToSegment(const pnt3d p11, const pnt3d p12, const pnt3d p21, const pnt3d p22, double points[2][3]);
}
