#ifndef VERSION
#define VERSION

#include "fly/base/common.hpp"

/* version structure
 -  
 -                        3  3   4
 -                        |  |   |
 -                        |  |   |
 -                        | ---  |
 -                       ---   ----
 - max version (uint32): 4294967295
 */
static const uint32 ASKCOIN_VERSION = 1; //3 3 4
static const char* ASKCOIN_VERSION_NAME = "0.0.1"; //major.minor.revision: 3 3 4

static bool version_compatible(uint32 ver_a, uint32 ver_b)
{
    uint32 major_a = ver_a / 10000000;
    uint32 major_b = ver_b / 10000000;

    if(major_a != major_b)
    {
        return false;
    }

    uint32 minor_a = (ver_a % 10000000) / 10000;
    uint32 minor_b = (ver_b % 10000000) / 10000;

    return minor_a == minor_b;
}

static void version_extract(uint32 ver, uint32 &major, uint32 &minor, uint32 &revision)
{
    major = ver / 10000000;
    minor = (ver % 10000000) / 10000;
    revision = ver % 10000;
}

#endif
