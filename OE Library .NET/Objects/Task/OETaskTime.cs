using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public class OETaskTime : OETask
    {
        private float m_targetTime;
        private float m_curTime;  

        public OETaskTime(float time, Action onFinished) : base(null, onFinished)
        {
            m_targetTime = time;
            m_onComplete = onFinished;
        }
        public override void Update()
        {
            if (!IsComplete())
            {
                m_curTime += ActionManager.DeltaTime;

                if (m_curTime >= m_targetTime)
                    OnComplete();
            }
        }
    }
}
