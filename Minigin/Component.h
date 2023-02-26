#pragma once
#include "Transform.h"


namespace dae
{
	class Component
	{
	public:
		Component();
		virtual ~Component();
		virtual void Update();
		virtual void Render()const;

		void SetPosition(float x, float y);
	protected:

		Transform m_transform{};
	private:
	};
}