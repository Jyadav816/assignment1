#include <iostream>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


#ifdef __cplusplus
extern "C" {
#endif
    
    float f1(float x, int intensity);
    float f2(float x, int intensity);
    float f3(float x, int intensity);
    float f4(float x, int intensity);
    
#ifdef __cplusplus
}
#endif

double calc_numerical_integration(int functionid, int a, int b, int n, int intensity) {
    double total = 0.0;
    double right = (b - a) / n;
    float x; 
    clock_t t;
	  t = clock() - t;
	for(int i = 0; i < n; i++) {
	    x = a + (i + 0.5) * right;
	    total += f(x, intensity) * right;
	}
    
    double time_taken = (t)/(double) CLOCKS_PER_SEC;
    cout << time_taken << endl;
	return total;
}

int main (int argc, char* argv[]) {
    if (argc < 6) {
        cout <<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<< endl;
        return -1;
    }
    
    int functionid = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int n = atoi(argv[4]);
    int intensity = atoi(argv[5]);
    double total = 0.0;
    
    if (functionid == "f1") {
          total = calc_numerical_integration(f1,a,b,n,intensity);
      }
      else if (functionid == "f2") {
          total = calc_numerical_integration(f2, a,b,n,intensity);
      }
      else if (functionid == "f3") {
          total = calc_numerical_integration(f3, a,b,n,intensity);
      }
      else {
          total = calc_numerical_integration(f4, a,b,n,intensity);
      }
      
      cout << total << endl;
      return 0;
}