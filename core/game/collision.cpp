//
// Created by dargonrol on 9/27/2024.
//

#include "collision.h"

#include "../GameProperties.h"
#include "objects/Player.h"
namespace collision {
    bool checkCollisionWindow(GameObject &object) {
        switch (object.getType()) {
            case object_types::PLAYER:
                auto* player = dynamic_cast<Player*>(&object);
            return(player->getPosition()[0] < 0 ||
                player->getPosition()[0] + player->getSize()[0] > properties.resolution.width ||
                player->getPosition()[1] < 0 ||
                player->getPosition()[1] + player->getSize()[1] > properties.resolution.height);

        }
        return false;
    }
}