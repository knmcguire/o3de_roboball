
#pragma once

#include <roboball_1/roboball_1TypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace roboball_1
{
    class roboball_1Requests
    {
    public:
        AZ_RTTI(roboball_1Requests, roboball_1RequestsTypeId);
        virtual ~roboball_1Requests() = default;
        // Put your public methods here
    };

    class roboball_1BusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using roboball_1RequestBus = AZ::EBus<roboball_1Requests, roboball_1BusTraits>;
    using roboball_1Interface = AZ::Interface<roboball_1Requests>;

} // namespace roboball_1
