#pragma once

namespace entityx {
namespace ne {

class NetEntityManager {
  entityx::Entity create();
  entityx::Entity net_create();
  entityx::Entity net_create(entityx::Entity::Id id);

 private:
   entityx::EntityManager _remoteManager;
   entityx::EntityManager _localManager;
}

} // namespace ne
} // namespace entityx
