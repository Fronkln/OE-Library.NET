using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public static class ActionHActCHPManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_HACTCHPMANAGER_GET_CURRENT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_HActCHPManager_GetCurrent();

        public static string CurrentName
        {
            get
            {
                return Marshal.PtrToStringAnsi(OELib_HActCHPManager_GetCurrent());
            }
        }
    }
}
