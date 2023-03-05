#include "Component.h"

dae::Component::Component() {}
dae::Component::~Component() {}
void dae::Component::Update([[maybe_unused]] const float deltaTime)
{

}
void dae::Component::Render()const 
{
}

bool dae::Component::GetDirtyFlag() const
{ 
	return m_dirtyFlag; 
}

void dae::Component::SetDirtyFlag(const bool newvalue = true)
{ 
	m_dirtyFlag = newvalue; 
}

//void dae::Component::SetOwner(GameObject* owner)
//{
//	m_owner = owner;
//	SetDirtyFlag(); //todo : check if this line's ok
//}