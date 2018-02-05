#pragma once

#include <cstring>

#include "objects.h"

namespace gmath {

	/*-------------------------------------------------------------------
	 * 与轴平行的长方体包围盒
	 *-----------------------------------------------------------------*/
	class AABB {
	public:
		AABB();                                     // 默认构造函数
		AABB(const pnt3d min, const pnt3d max);     // 自定义构造函数

		~AABB();  // 析构函数

		void get_min(pnt3d min) const { memcpy(min, min_, sizeof(min_)); }
		void get_max(pnt3d max) const { memcpy(max, max_, sizeof(max_)); }

		void addPoint(const pnt3d point);           // 向包围盒中添加点
		// TODO: 向包围盒中添加圆弧、圆、点集等

		bool intersect(const AABB& aabb) const;      // 判断两个包围盒是否有重合

		double lowerBound(const AABB& aabb) const;   // 计算两个包围盒间的最短距离

		// 将包围盒增大到某一值，然后判定是否与另一包围盒相交
		bool enlargeAndCheck(double value, const AABB& aabb) const;  


	private:
		void set(const pnt3d min, const pnt3d max);  // 设置包围盒的最大顶点和最小顶点
		void reset();                                // 复位函数，初始化最大、最小顶点

		bool isEmpty() const;                        // 判断包围盒是否为空

	private:
		double min_[3];
		double max_[3];
	};
}
