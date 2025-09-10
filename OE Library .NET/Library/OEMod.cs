using System.Dynamic;

namespace OELibrary
{
    public class OEMod
    {
        public string ModPath { get; internal set; }

        public virtual void OnModInit() { }
    }
}
