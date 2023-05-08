#ifndef __TESTLIB_H__
#define __TESTLIB_H__

typedef enum _TESTLIB_BOOL {
    TESTLIB_FALSE = 0,
    TESTLIB_TRUE = 1
} TESTLIB_BOOL;

typedef enum _TESTLIB_PATTERN {
    PATTERN_AB = 0,
    PATTERN_XY = 1,
    PATTERN_TP = 2,
    PATTERN_NONE = 3
} TESTLIB_PATTERN;

typedef struct _TESTLIB_INFO {
    char Name[64];
    int CameraID;
    long MaxHeight;
    long MaxWidth;

    TESTLIB_BOOL IsColorCam;
    TESTLIB_PATTERN BayerPattern;
    double pixelSize;
} TESTLIB_INFO;

int TestLib_GetInfo(TESTLIB_INFO *info);

#endif // __TESTLIB_H__