#pragma once
#include <glm/glm.hpp>
#include "SphereCollision.h"
struct Plane
{
    enum ePlaneResult : int {
        FRONT = 1,
        BACK = -1,
        INTERSECTS = 0
    };

	Plane() {}
	Plane(float x, float y, float d) : N(x, y, 0), d(d) {}
	Plane(const glm::vec3& n, float d) : N(n), d(d) {}
    Plane(const glm::vec3& p1, const glm::vec3& p2)
    {
        // calculate normalised vector from p0 to p1
        glm::vec3 v = p2 - p1;
        v = glm::normalize(v);

        // set normal perpendicular to the vector
        N.x = -v.y;
        N.y = v.x;

        // calculate d
        d = glm::dot(-p1, N);
    }

    float DistanceTo(const glm::vec3& p) const
    {
        return glm::dot(p, N) + d;
    }
    glm::vec3 ClosestPoint(const glm::vec3& p) const
    {
        return p - N * DistanceTo(p);
    }
    ePlaneResult TestSide(const glm::vec3& p) const {
        
        float t = glm::dot(p,N) + d;

        if (t < 0)
            return ePlaneResult::BACK;
        else if (t > 0)
            return ePlaneResult::FRONT;

        return ePlaneResult::INTERSECTS;
    }
    ePlaneResult TestSide(const SphereCollision& sphere) const {
        //float t = distanceTo(sphere.center);
        float t = glm::dot(sphere.center, N) + d;

        if (t > sphere.radius)
            return ePlaneResult::FRONT;
        else if (t < -sphere.radius)
            return ePlaneResult::BACK;

        return ePlaneResult::INTERSECTS;
    }
    ePlaneResult TestSide(const AABB& aabb) const {

        // tag if we find a corner on each side
        bool side[2] = { false, false };

        // compare each corner
        for (auto c : aabb.Corners()) {
            auto result = TestSide(c);
            if (result == ePlaneResult::FRONT)
                side[0] = true;
            else if (result == ePlaneResult::BACK)
                side[1] = true;
        }

        // if front but not back
        if (side[0] && !side[1])
            return ePlaneResult::FRONT;
        // if back but not front
        else if (!side[0] && side[1])
            return ePlaneResult::BACK;
        // else overlapping
        return ePlaneResult::INTERSECTS;
    }

	glm::vec3 N;
	float d;

};