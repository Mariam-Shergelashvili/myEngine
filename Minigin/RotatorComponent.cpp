#include "RotatorComponent.h"

dae::RotatorComponent::RotatorComponent()
{
	// Set rotation activity to true
	Component::SetDirtyFlag(true); 
}

void dae::RotatorComponent::Update([[maybe_unused]] const float deltaTime)
{
	// Check for set activity
	if (Component::GetDirtyFlag()) {

		//Calculate location
		//transform->Rotate(glm::vec3(0, 1, 0), speed * deltaTime);
	}
}

void dae::RotatorComponent::SetActive(const bool value = true)
{
	Component::SetDirtyFlag(value);
}