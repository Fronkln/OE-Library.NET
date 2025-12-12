using OELibrary.Unsafe;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public static class Save
    {
        private delegate int GetSaveHeaderValue();
        private static GetSaveHeaderValue _GetSaveHeaderValueFunc;

        static Save()
        {
            //this is so ass holy shit
            //TODO: Move this to an export in SequenceManager, this value is stored at 0x6D4 in mission data
            //_GetSaveHeaderValueFunc = Marshal.GetDelegateForFunctionPointer<GetSaveHeaderValue>(CPP.PatternSearch("48 8B 05 ? ? ? ? 48 8B 48 50 8B 81 D4 06 00 00"));
        }

        public static int CurrentChapter
        {
            get
            {
                //this is so ass holy shit
                int value = SequenceManager.SaveHeaderValues;
                return BitConverter.GetBytes(value)[2];
            }
        }
    }
}
