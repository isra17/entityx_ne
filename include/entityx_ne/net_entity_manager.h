#pragma once

#include <entityx/entityx.h>
#include <map>

namespace entityx {
namespace ne {

class NetEntityManager : public entityx::EntityManager {
 public:
  NetEntityManager(entityx::EventManager& events) : entityx::EntityManager(events) {}
  entityx::Entity net_create();
  entityx::Entity net_create(entityx::Entity::Id id);
  bool is_net(entityx::Entity entity);
 private:
  std::map<entityx::Entity::Id, entityx::Entity::Id> _net_id_mapping;
};

} // namespace ne
} // namespace entityx
