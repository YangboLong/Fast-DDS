// Copyright 2020 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file TypeLookupManager.hpp
 *
 */

#ifndef FASTDDS_FASTDDS_BUILTIN_TYPE_LOOKUP_SERVICE__TYPELOOKUPMANAGER_HPP
#define FASTDDS_FASTDDS_BUILTIN_TYPE_LOOKUP_SERVICE__TYPELOOKUPMANAGER_HPP

#include <vector>

#include <gmock/gmock.h>

#include <fastdds/dds/xtypes/type_representation/TypeObject.hpp>

#include <fastdds/builtin/type_lookup_service/detail/TypeLookupTypes.hpp>

namespace eprosima {

namespace fastdds {
namespace rtps {

class BuiltinProtocols;
class ReaderHistory;
class RTPSParticipantImpl;
class StatefulReader;
class StatefulWriter;
class ParticipantProxyData;
class WriterHistory;

} // namespace rtps

namespace dds {
namespace builtin {

extern const fastdds::rtps::SampleIdentity INVALID_SAMPLE_IDENTITY;

/**
 * Class TypeLookupManager that implements the TypeLookup Service described in the DDS-XTYPES 1.2 specification.
 * @ingroup XTYPES
 */
class TypeLookupManager
{

public:

    /**
     * Constructor
     */
    TypeLookupManager()
    {
    }

    virtual ~TypeLookupManager()
    {
    }

    MOCK_CONST_METHOD1(get_type_dependencies, fastdds::rtps::SampleIdentity(
                const fastdds::dds::xtypes::TypeIdentifierSeq&));

    MOCK_CONST_METHOD1(get_types, fastdds::rtps::SampleIdentity(
                const fastdds::dds::xtypes::TypeIdentifierSeq&));

    void remove_remote_endpoints(
            fastdds::rtps::ParticipantProxyData* pdata)
    {
        static_cast<void>(pdata);
    }

};

} // namespace builtin
} // namespace dds
} // namespace fastdds
} // namespace eprosima
#endif // FASTDDS_FASTDDS_BUILTIN_TYPE_LOOKUP_SERVICE__TYPELOOKUPMANAGER_HPP
