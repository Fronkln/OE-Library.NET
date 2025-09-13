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


        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_PARTICLEMANAGER_PLAY", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_ParticleManager_Play(int particleID, IntPtr mtx);


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

        public static void Play(int particleID, Matrix4x4 mtx)
        {
            var mtxPtr = mtx.ToIntPtr();
            OELib_ParticleManager_Play(particleID, mtxPtr);
            Marshal.FreeHGlobal(mtxPtr);
        }

        public static void Play(int particleID, Vector3 position)
        {
            Matrix4x4 mtx = Matrix4x4.Default;
            mtx.Position = position;
;
            Play(particleID, mtx);
        }
    }
}
