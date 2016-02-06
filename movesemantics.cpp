#include <iostream>

#include "movesemantics.h"
using namespace std;

int MoveSemantics::m_cp_times = 0;
int MoveSemantics::m_def_times = 0;

// Default constructor, just makes an int pointer as a member.
MoveSemantics::MoveSemantics()
{
  m_example_member = new int;
  *m_example_member = 0;

  cout << "    Default Constructor Called (" << ++m_def_times << " times)" << endl;
}

// Parameterized constructor which takes an integer, delegates to example
// to prepare memory then assigns the value.
MoveSemantics::MoveSemantics(const int example_member): MoveSemantics()
{
  cout << "    Parameterized Constructor Called" << endl;

  *m_example_member = example_member;
}

// Move constructor called. Destroys the other side's member variable
// as it's going to be deallocated anyway.
MoveSemantics::MoveSemantics(MoveSemantics&& ex)
{
  cout << "    Move Constructor" << endl;
  m_example_member = ex.m_example_member;
  ex.m_example_member = nullptr; // Oh, uh, this is the new C++11 constant for 0.
                                 // You can use this with pure virtual functions too.
}

// Boring copy constructor, also delegating to default to set up memory.
MoveSemantics::MoveSemantics(const MoveSemantics& ex): MoveSemantics()
{
  cout << "    Copy Constructor (" << ++m_cp_times << " times)" << endl;
  *m_example_member = *ex.m_example_member;
}

// Boring Destructor 
MoveSemantics::~MoveSemantics()
{
  delete m_example_member;
}

// Our move assignment operator. It trashes the example passed in.
MoveSemantics& MoveSemantics::operator=(MoveSemantics&& ex)
{
  cout << "    Move Assignment Operator" << endl;
  m_example_member = ex.m_example_member;
  ex.m_example_member = nullptr;

  return *this;
}

// Copy assignment operator, nothing special here.
MoveSemantics& MoveSemantics::operator=(const MoveSemantics& ex)
{
  cout << "  Copy Assignment Operator" << endl;
  *m_example_member = *ex.m_example_member;

  return *this;
}

void MoveSemantics::get_summary()
{
  cout << "    Total Copies: " << m_cp_times << endl;
  cout << "    Total Initializations: " << m_def_times << endl;
}

