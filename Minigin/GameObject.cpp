#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::UpdatePhysics([[maybe_unused]]const float fixedTimeStep){}
void dae::GameObject::Update([[maybe_unused]] const float deltaTime)
{

}

void dae::GameObject::Render() const
{
	for (auto component : m_components)
	{
		component->Render();
	}
	//const auto& pos = m_transform.GetPosition(); //original code?
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(/* todo: parameter needed*/)
{
	//influence m_components{};
}
void dae::GameObject::RemoveComponent(/* todo: parameter needed*/)
{
	//influence m_components{};
}
