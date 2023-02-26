#include "Component.h"

dae::Component::Component() {}
dae::Component::~Component() {}
void dae::Component::Update(){}
void dae::Component::Render()const 
{
}

void dae::Component::SetPosition(const float x, const float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}