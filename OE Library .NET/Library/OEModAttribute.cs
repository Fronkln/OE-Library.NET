using System;

namespace OELibrary
{
    [AttributeUsage(AttributeTargets.Assembly)]
    public class OEModAttribute : Attribute
    {
        public string ModName;
        public string Author;
        public Type ModType;

        public OEModAttribute(string modName, string author, Type modType)
        {
            ModName = modName;
            Author = author;
            ModType = modType;
        }
    }
}
