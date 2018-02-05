#pragma once

#include <cstring>

#include "objects.h"

namespace gmath {

	/*-------------------------------------------------------------------
	 * ����ƽ�еĳ������Χ��
	 *-----------------------------------------------------------------*/
	class AABB {
	public:
		AABB();                                     // Ĭ�Ϲ��캯��
		AABB(const pnt3d min, const pnt3d max);     // �Զ��幹�캯��

		~AABB();  // ��������

		void get_min(pnt3d min) const { memcpy(min, min_, sizeof(min_)); }
		void get_max(pnt3d max) const { memcpy(max, max_, sizeof(max_)); }

		void addPoint(const pnt3d point);           // ���Χ������ӵ�
		// TODO: ���Χ�������Բ����Բ���㼯��

		bool intersect(const AABB& aabb) const;      // �ж�������Χ���Ƿ����غ�

		double lowerBound(const AABB& aabb) const;   // ����������Χ�м����̾���

		// ����Χ������ĳһֵ��Ȼ���ж��Ƿ�����һ��Χ���ཻ
		bool enlargeAndCheck(double value, const AABB& aabb) const;  


	private:
		void set(const pnt3d min, const pnt3d max);  // ���ð�Χ�е���󶥵����С����
		void reset();                                // ��λ��������ʼ�������С����

		bool isEmpty() const;                        // �жϰ�Χ���Ƿ�Ϊ��

	private:
		double min_[3];
		double max_[3];
	};
}
