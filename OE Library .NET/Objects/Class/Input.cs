using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public static class Input
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_INPUT_GETTER_RAW_INPUTS_ADDRESS", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Input_RawAddress();

        public static IntPtr GetRawData(int slot)
        {
            IntPtr addr = OELib_Input_RawAddress();
            int size = OE.IsYK1() ? 856 : 848;


            addr = addr + (slot * size);

            return addr;
        }
    }
}
