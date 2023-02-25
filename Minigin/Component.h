#pragma once

namespace dae
{
	class Component
	{
	public:
		Component();
		virtual void Update(const float deltaTime) = 0;
		virtual void Render()const;
	private:
	};
}
