using System;
using System.Runtime.InteropServices;

namespace OELibrary.NET
{
    public class HActReplace : UnmanagedObject
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_GETTER_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Vector4 OELib_HActReplace_Getter_Position(IntPtr replacePtr);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_SETTER_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_HActReplace_Setter_Position(IntPtr replacePtr, ref Vector3 value);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_GETTER_FIGHTER_UID", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_HActReplace_Getter_Fighter_UID(IntPtr replacePtr);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_SETTER_FIGHTER_UID", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_HActReplace_Setter_Fighter_UID(IntPtr replacePtr, int value);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_GETTER_IS_ACTIVE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_HActReplace_Getter_Is_Active(IntPtr replacePtr);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_SETTER_IS_ACTIVE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_HActReplace_Setter_Is_Active(IntPtr replacePtr, int active);


        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_GETTER_UNK_VAL", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_HActReplace_Getter_Unk_Val(IntPtr replacePtr);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTREPLACE_SETTER_UNK_VAL", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_HActReplace_Setter_Unk_Val(IntPtr replacePtr, int val);


        public Vector3 Position
        {
            get
            {
                return OELib_HActReplace_Getter_Position(Pointer);
            }
            set
            {
                OELib_HActReplace_Setter_Position(Pointer, ref value);
            }
        }
        public int FighterUID
        {
            get
            {
                return OELib_HActReplace_Getter_Fighter_UID(Pointer);
            }
            set
            {
                OELib_HActReplace_Setter_Fighter_UID(Pointer, value);
            }
        }

        public bool IsActive
        {
            get
            {
                return OELib_HActReplace_Getter_Is_Active(Pointer) == 1;
            }
            set
            {
                OELib_HActReplace_Setter_Is_Active(Pointer, Convert.ToInt32(value));
            }
        }

        public int UnknownValue
        {
            get
            {
                return OELib_HActReplace_Getter_Unk_Val(Pointer);
            }
            set
            {
                OELib_HActReplace_Setter_Unk_Val(Pointer, value);
            }
        }
    }
}
