[![Main](https://github.com/vineetbansal/walrus/actions/workflows/main.yml/badge.svg?branch=master)](https://github.com/vineetbansal/walrus/actions/workflows/main.yml)

# walrus 

This is a sample python package meant as a boilerplate project leveraging C++/CMake for python extensions through
Pybind11, while exercising commonly applicable testing/CI practices.

I'll try to keep this updated as CIs evolve and try to improve things, but no
guarantees. If the badges you see here are green, then things are probably still working.

View the [documentation](https://vineetbansal.github.io/walrus/).

### Installation

#### Anaconda
```
conda env create -f environment.yml
conda activate walrus 
pip install -e .
```

#### VirtualEnv
```
python -m venv env
source env/bin/activate
pip install -e .
```

### What's happening here?

`walrus` is a simple Python package that has a single function `hello()`. All the rest of the functionality
is in the `walrus.ext` submodule (as a sub-folder `carpenter`), which wraps a C++ shared library.
In the `carpenter` sub-folder (look for `bindings.cpp` if you want to know what's exposed to Python), you'll find a
simple `add` function, an example of manipulating a numpy array. A simple `subtract` function is implemented
right inside `bindings.cpp`.
