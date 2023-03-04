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
		compontent->Update(deltaTime);
	}
}
void dae::GameObject::Render() const
{
	for (const auto& compontent : m_components)
	{
		compontent->Render();
	}
}

//location
void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

//components
void dae::GameObject::AddComponent(const std::shared_ptr<Component> component)
{
	m_components.push_back(component);
}
void dae::GameObject::RemoveComponent(const std::shared_ptr<Component> component)
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

//hierarchy
void dae::GameObject::AddChild(GameObject* newChild)
{
	/*--CHECK--*/
	if (!newChild) { return; } // cannot add nullptr as child
	if (newChild == this) { return; } //cannot parent to itself.
	auto iterator = std::find(m_children.begin(), m_children.end(), newChild); // [1/2] check if new child is already in list
	if (iterator != m_children.end()) { return; } // [2/2] if so, return.


	/*--APPLY--*/
	else
	{
		m_children.push_back(newChild);//add child to my vector of kids
		newChild->SetParent(this);
		//todo : update position, rotation, and scale
	}
}

void dae::GameObject::RemoveChild(GameObject* oldChild)
{
	/*--CHECK--*/
	if (!oldChild) { return; } // cannot remove nullptr as child
	/*TEMP*///if (oldChild == this) { return; }  //cannot unparent from itself.
	auto iterator = std::find(m_children.begin(), m_children.end(), oldChild); // [1/2] check if child is in list
	if (iterator == m_children.end()) { return; } // [2/2] if not, return.


	/*--APPLY--*/
	else
	{
		m_children.erase(iterator); //delete from list of children
		oldChild->SetParent(nullptr); //remove myself as parent of that kid
		//todo : update position, rotation, and scale
	}
}

void dae::GameObject::SetParent(GameObject* newParent)// todo : test if this function works if I pass a nullptr
{
	/*--CHECK--*/
	if (newParent == this) { return; } //cannot parent to itself.
	if (m_currentParent == newParent) { return; } //current parent equal to new parent?

		/*--APPLY--*/
	else
	{
		//already have a parent? -> remove THIS from its list of children
		if (m_currentParent != nullptr) { m_currentParent->RemoveChild(this); }
		//assign (new) parent to THIS
		m_currentParent = newParent;
		//new parent isn't a nullptr? -> add THIS to its list of children
		if (m_currentParent != nullptr) { m_currentParent->AddChild(this); }
	}
}