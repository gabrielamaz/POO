#ifndef FIBONACCI_H_
#define FIBONACCI_H_


template <class T>
class Fibonacci {
 public:
  Fibonacci<T>();
  static T calculateFibonacci(T num);
};


template <class T>
 T Fibonacci<T>::calculateFibonacci(T num) {
  int fn1 = 1, fn2 = 1;
  int fn, i; 

  if(num < 3) return 1;

  for(i = 3; i <= num; i++) {
    fn = fn2 + fn1;
    fn2 = fn1;
    fn1 = fn;
  }
  return (T) fn;
}

#endif
