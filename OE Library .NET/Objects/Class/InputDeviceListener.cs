using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public class InputDeviceListener : UnmanagedObject
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CINPUTDEVICELISTENER_GETTER_SLOT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Y5Lib_InputDeviceListener_Getter_Slot(IntPtr listener);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CINPUTDEVICELISTENER_SETTER_SLOT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void Y5Lib_InputDeviceListener_Setter_Slot(IntPtr listener, IntPtr slot);

        public InputDeviceSlot GetSlot()
        {
            return new InputDeviceSlot() { Pointer = Y5Lib_InputDeviceListener_Getter_Slot(Pointer) };
        }

        public void SetSlot(InputDeviceSlot inputSlot)
        {
            Y5Lib_InputDeviceListener_Setter_Slot(Pointer, inputSlot.Pointer);
        }
    }
}
