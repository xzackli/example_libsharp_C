#include <stdio.h>
#include<math.h>

#include <libsharp2/pocketfft.h>
#include <libsharp2/sharp_almhelpers.h>
#include <libsharp2/sharp_geomhelpers.h>
#include <libsharp2/sharp.h>

#define MAX_SHT 1

int main()
{

    sharp_alm_info *alm_info;
    sharp_geom_info *geom_info;
    int flags=SHARP_DP;

    int nside=4;
    int lmax=8;
    sharp_make_triangular_alm_info(lmax,lmax,1,&alm_info);
    sharp_make_weighted_healpix_geom_info(nside,1,NULL,&geom_info);

    printf("Hello, World.\n");
    fflush(stdout);
 
    return 0;
}