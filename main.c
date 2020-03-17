#include <stdio.h>
#include <complex.h>
#include <math.h>

#include <libsharp2/pocketfft.h>
#include <libsharp2/sharp_almhelpers.h>
#include <libsharp2/sharp_geomhelpers.h>
#include <libsharp2/sharp.h>

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

    // set up 2D arrays of maps and alms
    double **map;
    map = (double **) malloc(ncomp * sizeof(double *));
    map[0] = (double *) malloc(ncomp * npix * sizeof(double));
    for (i=1; i<ncomp; ++i)
        (map)[i]=(map)[i-1]+npix; 
    for (i=0;i<(int)(npix * ncomp);++i)
        (map[0])[i]=2.0;  // initialize all components to 2.0

    dcmplx **alm;
    alm = (dcmplx **) malloc(ncomp * sizeof(dcmplx *));
    alm[0] = (dcmplx *) malloc(ncomp * nalms * sizeof(dcmplx));
    for (i=1; i<ncomp; ++i)
        (alm)[i]=(alm)[i-1]+nalms; 
    for (i=0;i<(int)(nalms * ncomp);++i)
        (alm[0])[i]=0.0;  // we didn't need to do this, but set alms=0

    // perform the sht
    sharp_execute(
        SHARP_MAP2ALM,spin,&alm[0],&map[0],
        geom_info,alm_info,SHARP_DP,&time,NULL);

    // print out our nice alms!
    for (i=0; i<nalms; ++i)
        printf("%e + i%e\n", creal(alm[0][i]), cimag(alm[0][i]));

    return 0;
}