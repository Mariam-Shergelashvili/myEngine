#pragma once
#include "Component.h"
#include "Transform.h"

namespace dae 
{
    class RotatorComponent : public Component 
    {
    public:
        RotatorComponent(Transform* ownersTransform);
        virtual void Update([[maybe_unused]] const float deltaTime) override;
        void SetActive(const bool value);
    private:
        float m_angle{};
        float m_radius{};
        float m_speed{};

        Transform m_localTransform{};
        Transform m_pivotPoint{};

        void CalculateLocalTransform(const float deltaTime);
        void UpdateWorldTransform();
        void SetPivot(Transform* newPivot);
    };
}
