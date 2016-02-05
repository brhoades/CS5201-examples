// Billy Rhoades
// 2/4/16
// Example of Move Semantics and constructor delegation for CS5201
//
// Compile with g++ -std=c++11 move_semantics.cpp

#include <iostream>
using namespace std;

class MoveSemantics
{
  public:
    // Default constructor, just makes an int pointer as a member.
    MoveSemantics()
    {
      m_example_member = new int;
      *m_example_member = 0;

      cout << "    Default Constructor Called" << endl;
    }

    // Parameterized constructor which takes an integer, delegates to example
    // to prepare memory then assigns the value.
    MoveSemantics(const int example_member): MoveSemantics()
    {
      cout << "    Parameterized Constructor Called" << endl;

      *m_example_member = example_member;
    }

    // Move constructor called. Destroys the other side's member variable
    // as it's going to be deallocated anyway.
    MoveSemantics(MoveSemantics&& ex)
    {
      cout << "    Move Constructor" << endl;
      m_example_member = ex.m_example_member;
      ex.m_example_member = nullptr; // Oh, uh, this is the new C++11 constant for 0.
                                     // You can use this with pure virtual functions too.
    }

    // Boring copy constructor, also delegating to default to set up memory.
    MoveSemantics(const MoveSemantics& ex): MoveSemantics()
    {
      cout << "    Copy Constructor (" << ++cp_times << " times)" << endl;
      *m_example_member = *ex.m_example_member;
    }

    // Boring Destructor 
    ~MoveSemantics()
    {
      delete m_example_member;
    }

    // Our move assignment operator. It trashes the example passed in.
    MoveSemantics& operator=(MoveSemantics&& ex)
    {
      cout << "    Move Assignment Operator" << endl;
      m_example_member = ex.m_example_member;
      ex.m_example_member = nullptr;

      return *this;
    }

    // Copy assignment operator, nothing special here.
    MoveSemantics& operator=(const MoveSemantics& ex)
    {
      cout << "  Copy Assignment Operator" << endl;
      *m_example_member = *ex.m_example_member;

      return *this;
    }

  private:
    int* m_example_member;
    static int cp_times;
};

class Regular
{
  public:
    // Default constructor, just makes an int pointer as a member.
    Regular()
    {
      m_example_member = new int;
      *m_example_member = 0;

      cout << "    Default Constructor Called" << endl;
    }

    // Parameterized constructor which takes an integer, delegates to example
    // to prepare memory then assigns the value.
    Regular(const int example_member): Regular()
    {
      cout << "    Parameterized Constructor Called" << endl;

      *m_example_member = example_member;
    }

    // Boring copy constructor, also delegating to default to set up memory.
    Regular(const Regular& ex): Regular()
    {
      cout << "    Copy Constructor (" << ++cp_times << " times)" << endl;
      *m_example_member = *ex.m_example_member;
    }

    // Boring Destructor 
    ~Regular()
    {
      delete m_example_member;
    }

    // Copy assignment operator, nothing special here.
    Regular& operator=(const Regular& ex)
    {
      cout << "    Copy Assignment Operator" << endl;
      *m_example_member = *ex.m_example_member;

      return *this;
    }

  private:
    int* m_example_member;
    static int cp_times;
};


int MoveSemantics::cp_times = 0;
int Regular::cp_times = 0;

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
}

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

