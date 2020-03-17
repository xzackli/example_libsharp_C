#include <stdio.h>
#include <complex.h>
#include <math.h>

#include <libsharp2/pocketfft.h>
#include <libsharp2/sharp_almhelpers.h>
#include <libsharp2/sharp_geomhelpers.h>
#include <libsharp2/sharp.h>

#include "libsharp2/sharp_utils.h"
#include "libsharp2/sharp_utils.c"


typedef double complex dcmplx;  // complex double type

int main()
{
    int i;

    int nside=4;
    int lmax=4;
    double time=0;
    int spin=0;

    // libsharp configuration structures
    sharp_alm_info *alm_info;
    sharp_geom_info *geom_info;

    // establish alm format and geometry
    sharp_make_triangular_alm_info(lmax,lmax,1,&alm_info);
    sharp_make_healpix_geom_info(nside,1,&geom_info);
    size_t npix = sharp_map_size(geom_info);
    ptrdiff_t nalms = sharp_alm_count(alm_info);
    int ncomp = (spin==0) ? 1 : 2;

    // set up maps and alms
    double **map;
    ALLOC2D(map,double,ncomp,npix);
    for (i=0; i<ncomp; ++i)
        SET_ARRAY(map[i],0,(int)npix, 2.0);

    dcmplx **alm;
    ALLOC2D(alm,dcmplx,ncomp,nalms);
    for (i=0; i<ncomp; ++i)
        SET_ARRAY(alm[i],0,(int)nalms, 0.0);

    // perform the sht
    sharp_execute(
        SHARP_MAP2ALM,spin,&alm[0],&map[0],
        geom_info,alm_info,SHARP_DP,&time,NULL);

    // print out our nice alms!
    for (i=0; i<nalms; ++i)
        printf("%e + i%e\n", creal(alm[0][i]), cimag(alm[0][i]));
    return 0;
}