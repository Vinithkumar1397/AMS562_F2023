#include <cmath>
#include <cstdlib>
#include <ctime>  // for trigger the seed of random number generator
#include <iostream>

using namespace std;

static void genPointsOnUnitSphere(const int N, float *x, float *y, float *z);
// Function to compute arc length between two points
float compArcLength(float x1, float y1, float z1, float x2, float y2, float z2){
  return acos(x1*x2 + y1*y2 + z1*z2);
}

int main(int argc, char *argv[]) {
  // parse input argc/argv
  if(argc < 2){
    cerr << "The value of N is not entered\n";
    return 1;
  }

  int N = atoi(argv[1]);
  // get the size of N

  if(N < 2){
    cerr << "N has to be atleast 2 for computing arc lengths\n";
    return 1;
  }

  float *x = nullptr, *y = nullptr, *z = nullptr;
  // allocate memory for x, y, z
  x = new float[N];
  y = new float[N];
  z = new float[N];

  genPointsOnUnitSphere(N, x, y, z);// generate random points on the unit sphere

  // determine the extreme arc lengths

  cout<<"First point is ("<< x[0] <<" ,"<<y[0]<<" ,"<<z[0]<<")\n";
  float maxlen = 0.0, minlen = 10.0, arclength;
  int maxindex, minindex;

  for(int i = 1; i < N; i++){
    arclength = compArcLength(x[0],y[0],z[0],x[i],y[i],z[i]);
    if(arclength > maxlen){
      maxlen = arclength;
      maxindex = i;
    }
    if(arclength < minlen){
      minlen = arclength;
      minindex = i;
    }
  }

  cout<<"Max arc length - "<<maxlen<<" with coordinates : "<< x[maxindex] <<" ,"<<y[maxindex]<<" ,"<<z[maxindex]<<")\n";
  cout<<"Min arc length - "<<minlen<<" with coordinates : "<< x[minindex] <<" ,"<<y[minindex]<<" ,"<<z[minindex]<<")\n";
  // relax memory
  delete[] x;
  delete[] y;
  delete[] z;

  return 0;
}

// black-box function to generate a collection of random points
void genPointsOnUnitSphere(const int N, float *x, float *y, float *z) {
  if (x == nullptr || y == nullptr || z == nullptr || N <= 0) {
    std::cerr << "invalid pointers or size, aborting...\n";
    std::exit(1);
  }
  std::srand(std::time(0));  // trigger the seed
  const int BD = 10000000, BD2 = 2 * BD;
  const float inv_bd = 1.0f / BD;  // not integer division
  for (int i = 0; i < N; ++i) {
    x[i] = (std::rand() % BD2 - BD) * inv_bd;
    y[i] = (std::rand() % BD2 - BD) * inv_bd;
    z[i] = (std::rand() % BD2 - BD) * inv_bd;
    const float len = std::sqrt(x[i] * x[i] + y[i] * y[i] + z[i] * z[i]);
    if (len > 1e-5f) {
      // project on to unit sphere
      x[i] /= len;
      y[i] /= len;
      z[i] /= len;
    } else {
      // too close to zero
      // directly set the point to be (1,0,0)
      x[i] = 1.0f;
      y[i] = z[i] = 0.0f;
    }
  }
}
