//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_SCENE_H
#define RDALGEBRA2_SCENE_H

#include <vector>
#include "renderable.h"

namespace ui {
    class scene {
    public:
        std::vector<renderable*> renderables;
    };
}

#endif //RDALGEBRA2_SCENE_H
