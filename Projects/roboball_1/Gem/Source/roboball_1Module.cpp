
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "roboball_1SystemComponent.h"

#include <roboball_1/roboball_1TypeIds.h>

namespace roboball_1
{
    class roboball_1Module
        : public AZ::Module
    {
    public:
        AZ_RTTI(roboball_1Module, roboball_1ModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(roboball_1Module, AZ::SystemAllocator);

        roboball_1Module()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                roboball_1SystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<roboball_1SystemComponent>(),
            };
        }
    };
}// namespace roboball_1

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), roboball_1::roboball_1Module)
#else
AZ_DECLARE_MODULE_CLASS(Gem_roboball_1, roboball_1::roboball_1Module)
#endif
