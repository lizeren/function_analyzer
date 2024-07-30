
/* std::vector<int, std::allocator<int> >::_S_check_init_len(unsigned long, std::allocator<int>
   const&) */

ulong std::vector<int,std::allocator<int>>::_S_check_init_len(ulong param_1)

{
  long lVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  allocator<int>::allocator();
  uVar2 = _S_max_size();
  allocator<int>::~allocator();
  if (uVar2 < param_1) {
    std::__throw_length_error("cannot create std::vector larger than max_size()");
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}

