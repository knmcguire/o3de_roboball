
#pragma once

#include <roboball/roboballTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace roboball
{
    class roboballRequests
    {
    public:
        AZ_RTTI(roboballRequests, roboballRequestsTypeId);
        virtual ~roboballRequests() = default;
        // Put your public methods here
    };

    class roboballBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using roboballRequestBus = AZ::EBus<roboballRequests, roboballBusTraits>;
    using roboballInterface = AZ::Interface<roboballRequests>;

} // namespace roboball
