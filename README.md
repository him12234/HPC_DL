# HPC_DL
For running openmp programs run commands:-
g++ filename.cpp -fopenmp and ./a.exe [for windows users] or ./a.out [for linux users]

Make sure MinGW is installed with pthreads.

If you still get errors try running: mingw-get upgrade --recursive "gcc<4.7.*" "gcc-g++<4.7.*"

To run CUDA programs on Collab, follow these steps:
Go to Google Collab
Create a new Notebook(.ipynb file).
Click on Runtime and change runtime type to GPU.
Now run !pip install git+https://github.com/afnan47/cuda.git in a cell.
On a new cell run %load_ext nvcc_plugin
Test the following code
%%cu
#include <iostream>
int main(){
  std::cout << "Hello World\n";
  return 0;
}
Remember to add %%cu before writing the C++ code for every CUDA program. CUDA is now set.
Click here for detailed steps
