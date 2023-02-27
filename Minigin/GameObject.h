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
		void UpdatePhysics([[maybe_unused]] const float fixedTimeStep);
		virtual void Update([[maybe_unused]] const float deltaTime);
		virtual void Render() const;

		void SetPosition(float x, float y);
		void AddComponent(std::shared_ptr<Component> component);
		void RemoveComponent(std::shared_ptr<Component> component);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		std::vector < std::shared_ptr<Component>> m_components{};
	};
}