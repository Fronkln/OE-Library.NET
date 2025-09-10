#pragma once
#include "Class/CActionCameraManager.h"
#include "OEStatics.h"

class CCameraBase;

OE_LIBRARY_EXPORT inline CCameraBase* OE_LIB_CACTIONCAMERAMANAGER_GETTER_CURRENT_CAMERA()
{
    CActionCameraManager* cman = *OEStatics::ActionCameraManager;

    if (cman == nullptr)
        return 0;

    return cman->activeCamera;
}