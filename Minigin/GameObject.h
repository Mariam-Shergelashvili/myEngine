#pragma once
#include <memory>
#include "Transform.h"
#include <vector>

namespace dae
{
	class Component;

	class GameObject final
	{
	public:
		GameObject() = default;
		virtual ~GameObject();

		void UpdatePhysics([[maybe_unused]] const float fixedTimeStep);
		virtual void Update([[maybe_unused]] const float deltaTime);
		virtual void Render() const;

		void SetPosition(float x, float y);
		void AddComponent(const std::shared_ptr<Component> component);
		void RemoveComponent(const std::shared_ptr<Component> component); //todo : get feedback on this

		void AddChild(GameObject* newChild);
		void RemoveChild(GameObject* oldChild);
		void SetParent(GameObject* newParent);

	private:

		Transform m_transform{};
		std::vector < std::shared_ptr<Component>> m_components{};

		//PARENT/CHILD
		std::vector <GameObject*> m_children;
		GameObject* m_currentParent{nullptr};
	};
}