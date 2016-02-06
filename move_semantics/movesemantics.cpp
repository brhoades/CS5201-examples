#include "movesemantics.h"

int MoveSemantics::m_cp_times = 0, MoveSemantics::m_def_times = 0;

MoveSemantics::MoveSemantics()
{
  cout << "    Default Constructor Called (" << ++m_def_times
       << " times)" << endl;
  m_example_member = new int;
  *m_example_member = 0;
}

MoveSemantics::MoveSemantics(const int example_member): MoveSemantics()
{
  cout << "    Parameterized Constructor Called" << endl;
  *m_example_member = example_member;
}

MoveSemantics::MoveSemantics(MoveSemantics&& ex)
{
  cout << "    Move Constructor" << endl;
  m_example_member = ex.m_example_member;
  ex.m_example_member = nullptr;
  // nullptr is the new C++11 constant for null pointers.
}

MoveSemantics::MoveSemantics(const MoveSemantics& ex): MoveSemantics()
{
  cout << "    Copy Constructor (" << ++m_cp_times 
       << " times)" << endl;
  *m_example_member = *ex.m_example_member;
}

MoveSemantics::~MoveSemantics()
{
  delete m_example_member;
  m_example_member = nullptr;
}

MoveSemantics& MoveSemantics::operator=(MoveSemantics&& ex)
{
  cout << "    Move Assignment Operator" << endl;
  m_example_member = ex.m_example_member;
  ex.m_example_member = nullptr;
  return *this;
}

MoveSemantics& MoveSemantics::operator=(const MoveSemantics& ex)
{
  cout << "  Copy Assignment Operator" << endl;
  *m_example_member = *ex.m_example_member;
  return *this;
}

void MoveSemantics::get_summary()
{
  cout << "    Total Copies: " << m_cp_times
       << "    Total Default Calls: " << m_def_times << endl;
}

