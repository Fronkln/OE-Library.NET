using System;
using System.Runtime.InteropServices;


namespace OELibrary
{
    public class Fighter : Human
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTER_GET_INPUT_LISTENER", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Fighter_GetInputListener(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTER_GETTER_DISPOSE_INFO", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Fighter_Getter_DisposeInfo(IntPtr fighter);


        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTER_GETTER_BATTLE_STATUS", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Fighter_Getter_BattleStatus(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTER_GETTER_FIGHTERMODEMANAGER", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_Fighter_Getter_FighterModeManager(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTER_GETTER_INDEX", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_Fighter_Getter_Index(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTER_GETTER_INPUT_FLAGS", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_Fighter_Getter_InputFlags(IntPtr fighter);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_FIGHTER_SETTER_INPUT_FLAGS", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_Fighter_Setter_InputFlags(IntPtr fighter, int flags);



        protected override void Precache()
        {
            base.Precache();
        }


        public FighterBattleStatus BattleStatus
        {
            get
            {
                return new FighterBattleStatus() { Pointer = OELib_Fighter_Getter_BattleStatus(Pointer) };
            }
        }

        public DisposeInfo Dispose
        {
            get
            {
                IntPtr dispInf = OELib_Fighter_Getter_DisposeInfo(Pointer);

                if (dispInf == IntPtr.Zero)
                    return new DisposeInfo();

                DisposeInfo informat = Marshal.PtrToStructure<DisposeInfo>(dispInf);
                return informat;
            }
        }

        public int Index
        {
            get
            {
                return OELib_Fighter_Getter_Index(Pointer);
            }
        }
        public int InputFlags
        {
            get
            {
                return OELib_Fighter_Getter_InputFlags(Pointer);
            }
            set
            {
                OELib_Fighter_Setter_InputFlags(Pointer, value);
            }
        }
        public FighterModeManager ModeManager
        {
            get
            {
                return new FighterModeManager() { Pointer = OELib_Fighter_Getter_FighterModeManager(Pointer) };
            }
        }

        public InputDeviceListener GetInputListener()
        {
            return new InputDeviceListener() { Pointer = OELib_Fighter_GetInputListener(Pointer) };
        }
    }
}
