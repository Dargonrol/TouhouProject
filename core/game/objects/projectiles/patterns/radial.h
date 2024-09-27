//
// Created by dargonrol on 9/27/2024.
//

#ifndef RADIAL_H
#define RADIAL_H
#include <utility>

#include "../Projectile.h"
#include "../../createObjects.h"

class Radial {
public:
     Radial(Eigen::Vector2d pos) : m_position(std::move(pos))  {}
     void setObject(object_types object_type) { m_projectile = object_type; }
     void setCount(int count) { m_count = count; }
     void setSpeed(double speed) { m_speed = speed; }
     void spawnObjects() {
          int angleSteps = 360 / m_count;
          int angle = 0;
          for (int i = 0; i < m_count; i++) {
               Eigen::Vector2d bulletSpawn = {
                    m_minRadius * cos(angle*(std::numbers::pi/380)),
                    m_minRadius * sin(angle*(std::numbers::pi/380))};
               bulletSpawn += m_position;
               auto* projectile = dynamic_cast<Projectile *>(createObject(object_types::BULLET, bulletSpawn));
               m_objects.push_back(projectile);
               // velocity radius vector
               Eigen::Vector2d radiusNormal {0.0, 0.0};
               radiusNormal += (bulletSpawn - m_position).normalized();
               projectile->setVelocity(Eigen::Vector2d(radiusNormal * m_speed));
               angle += angleSteps;
          }
     }

     void update(double deltaTime) {
          for (auto &object : m_objects) {
               object->update(deltaTime);
          }
     }
     void render(float alpha) {
          for (auto &object : m_objects) {
               object->render(alpha);
          }
     }

private:
     object_types m_projectile;
     int m_count;
     double m_speed;
     std::vector<GameObject*> m_objects;
     double m_minRadius = 50;
     Eigen::Vector2d m_position;

};
#endif //RADIAL_H
