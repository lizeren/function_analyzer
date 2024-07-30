
/* std::allocator<int>::~allocator() */

void __thiscall std::allocator<int>::~allocator(void)

{
  __gnu_cxx::new_allocator<int>::~new_allocator();
  return;
}

