#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::UpdatePhysics([[maybe_unused]] const float fixedTimeStep) {}
void dae::GameObject::Update([[maybe_unused]] const float deltaTime){}

void dae::GameObject::Render() const
{
	for (auto component : m_componentPtrs)
	{
		component->Render();
	}
	//const auto& pos = m_transform.GetPosition(); //original code?
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(Component* componentPtr)
{
	m_componentPtrs.push_back(componentPtr);
}
void dae::GameObject::RemoveComponent(Component* componentPtr)
{
	// Find the iterator pointing to the element to remove
	auto it = std::find(m_componentPtrs.begin(), m_componentPtrs.end(), componentPtr);
	// If the element was found, delete it and remove it from the vector
	/* Why checking for vector.end() ? ...
	if the element HAS NOT been found, it'll return vector.end(), which is one element PAST the last element of a vector.*/
	if (it != m_componentPtrs.end()) {
		delete componentPtr; // todo : am I supposed to delete the component? How do components work?
		m_componentPtrs.erase(it);
	}
}
