class MoveSemantics
{
  public:
    MoveSemantics();
    MoveSemantics(const int example_member);
    MoveSemantics(MoveSemantics&& ex);
    MoveSemantics(const MoveSemantics& ex);
    ~MoveSemantics();

    MoveSemantics& operator=(MoveSemantics&& ex);
    MoveSemantics& operator=(const MoveSemantics& ex);
    static void get_summary();

  private:
    int* m_example_member;
    static int m_def_times;
    static int m_cp_times;
};
