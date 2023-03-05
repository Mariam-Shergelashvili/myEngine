#pragma once
#include "Component.h"

namespace dae 
{
    class RotatorComponent : public Component 
    {
    public:
        RotatorComponent();
        virtual void Update([[maybe_unused]] const float deltaTime) override;
        void SetActive(const bool value);
    private:
    };
}
