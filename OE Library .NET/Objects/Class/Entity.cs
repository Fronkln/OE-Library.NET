using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class Entity : EntityBase
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ENTITY_GET_CLASSNAME", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Entity_GetClassName(IntPtr ent);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ENTITY_GET_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Vector4 OELib_Entity_GetPosition(IntPtr ent);

        public string ClassName { get; private set; }

        protected override void Precache()
        {
            base.Precache();

            /*
            IntPtr classname = OELib_Entity_GetClassName(Pointer);

            if (classname == IntPtr.Zero)
                ClassName = "";
            else
                ClassName = Marshal.PtrToStringAnsi(classname);
            */
        }

        public Vector3 GetPosition()
        {
            return OELib_Entity_GetPosition(Pointer);
        }
    }
}
