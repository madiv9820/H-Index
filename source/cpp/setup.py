from setuptools import setup, Extension
from Cython.Build import cythonize

# 🚀 What does this file do?
# This script builds the Cython extension module that links Python 🐍
# with a C++ ⚡ implementation. It compiles solution.pyx into a
# Python-importable module named `solution`.

# 📦 Define the Cython extension module
# - name: module name used when importing in Python
# - sources: Cython source file (.pyx)
# - language: use C++ compiler
ext = Extension(
    name='solution',
    sources=['solution.pyx'],
    language='c++'
)

# ⚙️ Build configuration
# - cythonize: converts .pyx ➜ C/C++ code
# - language_level=3: ensures Python 3 behavior
setup(
    ext_modules=cythonize(
        ext,
        language_level=3
    )
)