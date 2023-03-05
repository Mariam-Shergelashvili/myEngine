#pragma once
#include <string>
#include <memory>
#include "Component.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent : public Component
	{
	public:
		TextComponent(const std::string& text, std::shared_ptr<Font> font, Transform* ownersTransform);
		virtual ~TextComponent() = default;

		void Update([[maybe_unused]] const float deltaTime) override;
		virtual void Render() const override;

		void SetText(const std::string& text);
	protected:
		std::string m_text;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
		Transform* m_ownersTransform;
	};
}