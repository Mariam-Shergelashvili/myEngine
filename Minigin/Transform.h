#pragma once
#include <glm/glm.hpp>

namespace dae
{
	class Transform final
	{
	public:
		Transform();
		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(const float x, const float y, const float z);
		float GetX()const;
		float GetY()const;
		float GetZ()const;
	private:
		glm::vec3 m_position{};
	};
}