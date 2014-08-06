#pragma once

#include <entityx/entity.h>

namespace entityx {
namespace ne {

struct NetInfo : public entityx::Component<NetInfo> {
  NetInfo(const entityx::Entity::Id& id) : net_id(id) {}
  entityx::Entity::Id net_id;
};

} // namespace ne
} // namespace entityx
