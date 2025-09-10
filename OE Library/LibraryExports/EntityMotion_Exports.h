#pragma once
#include "Class/Motion/EntityMotion.h"


OE_LIBRARY_EXPORT inline void OE_LIB_ENTITYMOTION_SET_POSITION(EntityMotion* mot, vec3f pos)
{
    if (mot == nullptr)
        return;

    mot->motionPos.x = pos.x;
    mot->motionPos.y = pos.y;
    mot->motionPos.z = pos.z;
}


OE_LIBRARY_EXPORT inline vec4f OE_LIB_ENTITYMOTION_GET_POSITION(EntityMotion* mot)
{
    if (mot == nullptr)
        return vec4f();

    return mot->motionPos;
}

OE_LIBRARY_EXPORT inline vec3f OE_LIB_ENTITYMOTION_GET_SCALE(EntityMotion* mot)
{
    if (mot == nullptr)
        return vec3f();

    return vec3f(mot->scaleX, mot->scaleY, mot->scaleZ);
}

OE_LIBRARY_EXPORT inline void OE_LIB_ENTITYMOTION_SET_SCALE(EntityMotion* mot, vec3f scale)
{
    if (mot == nullptr)
        return;

    mot->scaleX = scale.x;
    mot->scaleY = scale.y;
    mot->scaleZ = scale.z;
}