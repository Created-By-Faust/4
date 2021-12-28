#ifndef REALTYTABLE_H
#define REALTYTABLE_H

#include <iostream>

/**
* @brief Содержит описание класса Vector
* @class Iterator
* @details Iterator Класс итертарор для шаблонного класса Vector
*
*/

template <class T>
class Iterator {

private:

    //! A private variable.
    /*!
      Details.
    */
    T * curr;

public:

    Iterator() : curr(nullptr){}

    Iterator(T * ptr) : curr(ptr) {}

    Iterator(const Iterator & it) : curr(it.curr) {}

    /*!
    @brief оператор сравнения
    @param it != (const Iterator & it) const
    @returns operator !=
    */
    bool operator != (const Iterator & it) const {
        return curr != it.curr;
    }

    /*!
     @brief оператор сравнения
     @param it == (const Iterator & it) const
     @returns operator ==
    */
    bool operator == (const Iterator & it) const {
        return curr == it.curr;
    }
    /*!
     @fn operator * const
     @brief оператор разыменовывания
     @returns operator *
     */
    T & operator * () {
        return *curr;
    }
    
    /*!
     @fn operator ++ const
     @brief постфиксный префиксный инкреммент
     @returns operator ++

     */
    Iterator & operator ++ () {
        ++curr;
        return *this;
    }
    /*!
     @fn *operator ++ (int) const
     @brief  постфиксный постфиксный инкреммент
     @returns operator ++ (int)
     */
    Iterator *operator ++ (int) {
        ++(*this);
        return this;
    }
};

/**
* @brief Шаблон классa Vector, который является вектором
* @class Vector
*/

template <class T>
class Vector {

    friend class Iterator<T>;

private:
    //! A private variable.
    /*!
      Details.
    */

    unsigned int size = 0;
    unsigned int curr = 0;
    T *vector;

public:
    Vector() : size(1)
    {
        vector = new T[1];
    }

    Vector(const Vector & other) : size(other.size), curr(other.curr), vector(new T[other.size])
    {
        for (int i = 0; i < curr; i++)
            vector[i] = other.vector[i];
    }

    Vector(Vector && other) noexcept : size(other.size), curr(other.curr), vector(other.vector)
    {
        other.vector = nullptr;
    }

    ~Vector()
    {
        delete[] vector;
    }
    
    /*!
    @fn operator = (const Vector & other)
    @brief копирующий оператор присваивания
    @returns operator =
    */
    
    Vector & operator = (const Vector & other)
    {
        if (this != &other)
        {
            delete[] vector;
            size = other.m_size;
            curr = other.m_curr;
            vector = new T[size];
            for (int i = 0; i < curr; ++i)
                vector[i] = other.vector[i];
        }
        return *this;
    }
    
    
    /*!
     @brief метод добавление нового элемента
    */
    void push_back(T item) {
        if (curr == size) {
            T * old = vector;
            size++;
            vector = new T[size*2];
            for (int j = 0; j < curr; j++)
                vector[j] = old[j];
            delete [] old;
        }
        vector[curr] =  item;
        curr++;
        size = size*2;
    }
    

    //typedef class MyVectorIt<T> Iterator;
    
    const Iterator<T> begin()
    {
        return Iterator(this->vector);
    }

    const Iterator<T> end()
    {
        return Iterator(this->vector + curr);
    }
};

#endif //REALTYTABLE_H
