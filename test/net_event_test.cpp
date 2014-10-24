#include <gtest/gtest.h>
#include <entityx_ne/net_event_system.h>
#include "entityx_ne_test.h"
#include "support/test_system.h"

using namespace entityx::ne;

class NetEventTest : public EntityXNETest {
protected:
  virtual void SetUp() {
    EntityXNETest::SetUp();
    server->systems.add<NetEventSystem<TestNetConnection>>(server->net_connection);
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
