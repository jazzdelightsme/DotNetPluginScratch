// Plugin.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Plugin.h"


PLUGIN_API int DoSomething(int n)
{
    wprintf( L"Hi, from the [native] plugin (n is %#x).\n", n );
    return 0;
}

