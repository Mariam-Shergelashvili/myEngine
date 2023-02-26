#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::UpdatePhysics([[maybe_unused]] const float fixedTimeStep) {}
void dae::GameObject::Update([[maybe_unused]] const float deltaTime)
{
	for (const auto& compontent : m_components)
	{
		compontent->Update();
	}
}

void dae::GameObject::Render() const
{
	for (const auto& compontent : m_components)
	{
		compontent->Render();
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(std::shared_ptr<Component> component)
{
	m_components.push_back(component);
}
void dae::GameObject::RemoveComponent(std::shared_ptr<Component> component)
{
	// Find the iterator pointing to the element to remove
	auto it = std::find(m_components.begin(), m_components.end(), component);
	// If the element was found, delete it and remove it from the vector
	/* Why checking for vector.end() ? ...
	if the element HAS NOT been found, it'll return vector.end(), which is one element PAST the last element of a vector.*/
	if (it != m_components.end()) {
		//delete component; // todo : am I supposed to delete the component? How do components work?
		m_components.erase(it);
	}
}
