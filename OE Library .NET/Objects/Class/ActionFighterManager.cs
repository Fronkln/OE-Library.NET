using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public static class ActionFighterManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONFIGHTERMANAGER_IS_FIGHTER_PRESENT", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.U1)]
        internal static extern bool OELib_ActionFighterManager_IsFighterPresent(int index);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONFIGHTERMANAGER_SET_FIGHTER_PRESENT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_ActionFighterManager_SetFighterPresent(int index, bool present);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONFIGHTERMANAGER_IS_FIGHTER_ACTIVE", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.U1)]
        internal static extern bool OELib_ActionFighterManager_IsFighterActive(int index);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONFIGHTERMANAGER_SET_FIGHTER_ACTIVE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_ActionFighterManager_SetFighterActive(int index, bool present);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONFIGHTERMANAGER_DESTROY_FIGHTER", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_ActionFighterManager_DestroyFighter(int index);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONFIGHTERMANAGER_GETFIGHTERBYINDEX", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_ActionFighterManager_GetFighterByIndex(int index);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONFIGHTERMANAGER_GETFIGHTERBYUID", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_ActionFighterManager_GetFighterByUID(int index);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONFIGHTERMANAGER_GET_PLAYER", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr OELib_ActionFighterManager_GetPlayer();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_ACTIONFIGHTERMANAGER_SET_PLAYER", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_ActionFighterManager_SetPlayer(int idx);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONFIGHTERMANAGER_ADD_DISPOSE_FOR_SPAWN", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_ActionFighterManager_AddDisposeForSpawn(IntPtr inf);

        public static Fighter Player { get { return new Fighter() { Pointer = OELib_ActionFighterManager_GetPlayer() }; } }

        public static Fighter GetFighterByIndex(int index)
        {
            return new Fighter() { Pointer = OELib_ActionFighterManager_GetFighterByIndex(index) };
        }

        public static Fighter GetFighterByUID(int index)
        {
            return new Fighter() { Pointer = OELib_ActionFighterManager_GetFighterByUID(index) };
        }

        public static int AddDisposeForSpawn(DisposeInfo inf)
        {
            IntPtr ptr = inf.ToIntPtr();
            int idx = OELib_ActionFighterManager_AddDisposeForSpawn(ptr);
            Marshal.FreeHGlobal(ptr);

            return idx;
        }

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CACTIONFIGHTERMANAGER_PROCESS_DISPOSE_QUEUE", CallingConvention = CallingConvention.Cdecl)]
        public static extern void ProcessDisposeQueue();

        public static Fighter[] GetFighters()
        {
            List<Fighter> fighters = new List<Fighter>();

            for (int i = 0; i < 64; i++)
                if (IsFighterPresent(i))
                    fighters.Add(GetFighterByIndex(i));

            return fighters.ToArray();
        }

        public static int[] GetFighterIDs()
        {
            List<int> ids = new List<int>();

            for (int i = 0; i < 64; i++)
                if (IsFighterPresent(i))
                    ids.Add(i);

            return ids.ToArray();
        }

        public static Fighter[] GetEnemies()
        {
            List<Fighter> fighters = new List<Fighter>();

            for (int i = 0; i < 64; i++)
                if (IsFighterPresent(i))
                {
                    var fighter = GetFighterByIndex(i);
                    var dispose = fighter.Dispose;

                    if (dispose.npcType == NPCType.Goon || dispose.npcType == NPCType.Boss)
                        fighters.Add(fighter);
                }

            return fighters.ToArray();
        }

        public static void SetPlayer(int fighterIdx)
        {
            OELib_ActionFighterManager_SetPlayer(fighterIdx);
        }

        public static bool IsFighterPresent(int index)
        {
            return OELib_ActionFighterManager_IsFighterPresent(index);
        }

        public static void SetFighterPresent(int index, bool present)
        {
            OELib_ActionFighterManager_SetFighterPresent(index, present);
        }

        public static bool IsFighterActive(int index)
        {
            return OELib_ActionFighterManager_IsFighterActive(index);
        }

        public static void SetFighterActive(int index, bool present)
        {
            OELib_ActionFighterManager_SetFighterActive(index, present);
        }

        public static void DestroyFighter(int index)
        {
            OELib_ActionFighterManager_DestroyFighter(index);
        }
    }
}
