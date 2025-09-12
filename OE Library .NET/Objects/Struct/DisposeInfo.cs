using System;
using System.Runtime.InteropServices;

namespace OELibrary
{

    [StructLayout(LayoutKind.Explicit, Size = 0xC0)]
    public struct DisposeInfo
    {
        [FieldOffset(0)]
        public Vector4 spawnPosition; //0x0000
        [FieldOffset(0x10)]
        public ChecksumString model; //0x0010
        [FieldOffset(0x38)]
        public int fighterUID; //0x38
        [FieldOffset(0x3C)]
        public short N00001D1D; //0x3C
        [FieldOffset(0x3E)]
        public short N000013EA; //0x3E
        [FieldOffset(0x40)]
        public FixedString32 name; //0x0040
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        [FieldOffset(0x60)]
        public string battleAnim; //0x0060
        [FieldOffset(0x80)]
        public short N0000064F; //0x0082
        [FieldOffset(0x82)]
        public short rotY; //0x0082
        [FieldOffset(0x84)]
        public short N00001D22; //0x0084
        [FieldOffset(0x86)]
        public short N00001D20; //0x0086
        [FieldOffset(0x88)]
        public short N0000060F; //0x0088
        [FieldOffset(0x8A)]
        public NPCType npcType; //0x008A
        [FieldOffset(0x8B)]
        public byte damage; //0x008B
        [FieldOffset(0x8C)]
        public byte N00000651; //0x008C
        [FieldOffset(0x8D)]
        public byte N000013F8; //0x008D
        [FieldOffset(0x90)]
        public int voicer; //0x0090
        [FieldOffset(0xA0)]
        public int weaponID; //0x00A0
    }; //Size: 0x00B4//Size: 0x00AC
}
