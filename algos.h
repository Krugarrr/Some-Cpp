#ifndef ALGOS_H_INCLUDED
#define ALGOS_H_INCLUDED




template<typename Iter, typename P>
bool all_of (Iter start, Iter finish, P predicate)
{
  while (start != finish) {
    if (!predicate(*start))
        return false;
    ++start;
  }
  return true;
}

template<typename Iter, typename P>
bool any_of (Iter start, Iter finish, P predicate)
{
  while (start != finish) {
    if (predicate(*start))
        return true;
    ++start;
  }
  return false;
}

template<typename Iter, typename P>
bool none_of (Iter start, Iter finish, P predicate)
{
  while (start != finish) {
    if (predicate(*start))
        return false;
    ++start;
  }
  return true;
}

template<typename Iter, typename P>
bool one_of(Iter start, Iter finish, P predicate)
{
    Iter i = find_if(start, finish, predicate);
    if (i == finish)
        return false;
    return none_of(++i, finish, predicate);
}

template <typename FIter>
bool is_sorted (FIter start, FIter finish)
{
  if (start == finish)
    return true;
  FIter next = start;
  while (++next != finish) {
    if (*next<*start)
      return false;
    ++start;
  }
  return true;
}

template <typename Iter, typename P>
bool is_partitioned (Iter start, Iter finish, P predicate)
{
  while (start != finish && predicate(*start)) {
    ++start;
  }
  while (start != finish) {
    if (predicate(*start))
        return false;
    ++start;
  }
  return true;
}

template <typename Iter, typename T>
Iter find_not (Iter start, Iter finish, const T& value)
{
  while (start != finish) {
    if (!value(*start))
        return start;
    ++start;
  }
  return finish;
}

template<typename BIter , typename T>
BIter find_backward(BIter start, BIter finish, const T& value)
{

    while (finish != start) {
        if (*finish == value)
            return finish;
        --finish;
    }
    return finish;
}

template <typename BIter , typename P>
bool is_palindrome(BIter start, BIter finish, P predicate)
{
    if(start == finish)
        return true;

    --finish;
    while(start != finish)
    {
        if(!predicate(*start, *finish))
            return false;

        ++start;
        if(start == finish)
            break;

        --finish;
    }
    return true;
}

template<typename Iter, typename P>
Iter find_if (Iter start, Iter finish, P predicate)
{
  while (start != finish) {
    if (pred(*start)) return start;
    ++start;
  }
  return finish;
}


#endif // ALGOS_H_INCLUDED
