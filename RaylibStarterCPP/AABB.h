#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Utils.h"

struct AABB
{
	AABB() {}
	AABB(const glm::vec3& min, const glm::vec3& max) : min(min), max(max) {}

	glm::vec3 min, max;

	glm::vec3 Center() const
	{
		return (min + max) * 0.5f;
	}

	glm::vec3 Extents() const
	{
		return { abs(max.x - min.x) * 0.5f,
				 abs(max.y - min.y) * 0.5f , 
				 0};
	}

	std::vector<glm::vec3> Corners() const
	{
		std::vector<glm::vec3> corners(4);
		corners[0] = min;
		corners[1] = { min.x, max.y , 0};
		corners[2] = max;
		corners[3] = { max.x, min.y , 0};
		return corners;
	}

	void Fit(const glm::vec3* points, unsigned int count)
	{
		// invalidate the extents
		min = { FLT_MAX, FLT_MAX , 0};
		max = { -FLT_MAX,-FLT_MAX, 0 }; // NB These have -ve signs!

		// find min and max of the points
		for (unsigned int i = 0; i < count; ++i, ++points) {
			min = Min(min, points[i]);
			max = Max(max, points[i]);
		}
	}

	void Fit(const std::vector<glm::vec3>& points)
	{
		// invalidate the extents
		min = { FLT_MAX, FLT_MAX , 0};
		max = { -FLT_MAX, -FLT_MAX , 0};// NB These have -ve signs!
		// find min and max of the points
		for (auto& p : points) {
			min = Min(min, p);
			max = Max(max, p);
		}
	}

	bool Overlaps(const glm::vec3& p) const
	{
		// test for not overlapped as it exits faster
		return !(p.x < min.x || p.y < min.y ||
			p.x > max.x || p.y > max.y);
	}
	bool Overlaps(const AABB& other) const
	{
		// test for not overlapped as it exits faster
		return !(max.x < other.min.x || max.y < other.min.y ||
			min.x > other.max.x || min.y > other.max.y);
	}

	glm::vec3 ClosestPoint(const glm::vec3& p) const
	{
		return Clamp(p, min, max);
	}

};