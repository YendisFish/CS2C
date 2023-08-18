using System.Runtime.InteropServices;

namespace CS2C;

public unsafe class Program
{
    [UnmanagedCallersOnly(EntryPoint = "RunCS")]
    public static char * RunCS(delegate*<char *, char *> Foo, char *ptr)
    {
        try 
        {
            char *c = Foo(ptr);
            //Console.WriteLine(((char *)ptr.ToPointer())[0]);

            return c;
        } catch
        {
            char x = '\0';
            return &x;
        }
    }

}