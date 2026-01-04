from setuptools import setup, Extension
from Cython.Build import cythonize

# 🚀 Define the Cython extension
# This tells Python how to build the module
# Python list ➜ C array ➜ call C function ➜ result returned 🐍➡️⚡
ext = Extension(
    name='solution',          # 📦 Module name to import in Python
    sources=['solution.pyx'], # 📝 Cython source file
    language='c'              # ⚙️ Compile as C (not C++)
)

# ⚙️ Build configuration
# cythonize: converts .pyx ➜ C code ➜ compiled extension
# language_level=3 ensures Python 3 semantics
setup(
    ext_modules=cythonize(
        ext,
        language_level=3
    )
)