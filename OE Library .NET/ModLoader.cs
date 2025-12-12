using System;
using System.Collections.Generic;
using System.Reflection;
using System.IO;
using System.Runtime.InteropServices;

namespace OELibrary
{
    internal static class ModLoader
    {
        [DllImport("User32.dll", CharSet = CharSet.Unicode)]
        private static extern int MessageBox(IntPtr h, string m, string c, int type);

        internal static void InitializeMods()
        {
            string modDir = Path.Combine(Library.BaseDirectory, "mods");

            if (Directory.Exists(modDir))
            {
                int modCount = Parless.GetModCount();

                for (int i = 0; i < modCount; i++)
                {
                    IntPtr str = Parless.GetModName(i);

                    string name = Marshal.PtrToStringAnsi(str);
                    string path = Path.Combine(modDir, name);

                    if (Directory.Exists(path))
                    {
                        string[] modFiles = Directory.GetFiles(path, "*.dll");

                        foreach (string dllFile in modFiles)
                        {
                            bool loadRes = InitializeModLibrary(dllFile);

                            if (loadRes)
                                OE.LogInfo("Successfully loaded DLL library in " + name);
                        }
                    }
                }
            }

            OE.LogInfo("\n\nAll mods have been initialized.");
        }

        private static bool InitializeModLibrary(string path)
        {
            if (string.IsNullOrEmpty(path))
                return false;

            if (!File.Exists(path))
            {
                OE.LogError(path + " does not exist.");
                return false;
            }

            try
            {
                //Ugly reflection type
                Assembly loadedAssembly = Assembly.LoadFrom(path);

                foreach (CustomAttributeData dat in loadedAssembly.CustomAttributes)
                {
                    if (dat.AttributeType.FullName == "OELibrary.OEModAttribute") // type comparing didnt work. so we compare names
                    {
                        ProcessOEMod(new FileInfo(path).Directory.FullName, dat.ConstructorArguments);
                        return true;
                    }
                }

                return false;
            }
            catch (Exception ex)
            {
                if (ex as FileLoadException != null && ex.InnerException as NotSupportedException != null)
                    MessageBox((IntPtr)0, $"Failed to load {Path.GetFileName(path)} in mods/{Path.GetDirectoryName(path)} because it was untrusted by system, please unblock!\n" +
                        $"1)Go to the problematic file\n" +
                        $"2)Right click on it, go to properties\n" +
                        $"3)Press the unblock button", "Load Error", 0);

                //The issue was not that it wasn't a valid .NET library, it was something else.
                else if (ex as BadImageFormatException == null)
                    OE.LogError("Failed to load library.\nError: " + ex.Message + "\n" + ex.InnerException + "\nStacktrace:\n" + ex.StackTrace);

                return false;
            }
        }

        private static void ProcessOEMod(string directoryFullPath, IList<CustomAttributeTypedArgument> modInfo)
        {
            string modName = (string)modInfo[0].Value;
            string modAuthor = (string)modInfo[1].Value;
            Type modType = (Type)modInfo[2].Value;

            if (modType == null)
            {
                OE.LogError($"The mod {modName} does not have a valid mod initialization class");
                return;
            }

            if (modType.BaseType.FullName == "OELibrary.OEMod")
            {
                object createdObj = Activator.CreateInstance(modType);

                if (createdObj != null)
                {
                    OEMod mod = (OEMod)createdObj;
                    mod.ModPath = directoryFullPath;
                    mod.OnModInit();
                }
                else
                    OE.LogError("Mod class initialization for " + modName + " failed!");
            }
            else
                OE.LogError(modName + "'s initialization class does not derive from OEMod!");

        }
    }
}