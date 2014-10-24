#pragma once

#include <gtest/gtest.h>
#include "support/test_net_connection.h"

struct EntityXNETest : public testing::Test {
  virtual void setup() {
    _server_connection = std::make_shared<TestNetConnection>();
    _client_connection = std::make_shared<TestNetConnection>();

    _server_connection->set_other(_client_connection);
    _client_connection->set_other(_server_connection);

    server = std::make_shared<TestEntityXNE>(_server_connection);
    client = std::make_shared<TestEntityXNE>(_client_connection);
  }

  std::shared_ptr<TestNetConnection> _server_connection;
  std::shared_ptr<TestNetConnection> _client_connection;

  std::shared_ptr<TestEntityXNE> server;
  std::shared_ptr<TestEntityXNE> client;
};
