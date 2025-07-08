
#pragma once

#include <AzCore/Component/Component.h>

#include <roboball/roboballBus.h>

namespace roboball
{
    class roboballSystemComponent
        : public AZ::Component
        , protected roboballRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(roboballSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        roboballSystemComponent();
        ~roboballSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // roboballRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
