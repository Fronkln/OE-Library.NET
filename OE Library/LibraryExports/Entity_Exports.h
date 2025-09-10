#pragma once
#include "Class/Entity.h"

OE_LIBRARY_EXPORT inline int OE_LIB_ENTITYBASE_GETTER_UID(EntityBase* ent)
{
    if (ent == nullptr)
        return -1;

    return ent->UID;
}

OE_LIBRARY_EXPORT inline char* OE_LIB_ENTITY_GET_CLASSNAME(Entity* ent)
{
    if (ent == nullptr)
        return 0;

    return ent->className;
}

//should use virtual function version isntead
OE_LIBRARY_EXPORT inline vec4f OE_LIB_ENTITY_GET_POSITION(Entity* ent)
{
    if (ent == nullptr)
        return vec4f();
   
    return ent->entityPosition;
}