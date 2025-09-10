using System.Runtime.InteropServices;

namespace OELibrary
{
    public static class SequenceManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_SEQUENCEMANAGER_GETTER_CURRENT_MISSION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_ActionSequenceManager_Getter_CurrentMission();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_SEQUENCEMANAGER_GETTER_CURRENT_MISSION_STATE", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int OELib_ActionSequenceManager_Getter_CurrentMissionPhase();

        public static int MissionID { get { return OELib_ActionSequenceManager_Getter_CurrentMission(); } }
        public static int Phase { get { return OELib_ActionSequenceManager_Getter_CurrentMissionPhase(); } }
    }
}
