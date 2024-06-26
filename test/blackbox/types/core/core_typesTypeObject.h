// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*!
 * @file core_typesTypeObject.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_RTPS_CORE_CORE_TYPES_TYPE_OBJECT_H_
#define _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_RTPS_CORE_CORE_TYPES_TYPE_OBJECT_H_


#include <fastrtps/types/TypeObject.h>
#include <map>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(core_types_SOURCE)
#define core_types_DllAPI __declspec( dllexport )
#else
#define core_types_DllAPI __declspec( dllimport )
#endif // core_types_SOURCE
#else
#define core_types_DllAPI
#endif
#else
#define core_types_DllAPI
#endif // _WIN32

using namespace eprosima::fastdds::types;

eProsima_user_DllExport void registercore_typesTypes();

namespace eprosima {
    namespace fastdds {
        namespace rtps {
            namespace core {
                namespace detail {


                    eProsima_user_DllExport const TypeIdentifier* GetEntityId_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetEntityId_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalEntityId_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteEntityId_tObject();



                    eProsima_user_DllExport const TypeIdentifier* GetProtocolVersion_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetProtocolVersion_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalProtocolVersion_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteProtocolVersion_tObject();



                    eProsima_user_DllExport const TypeIdentifier* GetVendorId_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetVendorId_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalVendorId_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteVendorId_tObject();



                    eProsima_user_DllExport const TypeIdentifier* GetGuidPrefix_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetGuidPrefix_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalGuidPrefix_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteGuidPrefix_tObject();



                    eProsima_user_DllExport const TypeIdentifier* GetGUID_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetGUID_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalGUID_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteGUID_tObject();



                    eProsima_user_DllExport const TypeIdentifier* GetSequenceNumber_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetSequenceNumber_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalSequenceNumber_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteSequenceNumber_tObject();



                    eProsima_user_DllExport const TypeIdentifier* GetCount_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetCount_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalCount_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteCount_tObject();



                    eProsima_user_DllExport const TypeIdentifier* GetTime_tIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetTime_tObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalTime_tObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteTime_tObject();

                    eProsima_user_DllExport const TypeIdentifier* GetTimestampIdentifier(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetTimestampObject(bool complete = false);
                    eProsima_user_DllExport const TypeObject* GetMinimalTimestampObject();
                    eProsima_user_DllExport const TypeObject* GetCompleteTimestampObject();

                } // namespace detail


                eProsima_user_DllExport const TypeIdentifier* GetHeaderIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetHeaderObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalHeaderObject();
                eProsima_user_DllExport const TypeObject* GetCompleteHeaderObject();



                eProsima_user_DllExport const TypeIdentifier* GetSubmessageHeaderIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetSubmessageHeaderObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalSubmessageHeaderObject();
                eProsima_user_DllExport const TypeObject* GetCompleteSubmessageHeaderObject();

                eProsima_user_DllExport const TypeIdentifier* GetSubmessageKindIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetSubmessageKindObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalSubmessageKindObject();
                eProsima_user_DllExport const TypeObject* GetCompleteSubmessageKindObject();



                eProsima_user_DllExport const TypeIdentifier* GetHeartBeatSubmessageIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetHeartBeatSubmessageObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalHeartBeatSubmessageObject();
                eProsima_user_DllExport const TypeObject* GetCompleteHeartBeatSubmessageObject();



                eProsima_user_DllExport const TypeIdentifier* GetInfoDestinationSubmessageIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetInfoDestinationSubmessageObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalInfoDestinationSubmessageObject();
                eProsima_user_DllExport const TypeObject* GetCompleteInfoDestinationSubmessageObject();



                eProsima_user_DllExport const TypeIdentifier* GetInfoSourceSubmessageIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetInfoSourceSubmessageObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalInfoSourceSubmessageObject();
                eProsima_user_DllExport const TypeObject* GetCompleteInfoSourceSubmessageObject();



                eProsima_user_DllExport const TypeIdentifier* GetInfoTimestampSubmessageIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetInfoTimestampSubmessageObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalInfoTimestampSubmessageObject();
                eProsima_user_DllExport const TypeObject* GetCompleteInfoTimestampSubmessageObject();



                eProsima_user_DllExport const TypeIdentifier* GetSubmessageIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetSubmessageObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalSubmessageObject();
                eProsima_user_DllExport const TypeObject* GetCompleteSubmessageObject();





                eProsima_user_DllExport const TypeIdentifier* GetRTPSMessageIdentifier(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetRTPSMessageObject(bool complete = false);
                eProsima_user_DllExport const TypeObject* GetMinimalRTPSMessageObject();
                eProsima_user_DllExport const TypeObject* GetCompleteRTPSMessageObject();

            } // namespace core
        } // namespace rtps
    } // namespace fastdds
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_RTPS_CORE_CORE_TYPES_TYPE_OBJECT_H_