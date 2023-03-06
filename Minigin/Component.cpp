#include "Component.h"

dae::Component::Component() {}
dae::Component::~Component() {}
void dae::Component::Update([[maybe_unused]] const float deltaTime)
{

}
void dae::Component::Render()const
{
}

bool dae::Component::GetNeedsUpdate() const
{
	return m_needsUpdate;
}
void dae::Component::SetNeedsUpdate(const bool val)
{
	m_needsUpdate = val;
}

void dae::Component::SetOwner(GameObject* owner)
{
	m_owner = owner;
}

dae::GameObject* dae::Component::GetOwner() const
{
	return m_owner;
}