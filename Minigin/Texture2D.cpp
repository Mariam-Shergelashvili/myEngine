#include <SDL.h>
#include "Texture2D.h"

dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_texture);
}

glm::ivec2 dae::Texture2D::GetSize() const
{
	SDL_Rect dst;
	SDL_QueryTexture(GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	return { dst.w,dst.h };
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_texture;
}

dae::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_texture = texture;
}

//+ void dae::GameObject::Render() const
//{
//	const auto& pos = m_transform.GetPosition();
//	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
//}
//
//void dae::GameObject::SetTexture(const std::string& filename)
//{
//	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
//}
