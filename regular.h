#include <iostream>
using namespace std;

class Regular
{
  public:
    Regular();
    Regular(const int example_member);
    Regular(const Regular& ex);
    ~Regular();

    Regular& operator=(const Regular& ex);
    static void get_summary();

  private:
    int* m_example_member;
    static int m_def_times;
    static int m_cp_times;
};
