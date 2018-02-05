#pragma once

#include "objects.h"

namespace gmath {
	/*---------------------------------------------------------------------------
	  Function:    MinDistancePointToSegment
	  Description: 计算点到线段的最短距离
	  Calls:       无
	  Input:       @point为点，@p1@p2为线段2
	  Ouput:       无
	  Return:      点到线段的最短距离
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistancePointToSegment(const pnt3d point, const pnt3d p1, const pnt3d p2);

	/*---------------------------------------------------------------------------
	  Function:    MinDistancePointToSegment
	  Description: 计算点到线段的最短距离及最短距离所在的两个点
	  Calls:       无
	  Input:       @point为点，@p1@p2为线段2
	  Ouput:       @points为关键点的坐标
	  Return:      点到线段的最短距离
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistancePointToSegment(const pnt3d point, const pnt3d p1, const pnt3d p2, double points[2][3]);

	/*---------------------------------------------------------------------------
	  Function:    MinDistancePointToSegmentInDirection
	  Description: 计算点沿某个方向到线段的距离
	  Calls:       无
	  Input:       @point为点，@p1@p2为线段2, @direction方向矢量
	  Ouput:       无
	  Return:      点沿某个方向到线段的最短距离
	  Other:       如果点和方向矢量形成的直线与线段不想交则返回最大double值
	*---------------------------------------------------------------------------*/
	double MinDistancePointToSegmentInDirection(const pnt3d point, const vec3 direction, const pnt3d p1, const pnt3d p2);

	/*---------------------------------------------------------------------------
	  Function:    MinDistanceSegmentToSegment
	  Description: 计算两条线段之间的最短距离
	  Calls:       无
	  Input:       @p11@p12为线段1，@p21@p22为线段2
	  Ouput:       无
	  Return:      两个线段的最短距离
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistanceSegmentToSegment(const pnt3d p11, const pnt3d p12, const pnt3d p21, const pnt3d p22);

	/*---------------------------------------------------------------------------
	  Function:    MinDistanceSegmentToSegment
	  Description: 计算两条线段之间的最短距离及最短距离所在的两个点
	  Calls:       无
	  Input:       @p11@p12为线段1，@p21@p22为线段2
	  Ouput:       @points为关键点的坐标
	  Return:      两个线段的最短距离
	  Other:
	*---------------------------------------------------------------------------*/
	double MinDistanceSegmentToSegment(const pnt3d p11, const pnt3d p12, const pnt3d p21, const pnt3d p22, double points[2][3]);
}
