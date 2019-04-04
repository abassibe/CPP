/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 11:05:54 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 21:06:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

template <typename T> class Vector
{
	public:
		Vector<T>() : _tete(nullptr), _size(0) {}
		Vector(Vector<T> const& copy)
		{
			_tete = nullptr;
			vector_t	*tmp1 = copy._tete, *tmp2 = nullptr;
			while (tmp1 != nullptr)
			{
				if (tmp2 == nullptr)
				{
					_tete= new vector_s;
					tmp2 = _tete;
				}
				else
				{
					tmp2->Next = new vector_s;
					tmp2 = tmp2->Next;
				}
				tmp2->Item = tmp1->Item;
				tmp1 = tmp1->Next;
			}
			if (tmp2 != nullptr) tmp2->Next = nullptr;
			return;
		}
		~Vector() {}
		Vector<T>	&operator=(Vector<T> const& copy)
		{
			vector_s *tmp1 = copy._tete, *tmp2 = nullptr;

			while (tmp1 != nullptr)
			{
				if (tmp2 == nullptr)
				{
					_tete = new vector_s;
					tmp2 = _tete;
				}
				else
				{
					tmp2->Next = new vector_s;
					tmp2 = tmp2->Next;
				}
				tmp2->Item = tmp1->Item;
				tmp1 = tmp1->Next;
			}
			if (tmp2 != nullptr)
				tmp2->Next = nullptr;
			return *this;
		}
		T			*operator[](size_t index)
		{
			vector_s *ptmp = _tete;
			for (size_t i = 0; i < index; i++)
				ptmp = ptmp->Next;
			return (ptmp->Item);
		}
		T const		&operator[](size_t index) const
		{
			vector_s *ptmp = _tete;
			T		ret;
			for (size_t i = 0; i < index; i++)
				ptmp = ptmp->Next;
			return (ptmp->Item);
		}
		void push(T *Item)
		{
			vector_t	*tmp = _tete;
			if (_size == 0)
			{
				_tete = new vector_t;
				_tete->Item = Item;
				_tete->Next = nullptr;
				_size = 1;
				return ;
			}
			for (size_t i = 0; i < _size - 1; i++)
				tmp = tmp->Next;
			tmp->Next = new vector_t;
			tmp = tmp->Next;
			tmp->Item = Item;
			tmp->Next = nullptr;
			_size++;
			return;
		}
		void	pop(size_t index)
		{
			if (index >= _size)
				return ;
			if (index == 0)
			{
				vector_t *ptmp = _tete->Next;;
				delete (_tete->Item);
				delete (_tete);
				_tete = ptmp->Next;
				_size--;
				return;
			}
			vector_t *ptmp = _tete;
			vector_t *ptmp2 = _tete;
			for (size_t i = 0; i < index; i++)
			{
				if (i != 0)
					ptmp = ptmp->Next;
				ptmp2 = ptmp2->Next;
			}
			ptmp->Next = ptmp2->Next;
			delete (ptmp2->Item);
			delete (ptmp2);
			_size--;
		}
		void	pop(T *Item)
		{
			vector_t *ptmp = _tete;
			vector_t *ptmp2 = _tete;
			for (size_t i = 0; i < _size && ptmp->Item != Item; i++)
			{
				ptmp = ptmp->Next;
				ptmp2 = ptmp2->Next;
				if (i + 1 == _size && Item != ptmp->Item)
					return ;
			}
			ptmp2 = ptmp2->Next;
			delete (ptmp->Item);
			delete (ptmp);
			ptmp->Next = ptmp2;
			_size--;
		}
		size_t	getSize() const
		{
			return (_size);
		}

	private:
		typedef struct vector_s
		{
			T					*Item;
			struct vector_s		*Next;
		} vector_t;

		vector_s	*_tete;
		size_t		_size;
};

#endif
