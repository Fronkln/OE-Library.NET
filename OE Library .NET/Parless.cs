using System;
using System.Runtime.InteropServices;
using System.Text;

namespace OELibrary
{
    public static class Parless
    {
        [DllImport("YakuzaParless.asi", EntryPoint = "YP_GET_NUM_MODS", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetModCount();

        [DllImport("YakuzaParless.asi", EntryPoint = "YP_GET_MOD_NAME", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr GetModName(int idx);

        [DllImport("YakuzaParless.asi", EntryPoint = "YP_GET_FILE_PATH", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.LPStr)]
        internal static extern string GetFilePathInternal(string filePath);

        [DllImport("YakuzaParless.asi", EntryPoint = "YP_GET_FILE_PATH", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.LPStr)]
        public static extern string GetFilePath2(IntPtr filePathBuf);

        [DllImport("YakuzaParless.asi", EntryPoint = "YP_GET_FILE_PATH", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr GetFilePath3(IntPtr filePathBuf);

        private static IntPtr m_fileNameBuff = Marshal.AllocHGlobal(256);
        public static string GetFilePath(string path)
        {
            Marshal.Copy(new byte[256], 0, m_fileNameBuff, 256);
            byte[] strBuf = Encoding.ASCII.GetBytes(path);
            Marshal.Copy(strBuf, 0, m_fileNameBuff, strBuf.Length);
            string result = Marshal.PtrToStringAnsi(GetFilePath3(m_fileNameBuff));

            return result;
        }
    }
}
