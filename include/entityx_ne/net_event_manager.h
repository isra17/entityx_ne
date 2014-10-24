#pragma once

#include <entityx/entityx.h>

namespace entityx {
namespace ne {

template<class NetConnection>
class NetEventManager : public entityx::EventManager {
  public:
    NetEventManager(std::shared_ptr<NetConnection> net_connection)
      : _net_connection{net_connection}
    {}

    void net_emit(const BaseEvent &event) {

    }

  private:
    std::shared_ptr<NetConnection> _net_connection;
};

}
}
