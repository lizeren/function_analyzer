
/* findFirstNegative(std::vector<int, std::allocator<int> > const&) */

int findFirstNegative(long *param_1)

{
  ulong uVar1;
  int *piVar2;
  int local_1c;
  
  local_1c = 0;
  while( true ) {
    uVar1 = std::vector<int,std::allocator<int>>::size(param_1);
    if (uVar1 <= (ulong)(long)local_1c) {
      return -1;
    }
    piVar2 = (int *)std::vector<int,std::allocator<int>>::operator[]
                              ((vector<int,std::allocator<int>> *)param_1,(long)local_1c);
    if (*piVar2 < 0) break;
    local_1c = local_1c + 1;
  }
  return local_1c;
}

