#pragma once
#include "ResourceManager.h"
#include "Component.h"

namespace dae
{
	class Font;
	class TextComponent;
	class GameObject;
	class FPSCounter final : public Component
	{
	public:
		FPSCounter(std::shared_ptr<Font> font);

		void Update(const float deltaTime)override;
		void Render() const override;
	private:
		float m_fps{};
		std::shared_ptr<dae::TextComponent> m_text;
		std::shared_ptr<Font> m_font;
	};
}