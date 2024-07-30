
/* countPrimes(int) */

int countPrimes(int param_1)

{
  bool bVar1;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  local_10 = 2;
  do {
    if (param_1 < local_10) {
      return local_14;
    }
    bVar1 = true;
    for (local_c = 2; local_c * local_c <= local_10; local_c = local_c + 1) {
      if (local_10 % local_c == 0) {
        bVar1 = false;
        break;
      }
    }
    if (bVar1) {
      local_14 = local_14 + 1;
    }
    local_10 = local_10 + 1;
  } while( true );
}

