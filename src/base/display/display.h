class Display
{
  public:
    virtual ~Display() = default;
    virtual void SetCurrentLiftHeight(const unsigned int &value) = 0;
    virtual void SetCurrentMeasuredDistance(const unsigned int &value) = 0;
};
