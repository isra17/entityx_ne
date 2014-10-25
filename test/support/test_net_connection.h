#pragma once

#include <entityx/entityx.h>
#include <entityx_ne/entityx_ne.h>
#include <queue>

#include "test_system.h"

class TestNetConnection {
  public:
    void set_other(std::shared_ptr<TestNetConnection> other);

    std::unique_ptr<TestEvent> poll_event();
    void send_event(const entityx::BaseEvent& event);

  private:
    std::weak_ptr<TestNetConnection> _other;
    std::queue<TestEvent> _event_queue;
};

typedef entityx::ne::GenericEntityXNE<TestNetConnection> TestEntityXNE;


