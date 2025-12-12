using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary.Advanced
{
    public static class ImGui
    {
        internal delegate void DX11Present();
        private static List<DX11Present> _dx11Delegates = new List<DX11Present>();

        public static bool toInit = false;

        public static void RegisterUIUpdate(Action func)
        {
            DX11Present del = new DX11Present(func);
            _dx11Delegates.Add(del);

            DXHook.DELibrary_DXHook_RegisterPresentFunc(Marshal.GetFunctionPointerForDelegate(del));
        }

        public static void Init()
        {
            DXHook.Init();
        }
    }
}
