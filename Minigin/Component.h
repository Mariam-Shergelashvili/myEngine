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
	protected :
		Transform m_transform{};
	private:
	};
}