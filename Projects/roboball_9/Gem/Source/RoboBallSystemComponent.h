
#pragma once

#include <AzCore/Component/Component.h>

#include <RoboBall/RoboBallBus.h>

namespace RoboBall
{
    class RoboBallSystemComponent
        : public AZ::Component
        , protected RoboBallRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(RoboBallSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        RoboBallSystemComponent();
        ~RoboBallSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // RoboBallRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
