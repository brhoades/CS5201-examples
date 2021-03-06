#include "regular.h"

int Regular::m_cp_times = 0, Regular::m_def_times = 0;

Regular::Regular()
{
  cout << "    Default Constructor (" << ++m_def_times
       << " times total)" << endl;
  m_example_member = new int;
  *m_example_member = 0;
}

Regular::Regular(const int example_member): Regular()
{
  cout << "    Parameterized Constructor" << endl;
  *m_example_member = example_member;
}

Regular::Regular(const Regular& ex): Regular()
{
  cout << "    Copy Constructor (" << ++m_cp_times 
       << " times total)" << endl;
  *m_example_member = *ex.m_example_member;
}

Regular::~Regular()
{
  delete m_example_member;
  m_example_member = nullptr;
}

Regular& Regular::operator=(const Regular& ex)
{
  cout << "    Copy Assignment Operator" << endl;
  *m_example_member = *ex.m_example_member;
  return *this;
}

void Regular::get_summary()
{
  cout << "    Total Copies: " << m_cp_times
       << "    Total Default Calls: " << m_def_times << endl;
}

