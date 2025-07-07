
#include <AzCore/Serialization/SerializeContext.h>

#include "RoboBallSystemComponent.h"

#include <RoboBall/RoboBallTypeIds.h>

namespace RoboBall
{
    AZ_COMPONENT_IMPL(RoboBallSystemComponent, "RoboBallSystemComponent",
        RoboBallSystemComponentTypeId);

    void RoboBallSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<RoboBallSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void RoboBallSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("RoboBallService"));
    }

    void RoboBallSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("RoboBallService"));
    }

    void RoboBallSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void RoboBallSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    RoboBallSystemComponent::RoboBallSystemComponent()
    {
        if (RoboBallInterface::Get() == nullptr)
        {
            RoboBallInterface::Register(this);
        }
    }

    RoboBallSystemComponent::~RoboBallSystemComponent()
    {
        if (RoboBallInterface::Get() == this)
        {
            RoboBallInterface::Unregister(this);
        }
    }

    void RoboBallSystemComponent::Init()
    {
    }

    void RoboBallSystemComponent::Activate()
    {
        RoboBallRequestBus::Handler::BusConnect();
    }

    void RoboBallSystemComponent::Deactivate()
    {
        RoboBallRequestBus::Handler::BusDisconnect();
    }
}
