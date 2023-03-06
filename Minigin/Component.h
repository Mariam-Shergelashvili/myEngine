#pragma once

namespace dae
{
	class GameObject;
	class Component
	{
	public:
		Component();
		virtual ~Component();
		virtual void Update([[maybe_unused]] const float deltaTime);
		virtual void Render()const;

		bool GetNeedsUpdate() const;
		void SetNeedsUpdate(const bool val);

		void SetOwner(GameObject* owner);
		GameObject* GetOwner()const;
		//void RemoveOwner();

	protected:
		bool m_needsUpdate{true};
		GameObject* m_owner{ nullptr };
	private:
	};
}