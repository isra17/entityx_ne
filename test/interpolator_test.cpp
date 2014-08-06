#include <gtest/gtest.h>
#include "test_system.h"

class InteroplatorTest : public testing::Test {
protected:
  virtual void SetUp() {
    instance.systems.add<TestSystem>();
    instance.systems.add<TestInterpolator::BaseSystem>();
    instance.systems.add<TestInterpolator::System>();
    instance.systems.configure();

    local_entity = instance.entities.create();
    local_entity.assign<TestComponent>();
    local_entity.assign<entityx::ne::FramedComponent<TestComponent>>();
  }

  void update() {
    instance.systems.update<TestInterpolator::BaseSystem>(1.f);
    instance.systems.update<TestSystem>(1.f);
  }

  void renderUpdate(double dt) {
    instance.systems.update<TestInterpolator::System>(dt);
  }

  entityx::EntityX instance;
  entityx::Entity local_entity;
};

TEST_F(InteroplatorTest, FixtureTest) {
  TestComponent::Handle c = local_entity.component<TestComponent>();
  EXPECT_EQ(0, c->state);
  update();
  EXPECT_EQ(10, c->state);
  update();
  EXPECT_EQ(20, c->state);
}

TEST_F(InteroplatorTest, BaseComponent) {
  auto c = local_entity.component<TestComponent>();
  auto framed_c = local_entity.component<entityx::ne::FramedComponent<TestComponent>>();

  c->state = 1;
  EXPECT_EQ(1, c->state);
  EXPECT_EQ(0, framed_c->base.state);

  instance.systems.update<TestInterpolator::BaseSystem>(1.f);
  EXPECT_EQ(1, c->state);
  EXPECT_EQ(1, framed_c->base.state);

  c->state = 2;
  EXPECT_EQ(2, c->state);
  EXPECT_EQ(1, framed_c->base.state);
}

TEST_F(InteroplatorTest, CopyBaseSystem) {
  auto c = local_entity.component<TestComponent>();
  auto framed_c = local_entity.component<entityx::ne::FramedComponent<TestComponent>>();

  EXPECT_EQ(0, c->state);
  EXPECT_EQ(0, framed_c->base.state);

  update();
  EXPECT_EQ(10, c->state);
  EXPECT_EQ(0, framed_c->base.state);

  update();
  EXPECT_EQ(20, c->state);
  EXPECT_EQ(10, framed_c->base.state);
}

TEST_F(InteroplatorTest, InterpolateSystem) {
  auto c = local_entity.component<TestComponent>();
  auto framed_c = local_entity.component<entityx::ne::FramedComponent<TestComponent>>();

  EXPECT_EQ(0, c->state);
  EXPECT_EQ(0, framed_c->renderable.state);

  update();
  EXPECT_EQ(10, c->state);
  EXPECT_EQ(0, framed_c->renderable.state);

  renderUpdate(0.5f);
  EXPECT_EQ(10, c->state);
  EXPECT_EQ(5, framed_c->renderable.state);

  renderUpdate(0.6f);
  EXPECT_EQ(10, c->state);
  EXPECT_EQ(6, framed_c->renderable.state);

  update();
  renderUpdate(0.0f);
  EXPECT_EQ(20, c->state);
  EXPECT_EQ(10, framed_c->renderable.state);

  renderUpdate(1.0f);
  EXPECT_EQ(20, c->state);
  EXPECT_EQ(20, framed_c->renderable.state);
}
