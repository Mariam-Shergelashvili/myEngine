#pragma once
#include <string>
#include <memory>
#include "Renderer.h"
#include "Component.h"
#include "Transform.h"

namespace dae
{
	class Texture2D;
	class ImageComponent final : public Component
	{
	public:
		ImageComponent(std::shared_ptr<Texture2D> texture, Transform* ownersTransform);
		virtual ~ImageComponent() = default;

		void Render() const;
	private:
		std::shared_ptr<Texture2D> m_texture;
		Transform* m_ownersTransform;
	};
}