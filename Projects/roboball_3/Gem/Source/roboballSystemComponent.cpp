
#include <AzCore/Serialization/SerializeContext.h>

#include "roboballSystemComponent.h"

#include <roboball/roboballTypeIds.h>

namespace roboball
{
    AZ_COMPONENT_IMPL(roboballSystemComponent, "roboballSystemComponent",
        roboballSystemComponentTypeId);

    void roboballSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<roboballSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void roboballSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("roboballService"));
    }

    void roboballSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("roboballService"));
    }

    void roboballSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void roboballSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    roboballSystemComponent::roboballSystemComponent()
    {
        if (roboballInterface::Get() == nullptr)
        {
            roboballInterface::Register(this);
        }
    }

    roboballSystemComponent::~roboballSystemComponent()
    {
        if (roboballInterface::Get() == this)
        {
            roboballInterface::Unregister(this);
        }
    }

    void roboballSystemComponent::Init()
    {
    }

    void roboballSystemComponent::Activate()
    {
        roboballRequestBus::Handler::BusConnect();
    }

    void roboballSystemComponent::Deactivate()
    {
        roboballRequestBus::Handler::BusDisconnect();
    }
}
