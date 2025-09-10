#pragma once
#include "Class/Human.h"


OE_LIBRARY_EXPORT inline HumanMotion* OE_LIB_HUMAN_GETTER_MOTION(Human* human)
{
    if (human == nullptr)
        return 0;
    
    return human->motionPtr;
}