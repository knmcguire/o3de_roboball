
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "RoboBallSystemComponent.h"

#include <RoboBall/RoboBallTypeIds.h>

namespace RoboBall
{
    class RoboBallModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(RoboBallModule, RoboBallModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(RoboBallModule, AZ::SystemAllocator);

        RoboBallModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                RoboBallSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<RoboBallSystemComponent>(),
            };
        }
    };
}// namespace RoboBall

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), RoboBall::RoboBallModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_RoboBall, RoboBall::RoboBallModule)
#endif
