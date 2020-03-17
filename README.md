# LibSharp Example (C)

This example code demonstrates how to set up and perform map2alm using LibSharp on a Healpix grid.

This uses the [GitLab](https://gitlab.mpcdf.mpg.de/mtr/libsharp/tree/master) version. You can test the output of this code against 

```python
import healpy as hp
import numpy as np

hp.map2alm( 2*np.ones(hp.nside2npix(4)), lmax=4, mmax=4, iter=0 )
```
