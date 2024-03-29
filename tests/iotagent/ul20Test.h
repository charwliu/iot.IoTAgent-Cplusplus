/**
* Copyright 2015 Telefonica Investigación y Desarrollo, S.A.U
*
* This file is part of iotagent project.
*
* iotagent is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published
* by the Free Software Foundation, either version 3 of the License,
* or (at your option) any later version.
*
* iotagent is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with iotagent. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by the GNU Affero General Public License
* please contact with iot_support at tid dot es
*/
#ifndef SRC_TESTS_IOTAGENT_UL20TEST_H_
#define SRC_TESTS_IOTAGENT_UL20TEST_H_

#include <cppunit/extensions/HelperMacros.h>
#include "services/admin_service.h"
#include "services/ngsi_service.h"
#include "ultra_light/ul20_service.h"
#include "../mocks/http_mock.h"

class Ul20Test : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(Ul20Test);

    CPPUNIT_TEST(testTransformCommand);
    CPPUNIT_TEST(testNormalPOST);
    CPPUNIT_TEST(testTimePOST);
    CPPUNIT_TEST(testBadPost);
    CPPUNIT_TEST(testNoDevicePost);
    CPPUNIT_TEST(testRiotISO8601);
    CPPUNIT_TEST(testTranslate);
    CPPUNIT_TEST(testCommand);
    CPPUNIT_TEST(testGetAllCommand);
    CPPUNIT_TEST(testDevices);

    CPPUNIT_TEST(testisCommandResponse);

    CPPUNIT_TEST(testFindService);
    CPPUNIT_TEST(testSendRegister);
    CPPUNIT_TEST(testDevicesConfig);
    CPPUNIT_TEST(testNoDeviceFile);
    CPPUNIT_TEST(testRegisterDuration);
    CPPUNIT_TEST(testKVP);

    CPPUNIT_TEST(testCacheMongoGet);
    CPPUNIT_TEST(testCacheMongoGetNotFound);


    CPPUNIT_TEST(testPUSHCommand);
    CPPUNIT_TEST(testPUSHCommandProxyAndOutgoingRoute);
    CPPUNIT_TEST(testPUSHCommandAsync);
    CPPUNIT_TEST(testBADPUSHCommand);
    CPPUNIT_TEST(testPollingCommand);

    CPPUNIT_TEST(testPollingCommandTimeout);
    CPPUNIT_TEST(testCommandNOUL);

    CPPUNIT_TEST(testPUSHCommandParam);

    CPPUNIT_TEST(testPUSHCommand_MONGO);
    CPPUNIT_TEST(testPollingCommand_MONGO_CON);
    CPPUNIT_TEST(testPollingCommand_MONGO_SIN_ENTITY_NAME);
    CPPUNIT_TEST(testPollingCommand_MONGO_SIN_ENTITY_TYPE);
    CPPUNIT_TEST(testPollingCommand_MONGO_SIN);
    CPPUNIT_TEST(testBAD_PUSHCommand_MONGO);

    CPPUNIT_TEST(testCommandHandle);

    CPPUNIT_TEST(testQueryContext);
    CPPUNIT_TEST(testQueryContextAPI);

    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

    static const std::string POST_SERVICE;
    static const  std::string POST_DEVICE;
    static const  std::string POST_DEVICE2;
    static const  std::string POST_DEVICE_CON;
    static const  std::string POST_DEVICE_CON2;
    static const  std::string PUT_DEVICE;
    static const  std::string PUT_DEVICE2;
    static const std::string HOST;
    static const std::string CONTENT_JSON;
    static const int POST_RESPONSE_CODE;
    static const std::string UPDATE_CONTEXT;
    static const std::string POST_DEVICE_SIN;
    static const std::string POST_DEVICE_SIN_ENTITY_NAME;
    static const std::string POST_DEVICE_SIN_ENTITY_TYPE;
    static const int RESPONSE_CODE_NGSI;
    static const std::string RESPONSE_MESSAGE_NGSI_OK;


  private:

    /** function toi fill data to cb_mock, it is not a test */
    void start_cbmock(boost::shared_ptr<HttpMock>& cb_mock,
                      const std::string& type = "file",
                      bool vpn = false);

    void testPollingCommand_MONGO(
                    const std::string &name_device,
                    const std::string &entity_name,
                    const std::string &entity_type,
                    const std::string &post_device,
                    const boost::shared_ptr<HttpMock> &create_mock);


    void testNormalPOST();
    void testTimePOST();
    void testBadPost();
    void testNoDevicePost();
    void testRiotISO8601();
    void testTranslate();
    void testNgsiCommand();
    void testCommand();
    void testGetAllCommand();
    void testTransformCommand();
    void testDevices();
    void testisCommandResponse();

    void testFindService();
    void testSendRegister();
    void testDevicesConfig();
    void testNoDeviceFile();
    void testRegisterDuration();
    void testKVP();
    void testCacheMongoGet();
    void testCacheMongoGetNotFound();


    void testPUSHCommand();

    void testPUSHCommandProxyAndOutgoingRoute();
    void testPUSHCommandAsync();
    void testBADPUSHCommand();
    void testPollingCommand();
    void testPollingCommandTimeout();
    void testCommandNOUL();
    void testPUSHCommandParam();


    void testCommandHandle();

    void testPUSHCommand_MONGO();
    void testPollingCommand_MONGO_CON();
    void testPollingCommand_MONGO_SIN_ENTITY_NAME();
    void testPollingCommand_MONGO_SIN_ENTITY_TYPE();
    void testPollingCommand_MONGO_SIN();
    void testBAD_PUSHCommand_MONGO();

    void testQueryContext();
    void testQueryContextAPI();



    void populate_command_attributes(
                     const boost::shared_ptr<iota::Device>& device,
                     iota::ContextElement& entity_context_element);

int queryContext(iota::QueryContext& queryContext,
                                       const boost::property_tree::ptree& service_ptree,
                                       iota::ContextResponses&  context_responses,
                                       iota::UL20Service& ul);

};

#endif  /* UL20TEST_H */



