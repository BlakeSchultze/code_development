# code_development: Overview
This repository was created for rapidly developing and testing code snippets and algorithms prior to their integration within a larger C/C++/CUDA project, particularly those projects which form an expansive code base and/or are deployed to HPC cluster architectures. This provides a template from which branched development for various repos can be initialized. This is an atypical use case, only for those cases where branching from the source repo burdens or obscures the development of specific features due to source code overhead and indivisible dependencies/relationships.   

## Usage Scheme
Branching from this repo provides an isolated testbed for micro-unit development. This is initiated at the highest possible granularity (including only crucial portions of the source repo) and incrementally expanded with source repo code until micro-unit development is sufficiently solid to confidently incorporate into a branch of the source repo and merge in       

### New Project Branching
New branch development is incorporated by adding a .h/.cpp pair dedicated to this project (w/ includes || to main()).  

### NOTE: 
This has been especially useful for redesigning the pCT project's console printing/logging routines and the development of the AKS prime number eval algorithm.
