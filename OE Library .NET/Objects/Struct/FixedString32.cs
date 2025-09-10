using System;
using System.Runtime.InteropServices;

namespace OELibrary
{
    [StructLayout(LayoutKind.Sequential)]
    public struct FixedString32
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst =32)]
        char[] str;

        public void Set(string val)
        {
            if (str == null || str.Length <= 0)
                str = new char[32];

            char[] valChar = val.ToCharArray();

            int len = (valChar.Length <= 32 ? valChar.Length : 32);

            for (int i = 0; i < len; i++)
                str[i] = valChar[i];
        }
    }
}
