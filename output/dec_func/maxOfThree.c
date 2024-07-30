
/* maxOfThree(int, int, int) */

int maxOfThree(int param_1,int param_2,int param_3)

{
  if (param_2 < param_1) {
    if (param_3 < param_1) {
      param_3 = param_1;
    }
  }
  else if (param_3 < param_2) {
    param_3 = param_2;
  }
  return param_3;
}

