from setuptools import setup, find_packages, Extension
from os import path
import os

module_name = "pypath"

here = path.abspath(path.dirname(__file__))
# Get the long description from the README file
with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

sources_files = []
for r, d, f in os.walk(here + "/castar/src/"):
    for file in f:
        if '.cpp' in file:
            sources_files.append(os.path.join(r, file))
print(sources_files)
castar = Extension(module_name +".castar",
                    include_dirs = [here + "/castar/src/", here + "/castar/src/pybind11"],
                    sources=sources_files)

setup(
    name=module_name + "-fpa", # change name for pypi not module
    version='0.2.0',
    description='Fast pathfinding algorithme',
    long_description=long_description,
    long_description_content_type='text/markdown',
    url='https://github.com/bcluzel/pypath', 
    author='Baptiste CLUZEL',
    author_email='baptiste.clu@gmail.com',  
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Intended Audience :: Developers',
        'Topic :: Scientific/Engineering :: GIS',
        'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
        'Programming Language :: Python :: 3'
    ],
    keywords='pathfinding fast astar A* a*',
    packages=find_packages(),
    python_requires='>=3.5',
    install_requires=['pybind11'],
    project_urls={ 
        'Bug Reports': 'https://github.com/bcluzel/pypath/issues',
        'Source': 'https://github.com/bcluzel/pypath'
    },
    ext_modules = [castar]
)