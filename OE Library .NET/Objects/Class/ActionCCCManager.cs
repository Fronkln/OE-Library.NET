using System;
using System.Runtime.InteropServices;


namespace OELibrary
{
    public static class ActionCCCManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONCCCMANAGER_IS_ACTIVE", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool IsActive();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONCCCMANAGER_IS_ENDING", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetUnknownFlags();
    }
}
