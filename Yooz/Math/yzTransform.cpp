#include <Math/yzTransform.hpp>

namespace yz
{
Transform& Transform::Translate(const float x, const float y)
{
	m[2] += x * m[0] + y * m[1];
	m[5] += x * m[3] + y * m[4];
	return *this;
}

Transform& Transform::Scale(const float x, const float y)
{
	m[0] *= x;
	m[1] *= y;
	m[3] *= x;
	m[4] *= y;
	return *this;
}

Transform& Transform::Shear(const float x, const float y)
{
	float a = m[0];
	float b = m[1];
	float d = m[3];
	float e = m[4];

	m[0] += b * y;
	m[1] += a * x;
	m[3] += e * y;
	m[4] += d * x;
	return *this;
}

Transform& Transform::Rotate(const float angle)
{
	float c = std::cos(angle);
	float s = std::sin(angle);
	float a = m[0];
	float b = m[1];
	float d = m[3];
	float e = m[4];

	m[0] = +a * c + b * s;
	m[1] = -a * s + b * c;
	m[3] = +d * c + e * s;
	m[4] = -d * s + e * c;
	return *this;
}

Transform& Transform::Project(const float width, const float height)
{
	float tw = 2.0f / width;
	float th = -2.0f / height;

	m[2] += (m[1] - m[0]);
	m[5] += (m[4] - m[3]);
	m[0] *= tw;
	m[1] *= th;
	m[3] *= tw;
	m[4] *= th;
	return *this;
}

Transform& Transform::operator*=(const Transform& r)
{
	*this = Transform(
	        m[0] * r.m[0] + m[1] * r.m[3], m[0] * r.m[1] + m[1] * r.m[4],
	        m[0] * r.m[2] + m[1] * r.m[5] + m[2], m[3] * r.m[0] + m[4] * r.m[3],
	        m[3] * r.m[1] + m[4] * r.m[4],
	        m[3] * r.m[2] + m[4] * r.m[5] + m[5]);
	return *this;
}

Transform Transform::operator*(const Transform& r) const
{
	return Transform(
	        m[0] * r.m[0] + m[1] * r.m[3], m[0] * r.m[1] + m[1] * r.m[4],
	        m[0] * r.m[2] + m[1] * r.m[5] + m[2], m[3] * r.m[0] + m[4] * r.m[3],
	        m[3] * r.m[1] + m[4] * r.m[4],
	        m[3] * r.m[2] + m[4] * r.m[5] + m[5]);
}

}  // namespace yz
