
#include <AzCore/Serialization/SerializeContext.h>

#include "roboball_1SystemComponent.h"

#include <roboball_1/roboball_1TypeIds.h>

namespace roboball_1
{
    AZ_COMPONENT_IMPL(roboball_1SystemComponent, "roboball_1SystemComponent",
        roboball_1SystemComponentTypeId);

    void roboball_1SystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<roboball_1SystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void roboball_1SystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("roboball_1Service"));
    }

    void roboball_1SystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("roboball_1Service"));
    }

    void roboball_1SystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void roboball_1SystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    roboball_1SystemComponent::roboball_1SystemComponent()
    {
        if (roboball_1Interface::Get() == nullptr)
        {
            roboball_1Interface::Register(this);
        }
    }

    roboball_1SystemComponent::~roboball_1SystemComponent()
    {
        if (roboball_1Interface::Get() == this)
        {
            roboball_1Interface::Unregister(this);
        }
    }

    void roboball_1SystemComponent::Init()
    {
    }

    void roboball_1SystemComponent::Activate()
    {
        roboball_1RequestBus::Handler::BusConnect();
    }

    void roboball_1SystemComponent::Deactivate()
    {
        roboball_1RequestBus::Handler::BusDisconnect();
    }
}
