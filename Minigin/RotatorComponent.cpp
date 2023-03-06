#include "RotatorComponent.h"

#include "GameObject.h"
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

dae::RotatorComponent::RotatorComponent(Transform* ownersTransform)
	: m_speed{ 0.3f }, m_radius{ 50 }
{
	// Set pivot point
	Transform* m_ownerTransform = ownersTransform;
	m_pivotPoint.SetPosition(m_ownerTransform->GetX(), m_ownerTransform->GetY(), m_ownerTransform->GetZ());

	// Set rotation activity to true
	Component::SetNeedsUpdate(true);
}

void dae::RotatorComponent::Update([[maybe_unused]] const float deltaTime)
{
	// Check for set activity
	if (Component::GetNeedsUpdate()) 
	{
		CalculateLocalTransform(deltaTime);
		UpdateWorldTransform();
	}
}

void dae::RotatorComponent::SetActive(const bool value = true)
{
	Component::SetNeedsUpdate(value);
}

void dae::RotatorComponent::CalculateLocalTransform(const float deltaTime)
{
	m_angle += deltaTime * m_speed;
	while (m_angle >= float(2 * M_PI)) { m_angle -= float(2 * M_PI); }

	const float x = m_radius * (cosf(m_angle));
	const float y = m_radius * (sinf(m_angle));

	m_localTransform.SetPosition(x, y, 0);
}

void dae::RotatorComponent::UpdateWorldTransform()
{
	const float x = m_pivotPoint.GetX() + m_localTransform.GetX();
	const float y = m_pivotPoint.GetY() + m_localTransform.GetY();

	dae::Component::m_owner->SetPosition(x, y);
}