/****************************************************************************
*   PROJECT: Squeak port for Win32 (NT / Win95)
*   FILE:    sqWin32ExternalPrims.c
*   CONTENT: External (named) primitive support
*
*   AUTHOR:  Andreas Raab (ar)
*   ADDRESS: University of Magdeburg, Germany
*   EMAIL:   raab@isg.cs.uni-magdeburg.de
*   RCSID:   $Id: sqWin32ExternalPrims.c 1224 2005-06-22 07:31:28Z bernd $
*
*   NOTES:
*     1) Currently, we're looking for DLLs named either sample.dll or sample32.dll
*
*****************************************************************************/
#include <stdio.h>
#include "sq.h"

/* Return the module entry for the given module name */
void *ioLoadModule(char *pluginName)
{
	return NULL;
}

void *ioFindExternalFunctionIn(char *lookupName, void *moduleHandle)
{
	return NULL;
}

sqInt ioFreeModule(void *moduleHandle)
{
	return 0;
}
