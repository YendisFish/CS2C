# CS2C
This is a small little proof of concept I made that proves
you can now port C libraries to C# without using P/Invokes.
Meaning you can end up with a single binary that runs both
your C and C#! There are a few glue layers included in this
project!

### The Internals Themselves
So the C file itself here is the magic! Our C file actually
calls our C# which also happens to call our C method! The internals
include passing a function pointer from our main C binary
to our C# methods. Upon recieving that pointer our C# binary
invokes it, and by then we have successfully bound our C library
to C#!

### To build this project
I have only tried building this on linux. So I'm not sure how
to build it on windows.

First you need to AOT compile the C#
```sh
dotnet publish /p:NativeLib=Shared -r linux-x64 -o .
```

After this you will have to rename ``CS2C.so`` to ``libCS2C.so``

Next you will need to update ``ld.so.conf``
```sh
echo "/path/to/your/library/directory" | sudo tee -a /etc/ld.so.conf
sudo ldconfig
```

Then you need to compile the C and link the C#
```sh
gcc main.c -L. -lCS2C -o main
```

### My Questions
A few questions come along with this discovery:

- What are the limitations of this method of interop?
- Is this even a good idea?
- What overhead does this eliminate? If any?