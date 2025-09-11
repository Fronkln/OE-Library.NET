#pragma once
#include "Class/Human.h"


OE_LIBRARY_EXPORT inline HumanMotion* OE_LIB_HUMAN_GETTER_MOTION(Human* human)
{
    if (human == nullptr)
        return 0;
    
    return human->motionPtr;
}

OE_LIBRARY_EXPORT inline void OE_LIB_HUMAN_WARP_TO_POSITION(Human* human, vec3f pos)
{
    if (human == nullptr)
        return;

    vec4f vec4 = (vec4f)pos;
    human->WarpToPosition(&vec4);
}