#include <stdio.h>
#include <stdlib.h>

class mcp {
  int input_set;
  int excit;
  int inhib;
  int thrs;
  int output;
  int n_ex;
  int n_in;

  mcp::mcp(int n, int m, int thr ) {
    thrs = thr;
    n_ex=n;
    n_in=m;
    input_set=0;
  }

  void set_input(int exc, int inh) {
    excit = exc;
    inhib=inh;
    input_set=1;
    return;    
  }
  
  int compute() {
    if(input_set==0) {
      fprintf(stderr, "Input not set.\n");
      return -1;
    } else {
      int i, j, k;
      j = 0;
      k = excit;
      for(i=0;i<n_ex;i++) {
	j += k&1;
	k >>= 1;
      }
      if ((inhib > 0)||(j < thrs)) {
        output = 0;
      } else {
	output = 1;
      }
      
    }
  }  
};

int main (int argc, char **argv) {
  mcp* xor  = new( 4,4,1);
  xor->set_input(10,6);
  xor->compute();
  return 0;
}
