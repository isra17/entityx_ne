#include <entityx_ne/net_entity_manager.h>
#include <entityx_ne/net_info.h>

using namespace entityx;
using namespace entityx::ne;

Entity NetEntityManager::net_create() {
  auto e = create();
  e.assign<NetInfo>(e.id());
  _net_id_mapping[e.id()] = e.id();
  return e;
}

Entity NetEntityManager::net_create(Entity::Id id) {
  auto e = create();
  e.assign<NetInfo>(id);
  _net_id_mapping[id] = e.id();
  return e;
}

bool NetEntityManager::is_net(entityx::Entity entity) {
  return entity.has_component<NetInfo>();
}
