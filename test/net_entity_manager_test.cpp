#include <gtest/gtest.h>
#include <entityx_ne/net_entity_manager.h>
#include "support/test_system.h"

class NetEntityManagerTest : public testing::Test {
protected:
  NetEntityManagerTest() : events(), remote_events(), manager(events), remote_manager(remote_events) {}

  virtual void SetUp() {

  }

  entityx::EventManager events;
  entityx::EventManager remote_events;
  entityx::ne::NetEntityManager manager;
  entityx::ne::NetEntityManager remote_manager;
};

TEST_F(NetEntityManagerTest, NetCreate) {
  auto net_e = manager.net_create();
  auto e = manager.create();

  EXPECT_TRUE(manager.is_net(net_e));
  EXPECT_FALSE(manager.is_net(e));

  auto net_other = remote_manager.net_create(net_e.id());
  EXPECT_TRUE(manager.is_net(net_other));
}
