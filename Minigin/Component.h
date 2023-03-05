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

		bool GetDirtyFlag() const;
		void SetDirtyFlag(const bool newvalue);

		void SetOwner(GameObject* owner); //make it so that ONLY gameobject can call this
	protected:
       bool m_dirtyFlag{ true };
	   /*GameObject* m_owner{ nullptr };*/
	private:
	};
}