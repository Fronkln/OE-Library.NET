using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public static class ParticleManager
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_PARTICLEMANAGER_LOAD_ARCHIVE", CallingConvention = CallingConvention.Cdecl)]
        private static extern int OELib_ParticleManager_LoadArchive(string archiveName, int unknown = 1);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_PARTICLEMANAGER_UNLOAD_ARCHIVE", CallingConvention = CallingConvention.Cdecl)]
        private static extern void OELib_ParticleManager_UnloadArchive(int archiveID);


        public static int LoadArchive(string archiveName) 
        {
            if (string.IsNullOrEmpty(archiveName))
                return -1;

            return OELib_ParticleManager_LoadArchive(archiveName, 1);
        }
        
        public static void UnloadArchive(int archiveID)
        {
            OELib_ParticleManager_UnloadArchive(archiveID);
        }
    }
}
