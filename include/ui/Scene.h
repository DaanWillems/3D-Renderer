//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_SCENE_H
#define RDALGEBRA2_SCENE_H

#include <vector>
#include "Renderable.h"

namespace ui {
    class Scene {
    public:
        std::vector<Renderable*> renderables;
    };
}

#endif //RDALGEBRA2_SCENE_H
