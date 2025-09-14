using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OELibrary
{
    public static class OETaskManager
    {
        private static List<OETask> m_tasksToStart = new List<OETask>();
        private static List<OETask> m_tasks = new List<OETask>();

        public static void Update()
        {
            foreach(var task in m_tasksToStart)
                m_tasks.Add(task);

            m_tasksToStart.Clear();

            List<OETask> incompleteTasks = new List<OETask>();

            foreach(OETask task in m_tasks)
                if(!task.IsComplete())
                    incompleteTasks.Add(task);

            m_tasks = incompleteTasks;

            foreach (OETask task in m_tasks)
                task.Update();
        }

        public static void StartTask(OETask task)
        {
            m_tasksToStart.Add(task);
        }
    }
}
