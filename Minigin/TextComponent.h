#pragma once
#include <string>
#include <memory>
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent : public Component
	{
	public:
		TextComponent(const std::string& text, std::shared_ptr<Font> font);
		virtual ~TextComponent() = default;

		void Update([[maybe_unused]] const float deltaTime) override;
		virtual void Render() const override;

		void SetText(const std::string& text);
	protected:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}