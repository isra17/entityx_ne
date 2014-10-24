#pragma once

#include <entityx/entityx.h>
#include <entityx_ne/net_entity_manager.h>
#include <entityx_ne/net_event_manager.h>

namespace entityx {
namespace ne {

template<class NetConnection>
class GenericEntityXNE {
  public:
    GenericEntityXNE(std::shared_ptr<NetConnection> net_connection)
    : net_connection{net_connection},
      events{net_connection},
      entities{events},
      systems{entities, events}
    {}

    std::shared_ptr<NetConnection> net_connection;
    NetEventManager<NetConnection> events;
    NetEntityManager entities;
    SystemManager systems;
};

}
}
