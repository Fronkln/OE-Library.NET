using System;
using System.Collections.Generic;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Security;
using System.Security.Cryptography;


namespace OELibrary
{
    namespace Unsafe
    {
        public static class CPP
        {
            [DllImport("OE Library.dll", EntryPoint = "LIB_UNSAFE_NOP", CallingConvention = CallingConvention.Cdecl)]
            public static extern void NopMemory(IntPtr memory, uint len);


            [DllImport("OE Library.dll", EntryPoint = "LIB_UNSAFE_PATCH", CallingConvention = CallingConvention.Cdecl)]
            private static extern void Unsafe_NopMemory(IntPtr memory, IntPtr buf, int len);

            [DllImport("OE Library.dll", EntryPoint = "LIB_READ_RELATIVE_ADDRESS", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr ResolveRelativeAddress(IntPtr addr, int instructionLen);

            [DllImport("OE Library.dll", EntryPoint = "LIB_PATTERN_SEARCH", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr PatternSearch(string pattern);

            [DllImport("OE Library.dll", EntryPoint = "LIB_READ_CALL", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr ReadCall(IntPtr addr);

            [DllImport("OE Library.dll", EntryPoint = "LIB_WRITE_CALL", CallingConvention = CallingConvention.Cdecl)]
            public static extern void WriteCall(IntPtr addr, IntPtr func);

            public static void PatchMemory(IntPtr addr, params byte[] bytes)
            {
                IntPtr byteArr = Marshal.AllocHGlobal(bytes.Length);
                Marshal.Copy(bytes, 0, byteArr, bytes.Length);

                Unsafe_NopMemory(addr, byteArr, bytes.Length);

                Marshal.FreeHGlobal(byteArr);
            }

            public static byte[] ReadMemory(IntPtr addr, byte length)
            {
                byte[] bytes = new byte[length];
                Marshal.Copy(addr, bytes, 0, length);

                return bytes;
            }
        }
    }

    public static class OE
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_REFRESH_OFFSETS", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void RefreshOffsets();

        [DllImport("OE Library.dll", EntryPoint = "OE_INITIALIZED", CallingConvention = CallingConvention.Cdecl)]
        [return:MarshalAs(UnmanagedType.U1)]
        internal static extern bool IsEngineInitialized();

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_INIT", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void InitLib();

        [DllImport("OE Library.dll", EntryPoint = "OE_REGISTER_JOB", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_RegisterJob(IntPtr deleg, uint type, uint priority);

        [DllImport("user32.dll")]
        private static extern short GetAsyncKeyState(int vKey);

        private static bool m_isYK1;



        internal delegate void RegisterJobDelegate();

        internal class JobRegisterInfo
        {
            public Action funcRaw;
            public RegisterJobDelegate del;
            public IntPtr delPointer;
            public uint phase;
            public uint priority;

            public JobRegisterInfo(Action func, RegisterJobDelegate del, IntPtr ptr, uint phase, uint priority)
            {
                this.funcRaw = func;
                this.del = del;
                this.phase = phase;
                delPointer = ptr;
                this.priority = priority;
            }
        }
        internal static List<JobRegisterInfo> _jobDelegates = new List<JobRegisterInfo>();


        public static bool IsYK1()
        {
            return m_isYK1;
        }

        public static bool IsY0()
        {
            return !m_isYK1;
        }

        internal static void Init()
        {
            m_isYK1 = Library.Root.Contains("Kiwami");
        }

        public static Player GetPlayer()
        {
            return new Player() { Pointer = ActionFighterManager.GetFighterByIndex(0).Pointer };
        }

        internal static string _LogPath;
        private static void WriteLineColor(string text, ConsoleColor col)
        {
            lock (m_writeLock)
            {

                // m_logWriter.WriteLine(text);
                System.IO.File.AppendAllText(_LogPath, text + "\n");

                Console.ForegroundColor = col;
                Console.WriteLine(text);
                Console.ForegroundColor = ConsoleColor.Gray; //return to normal color or it will do all upcoming writes in this color
            }
        }

        public static void RegisterJob(JobPhase phase, Action action, uint priority = 0)
        {
            RegisterJobDelegate del = new RegisterJobDelegate(action);
            JobRegisterInfo inf = new JobRegisterInfo(action, del, Marshal.GetFunctionPointerForDelegate(del), (uint)phase, priority);
            _jobDelegates.Add(inf);

            OELib_RegisterJob(inf.delPointer, (uint)phase, priority);

            LogInfo("Job for phase " + phase + " registered.");
        }


        static readonly object m_writeLock = new object();
        public static void LogInfo(object text) => WriteLineColor(text.ToString(), ConsoleColor.Cyan);
        public static void LogWarning(object text) => WriteLineColor(text.ToString(), ConsoleColor.Yellow);
        public static void LogError(object text) => WriteLineColor(text.ToString(), ConsoleColor.Red);

        public static bool IsKeyDown(VirtualKey virtualKey)
        {
            return (GetAsyncKeyState((int)virtualKey)) == -32767;
        }

        public static bool IsKeyHeld(VirtualKey virtualKey)
        {
            return (GetAsyncKeyState((int)virtualKey) & 0x8000) == 0x8000;
        }

        [DllImport("user32.dll")]
        private static extern int MessageBox(IntPtr hWnd, String text, String caption, int options);

        [SecurityCritical, HandleProcessCorruptedStateExceptions]
        internal static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            AppDomain.CurrentDomain.UnhandledException -= CurrentDomain_UnhandledException;  // this is important. Any exception occuring in the logging mechanism can cause a stack overflow exception which triggers the window's own JIT message/App crash message if Win JIT is not available.

            Exception ex = e.ExceptionObject as Exception;
            OE.LogInfo("*******************FATAL ERROR***************");
            OE.LogInfo("Inner Exception:\n" + ex.InnerException);
            OE.LogInfo("Message:\n" + ex.Message);
            OE.LogInfo("Stacktrace: \n" + ex.StackTrace);
            MessageBox((IntPtr)0, $"Fatal error! More information available on {Library.Root}/log.txt. The game will now exit", "Fatal OOELibrary Error", 0x00000010);
            Environment.Exit(-1); // exit and avoid WER etc
        }
    }
}
