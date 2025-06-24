
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "roboballSystemComponent.h"

#include <roboball/roboballTypeIds.h>

namespace roboball
{
    class roboballModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(roboballModule, roboballModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(roboballModule, AZ::SystemAllocator);

        roboballModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                roboballSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<roboballSystemComponent>(),
            };
        }
    };
}// namespace roboball

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), roboball::roboballModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_roboball, roboball::roboballModule)
#endif
