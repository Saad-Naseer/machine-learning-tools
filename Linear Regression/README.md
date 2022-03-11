## Tool to perfrom linear Regression
### Step 1: To run this need you need to insatll some libraries :
 #### Step 1.1 : To install eigen libraries for vectors and matrices operation:
  $ sudo apt install libeigen3-dev
 #### Step 1.2 To upgrade your cmake (minimum required 3.15):
  $ sudo apt remove cmake\
  $ sudo apt-get install libssl-dev
  ##### Download tar file from https://cmake.org/download/. Extract the downloaded tar file and then:
   $ cd <CMAKE_DOWNLOAD_PATH>\
   $ ./configure\
   $ make\
   $ sudo make install
 #### Step 1.3 To install matplotlib, numpy and python2.7:
  $ sudo apt-get install python-matplotlib python-numpy python2.7-dev
### Step 2: Cone the repository and build the program either with g++ or cmake and run the output :
  $ git clone https://github.com/Saad-Naseer/machine-learning-tools.git
  ##### Build with g++ :
  $ cd <Linear_Regression_directory_path>\
  $ cd src/\
  $ g++ l_regression.cpp -std=c++11 -I/usr/local/include/python2.7   -I/usr/local/lib/python2.7/site-packages/numpy/core/include -lpython2.7\
  $ ./a.out\
  ##### Build with cmake
  $ cd <Linear_Regression_directory_path>\
  $ mkdir build\
  $ cd build/\
  $ cmake ..\
  $ make\
  $ ./least_square 

