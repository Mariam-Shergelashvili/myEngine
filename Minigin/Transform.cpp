#include "Transform.h"

dae::Transform::Transform()
{
	SetPosition(0, 0, 0);
}

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

float dae::Transform::GetX()const 
{
	return m_position.x;
}
float dae::Transform::GetY()const
{
	return m_position.y;
}
float dae::Transform::GetZ()const
{
	return m_position.z;
}