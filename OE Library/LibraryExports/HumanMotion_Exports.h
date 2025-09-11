#pragma once
#include "Class/Motion/HumanMotion.h"

OE_LIBRARY_EXPORT inline void OE_LIB_HUMANMOTION_SET_POSITION(HumanMotion* mot, vec3f pos)
{
    if (mot == nullptr)
        return;

    vec4f vec4 = (vec4f)pos;
    mot->SetPosition(&vec4);
}


OE_LIBRARY_EXPORT inline unsigned short OE_LIB_HUMANMOTION_GETTER_ROT_Y(HumanMotion* mot)
{
    if (mot == nullptr)
        return 0;

    return mot->rotY;
}

OE_LIBRARY_EXPORT inline void OE_LIB_HUMANMOTION_SETTER_ROT_Y(HumanMotion* mot, unsigned short rot)
{
    if (mot == nullptr)
        return;

    mot->rotY = rot;
}

OE_LIBRARY_EXPORT inline Matrix4x4 OE_LIB_BONEMOTION_GETTER_MATRIX(HumanMotion* mot)
{
	if (mot == nullptr)
		return Matrix4x4();

    return mot->matrix;
}