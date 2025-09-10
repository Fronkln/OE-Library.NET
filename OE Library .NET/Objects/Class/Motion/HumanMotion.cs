using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class HumanMotion : UnkMotionClass
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_BONEMOTION_GETTER_MATRIX", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Matrix4x4 Y5Lib_Motion_Getter_Matrix(IntPtr ent);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HUMANMOTION_SET_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_HumanMotion_SetPosition(IntPtr ent, Vector3 pos);

        public Matrix4x4 Matrix
        {
            get
            {
                return Y5Lib_Motion_Getter_Matrix(Pointer);
            }
        }

        public override void SetPosition(Vector3 pos)
        {
            OELib_HumanMotion_SetPosition(Pointer, pos);
        }

    }
}
