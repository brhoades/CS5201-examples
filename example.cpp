// Billy Rhoades
// 2/4/16
// Example of Move Semantics and constructor delegation for CS5201
//
// Compile with g++ -std=c++11 move_semantics.cpp

#include <iostream>

#include "movesemantics.h"
#include "regular.h"
using namespace std;

template <class T>
T some_func(T in);

template <class T>
void run_example();

class Regular;
class MoveSemantics;

int main()
{
  cout << "No Move Semantics Example: " << endl << endl;
  // Do this with the regular class
  run_example<Regular>();

  cout << endl << endl << "With Move Semantics: " << endl << endl;
  // Do this with the move semantics class.
  run_example<MoveSemantics>();

  return 0;
}

// Some function where an object is copied in and then returned.
template <class T>
T some_func(T in)
{
  // makes a rhs copy of in
  return in;
}

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

