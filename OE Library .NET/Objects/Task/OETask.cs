using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public class OETask
    {
        protected bool m_isComplete;
        protected Action m_onComplete;
        protected Func<bool> m_checkDelegate;

        public OETask(Func<bool> checkDelegate, Action onFinished)
        {
            m_checkDelegate = checkDelegate;
            m_onComplete = onFinished;
        }

        public bool IsComplete()
        {
            return m_isComplete;
        }

        public virtual void Update()
        {
            if (m_checkDelegate.Invoke())
                OnComplete();
        }

        protected void OnComplete()
        {
            m_isComplete = true;
            m_onComplete?.Invoke();
        }
    }
}
