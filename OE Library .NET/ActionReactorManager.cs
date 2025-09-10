using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public static class ActionReactorManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONREACTORMANAGER_CREATEREACTOR", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr Y5Lib_ActionReactorManager_CreateReactor(int ID, Vector4 position, Quaternion rotation);

        public static Entity CreateReactor(int id, Vector4 position, Quaternion rotation)
        {
            IntPtr result = Y5Lib_ActionReactorManager_CreateReactor(id, position, rotation);
            return new Entity() { Pointer = result };
        }
    }
}
