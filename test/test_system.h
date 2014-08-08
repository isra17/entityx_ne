#ifndef ENTITYX_NE_TEST_TEST_SYSTEM_H
#define ENTITYX_NE_TEST_TEST_SYSTEM_H

#include <entityx/entityx.h>
#include <entityx_ne/interpolator.h>

struct TestComponent : public entityx::Component < TestComponent > {
  int state = 0;
};

struct TestInterpolator : public entityx::ne::Interpolator< TestInterpolator, TestComponent > {
  virtual void interpolate(const TestComponent& base, const TestComponent& current, TestComponent& interpolated, double t) override {
    interpolated.state = base.state * (1 - t) + current.state * t + 0.5f;
  }
};

struct TestSystem : public entityx::System < TestSystem > {
  void update(entityx::EntityManager &es, entityx::EventManager &events, double dt) override {
    TestComponent::Handle c;
    for (entityx::Entity entity : es.entities_with_components(c)) {
      c->state += (10 * dt) + 0.5f;
    }
  }
};

struct TestEvent : public entityx::Event<TestEvent> {
  TestEvent(int value) : value(value) {};
  int value;
};

#endif
