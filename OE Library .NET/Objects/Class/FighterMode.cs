using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public class FighterMode : UnmanagedObject
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERMODE_GETTER_NAME", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Y5Lib_FighterMode_Getter_Name(IntPtr fighterMode);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERMODE_GETTER_FIGHTER", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Y5Lib_FighterMode_Getter_Fighter(IntPtr fighterMode);


        public Fighter Fighter
        {
            get
            {
                return new Fighter() { Pointer = Y5Lib_FighterMode_Getter_Fighter(Pointer) };
            }
        }

        public string Name
        {
            get
            {
                IntPtr namePtr = Y5Lib_FighterMode_Getter_Name(Pointer);

                if (namePtr == IntPtr.Zero)
                    return "";

                return Marshal.PtrToStringAnsi(namePtr);
            }
        }
    }
}
