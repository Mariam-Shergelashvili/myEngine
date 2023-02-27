#include "FPSCounter.h"
#include "TextComponent.h"
#include <string>
#include <iostream>

dae::FPSCounter::FPSCounter(std::shared_ptr<Font> font)
	:m_font(font)
{
	m_text = std::make_shared<dae::TextComponent>("000000000000000000000000000000", m_font);
}

void dae::FPSCounter::Update(const float deltaTime)
{
	m_fps = 1.f / deltaTime;
	std::string text = "FPS : " + std::to_string(m_fps);
	//m_text->SetText(text);
}

void dae::FPSCounter::Render() const
{
	m_text->Render();
}