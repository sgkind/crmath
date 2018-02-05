#include "stdafx.h"

#include "AABB.h"

#include <cfloat>
#include <limits>

#include "segment.h"

namespace gmath {
	AABB::AABB() {
		reset();          // 初始化最小顶点和最大顶点
	}

	AABB::AABB(const pnt3d min, const pnt3d max){
		set(min, max);    // 设置最小顶点和最大顶点
	}

	AABB::~AABB(){

	}

	// 向包围盒中添加点，用来构造控件包围盒
	void AABB::addPoint(const pnt3d point){
		for (int i = 0; i < 3; i++) {
			if (point[i] < min_[i])
				min_[i] = point[i];
			if (point[i] > max_[i])
				max_[i] = point[i];
		}
	}

	bool AABB::intersect(const AABB& aabb) const {
		if (max_[0] < aabb.min_[0])
			return false;
		if (aabb.max_[0] < min_[0])
			return false;
		if (max_[1] < aabb.min_[1])
			return false;
		if (aabb.max_[1] < min_[1])
			return false;
		if (max_[2] < aabb.min_[2])
			return false;
		if (aabb.max_[2] < min_[2])
			return false;
		return true;
	}

	double AABB::lowerBound(const AABB& aabb) const {
		double lower = DBL_MAX;

		if (intersect(aabb))
			return 0.0;

		AABB temp;

		pnt3d a, b;

		a[0] = max_[0] - aabb.min_[0];
		a[1] = max_[1] - aabb.min_[1];
		a[2] = max_[2] - aabb.min_[2];

		b[0] = min_[0] - aabb.max_[0];
		b[1] = min_[1] - aabb.max_[1];
		b[2] = min_[2] - aabb.max_[2];

		temp.addPoint(a);
		temp.addPoint(b);

		if (temp.min_[1] < 0 && temp.max_[1] > 0 && temp.min_[2] < 0 && temp.max_[2] > 0)
		{
			lower = (fabs(temp.min_[0]) < fabs(temp.max_[0])) ? fabs(temp.min_[0]) : fabs(temp.max_[0]);
		}
		else if (temp.min_[0] < 0 && temp.max_[0] > 0 && temp.min_[2] < 0 && temp.max_[2] > 0)
		{
			lower = (fabs(temp.min_[1]) < fabs(temp.max_[1])) ? fabs(temp.min_[1]) : fabs(temp.max_[1]);
		}
		else if (temp.min_[0] < 0 && temp.max_[0] > 0 && temp.min_[1] < 0 && temp.max_[1] > 0)
		{
			lower = (fabs(temp.min_[2]) < fabs(temp.max_[2])) ? fabs(temp.min_[2]) : fabs(temp.max_[2]);
		}
		else
		{
			pnt3d p = { 0.0, 0.0, 0.0 };
			pnt3d p11 = { temp.min_[0], temp.min_[1], temp.min_[2] };
			pnt3d p12 = { temp.min_[0], temp.max_[1], temp.min_[2] };
			pnt3d p13 = { temp.min_[0], temp.max_[1], temp.max_[2] };
			pnt3d p14 = { temp.min_[0], temp.min_[1], temp.max_[2] };

			pnt3d p21 = { temp.max_[0], temp.min_[1], temp.min_[2] };
			pnt3d p22 = { temp.max_[0], temp.max_[1], temp.min_[2] };
			pnt3d p23 = { temp.max_[0], temp.max_[1], temp.max_[2] };
			pnt3d p24 = { temp.max_[0], temp.min_[1], temp.max_[2] };

			double d[12];
			d[0] = MinDistancePointToSegment(p, p11, p12);
			d[1] = MinDistancePointToSegment(p, p12, p13);
			d[2] = MinDistancePointToSegment(p, p13, p14);
			d[3] = MinDistancePointToSegment(p, p14, p11);
			d[4] = MinDistancePointToSegment(p, p11, p21);
			d[5] = MinDistancePointToSegment(p, p12, p22);
			d[6] = MinDistancePointToSegment(p, p13, p23);
			d[7] = MinDistancePointToSegment(p, p14, p24);
			d[8] = MinDistancePointToSegment(p, p21, p22);
			d[9] = MinDistancePointToSegment(p, p22, p23);
			d[10] = MinDistancePointToSegment(p, p23, p24);
			d[11] = MinDistancePointToSegment(p, p24, p21);

			for (int i = 0; i < 12; i++)
				if (d[i] < lower)
					lower = d[i];
		}
		return lower;
	}

	bool AABB::enlargeAndCheck(double value, const AABB &aabb) const
	{
		pnt3d min_n, max_n;
		for (int i = 0; i < 3; i++)
		{
			min_n[i] = min_[i] - value;
			max_n[i] = max_[i] + value;
		}

		AABB temp(min_n, max_n);

		return temp.intersect(aabb);
	}

	// 设置最大顶点和最小顶点
	void AABB::set(const pnt3d min, const pnt3d max)
	{
		memcpy(min_, min, sizeof(double) * 3);
		memcpy(max_, max, sizeof(double) * 3);
	}

	// 复位函数，顶点复位
	void AABB::reset()
	{
		min_[0] = DBL_MAX; min_[1] = DBL_MAX; min_[2] = DBL_MAX;
		max_[0] = -DBL_MAX; max_[1] = -DBL_MAX; max_[2] = -DBL_MAX;
	}

	// 判断包围盒是否为空
	bool AABB::isEmpty() const
	{
		if (min_[0] > max_[0])
			return true;
		if (min_[1] > max_[1])
			return true;
		if (min_[2] > max_[2])
			return true;
		return false;
	}

}