using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace OELibrary
{
    public static class Library
    {
        public static string BaseDirectory;
        public static string Root;

        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern IntPtr LoadLibrary(string libname);

        public static void Main(string[] args)
        {

            ChickenShit();

            try
            {
                BaseDirectory = AppDomain.CurrentDomain.BaseDirectory;
                Root = args[0];
                OE._LogPath = Path.Combine(Root, "log.txt");

                File.WriteAllText(OE._LogPath, "");

                // Environment.CurrentDirectory = Root;

                OE.LogInfo("OELib Start");

                string libPath = Path.Combine(Root, "OE Library.dll");

                OE.LogInfo("BaseDirectory: " + BaseDirectory);
                OE.LogInfo("OELibrary path: " + libPath);

                if (LoadLibrary(libPath) == IntPtr.Zero)
                {
                    OE.LogError("Failed to load the library! " + "GetLastWinError32:" + Marshal.GetLastWin32Error());
                    return;
                }
                else
                    OE.LogInfo("Loaded OELibrary, initialization time!");

                while (!OE.IsEngineInitialized())
                {
                    OE.RefreshOffsets();
                    continue;
                }

                AppDomain.CurrentDomain.UnhandledException += OE.CurrentDomain_UnhandledException;

                OE.InitLib();
                //    Hooks.Initialize();
                //  DXHook.Init();

                OE.Init();
                ModLoader.InitializeMods();

                OE.RegisterJob(JobPhase.Camera, OETaskManager.Update);

                OE.LogInfo("\nOE Library initialized.");

            }
            catch (Exception ex)
            {
                OE.LogError("Library initialization error!:  " + ex.Message);
            }
        }

        private static void ChickenShit()
        {
            AppDomain.CurrentDomain.AssemblyResolve += ResolveLibrary;
        }

        [MethodImpl(MethodImplOptions.NoInlining)]
        private static Assembly ResolveLibrary(object sender, ResolveEventArgs argses)
        {
            string assemblyName = argses.Name.Split(',')[0];
            if (assemblyName == "OELibraryNET")
                return AppDomain.CurrentDomain.GetAssemblies().FirstOrDefault(x => x.GetName().Name == "OELibraryNET");

            return null;
        }
    }
}
