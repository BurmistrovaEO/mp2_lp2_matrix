#pragma once

#ifndef TVector_H
#define TVector_H
#include <iostream>
using namespace std;
const int MAX_VECTOR_SIZE = 100000000;
template <class Type>
class TVector
{
protected:
	Type *pVec;
	int Size; //размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v); // конструктор копирования
	int GetSize() { return Size; }; // получить размер вектора
	int GetStartIndex() { return StartIndex; }; //получить индекс первого элемента вектора
	Type& GetValue(int pos); // доступ с контролем индекса
	Type& operator[](int pos); // доступ
	bool operator==(const TVector &v); //сравнение
	bool operator!=(const TVector &v); // проверка на неравенство
	TVector& operator=(const TVector &v); // присваивание

	//скалярные операции

	TVector operator+(const Type &val); // прибавить скаляр
	TVector operator-(const Type &val); // вычесть скаляр
	TVector operator*(const Type &val); // умножить на скаляр

	// векторные операции

	TVector operator+(const TVector &v); // сложение
	TVector operator-(const TVector &v); // вычитание
	Type operator*(const TVector &v); // скалярное произведение

	// ввод-вывод

	friend istream& operator>>(istream &in, TVector &v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVec[i];
		return in;
	}
	friend ostream& operator<<(ostream &out, TVector &v)
	{
		for (int i = 0; i < v.Size; i++)
			out << v.pVec[i] << " ";
		return out;
	}
};
	template <class Type>
	TVector<Type>::TVector(int s, int si) // конструктор по умолчанию
	{		
		//if (s > MAX_VECTOR_SIZE || s<0 || si>s || si < 0) 
		//{ throw out_of_range("Given size(s) must be less than 100000000 and greater than 0"); }
		Size = s;
		StartIndex = si;
		pVec = new Type[Size];
		for (int i = 0; i < Size; i++)
			pVec[i] = 0;

	}
	
	template <class Type>
	TVector<Type>::TVector(const TVector&v) // конструктор копирования
	{
		Size = v.Size;
		StartIndex = v.StartIndex;
		pVec = new Type[Size];
		for (int i = 0; i < Size; i++)
			pVec[i] = v.pVec[i];
	}

	template<class Type>
	Type& TVector<Type>::GetValue(int pos) // доступ к элементу с контролем индекса
	{
		//if (pos > Size || pos < StartIndex) throw out_of_range("You cannot reach this element. No such element. Out of range.");
		return pVec[pos - StartIndex];
	}

	template<class Type>
	Type& TVector<Type>::operator[](int pos) // доступ к элементу без контроля индекса
	{
		return pVec[pos - StartIndex];
	}

	template<class Type>
	bool TVector<Type>::operator==(TVector const& v)
	{
		if (Size != v.Size || StartIndex != v.StartIndex)
			return false;
		for (int i = 0; i < v.Size; i++)
		{
			if (v.pVec[i] != pVec[i])
				return false;
		}
		return true;
	}

	template<class Type>
	bool TVector<Type>::operator!=(TVector const& v) //if(!(*this==v))return true;return false;
	{
		if (Size != v.Size || StartIndex != v.StartIndex)
			return true;
		for (int i = 0; i < v.Size; i++)
		{
			if (v.pVec[i] != pVec[i])
				return true;
		}
		return false;
	}

	template<class Type>
	TVector<Type>& TVector<Type>::operator=(const TVector &v)  // операция присваивания
	{	
		if (this != &v)
		{
			if (Size != v.Size)
			{
				delete[] pVec;
				pVec = new Type[v.Size];
			}
			Size = v.Size;
			StartIndex = v.StartIndex;
			for (int i = 0; i < Size; i++)
			{
				pVec[i] = v.pVec[i];
			}
		}
		return *this;
	}

	template<class Type>
	TVector<Type> TVector<Type>::operator+(Type const& val)// прибавить скаляр
	{
		TVector<Type> tmp(*this);
		for (int i = 0; i < this->Size; i++)
			tmp.pVec[i] += val;
		return tmp;
	}


	template<class Type>
	TVector<Type> TVector<Type>::operator-(Type const& val)// вычесть скаляр
	{
		TVector<Type> tmp(*this);
		for (int i = 0; i < this->Size; i++)
			tmp.pVec[i] -= val;
		return tmp;
	}


	template<class Type>
	TVector<Type> TVector<Type>::operator*(const Type &val)// умножить на скаляр
	{
		TVector<Type> tmp(*this);
		for (int i = 0; i < this->Size; i++)
			tmp.pVec[i] *= val;
		return tmp;
	}

	template<class Type>
	TVector<Type> TVector<Type>:: operator+(const TVector &v) // сложение векторов
	{
		TVector<Type> tmp(*this);
		if (v.Size != tmp.Size || v.StartIndex != tmp.StartIndex) throw length_error("Vectors' sizes must be equal");
		for (int i = 0; i < tmp.Size; i++)
			tmp.pVec[i] = tmp.pVec[i] + v.pVec[i];
		return tmp;
	}
	template<class Type>
	TVector<Type> TVector<Type>:: operator-(const TVector &v) // вычитание векторов
	{
		TVector<Type> tmp(*this);
		if (v.Size != tmp.Size || v.StartIndex != tmp.StartIndex) throw length_error("Vectors' sizes must be equal");
		for (int i = 0; i < tmp.Size; i++)
			tmp.pVec[i] = tmp.pVec[i] - v.pVec[i];
		return tmp;
	}

	template<class Type>
	Type TVector<Type>::operator*(const TVector &v) // скалярное произведение
	{
		Type tmp = 0;
		if (v.Size != Size || v.StartIndex != StartIndex) throw length_error("Vectors' sizes must be equal");
		for (int i = 0; i < Size; i++)
			tmp = tmp + (this->pVec[i] * v.pVec[i]);
		return tmp;
	}
#endif