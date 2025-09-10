using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class EntityBase : OEBase
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ENTITYBASE_GETTER_UID", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_Entity_Getter_UID(IntPtr entBase);

        public int UID
        {
            get
            {
                return OELib_Entity_Getter_UID(Pointer);
            }
        }
    }
}
