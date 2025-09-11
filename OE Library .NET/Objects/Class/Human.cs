using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class Human : RenderableEntity
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HUMAN_GETTER_MOTION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Human_GetMotion(IntPtr ent);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HUMAN_WARP_TO_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_Human_WarpToPosition(IntPtr ent, Vector3 pos);


        public HumanMotion Motion { get { return new HumanMotion() { Pointer = OELib_Human_GetMotion(Pointer) }; } }

        protected override void Precache()
        {
            base.Precache();
        }

        public void WarpToPosition(Vector3 position)
        {
            OELib_Human_WarpToPosition(Pointer, position);
        }
    }
}
