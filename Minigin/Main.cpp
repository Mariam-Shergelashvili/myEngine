#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "Component.h"
#include "TextComponent.h"
#include "ImageComponent.h"
#include "RotatorComponent.h"
#include "FPS.h"
#include "Texture2D.h"

void loadDemoScene()
{
	/*SCENE*/
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	//containing...


	/*OBJECT*/
	auto bg = std::make_shared<dae::GameObject>();
	scene.Add(bg);

	/*COMPONENT*/
	std::shared_ptr<dae::Texture2D> texture1 = dae::ResourceManager::GetInstance().LoadTexture("background.tga");
	std::shared_ptr<dae::ImageComponent> bgImage = std::make_shared<dae::ImageComponent>(texture1, bg->GetTransform());
	bg->AddComponent(bgImage);


	/*OBJECT*/
	auto logo = std::make_shared<dae::GameObject>();
	scene.Add(logo);

	/*COMPONENT*/
	std::shared_ptr<dae::Texture2D> texture2 = dae::ResourceManager::GetInstance().LoadTexture("logo.tga");
	std::shared_ptr<dae::ImageComponent> logoImage = std::make_shared<dae::ImageComponent>(texture2, logo->GetTransform());
	logo->AddComponent(logoImage);
	logo->SetPosition(216, 180);


	/*OBJECT*/
	auto textObj = std::make_shared<dae::GameObject>();
	scene.Add(textObj);

	/*COMPONENT*/
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	std::shared_ptr<dae::TextComponent> textComp = std::make_shared<dae::TextComponent>("Programming 4 Assignment", font, textObj->GetTransform());
	textObj->AddComponent(textComp);
	

	/*OBJECT*/
	auto fpsObj = std::make_shared<dae::GameObject>();
	scene.Add(fpsObj);

	/*COMPONENT*/
	std::shared_ptr<dae::FPS> fps = std::make_shared<dae::FPS>(font, fpsObj->GetTransform());
	fpsObj->AddComponent(fps);
	fpsObj->SetPosition(0, 300); //todo: fix magic number


	/*OBJECT*/
	auto parent = std::make_shared<dae::GameObject>();
	scene.Add(parent);

	/*COMPONENT*/
	std::shared_ptr<dae::Texture2D> texture3 = dae::ResourceManager::GetInstance().LoadTexture("evilface.tga");
	std::shared_ptr<dae::ImageComponent> parentImage = std::make_shared<dae::ImageComponent>(texture3, parent->GetTransform());

	parent->SetPosition(300, 300);
	std::shared_ptr<dae::RotatorComponent> parentRot = std::make_shared<dae::RotatorComponent>(parent->GetTransform());
	parent->AddComponent(parentImage);
	parent->AddComponent(parentRot);
}

void load()
{	
	loadDemoScene();
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}