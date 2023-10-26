#include <iostream>

class String {
private:
  size_t m_size = 0;
  char *m_storage = nullptr;

  // Меняет местами параметры входной строки и исходной
  // Полезна для избежания копий кода
  void swap(String &other)
  {
    char *tmp = new char[other.m_size];
    for(size_t idx = 0; idx != other.m_size; ++idx)
    {
        tmp[idx] = other.m_storage[idx];
    }
    delete [] other.m_storage;
    other.m_storage = new char[m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        other.m_storage[idx] = m_storage[idx]; 
    }
    delete [] m_storage;
    m_storage = new char[other.m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = tmp[idx];
    }
    delete [] tmp;
    std::swap(m_size, other.m_size);
  }

  // Устанавливает ежиничный элемент для всех значений в массиве
  // Полезна для избежания копий кода
  void assign_element(char &el)
  {
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = el;
    }
  }
public:

  // Конструктор
  explicit String(size_t size = 0, char el = 'a') : m_size(size), m_storage(new char[size]) 
  {
    assign_element(el);
  }

  // Копирующий конструктор
  String(const String &other)
  {
    m_size = other.m_size;
    m_storage = new char[m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = other.m_storage[idx];
    }
  }

  // Деструктор
  ~String()
  {
    delete [] m_storage;
  }

  // Оператор копирующего присваивания
  String &operator=(String &other)
  {
    m_size = other.m_size;
    delete [] m_storage;
    m_storage = new char[m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = other.m_storage[idx];
    }
    return *this;
  }

  // Перемещающий конструктор
  String(String &&other)
  {
    swap(other);
  }

  // Оператор перемещающего присваивания
  String &operator=(String &&other)
  {
    swap(other);
    return *this;
  }

  // Оператор +=
  String &operator+=(String const &other)
  {
    char * tmp = new char[m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        tmp[idx] = m_storage[idx];
    }
    delete [] m_storage;
    m_storage = new char[m_size + other.m_size];
    for(size_t idx = 0; idx != m_size; ++idx)
    {
        m_storage[idx] = tmp[idx];
    }
    for(size_t idx = m_size; idx != other.m_size + m_size; ++idx)
    {
        m_storage[idx] = other.m_storage[idx];
    }
    m_size = m_size + other.m_size;
    return *this;
  }

  // Внешний оператор сложения
  friend String operator+(String const &lha, String const &rha);

  // Возвращает размер строки
  size_t size() const
  {
    size_t const size_const = m_size;
    return size_const;
  }

  // Возвращает элемент строки с индексом idx
  char &operator[](size_t idx)
  {
    return m_storage[idx];
  }

  // Операторы ввода-вывода
  friend std::ostream &operator<<(std::ostream &out, const String &obj);
  friend std::istream &operator>>(std::istream &in, const String &obj);
};

String operator+(String const &lha, String const &rha)
{
    String tmp = String(lha);
    tmp += rha;
    return tmp;
}
std::ostream &operator<<(std::ostream &out, const String &obj)
{
    for(size_t idx = 0; idx != obj.m_size; ++idx)
    {
        out << obj.m_storage[idx];
    }
    return out;
}
std::istream &operator>>(std::istream &in, const String &obj)
{
    for(size_t idx = 0; idx != obj.m_size; ++idx)
    {
        in >> obj.m_storage[idx];
    }
    return in;
}