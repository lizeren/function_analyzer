
/* std::vector<int, std::allocator<int> >::operator[](unsigned long) const */

long __thiscall
std::vector<int,std::allocator<int>>::operator[](vector<int,std::allocator<int>> *this,long param_1)

{
  return *(long *)this + param_1 * 4;
}

