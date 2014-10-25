#include <gtest/gtest.h>
#include <entityx_ne/net_event_system.h>
#include "entityx_ne_test.h"
#include "support/test_system.h"

using namespace entityx::ne;

class NetEventTest : public EntityXNETest {
protected:
  virtual void SetUp() override {
    EntityXNETest::SetUp();

    server->systems.add<NetEventSystem<TestNetConnection>>(server->net_connection);
    client->systems.add<NetEventSystem<TestNetConnection>>(client->net_connection);

    server->systems.configure();
    client->systems.configure();
  }
};

TEST_F(NetEventTest, send_event_from_client) {
  TestReceiver test_receiver;
  server->events.subscribe<TestEvent>(test_receiver);

  TestEvent event(42);
  client->events.net_emit(event);

  server->systems.update<NetEventSystem<TestNetConnection>>(0);
  EXPECT_EQ(42, test_receiver.value());
}

TEST_F(NetEventTest, send_event_from_server) {
  TestReceiver test_receiver;
  client->events.subscribe<TestEvent>(test_receiver);

  TestEvent event(42);
  server->events.net_emit(event);

  client->systems.update<NetEventSystem<TestNetConnection>>(0);
  EXPECT_EQ(42, test_receiver.value());
}
