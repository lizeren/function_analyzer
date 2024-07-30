
undefined8 main(void)

{
  basic_ostream *pbVar1;
  basic_ostream<char,std::char_traits<char>> *pbVar2;
  long in_FS_OFFSET;
  undefined local_75;
  int local_74;
  int local_70;
  int local_6c;
  long local_68 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_74 = maxOfThree(10,0x14,0x1e);
  pbVar1 = std::operator<<((basic_ostream *)std::cout,"Max of 10, 20, 30 is: ");
  pbVar2 = (basic_ostream<char,std::char_traits<char>> *)
           std::basic_ostream<char,std::char_traits<char>>::operator<<
                     ((basic_ostream<char,std::char_traits<char>> *)pbVar1,local_74);
  std::basic_ostream<char,std::char_traits<char>>::operator<<
            (pbVar2,(_func_basic_ostream_ptr_basic_ostream_ptr *)
                    PTR_endl<char,std_char_traits<char>>_00104fd0);
  local_48 = 1;
  local_44 = 2;
  local_40 = 3;
  local_3c = 0xfffffffc;
  local_38 = 5;
  std::allocator<int>::allocator();
                    /* try { // try from 0010147f to 00101483 has its CatchHandler @ 00101540 */
  std::vector<int,std::allocator<int>>::vector(local_68,&local_48,5,&local_75);
  std::allocator<int>::~allocator();
  local_70 = findFirstNegative(local_68);
                    /* try { // try from 001014ad to 0010151b has its CatchHandler @ 0010155e */
  pbVar1 = std::operator<<((basic_ostream *)std::cout,"First negative index: ");
  pbVar2 = (basic_ostream<char,std::char_traits<char>> *)
           std::basic_ostream<char,std::char_traits<char>>::operator<<
                     ((basic_ostream<char,std::char_traits<char>> *)pbVar1,local_70);
  std::basic_ostream<char,std::char_traits<char>>::operator<<
            (pbVar2,(_func_basic_ostream_ptr_basic_ostream_ptr *)
                    PTR_endl<char,std_char_traits<char>>_00104fd0);
  local_6c = countPrimes(10);
  pbVar1 = std::operator<<((basic_ostream *)std::cout,"Number of primes up to 10: ");
  pbVar2 = (basic_ostream<char,std::char_traits<char>> *)
           std::basic_ostream<char,std::char_traits<char>>::operator<<
                     ((basic_ostream<char,std::char_traits<char>> *)pbVar1,local_6c);
  std::basic_ostream<char,std::char_traits<char>>::operator<<
            (pbVar2,(_func_basic_ostream_ptr_basic_ostream_ptr *)
                    PTR_endl<char,std_char_traits<char>>_00104fd0);
  std::vector<int,std::allocator<int>>::~vector((vector<int,std::allocator<int>> *)local_68);
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

