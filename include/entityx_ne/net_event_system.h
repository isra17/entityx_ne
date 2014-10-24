#pragma once

#include <entityx/entityx.h>

namespace entityx {
namespace ne {

template<class NetConnection>
class NetEventSystem : public entityx::System<NetEventSystem<NetConnection>> {
  public:
    NetEventSystem(std::shared_ptr<NetConnection> net_connection)
      : _net_connection(net_connection)
    {
    }

    void update(entityx::EntityManager &entities, entityx::EventManager &events, double dt) {
      std::unique_ptr<entityx::BaseEvent> event;
      while((event = _net_connection->poll_event())) {
        events.emit(*event);
      }
    }

  private:
    std::shared_ptr<NetConnection> _net_connection;
};

} // namespace ne
} // namespace entityx
