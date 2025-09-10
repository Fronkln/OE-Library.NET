using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public static class ActionCameraManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONCAMERAMANAGER_GETTER_CURRENT_CAMERA", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_ActionCameraManager_Getter_CurrentCamera();

        public static CameraBase Active
        {
            get
            {
                return new CameraBase() { Pointer = OELib_ActionCameraManager_Getter_CurrentCamera() };
            }
        }
    }
}
