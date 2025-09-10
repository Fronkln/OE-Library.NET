using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public static class ActionManager
    {

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONMANAGER_GETTER_DELTA_TIME", CallingConvention = CallingConvention.Cdecl)]
        internal static extern float OELib_ActionManager_Getter_DeltaTime();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONMANAGER_GETTER_FIXED_DELTA_TIME", CallingConvention = CallingConvention.Cdecl)]
        internal static extern float OELib_ActionManager_Getter_FixedDeltaTime();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONMANAGER_GETTER_IS_LOADED", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.U1)]
        internal static extern bool OELib_ActionManager_Getter_IsLoaded();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONMANAGER_GETTER_IS_PAUSED", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool IsPaused();

        /// <summary>
        /// (Seconds)Time that has passed since last frame, affected by game speed.
        /// </summary>
        public static float DeltaTime { get { return OELib_ActionManager_Getter_DeltaTime(); } }


        /// <summary>
        /// (Seconds)Time that has passed since last frame, not affected by game speed.
        /// </summary>
        public static float UnscaledDeltaTime { get { return OELib_ActionManager_Getter_FixedDeltaTime(); } }

        public static bool IsLoaded()
        {
            return OELib_ActionManager_Getter_IsLoaded();
        }
    }
}
