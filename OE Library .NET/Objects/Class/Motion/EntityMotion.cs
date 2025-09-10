using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class EntityMotion
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ENTITYMOTION_SET_SCALE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_EntityMotion_SetScale(IntPtr ent, Vector3 scale);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ENTITYMOTION_GET_SCALE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Vector3 OELib_EntityMotion_GetScale(IntPtr ent);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ENTITYMOTION_SET_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_EntityMotion_SetPosition(IntPtr ent, Vector3 scale);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ENTITYMOTION_GET_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Vector3 OELib_EntityMotion_GetPosition(IntPtr ent);

        public IntPtr Pointer;

        public void SetScale(Vector3 scale)
        {
            OELib_EntityMotion_SetScale(Pointer, scale);
        }

        public Vector3 GetScale()
        {
            return OELib_EntityMotion_GetScale(Pointer);
        }

        public virtual void SetPosition(Vector3 pos)
        {
            OELib_EntityMotion_SetPosition(Pointer, pos);
        }

        public Vector3 GetPosition()
        {
            return OELib_EntityMotion_GetPosition(Pointer);
        }
    }
}
