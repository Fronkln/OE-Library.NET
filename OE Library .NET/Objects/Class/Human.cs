using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class Human : RenderableEntity
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HUMAN_GETTER_MOTION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Human_GetMotion(IntPtr ent);

        public HumanMotion Motion { get { return new HumanMotion() { Pointer = OELib_Human_GetMotion(Pointer) }; } }

        protected override void Precache()
        {
            base.Precache();
        }
    }
}
