
#pragma once

#include <AzCore/Component/Component.h>

#include <roboball_1/roboball_1Bus.h>

namespace roboball_1
{
    class roboball_1SystemComponent
        : public AZ::Component
        , protected roboball_1RequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(roboball_1SystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        roboball_1SystemComponent();
        ~roboball_1SystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // roboball_1RequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
