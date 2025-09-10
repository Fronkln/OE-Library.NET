using System;
using System.Runtime.InteropServices;

namespace OELibrary
{

    [StructLayout(LayoutKind.Sequential, Size = 32)]
    public struct ChecksumString
    {
        ushort checksum; //0x0000
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 30)]
        char[] str; //0x0002

        public override string ToString()
        {
            return str.ToNullTerminatedString();
        }

        public void Set(string val)
        {
            if (str == null || str.Length <= 0)
                str = new char[30];

            char[] valChar = val.ToCharArray();

            int len = (valChar.Length <= 30 ? valChar.Length : 30);

            for (int i = 0; i < len; i++)
                str[i] = valChar[i];
        }
    }
}

