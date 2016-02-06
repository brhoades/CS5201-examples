#include <iostream>
#include "movesemantics.h"
#include "regular.h"
using namespace std;

template <class T>
T some_func(T in) { return in; }

template <class T>
void run_example()
{
  cout << "  First Part" << endl;
  T b;
  T c(some_func<T>(b));

  cout << endl << "  Second Part" << endl;
  b = some_func<T>(c);

  cout << endl << "  Third Part" << endl;
  b = move(c);
  T d(move(b));

  cout << endl << "  Fourth Part" << endl;
  
  int i = 5;
  T e(i);
  e = 4;

  cout << "  TOTALS: " << endl;
  T::get_summary();
}

int main()
{
  cout << "No Move Semantics Example: " << endl << endl;
  run_example<Regular>();
  cout << endl << endl << "With Move Semantics: " << endl << endl;
  run_example<MoveSemantics>();
  return 0;
}
