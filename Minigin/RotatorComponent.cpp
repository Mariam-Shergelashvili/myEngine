#include "RotatorComponent.h"

#include "GameObject.h"
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

dae::RotatorComponent::RotatorComponent(Transform* ownersTransform)
	: m_speed{ 1.f }, m_radius{ 50.f }
{
	// Set pivot point
	SetPivot(ownersTransform);
	

	// Set rotation activity to true
	Component::SetNeedsUpdate(true);
}

void dae::RotatorComponent::Update([[maybe_unused]] const float deltaTime)
{
	if (Component::m_owner)
	{
		if (Component::m_owner->GetDirtyFlag())
		{
			SetPivot(Component::m_owner->GetTransform());
			Component::m_owner->SetDirtyFlag(false);
		}
	}

	if (Component::GetNeedsUpdate()) 
	{
		CalculateLocalTransform(deltaTime);
		UpdateWorldTransform();
	}
}

void dae::RotatorComponent::SetPivot(Transform* newPivot)
{
	m_pivotPoint.SetPosition(newPivot->GetX(), newPivot->GetY(), newPivot->GetZ());
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

	dae::Component::m_owner->SetPosition(x,y);
}