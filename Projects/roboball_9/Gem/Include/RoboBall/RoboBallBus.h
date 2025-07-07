
#pragma once

#include <RoboBall/RoboBallTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RoboBall
{
    class RoboBallRequests
    {
    public:
        AZ_RTTI(RoboBallRequests, RoboBallRequestsTypeId);
        virtual ~RoboBallRequests() = default;
        // Put your public methods here
    };

    class RoboBallBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RoboBallRequestBus = AZ::EBus<RoboBallRequests, RoboBallBusTraits>;
    using RoboBallInterface = AZ::Interface<RoboBallRequests>;

} // namespace RoboBall
