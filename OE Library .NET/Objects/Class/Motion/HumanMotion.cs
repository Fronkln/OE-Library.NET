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

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HUMANMOTION_GETTER_ROT_Y", CallingConvention = CallingConvention.Cdecl)]
        internal static extern ushort Y5Lib_Motion_Getter_Rot_Y(IntPtr ent);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HUMANMOTION_SETTER_ROT_Y", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void Y5Lib_Motion_Setter_Rot_Y(IntPtr ent, ushort value);

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

        public ushort RotY
        {
            get
            {
                return Y5Lib_Motion_Getter_Rot_Y(Pointer);
            }
            set
            {
                Y5Lib_Motion_Setter_Rot_Y(Pointer, value);
            }
        }

    }
}
