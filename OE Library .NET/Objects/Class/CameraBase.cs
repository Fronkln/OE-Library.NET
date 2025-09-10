using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public class CameraBase : Entity
    {
        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_GETTER_CURRENT_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Vector4 OELib_CameraBase_Getter_CurrentPosition(IntPtr cam);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_SETTER_CURRENT_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_CameraBase_Setter_CurrentPosition(IntPtr cam, Vector4 pos);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_GETTER_FOCUS_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Vector4 OELib_CameraBase_Getter_FocusPosition(IntPtr cam);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_SETTER_FOCUS_POSITION", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_CameraBase_Setter_FocusPosition(IntPtr cam, Vector4 pos);


        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_GETTER_MATRIX", CallingConvention = CallingConvention.Cdecl)]
        internal static extern Matrix4x4 OELib_CameraBase_Getter_Matrix(IntPtr cam);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_GETTER_FOV", CallingConvention = CallingConvention.Cdecl)]
        internal static extern float OELib_CameraBase_Getter_FOV(IntPtr cam);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_SETTER_FOV", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_CameraBase_Setter_FOV(IntPtr cam, float fov);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_GETTER_NEAR_CLIP", CallingConvention = CallingConvention.Cdecl)]
        internal static extern float OELib_CameraBase_Getter_NearClip(IntPtr cam);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_SETTER_NEAR_CLIP", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_CameraBase_Setter_NearClip(IntPtr cam, float fov);


        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_GETTER_FAR_CLIP", CallingConvention = CallingConvention.Cdecl)]
        internal static extern float OELib_CameraBase_Getter_FarClip(IntPtr cam);

        [DllImport("OE Library.dll", EntryPoint = "OE_LIB_CCAMERABASE_SETTER_FAR_CLIP", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void OELib_CameraBase_Setter_FarClip(IntPtr cam, float fov);

        public new Vector3 Position
        {
            get
            {
                return OELib_CameraBase_Getter_CurrentPosition(Pointer);
            }
            set
            {
                OELib_CameraBase_Setter_CurrentPosition(Pointer, value);
            }
        }

        public Vector3 FocusPosition
        {
            get
            {
                return OELib_CameraBase_Getter_FocusPosition(Pointer);
            }
            set
            {
                OELib_CameraBase_Setter_FocusPosition(Pointer, value);
            }
        }

        public Matrix4x4 Matrix
        {
            get
            {
                return OELib_CameraBase_Getter_Matrix(Pointer);
            }
        }

        public float FieldOfView
        {
            get
            {
                return OELib_CameraBase_Getter_FOV(Pointer);
            }
            set
            {
                OELib_CameraBase_Setter_FOV(Pointer, value);
            }
        }

        public float NearClip
        {
            get
            {
                return OELib_CameraBase_Getter_NearClip(Pointer);
            }
            set
            {
                OELib_CameraBase_Setter_NearClip(Pointer, value);
            }
        }

        public float FarClip
        {
            get
            {
                return OELib_CameraBase_Getter_FarClip(Pointer);
            }
            set
            {
                OELib_CameraBase_Setter_FarClip(Pointer, value);
            }
        }
    }
}
