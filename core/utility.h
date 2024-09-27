//
// Created by dargonrol on 6/23/2024.
//

#ifndef UTILITY_H
#define UTILITY_H
#include <vector>

#include "GameProperties.h"

template<typename... Args>

bool anyNull(Args... args) {
    return ((args == nullptr) || ...);
}

inline int ScreenCenterX() {
    return properties.resolution.width / 2;
}

inline int ScreenCenterY() {
    return properties.resolution.height / 2;
}


#endif //UTILITY_H
