#include "testlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TestLib_GetInfo(TESTLIB_INFO *info)
{
    if (info == NULL)
        return 1;
    snprintf(info->Name, sizeof(info->Name), "TestLib");
    info->CameraID = 0xdeadbeef;
    info->MaxHeight = 1024;
    info->MaxWidth = 1024;

    info->IsColorCam = rand() % 2;
    info->BayerPattern = rand() % 4;
    info->pixelSize = 10;
    return 0;
}