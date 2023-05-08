#include <stdio.h>
#include "testlib.h"

int main()
{
    TESTLIB_INFO info;
    TestLib_GetInfo(&info);
    printf("Name: %s\n", info.Name);
    printf("CameraID: 0x%x\n", info.CameraID);
    printf("MaxHeight: %ld\n", info.MaxHeight);
    printf("MaxWidth: %ld\n", info.MaxWidth);
    printf("IsColorCam: %d\n", info.IsColorCam);
    printf("BayerPattern: %d\n", info.BayerPattern);
    printf("pixelSize: %f\n", info.pixelSize);
    return 0;
}