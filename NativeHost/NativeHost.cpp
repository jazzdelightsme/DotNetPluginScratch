#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

typedef int (*DoSomethingFunction)(int);

int main( int numArgs, wchar_t* args )
{
    wprintf( L"Hey there!\n" );

    // Let's load a plugin.

    HMODULE hPlugin = LoadLibraryW( L"Plugin.dll" );

    wprintf( L"Plugin loaded: %p\n", hPlugin );

    if( hPlugin )
    {
        DoSomethingFunction dsf = reinterpret_cast<DoSomethingFunction>( GetProcAddress( hPlugin, "DoSomething" ) );

        wprintf( L"Got DoSomething: %p\n", dsf );

        if( dsf )
        {
            wprintf( L"Calling DoSomething...\n" );
            int result = dsf( 42 );
            wprintf( L"DoSomething returned: %d\n", result );
        }
    }

    return 0;
}

