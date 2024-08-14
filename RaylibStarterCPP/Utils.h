#pragma once
#include <glm/glm.hpp>

// Define these in a utility header, if you haven't already
constexpr float Min(float a, float b) { return a < b ? a : b; }
constexpr float Max(float a, float b) { return a > b ? a : b; }

glm::vec3 Min(const glm::vec3& a, const glm::vec3& b)
{
	return { Min(a.x,b.x), Min(a.y, b.y), Min(a.z, b.z) };
}

glm::vec3 Max(const glm::vec3& a, const glm::vec3& b)
{
	return { Max(a.x,b.x), Max(a.y, b.y) , Max(a.z, b.z) };
}

constexpr float Clamp(float t, float a, float b)
{
	return Max(a, Min(b, t));
}

glm::vec3 Clamp(const glm::vec3& t, const glm::vec3& a, const glm::vec3& b)
{
	return Max(a, Min(b, t));
}