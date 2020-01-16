// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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
 * @file Subscriber.hpp
 */


#ifndef _FASTDDS_SUBSCRIBER_HPP_
#define _FASTDDS_SUBSCRIBER_HPP_

#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastdds/dds/core/Entity.hpp>

#include <fastdds/dds/topic/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/SubscriberQos.hpp>
#include <fastrtps/types/TypesBase.h>

#include <dds/core/status/Status.hpp>

using eprosima::fastrtps::types::ReturnCode_t;

namespace dds {
namespace domain {
class DomainParticipant;
} // domain
namespace sub {
class Subscriber;
} // sub
} // dds

namespace eprosima {
namespace fastrtps {

class TopicAttributes;

} // namespace fastrtps

namespace fastdds {
namespace dds {

class DomainParticipant;
class SubscriberListener;
class SubscriberImpl;
class SubscriberQos;
class DataReader;
class DataReaderListener;
class DataReaderQos;
class Topic;
class TopicQos;
class TopicDescription;

/**
 * Class Subscriber, contains the public API that allows the user to control the reception of messages.
 * This class should not be instantiated directly.
 * DomainRTPSParticipant class should be used to correctly create this element.
 * @ingroup FASTDDS_MODULE
 */
class Subscriber : public DomainEntity
{
    friend class SubscriberImpl;
    friend class DomainParticipantImpl;
    friend class ::dds::sub::Subscriber;

    /**
     * Constructor from a SubscriberImpl pointer
     * @param pimpl Actual implementation of the subscriber
     */
    Subscriber(
            SubscriberImpl* pimpl,
            const ::dds::core::status::StatusMask& mask = ::dds::core::status::StatusMask::all())
        : DomainEntity(mask)
        , impl_(pimpl)
    {
    }

    Subscriber(
            const ::dds::domain::DomainParticipant& dp,
            const SubscriberQos& qos,
            SubscriberListener* listener = NULL,
            const ::dds::core::status::StatusMask& mask = ::dds::core::status::StatusMask::all());

public:

    RTPS_DllAPI virtual ~Subscriber()
    {
    }

    /**
     * Allows accessing the Subscriber Qos.
     */
    RTPS_DllAPI const SubscriberQos& get_qos() const;

    /**
     * Retrieves the Subscriber Qos.
     * @return true
     */
    RTPS_DllAPI ReturnCode_t get_qos(
            SubscriberQos& qos) const;

    /**
     * Allows modifying the Subscriber Qos.
     * The given Qos must be supported by the SubscriberQos.
     * @param qos
     * @return False if IMMUTABLE_POLICY or INCONSISTENT_POLICY occurs. True if updated.
     */
    RTPS_DllAPI ReturnCode_t set_qos(
            const SubscriberQos& qos);

    /**
     * Retrieves the attached SubscriberListener.
     */
    RTPS_DllAPI const SubscriberListener* get_listener() const;

    RTPS_DllAPI SubscriberListener* get_listener();

    /**
     * Modifies the SubscriberListener.
     * @param listener
     * @return if successfully set.
     */
    RTPS_DllAPI ReturnCode_t set_listener(
            SubscriberListener* listener,
            const ::dds::core::status::StatusMask& mask = ::dds::core::status::StatusMask::all());

    /**
     * This operation creates a DataReader. The returned DataReader will be attached and belong to the Subscriber.
     * @param topic_attr
     * @param reader_qos
     * @param listener
     * @return Pointer to the created DataReader. nullptr if failed.
     */
    RTPS_DllAPI DataReader* create_datareader(
            const TopicDescription& topic_desc,
            const DataReaderQos& reader_qos,
            DataReaderListener* listener,
            const ::dds::core::status::StatusMask& mask = ::dds::core::status::StatusMask::all());

    RTPS_DllAPI DataReader* create_datareader(
            Topic* topic,
            const DataReaderQos& qos,
            DataReaderListener* listener,
            const ::dds::core::status::StatusMask& mask = ::dds::core::status::StatusMask::all());

    /**
     * This operation deletes a DataReader that belongs to the Subscriber.
     *
     * The delete_datareader operation must be called on the same Subscriber object used to create the DataReader.
     * If delete_datareader is called on a different Subscriber, the operation will have no effect and it will
     * return false.
     * @param reader
     */
    RTPS_DllAPI ReturnCode_t delete_datareader(
            DataReader* reader);

    /**
     * This operation retrieves a previously-created DataReader belonging to the Subscriber that is attached to a
     * Topic with a matching topic_name. If no such DataReader exists, the operation will return nullptr.
     *
     * If multiple DataReaders attached to the Subscriber satisfy this condition, then the operation will return
     * one of them. It is not specified which one.
     * @param topic_name
     */
    RTPS_DllAPI DataReader* lookup_datareader(
            const std::string& topic_name) const;

    /**
     * This operation allows the application to access the DataReader objects.
     * @param readers
     * @return true
     */
    RTPS_DllAPI ReturnCode_t get_datareaders(
            std::vector<DataReader*>& readers) const;

    /**
     * This operation checks if the subscriber has DataReaders
     * @return true if the subscriber has one or several DataReaders, false in other case
     */
    RTPS_DllAPI bool has_datareaders() const;

    /* TODO
       bool begin_access();
     */

    /* TODO
       bool end_access();
     */

    /**
     * This operation invokes the operation on_data_available on the DataReaderListener objects attached to
     * contained DataReader entities.
     *
     * This operation is typically invoked from the on_data_on_readers operation in the SubscriberListener.
     * That way the SubscriberListener can delegate to the DataReaderListener objects the handling of the data.
     * @return
     */
    RTPS_DllAPI ReturnCode_t notify_datareaders() const;

    RTPS_DllAPI ReturnCode_t delete_contained_entities();

    /**
     * This operation sets a default value of the DataReader QoS policies which will be used for newly created
     * DataReader entities in the case where the QoS policies are defaulted in the create_datareader operation.
     *
     * This operation will check that the resulting policies are self consistent; if they are not, the operation
     * will have no effect and return false.
     *
     * The special value DATAREADER_QOS_DEFAULT may be passed to this operation to indicate that the default QoS
     * should be reset back to the initial values the factory would use, that is the values that would be used
     * if the set_default_datareader_qos operation had never been called.
     * @param qos
     */
    RTPS_DllAPI ReturnCode_t set_default_datareader_qos(
            const DataReaderQos& qos);

    /**
     * This operation returns the default value of the DataReader QoS, that is, the QoS policies which will be
     * used for newly created DataReader entities in the case where the QoS policies are defaulted in the
     * create_datareader operation.
     *
     * The values retrieved get_default_datareader_qos will match the set of values specified on the last successful
     * call to get_default_datareader_qos, or else, if the call was never made, the default values.
     * @return Current default DataReaderQos.
     */
    RTPS_DllAPI const DataReaderQos& get_default_datareader_qos() const;

    /**
     * This operation retrieves the default value of the DataReader QoS, that is, the QoS policies which will be
     * used for newly created DataReader entities in the case where the QoS policies are defaulted in the
     * create_datareader operation.
     *
     * The values retrieved get_default_datareader_qos will match the set of values specified on the last successful
     * call to get_default_datareader_qos, or else, if the call was never made, the default values.
     * @param qos Current default DataReaderQos.
     * @return Always true.
     */
    RTPS_DllAPI ReturnCode_t get_default_datareader_qos(
            DataReaderQos& qos) const;

    RTPS_DllAPI ReturnCode_t copy_from_topic_qos(
            DataReaderQos& reader_qos,
            const TopicQos& topic_qos) const;

    /**
     * Update the Attributes of the subscriber;
     * @param att Reference to a SubscriberAttributes object to update the parameters;
     * @return True if correctly updated, false if ANY of the updated parameters cannot be updated
     */
    RTPS_DllAPI bool set_attributes(
            const fastrtps::SubscriberAttributes& att);

    /**
     * Get the Attributes of the Subscriber.
     * @return Attributes of the Subscriber.
     */
    RTPS_DllAPI const fastrtps::SubscriberAttributes& get_attributes() const;

    /**
     * This operation returns the DomainParticipant to which the Subscriber belongs.
     */
    RTPS_DllAPI DomainParticipant& get_participant() const;

    RTPS_DllAPI ReturnCode_t enable();

private:

    SubscriberImpl* impl_;
};

} /* namespace dds */
} /* namespace fastdds */
} /* namespace eprosima */

#endif /* _FASTDDS_SUBSCRIBER_HPP_ */