#pragma once
#include "TextComponent.h"

namespace dae
{
	class TextComponent;
	class FPS : public TextComponent
	{
	public:
		FPS(std::shared_ptr<Font> font);
		void Update(const float deltaTime) override;
	private:
		float m_elapsedTime{};
	};
}