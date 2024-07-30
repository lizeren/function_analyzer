
/* std::initializer_list<int>::end() const */

long std::initializer_list<int>::end(undefined8 *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = begin(param_1);
  lVar2 = size((long)param_1);
  return lVar2 * 4 + lVar1;
}

