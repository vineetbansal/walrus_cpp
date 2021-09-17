import numpy as np
import walrus.ext as ext


def test_zero_first():
    # When passing numpy arrays to c++ functions, we need to strictly adhere to the appropriate dtype
    x = np.arange(1, 21).reshape(5, 4).astype('double')

    ext.zero_first(x)
    assert 0 == x[0, 0]
