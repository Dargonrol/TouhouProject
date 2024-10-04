//
// Created by Dargonrol on 02/10/2024.
//
#ifndef COMPONENTS_H
#define  COMPONENTS_H

#include <Dense>
#include "../CollisionHelper.h"

struct Component
{
public:
   uint8_t component_id = 0;
};

struct TransformComponent : Component
{
    TransformComponent() : Component{1} {}

    Eigen::Vector2f position;
    Eigen::Quaternionf rotation;
    Eigen::Vector2f scale; // to scale in x and y
};

struct VelocityComponent : Component
{
    VelocityComponent() : Component{1} {}
    Eigen::Vector2f velocity;
};

struct AccelerationComponent : Component
{
    Eigen::Vector2f acceleration;
};

struct HealthComponent : Component
{
    float health;
    float max_health;
    float regeneration;
};

struct ColorComponent : Component
{
    uint8_t r, g, b, a;
};

struct CollisionComponent : Component
{
    bool collision;
    CollisionHelper::CollisionType type;
};

struct LifeTimeComponent : Component
{
    float lifetime;
    std::function<float(float)> lifeTimeReductionFunction;
};

// not intended to use outside AttackPattern.
struct TrajectoryComponent : Component
{
    std::function<float(float, float)> trajectory; // which trajectory shall the entity follow? like sin wave, linear etc
};

// not intended to use outside Shooter.
struct AttackPatternComponent : Component // like 380° etc.
{
    int count; // how many entities to create
    std::function<Eigen::Vector2f(int)> placementFunction; // function which takes the nth entity as an argument and returns the relative coordinates to the "calling" entity where it shall place it
    TrajectoryComponent trajectory;
};

struct ShooterComponent : Component
{
    bool active;
    float cooldown;
    float shootTimer;
    AttackPatternComponent attackPattern;
};

struct PlayerInputComponent : Component
{
    bool active = true;
};

#endif // COMPONENTS_H