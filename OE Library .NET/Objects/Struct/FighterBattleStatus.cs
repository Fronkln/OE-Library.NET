using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public class FighterBattleStatus : UnmanagedObject
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_GETTER_STYLE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_FighterBattleStatus_Getter_Style(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_SETTER_STYLE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_FighterBattleStatus_Setter_Style(IntPtr fighter, int style);


        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_GETTER_CURRENT_HEALTH", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_FighterBattleStatus_Getter_Current_Health(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_SETTER_CURRENT_HEALTH", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_FighterBattleStatus_Setter_Current_Health(IntPtr fighter, int health);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_GETTER_MAX_HEALTH", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_FighterBattleStatus_Getter_Max_Health(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_SETTER_MAX_HEALTH", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_FighterBattleStatus_Setter_Max_Health(IntPtr fighter, int health);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_GETTER_HEAT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern float OELib_FighterBattleStatus_Getter_Heat(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTERBATTLESTATUS_SETTER_HEAT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_FighterBattleStatus_Setter_Heat(IntPtr fighter, float health);

        public int Style
        {
            get
            {
                return OELib_FighterBattleStatus_Getter_Style(Pointer);
            }
            set
            {
                OELib_FighterBattleStatus_Setter_Style(Pointer, value);
            }
        }

        public int CurrentHealth
        {
            get
            {
                return OELib_FighterBattleStatus_Getter_Current_Health(Pointer);
            }
            set
            {
                OELib_FighterBattleStatus_Setter_Current_Health(Pointer, value);
            }
        }
        public int MaxHealth
        {
            get
            {
                return OELib_FighterBattleStatus_Getter_Max_Health(Pointer);
            }
            set
            {
                OELib_FighterBattleStatus_Setter_Max_Health(Pointer, value);
            }
        }

        public float Heat
        {
            get
            {
                return OELib_FighterBattleStatus_Getter_Heat(Pointer);
            }
            set
            {
                OELib_FighterBattleStatus_Setter_Heat(Pointer, value);
            }
        }
    }
}
