////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2016 The isuhao.cn Authors . All Rights Reserved.
// Use of this source code is governed by a Apache-2.0-style license that can be
// found in the LICENSE file.
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "version.h"

#if defined(COMPILER_MSVC)
// We usually use the _CrtDumpMemoryLeaks() with the DEBUGER and CRT library to
// check a memory leak.
#if defined(_DEBUG) && _MSC_VER > 1000 // VC++ DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define  DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#if defined(DEBUG_NEW)
#define new DEBUG_NEW
#endif // DEBUG_NEW
#endif // VC++ DEBUG
#endif // defined(COMPILER_MSVC)

int copyright(int code) {
    printf("Hello world example %s\n"
           "Copyright Suhao <isuhao.cn>, 2016.\n", _VERSION);
    return code;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf ("Hello world.\n");
    } else if ( strcmp(argv[1],"-h") == 0 ||
                strcmp(argv[1],"--help") == 0 ) {
                return usage(0);
    } else {
        printf ("Hi, %s.\n", argv[1]);
    }

    printf( "(version: %s)\n", _VERSION );
    return 0;
}
