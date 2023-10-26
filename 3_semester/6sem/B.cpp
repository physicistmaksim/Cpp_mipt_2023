#pragma once
#include <iostream>
template <typename T>
class Array 
{
private:
  size_t m_size = 0;
  T *m_storage = nullptr;

  void swap(Array<T> &other)  // Приватный метод для упрощения перемещения
  {
    T *tmp = new T[other.m_size];
    for(size_t idx = 0; idx != other.m_size; ++idx)
    {
        tmp[idx] = other.m_storage[idx];
    }
    delete [] other.m_storage;
    other.m_storage = new T[m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        other.m_storage[idx] = m_storage[idx];
    }
    delete [] m_storage;
    m_storage = new T[other.m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = tmp[idx];
    }
    delete [] tmp;
    std::swap(m_size, other.m_size);
  }

public:
  // Конструктор
  explicit Array(size_t size = 0, const T & value = T()) : m_size(size), m_storage(new T[size]) 
  {
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = value;
    }
  }

  // Копирующий  конструктор
  Array(const Array &other) 
  { 
    m_size = other.m_size;
    m_storage = new T[m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = other.m_storage[idx];
    }
  }

  // Деструктор
  ~Array()
  {
    delete [] m_storage;
  }

  // Оператор копирующего присваивания
  Array& operator=(Array<T>& other)
  {
    m_size = other.m_size;
    delete [] m_storage;
    m_storage = new T[m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = other.m_storage[idx];
    }
    return *this;
  }

  // Перемещающий конструктор
  Array(Array<T> &&other)
  {
    this->swap(other);
  }

  // Перемещающий оператор присваиваивания
  Array& operator=(Array<T> &&other)
  {
    this->swap(other);
    return *this;
  }

  // Возвращает размер массива
  size_t size() const
  {
    size_t const size_const = m_size;
    return size_const;
  }

  // Возвращает idx элемент массива
  T& operator[](size_t idx)
  {
    return m_storage[idx];
  }

};