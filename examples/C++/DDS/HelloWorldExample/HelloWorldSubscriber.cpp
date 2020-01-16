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

/**
 * @file HelloWorldSubscriber.cpp
 *
 */

#include "HelloWorldSubscriber.h"
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/topic/DataReader.hpp>
#include <fastdds/dds/topic/qos/DataReaderQos.hpp>
#include <fastdds/dds/topic/Topic.hpp>

#include <fastdds/dds/core/conditions/WaitSet.hpp>
#include <fastdds/dds/core/conditions/StatusCondition.hpp>

using namespace eprosima::fastdds::dds;

HelloWorldSubscriber::HelloWorldSubscriber()
    : participant_(nullptr)
    , subscriber_(nullptr)
    , type_(new HelloWorldPubSubType())
{
}

bool HelloWorldSubscriber::init(
        int domain_id)
{
    eprosima::fastrtps::ParticipantAttributes participant_att;
    participant_att.rtps.builtin.domainId = domain_id;
    participant_att.rtps.setName("Participant_sub");
    participant_ = DomainParticipantFactory::get_instance()->create_participant(participant_att, &listener_);

    if (participant_ == nullptr)
    {
        return false;
    }

    //REGISTER THE TYPE
    type_.register_type(participant_, type_.get_type_name());

    //CREATE THE SUBSCRIBER
    eprosima::fastrtps::SubscriberAttributes sub_att;
    subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, sub_att, nullptr);

    if (subscriber_ == nullptr)
    {
        return false;
    }

    // CREATE THE READER
    DataReaderQos rqos;
    rqos.reliability.kind = RELIABLE_RELIABILITY_QOS;
    //Topic topic(participant_, "HelloWorldTopic", "HelloWorld", TopicQos()); //PSM
    TopicDescription topic_desc(participant_, "HelloWorldTopic", "HelloWorld"); //PIM
    reader_ = subscriber_->create_datareader(topic_desc, rqos, &listener_);

    if (reader_ == nullptr)
    {
        return false;
    }

    return true;
}

HelloWorldSubscriber::~HelloWorldSubscriber()
{
    DomainParticipantFactory::get_instance()->delete_participant(participant_);
}

void HelloWorldSubscriber::SubListener::on_subscription_matched(
        eprosima::fastdds::dds::DataReader*,
        const eprosima::fastdds::dds::SubscriptionMatchedStatus& info)
{
    if (info.current_count_change == 1)
    {
        matched_ = info.total_count;
        std::cout << "Subscriber matched." << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        matched_ = info.total_count;
        std::cout << "Subscriber unmatched." << std::endl;
    }
    else
    {
        std::cout << info.current_count_change
                  << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
    }
}

void HelloWorldSubscriber::SubListener::on_inconsistent_topic(
        Topic* topic,
        const InconsistentTopicStatus& status)
{
    if (status.total_count_change == 1)
    {
        std::cout << "The discovered topic is inconsistent with topic " << topic->get_instance_handle() <<
            std::endl;
    }
}

void HelloWorldSubscriber::SubListener::on_requested_incompatible_qos(
        DataReader*,
        const RequestedIncompatibleQosStatus& status)
{
    QosPolicy qos;
    std::cout << "The Requested Qos is incompatible with the Offered one." << std::endl;
    std::cout << "The Qos causing this incompatibility is " << qos.search_qos_by_id(
        status.last_policy_id) << "." << std::endl;
}

void HelloWorldSubscriber::SubListener::on_sample_rejected(
        DataReader*,
        const SampleRejectedStatus& status)
{
    std::cout << "Sample Rejected Status" << std::endl;
    std::cout << "Total Count " << status.total_count << std::endl;
    std::cout << "Total Count Change " << status.total_count_change << std::endl;
    std::cout << "Reason " << status.reason_to_string() << std::endl;
}

void HelloWorldSubscriber::SubListener::on_sample_lost(
        DataReader*,
        const SampleLostStatus& status)
{
    std::cout << "Sample Lost Status" << std::endl;
    std::cout << "Total Count " << status.total_count << std::endl;
    std::cout << "Total Count Change " << status.total_count_change << std::endl;
}

void HelloWorldSubscriber::SubListener::on_data_available(
        eprosima::fastdds::dds::DataReader* reader)
{
    ReturnCode_t code = reader->take_next_sample(&hello_, &info_);
    if (code == ReturnCode_t::RETCODE_OK && enable_)
    {
        if (info_.instance_state == ::dds::sub::status::InstanceState::alive())
        {
            samples_++;
            // Print your structure data here.
            std::cout << "Message " << hello_.message() << " " << hello_.index() << " RECEIVED" << std::endl;

        }
    }
    else if (code == ReturnCode_t::RETCODE_NOT_ENABLED && enable_)
    {
        enable_ = false;
        std::cout << "Reader not enabled." << std::endl;
    }
}

void HelloWorldSubscriber::run()
{
    std::cout << "Subscriber running. Please press enter to stop the Subscriber" << std::endl;
    std::cin.ignore();
}

void HelloWorldSubscriber::run(
        uint32_t number)
{
    std::cout << "Subscriber running until " << number << " samples have been received" << std::endl;
    while (number > listener_.samples_)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}