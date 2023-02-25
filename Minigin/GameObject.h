#pragma once
#include <memory>
#include "Transform.h"
#include <vector>

namespace dae
{
	class Component;

	// todo: this should become final.
	class GameObject
	{
	public:
		void UpdatePhysics([[maybe_unused]] const float fixedTimeStep);
		virtual void Update([[maybe_unused]] const float deltaTime);
		virtual void Render() const;

		void SetPosition(float x, float y);
		void AddComponent(Component* componentPtr);
		void RemoveComponent(Component* componentPtr);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		std::vector<Component*> m_componentPtrs{};
	};
}