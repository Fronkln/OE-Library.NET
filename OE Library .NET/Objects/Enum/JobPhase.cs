using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public enum JobPhase
    {
        SystemAboveNormal,
        SystemNormal,
        BeforeCameraNormal,
        BeforeCameraBelowNormal,
        Camera,
        SystemCullingSetup,
        AfterCameraHigh,
        AfterCameraAboveNormal,
        AfterCameraNormal,
        AfterCameraBattle,
        AfterCameraBattle2,
        AfterCameraBattle3,
        AfterCameraWanderer,
        AfterCameraNormal2,
        AfterCameraBelowNormal,
        AfterCameraLow,
        StaticCollisionUpdate,
        StaticCollisionDynamicsUpdate,
        BeforePhysicsHigh,
        BeforePhysicsBelowNormal,
        BeforePhysicsLow,
        PhysicsSetup,
        Physics,
        AfterPhysicsHigh,
        AfterPhysicsAboveNormal,
        AfterPhysicsBattle,
        AfterPhysicsBattle2,
        AfterPhysicsBattle3,
        StageCullingPhase1,
        StageCullingBetween,
        AfterPhysicsNormal,
        AfterPhysicsNormal2,
        AfterPhysicsBelowNormal,
        AfterPhysicsLow,
        Visible,
        VisibleManagerVisibleSetup,
        AfterVisibleHigh,
        AfterVisibleCloth,
        AfterVisibleAboveNormal,
        AfterVisibleNormal,
        WandererUpdate,
        StageClipSetupBefore,
        SetupClipSetupNormal,
        StageClipSetupAfter,
        ParallelDraw,
        Render,
        Cleanup,
        SystemSync
    }
}
