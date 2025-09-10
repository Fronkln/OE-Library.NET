using System;

namespace OELibrary
{
    public class OEBase
    {
        private IntPtr _ptr;
        public IntPtr Pointer { get { return _ptr; } set { _ptr = value; Precache(); } }

        protected virtual void Precache() { }
    }
}
