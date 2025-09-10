using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class Player : Fighter
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_PLAYER_GET_ID", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_Player_GetID();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_PLAYER_UPDATE_STYLE_EFFECT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_Player_UpdateStyleEffect(IntPtr fighter);

        public static int GetPlayerID()
        {
            if (OE.IsYK1())
                return 0;


            return OELib_Player_GetID();
        }

        public void UpdateStyleEffect()
        {
            OELib_Player_UpdateStyleEffect(Pointer);
        }
    }
}
