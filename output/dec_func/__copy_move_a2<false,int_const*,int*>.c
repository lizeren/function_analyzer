
/* int* std::__copy_move_a2<false, int const*, int*>(int const*, int const*, int*) */

int * std::__copy_move_a2<false,int_const*,int*>
                (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  void *pvVar1;
  long lVar2;
  void *pvVar3;
  int *piVar4;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_30 = param_3;
  local_28 = param_2;
  local_20 = param_1;
  pvVar1 = (void *)__niter_base<int*>(param_3);
  lVar2 = __niter_base<int_const*>(local_28);
  pvVar3 = (void *)__niter_base<int_const*>(local_20);
  piVar4 = __copy_move_a<false,int_const*,int*>(pvVar3,lVar2,pvVar1);
  piVar4 = (int *)__niter_wrap<int*>(&local_30,piVar4);
  return piVar4;
}

