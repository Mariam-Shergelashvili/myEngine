#include <stdexcept>
#include <SDL_ttf.h>
#include "ImageComponent.h"
#include "Renderer.h"
#include "Texture2D.h"

dae::ImageComponent::ImageComponent(const std::shared_ptr<Texture2D> texture)
	: m_texture(texture) 
{}


void dae::ImageComponent::Render() const
{
	if (m_texture != nullptr)
	{
		const auto& pos = m_transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
	}
}
