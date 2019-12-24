#pragma once

#ifndef TMatrix_H
#define TMatrix_H
#include "TVector.h"
#include <iostream>
const int MAX_MATRIX_SIZE = 10000;

template<class Type>

class TMatrix : public TVector<TVector<Type> >
{
public:
	TMatrix(int s = 10);  //конструктор по умолчанию
	TMatrix(const TMatrix &mt); // копирование
	TMatrix(const TVector<TVector<Type> > &mt); //преобразование типа
	bool operator==(const TMatrix &mt); // сравнение
	TMatrix& operator=(const TMatrix &mt); //присваивание
	TMatrix operator+(const TMatrix &mt); //сложение
	TMatrix operator-(const TMatrix &mt); //вычитание
	TMatrix operator*(const TMatrix &mt); //умножение

	//ввод/вывод

	friend istream& operator>>(istream& in, TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVec[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVec[i] << "\n";
		return out;
	}
};
	template<class Type>
	TMatrix<Type>::TMatrix(int s) : TVector<TVector<Type> >(s)
	{
		for (int i = 0; i < s; i++)
			this->pVec[i] = TVector<Type>(s - i, i);
	}

	template<class Type>
	TMatrix<Type>::TMatrix(const TMatrix<Type> &mt) :TVector<TVector<Type> >(mt) {}

	template<class Type>
	TMatrix<Type>::TMatrix(const TVector<TVector<Type> > &mt) : TVector<TVector<Type> >(mt)
	{
		for (int i = 0; i < this->GetSize(); i++)
		{
			if (this->pVec[i].GetSize() != this->GetSize() - i)
				throw std::out_of_range("This is not a triangle matrix");
		}
	}


	template<class Type>
	TMatrix<Type>& TMatrix<Type>:: operator=(const TMatrix &mt) //присваивание
	{
		if (this != &mt)
		{
			if (this->Size != mt.Size)
			{
				delete[] this->pVec;
				this->pVec = new TVector<Type>[mt.Size];
			}
			this->Size = mt.Size;
			this->StartIndex = mt.StartIndex;
			for (int i = 0; i < this->Size; i++)
			{
				this->pVec[i] = mt.pVec[i];
			}
		}
		return *this;
	}

	template<class Type>
	bool TMatrix<Type>::operator==(TMatrix const& mt)
	{
		if (this->Size != mt.Size || this->StartIndex != mt.StartIndex)
			return false;
		for (int i = 0; i < mt.Size; i++)
		{
			if (mt.pVec[i] != this->pVec[i])
				return false;
		}
		return true;
	}

	template<class Type>
	TMatrix<Type> TMatrix<Type>::operator+(const TMatrix &mt)
	{
		TMatrix tmp(*this);
		//if (mt.Size != tmp.Size || mt.StartIndex != tmp.StartIndex) throw length_error("Matrixes' sizes must be equal");
		for (int i = 0; i < tmp.Size; i++)
			tmp.pVec[i] = tmp.pVec[i] + mt.pVec[i];
		return tmp;
	}

	template<class Type>
	TMatrix<Type> TMatrix<Type>::operator-(const TMatrix &mt)
	{
		TMatrix tmp(*this);
		//if (mt.Size != tmp.Size || mt.StartIndex != tmp.StartIndex) throw length_error("Matrixes' sizes must be equal");
		for (int i = 0; i < tmp.Size; i++)
			tmp.pVec[i] = tmp.pVec[i] - mt.pVec[i];
		return tmp;
	}

	template<class Type>
	TMatrix<Type> TMatrix<Type>::operator*(const TMatrix &mt)
	{
		
		//if (mt.Size != this->Size || mt.StartIndex != this->StartIndex) throw length_error("Matrixes' sizes must be equal");
		TMatrix<Type> tmp(this->Size);
		for (int i = 0; i < this->Size; i++)
			for(int j=0;j<this->Size/2;j++) //size/2
			{	Type tp = Type();
				for (int k = i; k <= j; ++k) 
				{
				tp = tp + (this->pVec[i][k] * mt.pVec[k][j]);
				}
		tmp.pVec[i][j] = tp;
	}
		return tmp;
	}

#endif