
/* std::_Vector_base<int, std::allocator<int> >::_M_deallocate(int*, unsigned long) */

void __thiscall
std::_Vector_base<int,std::allocator<int>>::_M_deallocate
          (_Vector_base<int,std::allocator<int>> *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    allocator_traits<std::allocator<int>>::deallocate(this,param_1);
  }
  return;
}

