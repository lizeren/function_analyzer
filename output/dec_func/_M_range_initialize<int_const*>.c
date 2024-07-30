
/* void std::vector<int, std::allocator<int> >::_M_range_initialize<int const*>(int const*, int
   const*, std::forward_iterator_tag) */

void std::vector<int,std::allocator<int>>::_M_range_initialize<int_const*>
               (long *param_1,long param_2,long param_3)

{
  difference_type dVar1;
  undefined4 extraout_var;
  ulong uVar2;
  long lVar3;
  int *piVar4;
  
  dVar1 = distance<int_const*>(param_2,param_3);
  _Vector_base<int,std::allocator<int>>::_M_get_Tp_allocator(param_1);
  uVar2 = _S_check_init_len(CONCAT44(extraout_var,dVar1));
  lVar3 = _Vector_base<int,std::allocator<int>>::_M_allocate
                    ((_Vector_base<int,std::allocator<int>> *)param_1,uVar2);
  *param_1 = lVar3;
  param_1[2] = CONCAT44(extraout_var,dVar1) * 4 + *param_1;
  _Vector_base<int,std::allocator<int>>::_M_get_Tp_allocator(param_1);
  piVar4 = __uninitialized_copy_a<int_const*,int*,int>(param_2,param_3,*param_1);
  param_1[1] = (long)piVar4;
  return;
}

