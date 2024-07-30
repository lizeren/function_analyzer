
/* std::iterator_traits<int const*>::difference_type std::__distance<int const*>(int const*, int
   const*, std::random_access_iterator_tag) */

long std::__distance<int_const*>(long param_1,long param_2)

{
  return param_2 - param_1 >> 2;
}

