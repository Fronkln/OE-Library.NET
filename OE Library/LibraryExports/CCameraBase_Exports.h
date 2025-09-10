#pragma once
#include "defines.h"
#include "Class/CCameraBase.h"

OE_LIBRARY_EXPORT inline vec4f OE_LIB_CCAMERABASE_GETTER_CURRENT_POSITION(CCameraBase* camera)
{
	if (camera == nullptr)
		return vec4f();

	return camera->currentPosition;
}

OE_LIBRARY_EXPORT inline void OE_LIB_CCAMERABASE_SETTER_CURRENT_POSITION(CCameraBase* camera, vec4f position)
{
	if (camera == nullptr)
		return;

	camera->currentPosition = position;
}

OE_LIBRARY_EXPORT inline vec4f OE_LIB_CCAMERABASE_GETTER_FOCUS_POSITION(CCameraBase* camera)
{
	if (camera == nullptr)
		return vec4f();

	return camera->focusPos;
}

OE_LIBRARY_EXPORT inline void OE_LIB_CCAMERABASE_SETTER_FOCUS_POSITION(CCameraBase* camera, vec4f position)
{
	if (camera == nullptr)
		return;

	camera->focusPos = position;
}

OE_LIBRARY_EXPORT inline Matrix4x4 OE_LIB_CCAMERABASE_GETTER_MATRIX(CCameraBase* camera)
{
	if (camera == nullptr)
		return Matrix4x4();

	return camera->matrix;
}

OE_LIBRARY_EXPORT inline float OE_LIB_CCAMERABASE_GETTER_FOV(CCameraBase* camera)
{
	if (camera == nullptr)
		return 0;

	return camera->fov;
}

OE_LIBRARY_EXPORT inline void OE_LIB_CCAMERABASE_SETTER_FOV(CCameraBase* camera, float fov)
{
	if (camera == nullptr)
		return;

	camera->fov = fov;
}

OE_LIBRARY_EXPORT inline float OE_LIB_CCAMERABASE_GETTER_NEAR_CLIP(CCameraBase* camera)
{
	if (camera == nullptr)
		return 0;

	return camera->nearClip;
}

OE_LIBRARY_EXPORT inline void OE_LIB_CCAMERABASE_SETTER_NEAR_CLIP(CCameraBase* camera, float clip)
{
	if (camera == nullptr)
		return;

	camera->nearClip = clip;
}


OE_LIBRARY_EXPORT inline float OE_LIB_CCAMERABASE_GETTER_FAR_CLIP(CCameraBase* camera)
{
	if (camera == nullptr)
		return 0;

	return camera->farClip;
}

OE_LIBRARY_EXPORT inline void OE_LIB_CCAMERABASE_SETTER_FAR_CLIP(CCameraBase* camera, float clip)
{
	if (camera == nullptr)
		return;

	camera->farClip = clip;
}