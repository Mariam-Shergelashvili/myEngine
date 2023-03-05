#include <stdexcept>
#include <SDL_ttf.h>
#include "FPS.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"

dae::FPS::FPS(std::shared_ptr<Font> font, Transform* ownersTransform)
	: TextComponent{ "",font, ownersTransform}
{

}
void dae::FPS::Update(const float deltaTime)
{
	const int fps = (int) (1.f / (deltaTime));
	SetText("FPS : " + std::to_string(fps));

	if (Component::GetDirtyFlag())
	{
		const SDL_Color color = { 255,0,0 };
		const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_textTexture = std::make_shared<Texture2D>(texture);
		Component::SetDirtyFlag(false);
	}


}