#pragma once

/**
 * @file	List.hpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

#include <cstddef>

namespace Utils
{
	template <class T>
		class List
		{
		public:
			List();
			~List();

			size_t Size() const;
			bool IsEmpty() const;
			const T* Front() const;
			const T* Back() const;
			void PushFront(const T &);
			void PushBack(const T &);
			bool PopFront();
			bool PopBack();
			void Clear();

			T * operator[](size_t);

		private:
			struct Node
			{
				T* object;
				Node *next;
			};

			Node *_head;
			Node *_tail;
		};
}

#include <libUtils/List.tpp>