#pragma once
#include <glm/glm.hpp>
#include "Utils.h"
#include <vector>
#include "AABB.h"

struct SphereCollision
{
    SphereCollision() {}
    SphereCollision(const glm::vec3& p, float r) : center(p), radius(r) {}

    glm::vec3 center;
    float radius;

    void Fit(const  glm::vec3* points, unsigned int count)
    {
        // invalidate extents
        glm::vec3 min = { FLT_MAX, FLT_MAX , 0};
        glm::vec3 max = { FLT_MIN, FLT_MIN , 0};

        // find min and max of the points
        for (unsigned int i = 0; i < count; ++i, ++points) {
            min = Min(min, *points);
            max = Max(max, *points);
        }

        // put a circle around the min/max box
        center = (min + max) * 0.5f;
        radius = (center - max).length();
    }

    void Fit(const std::vector<glm::vec3>& points)
    {
        // invalidate extents
        glm::vec3 min = { FLT_MAX, FLT_MAX , 0};
        glm::vec3 max = { FLT_MIN, FLT_MIN , 0};

        // find min and max of the points
        for (auto& p : points) {
            min = ::Min(min, p);
            max = ::Max(max, p);
        }

        // put a circle around the min/max box
        center = (min + max) * 0.5f;
        radius = (center - max).length();
    }

    bool Overlaps(const glm::vec3& p) const
    {
        glm::vec3 toPoint = p - center;
        return glm::dot(toPoint, toPoint) <= (radius * radius); // test this
    }

    bool Overlaps(const AABB& aabb) const {
        auto diff = aabb.ClosestPoint(center) - center;

        return glm::dot(diff,diff) <= (radius * radius);
    }

    glm::vec3 ClosestPoint(const glm::vec3& p) const {
        // distance from center
        glm::vec3 toPoint = p - center;

        // if outside of radius bring it back to the radius
        if (glm::dot(toPoint,toPoint) > radius * radius) {
            toPoint = (toPoint / toPoint) * radius; // check this
        }

        return center + toPoint;
    }
};