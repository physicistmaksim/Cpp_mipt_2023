#include <iostream>
class PseudoArray {
protected:
  size_t size_;

public:
  explicit PseudoArray(size_t size) : size_(size) {}
  virtual void clear() = 0;
  bool is_empty() const { return size_; }

  virtual ~PseudoArray() {}
};

class FloatArray : public PseudoArray {
protected:
  float *storage_ = nullptr;

public:
  FloatArray(size_t size, float value) : PseudoArray(size), storage_(new float[size]) 
  { 
    for(size_t i = 0; i < size; ++i)
    {
        storage_[i] = value;
    }
  }
  void clear() override
  {
    for(size_t i = 0; i < PseudoArray::size_; ++i)
    {
        storage_[i] = 0;
    }
  }
  float operator[](size_t idx)
  {
    return storage_[idx];
  }
  ~FloatArray()
  {
    delete [] storage_;
  }
};

class DoubleArray : public PseudoArray {
protected:
  double *storage_ = nullptr;

public:
  DoubleArray(size_t size, double value) : PseudoArray(size), storage_(new double[size]) 
  { 
    for(size_t i = 0; i < size; ++i)
    {
        storage_[i] = value;
    }
  }
  void clear() override
  {
    for(size_t i = 0; i < PseudoArray::size_; ++i)
    {
        storage_[i] = 0;
    }
  }
  double operator[](size_t idx)
  {
    return storage_[idx];
  }
  ~DoubleArray()
  {
    delete [] storage_;
  }
};

int main()
{
    return 0;
}