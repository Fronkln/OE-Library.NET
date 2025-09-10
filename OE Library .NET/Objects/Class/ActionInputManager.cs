using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public static class ActionInputManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONPUTDEVICEMANAGER_GET_SLOT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Y5Lib_ActionInputDeviceManager_Get_Slot(int type);

        public static InputDeviceSlot GetInputDeviceSlot(int type)
        {
            return new InputDeviceSlot() { Pointer = Y5Lib_ActionInputDeviceManager_Get_Slot(type) };
        }
    }
}
