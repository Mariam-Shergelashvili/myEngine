#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"
#include <iostream>

dae::GameObject::GameObject()
{
	m_transform = new Transform();
	m_oldPos.SetPosition(m_transform->GetX(), m_transform->GetY(), m_transform->GetZ()); //optimize this
	m_newPos.SetPosition(m_transform->GetX(), m_transform->GetY(), m_transform->GetZ());
}
dae::GameObject::~GameObject()
{
	delete m_transform;
	m_transform = nullptr;
}
void dae::GameObject::UpdatePhysics([[maybe_unused]] const float fixedTimeStep) {}
void dae::GameObject::Update([[maybe_unused]] const float deltaTime)
{
	for (const auto& compontent : m_components)
	{
		compontent->Update(deltaTime);
	}

	if (m_newPos.GetPosition() != m_oldPos.GetPosition())
	{
		UpdateChildrenPosition();
	}
}

void dae::GameObject::UpdateChildrenPosition()
{
	const float distX = m_newPos.GetX() - m_oldPos.GetX();
	const float distY = m_newPos.GetY() - m_oldPos.GetY();

	for (auto child : m_children)
	{
		const float x = child->GetTransform()->GetX() + distX;
		const float y = child->GetTransform()->GetY() + distY;
		child->SetPosition(x,y);

		std::cout << x << " " << y << "\n";
	}

	m_oldPos.SetPosition(m_newPos.GetX(), m_newPos.GetY(), m_newPos.GetZ());
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
	m_transform->SetPosition(x, y, 0.0f);
	m_newPos.SetPosition(m_transform->GetX(), m_transform->GetY(), m_transform->GetZ());
}

void dae::GameObject::SetPositionDirty(float x, float y)
{
	SetPosition(x, y);
	SetDirtyFlag(true);
}

dae::Transform* dae::GameObject::GetTransform() const
{
	return m_transform;
}

//components
void dae::GameObject::AddComponent(const std::shared_ptr<Component> component)
{
	component->SetOwner(this);
	m_components.push_back(component);
}
void dae::GameObject::RemoveComponent(const std::shared_ptr<Component> component)
{
	auto it = std::find(m_components.begin(), m_components.end(), component);
	if (it != m_components.end()) {
		//delete component; // todo : am I supposed to delete the component? How do components work?
		m_components.erase(it);
	}
}

//hierarchy
void dae::GameObject::AddChild(GameObject* newChild)
{
	/*--CHECK--*/
	// Check for invalid child.
	if (!newChild) { return; }
	// Check for self-parenting.
	if (newChild == this) { return; }
	// Check if child is already in list.
	if (std::find(m_children.begin(), m_children.end(), newChild) != m_children.end()) { return; }
	// Check for circular dependency.
	if (HasCircularDependency(newChild, this)) { return; }

	/*--APPLY--*/
	else
	{
		m_children.push_back(newChild);
		newChild->SetParent(this);
		//todo : update position, rotation, and scale
	}
}
void dae::GameObject::RemoveChild(GameObject* oldChild)
{
	/*--CHECK--*/
	// Check for invalid child
	if (!oldChild) { return; }
	// Check for self-unparenting
	if (oldChild == this) { return; }
	// Check if child isn't in list
	auto iterator = std::find(m_children.begin(), m_children.end(), oldChild);
	if (iterator == m_children.end()) { return; }

	/*--APPLY--*/
	else
	{
		m_children.erase(iterator);
		oldChild->SetParent(nullptr);
		//todo : update position, rotation, and scale
	}
}
void dae::GameObject::SetParent(GameObject* newParent)// todo : test if this function works if I pass a nullptr
{
	/*--CHECK--*/
	// Check for self-parenting.
	if (newParent == this) { return; }
	// Check for no change.
	if (m_currentParent == newParent) { return; } //current parent equal to new parent?
	// Check for circular dependency.
	if (newParent != nullptr && HasCircularDependency(this, newParent)) { return; }

	/*--APPLY--*/
	else
	{
		// Remove this from old parent's list of children.
		if (m_currentParent != nullptr) { m_currentParent->RemoveChild(this); }
		// Set new parent.
		m_currentParent = newParent;
		// Add THIS to new parent's list of children.
		if (m_currentParent != nullptr) { m_currentParent->AddChild(this); }
	}
}

bool dae::GameObject::HasCircularDependency(GameObject* child, GameObject* parent) const {

	// Going up parent chain until root ...
	while (parent != nullptr) {
		// Check for circular dependency through being the child of one's parent
		if (child == parent) {
			return true;
		}
		// Move up to next parent
		parent = parent->GetParent();
	}
	// No circular dependency found.
	return false;
}

dae::GameObject* dae::GameObject::GetParent() const {
	return m_currentParent;
}
const std::vector< dae::GameObject*>& dae::GameObject::GetChildren() const {
	return m_children;
}

bool dae::GameObject::GetDirtyFlag() const
{
	return m_dirtyFlag;
}
void dae::GameObject::SetDirtyFlag(const bool newvalue = true)
{
	m_dirtyFlag = newvalue;
}
