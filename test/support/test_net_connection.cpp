#include <memory>
#include "test_net_connection.h"

void TestNetConnection::set_other(std::shared_ptr<TestNetConnection> other) {
  _other = other;
}

std::unique_ptr<TestEvent> TestNetConnection::poll_event() {
  if(_event_queue.empty()) {
    return std::unique_ptr<TestEvent>();
  } else {
    auto event = std::unique_ptr<TestEvent>(new TestEvent(_event_queue.front()));
    _event_queue.pop();
    return event;
  }
}

void TestNetConnection::send_event(const TestEvent& event) {
  _event_queue.push(event);
}
