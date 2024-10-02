//
// Created by Dargonrol on 02/10/2024.
//
#include <Dense>

struct Transform
{
    Eigen::Vector2f position;
    Eigen::Quaternionf rotation;
    Eigen::Vector2f scale; // to scale in x and y
};