#include "stdafx.h"

#include "segment.h"

#include <cstring>
#include <cfloat>

#include "geometric.h"

namespace gmath {
	/// 计算点到线段的最短距离
	double MinDistancePointToSegment(const pnt3d point, const pnt3d p1, const pnt3d p2)
	{
		double minDistance;

		double x0, y0, z0, x1, y1, z1, x2, y2, z2;

		x0 = point[0]; y0 = point[1]; z0 = point[2];
		x1 = p1[0]; y1 = p1[1]; z1 = p1[2];
		x2 = p2[0]; y2 = p2[1]; z2 = p2[2];

		double t = ((x1 - x0) * (x1 - x2) + (y1 - y0) * (y1 - y2) + (z1 - z0) * (z1 - z2))
			/ ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));

		if (0 <= t && t <= 1)
		{
			double x = x1 + t * (x2 - x1);
			double y = y1 + t * (y2 - y1);
			double z = z1 + t * (z2 - z1);
			minDistance = sqrt((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) + (z0 - z) * (z0 - z));
		}
		else if (t < 0)
		{
			minDistance = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) + (z0 - z1) * (z0 - z1));
		}
		else if (t > 1)
		{
			minDistance = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2) + (z0 - z2) * (z0 - z2));
		}

		return minDistance;
	}

	/// 计算点到线段的最短距离及关键点
	double MinDistancePointToSegment(const pnt3d point, const pnt3d p1, const pnt3d p2, double points[2][3])
	{
		double minDistance;

		double x0, y0, z0, x1, y1, z1, x2, y2, z2;

		x0 = point[0]; y0 = point[1]; z0 = point[2];
		x1 = p1[0]; y1 = p1[1]; z1 = p1[2];
		x2 = p2[0]; y2 = p2[1]; z2 = p2[2];

		double t = ((x1 - x0) * (x1 - x2) + (y1 - y0) * (y1 - y2) + (z1 - z0) * (z1 - z2))
			/ ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));

		if (0 <= t && t <= 1)
		{
			double x = x1 + t * (x2 - x1);
			double y = y1 + t * (y2 - y1);
			double z = z1 + t * (z2 - z1);
			memcpy(points[0], point, sizeof(pnt3d));
			points[1][0] = x; points[1][1] = y; points[1][2] = z;

			minDistance = sqrt((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) + (z0 - z) * (z0 - z));
		}
		else if (t < 0)
		{
			memcpy(points[0], point, sizeof(pnt3d));
			memcpy(points[1], p1, sizeof(pnt3d));
			minDistance = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) + (z0 - z1) * (z0 - z1));
		}
		else if (t > 1)
		{
			memcpy(points[0], point, sizeof(pnt3d));
			memcpy(points[1], p2, sizeof(pnt3d));
			minDistance = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2) + (z0 - z2) * (z0 - z2));
		}

		return minDistance;
	}

	/// 计算点沿某个方向到线段的距离
	double MinDistancePointToSegmentInDirection(const pnt3d point, const vec3 direction, const pnt3d p1, const pnt3d p2)
	{
		pnt3d interPoint;
		double x1 = point[0], y1 = point[1], z1 = point[2];
		double x2 = p1[0], y2 = p1[1], z2 = p1[2];

		double u1 = direction[0];
		double v1 = direction[1];
		double w1 = direction[2];
		double u2 = p2[0] - p1[0];
		double v2 = p2[1] - p1[1];
		double w2 = p2[2] - p1[2];

		double t;

		if (fabs(u1 * v2 - u2 * v1) > 1.0e-8)
		{
			double left = u1 * v2 - u2 * v1;
			double right = v2 * x2 - u2 * y2 + u2 * y1 - v2 * x1;
			t = right / left;
		}
		else if (fabs(v1 * w2 - v2 * w1) > 1.0e-8)
		{
			double left = v1 * w2 - v2 * w1;
			double right = w2 * y2 - v2 * z2 - w2 * y1 + v2 * z1;
			t = right / left;
		}
		else
		{
			double left = u1 * w2 - u2 * w1;
			double right = w2 * x2 - u2 * z2 + u2 * z1 - w2 * x1;
			t = right / left;
		}

		interPoint[0] = x1 + u1 * t;
		interPoint[1] = y1 + v1 * t;
		interPoint[2] = z1 + w1 * t;

		double xmin = (p1[0] < p2[0] ? p1[0] : p2[0]);
		double xmax = (p1[0] > p2[0] ? p1[0] : p2[0]);

		if (xmin <= interPoint[0] && xmax >= interPoint[0])
			return Distance3d(point, interPoint);
		else
			return DBL_MAX;
	}

	/// 计算线段到线段的最短距离
	double MinDistanceSegmentToSegment(const pnt3d p1, const pnt3d p2, const pnt3d p3, const pnt3d p4)
	{
		double minDistance;
		double x1, y1, z1, x2, y2, z2;
		double x3, y3, z3, x4, y4, z4;

		x1 = p1[0]; y1 = p1[1]; z1 = p1[2];
		x2 = p2[0]; y2 = p2[1]; z2 = p2[2];
		x3 = p3[0]; y3 = p3[1]; z3 = p3[2];
		x4 = p4[0]; y4 = p4[1]; z4 = p4[2];

		double a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
		double b = -((x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3) + (z2 - z1) * (z4 - z3));
		double c = -((x1 - x2) * (x1 - x3) + (y1 - y2) * (y1 - y3) + (z1 - z2) * (z1 - z3));

		double d = -((x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3) + (z2 - z1) * (z4 - z3));
		double e = (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3) + (z4 - z3) * (z4 - z3);
		double f = -((x1 - x3) * (x4 - x3) + (y1 - y3) * (y4 - y3) + (z1 - z3) * (z4 - z3));

		if ((a * e - b * d) == 0 && (b * d - a * e) == 0)
		{
			double d1 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) + (z1 - z3) * (z1 - z3));
			double d2 = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4) + (z1 - z4) * (z1 - z4));
			double d3 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) + (z2 - z3) * (z2 - z3));
			double d4 = sqrt((x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4) + (z2 - z4) * (z2 - z4));
			minDistance = (d1 < d2) ? d1 : d2;
			minDistance = (minDistance < d3) ? minDistance : d3;
			minDistance = (minDistance < d4) ? minDistance : d4;
			return minDistance;
		}

		double s = (b * f - e * c) / (a * e - b * d);
		double t = (a * f - d * c) / (b * d - a * e);

		if (0 <= s && s <= 1 && 0 <= t && t <= 1)
		{
			double x = x1 + s * (x2 - x1);
			double y = y1 + s * (y2 - y1);
			double z = z1 + s * (z2 - z1);

			double u = x3 + t * (x4 - x3);
			double v = y3 + t * (y4 - y3);
			double w = z3 + t * (z4 - z3);

			minDistance = sqrt((u - x) * (u - x) + (v - y) * (v - y) + (w - z) * (w - z));
		}
		else
		{
			double d1 = MinDistancePointToSegment(p1, p3, p4);
			double d2 = MinDistancePointToSegment(p2, p3, p4);
			double d3 = MinDistancePointToSegment(p3, p1, p2);
			double d4 = MinDistancePointToSegment(p4, p1, p2);
			minDistance = (d1 < d2) ? d1 : d2;
			minDistance = (minDistance < d3) ? minDistance : d3;
			minDistance = (minDistance < d4) ? minDistance : d4;
		}
		return minDistance;
	}

	/// 计算线段到线段的最短距离及关键点
	double minDistanceSegmentToSegment(const pnt3d p1, const pnt3d p2, const pnt3d p3, const pnt3d p4, double points[2][3])
	{
		double minDistance;
		double x1, y1, z1, x2, y2, z2;
		double x3, y3, z3, x4, y4, z4;

		x1 = p1[0]; y1 = p1[1]; z1 = p1[2];
		x2 = p2[0]; y2 = p2[1]; z2 = p2[2];
		x3 = p3[0]; y3 = p3[1]; z3 = p3[2];
		x4 = p4[0]; y4 = p4[1]; z4 = p4[2];

		double a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
		double b = -((x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3) + (z2 - z1) * (z4 - z3));
		double c = -((x1 - x2) * (x1 - x3) + (y1 - y2) * (y1 - y3) + (z1 - z2) * (z1 - z3));

		double d = -((x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3) + (z2 - z1) * (z4 - z3));
		double e = (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3) + (z4 - z3) * (z4 - z3);
		double f = -((x1 - x3) * (x4 - x3) + (y1 - y3) * (y4 - y3) + (z1 - z3) * (z4 - z3));

		if ((a * e - b * d) == 0 && (b * d - a * e) == 0)
		{
			double d1 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) + (z1 - z3) * (z1 - z3));
			double d2 = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4) + (z1 - z4) * (z1 - z4));
			double d3 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) + (z2 - z3) * (z2 - z3));
			double d4 = sqrt((x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4) + (z2 - z4) * (z2 - z4));

			if (d1 < d2)
			{
				minDistance = d1;
				memcpy(points[0], p1, sizeof(pnt3d));
				memcpy(points[1], p3, sizeof(pnt3d));
			}
			else
			{
				minDistance = d2;
				memcpy(points[0], p1, sizeof(pnt3d));
				memcpy(points[1], p4, sizeof(pnt3d));
			}

			if (minDistance > d3)
			{
				minDistance = d3;
				memcpy(points[0], p2, sizeof(pnt3d));
				memcpy(points[1], p3, sizeof(pnt3d));
			}

			if (minDistance > d4)
			{
				minDistance = d4;
				memcpy(points[0], p2, sizeof(pnt3d));
				memcpy(points[1], p4, sizeof(pnt3d));
			}

			return minDistance;
		}

		double s = (b * f - e * c) / (a * e - b * d);
		double t = (a * f - d * c) / (b * d - a * e);

		if (0 <= s && s <= 1 && 0 <= t && t <= 1)
		{
			double x = x1 + s * (x2 - x1);
			double y = y1 + s * (y2 - y1);
			double z = z1 + s * (z2 - z1);

			double u = x3 + t * (x4 - x3);
			double v = y3 + t * (y4 - y3);
			double w = z3 + t * (z4 - z3);

			points[0][0] = x; points[0][1] = y; points[0][2] = z;
			points[1][0] = u; points[1][1] = v; points[1][2] = w;

			minDistance = sqrt((u - x) * (u - x) + (v - y) * (v - y) + (w - z) * (w - z));
		}
		else
		{
			double d1 = MinDistancePointToSegment(p1, p3, p4);
			double d2 = MinDistancePointToSegment(p2, p3, p4);
			double d3 = MinDistancePointToSegment(p3, p1, p2);
			double d4 = MinDistancePointToSegment(p4, p1, p2);
			minDistance = (d1 < d2) ? d1 : d2;
			minDistance = (minDistance < d3) ? minDistance : d3;
			minDistance = (minDistance < d4) ? minDistance : d4;

			if (d1 < d2)
			{
				minDistance = d1;
				MinDistancePointToSegment(p1, p3, p4, points);
			}
			else
			{
				minDistance = d2;
				MinDistancePointToSegment(p2, p3, p4, points);
			}

			if (minDistance > d3)
			{
				minDistance = d3;
				MinDistancePointToSegment(p3, p1, p2, points);
			}

			if (minDistance > d4)
			{
				minDistance = d4;
				MinDistancePointToSegment(p4, p1, p2, points);
			}
		}
		return minDistance;
	}

}