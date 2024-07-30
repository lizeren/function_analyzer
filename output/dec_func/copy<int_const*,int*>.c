
/* int* std::copy<int const*, int*>(int const*, int const*, int*) */

int * std::copy<int_const*,int*>(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int *piVar3;
  
  uVar1 = __miter_base<int_const*>(param_2);
  uVar2 = __miter_base<int_const*>(param_1);
  piVar3 = __copy_move_a2<false,int_const*,int*>(uVar2,uVar1,param_3);
  return piVar3;
}

