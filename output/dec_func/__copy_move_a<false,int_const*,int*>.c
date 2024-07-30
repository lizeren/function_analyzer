
/* int* std::__copy_move_a<false, int const*, int*>(int const*, int const*, int*) */

int * std::__copy_move_a<false,int_const*,int*>(void *param_1,long param_2,void *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)__copy_move<false,true,std::random_access_iterator_tag>::__copy_m<int>
                            (param_1,param_2,param_3);
  return piVar1;
}

