#ifndef ENTITYX_NE_INTERPORLATOR_H
#define ENTITYX_NE_INTERPORLATOR_H

#include <entityx/entityx.h>

namespace entityx {
  namespace ne {
    template <typename C>
    struct FramedComponent : public entityx::Component < FramedComponent<C> > {
      C base;
      C renderable;
    };

    template <typename I, typename Type>
    class InterpolateSystem : public entityx::System < InterpolateSystem<I, Type> > {
    public:
      void update(entityx::EntityManager &entities, entityx::EventManager &events, double dt) {
        typename Type::Handle current;
        typename FramedComponent<Type>::Handle frameComponent;

        for (Entity e : entities.entities_with_components(current, frameComponent)) {
          interpolator_.interpolate(frameComponent->base, *current.get(), frameComponent->renderable, dt / frameLength_);
        }
      }

    private:
      I interpolator_;
      double frameLength_ = 1.0f;
    };

    template<typename Type>
    struct CopyBaseSystem : public entityx::System < CopyBaseSystem<Type> > {
      void update(entityx::EntityManager &entities, entityx::EventManager &events, double dt) {
        typename Type::Handle current;
        typename FramedComponent<Type>::Handle frameComponent;

        for (Entity e : entities.entities_with_components(current, frameComponent)) {
          frameComponent->base = *current.get();
        }
      }
    };

    template <typename I, typename T>
    struct Interpolator {
      typedef InterpolateSystem<I, T> System;
      typedef CopyBaseSystem<T> BaseSystem;
      virtual void interpolate(const T& base, const T& current, T& interpolated, double t)  {}
    };

  }
}

#endif
