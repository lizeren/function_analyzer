
/* void std::_Destroy<int*>(int*, int*) */

void std::_Destroy<int*>(void)

{
  _Destroy_aux<true>::__destroy<int*>();
  return;
}

