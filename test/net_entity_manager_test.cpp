#include <gtest/gtest.h>
#include "test_system.h"

class NetEntityManagerTest : public testing::Test {
protected:
  virtual void SetUp() {

  }

  entityx::ne::NetEntityManager manager;
  entityx::ne::NetEntityManager remote_manager;
}

TEST_F(NetEntityManagerTest, NetCreate) {
  auto net_e = manager.net_create();
  auto e = manager.create();

  EXPECT_TRUE(manager.is_net(net_e));
  EXPECT_FALSE(manager.is_net(e));

  auto net_other = remote_manager.net_create(net_e.id());
  EXPECT_EQ(net_e.id(), net_other.id());
}
