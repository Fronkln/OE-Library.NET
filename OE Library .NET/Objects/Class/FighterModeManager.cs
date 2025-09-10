using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public class FighterModeManager : UnmanagedObject
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERMODEMANAGER_GETTER_CURRENT_MODE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_FighterModeManager_Getter_CurrentMode(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERMODEMANAGER_SET_COMMANDSET", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_FighterModeManager_Set_Commandset(IntPtr fighter, string commandset);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERMODEMANAGER_TO_BATTLE_START", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_FighterModeManager_ToBattleStart(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERMODEMANAGER_GETTER_FIGHTER", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_FighterModeManager_Getter_Fighter(IntPtr fighter);

        public Fighter Fighter
        {
            get
            {
                return new Fighter() { Pointer = OELib_FighterModeManager_Getter_Fighter(Pointer) };
            }
        }

        public FighterMode Current
        {
            get
            {
                return new FighterMode() { Pointer = OELib_FighterModeManager_Getter_CurrentMode(Pointer) };
            }
        }

        public void SetCommandset(string commandset)
        {
            OELib_FighterModeManager_Set_Commandset(Pointer, commandset);
        }

        public void ToBattleStart()
        {
            OELib_FighterModeManager_ToBattleStart(Pointer);
        }
    }
}
