#pragma once

/**
 * @file	List.hpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

#include <cstdint>

namespace Utils
{
	template <class Type>
		class List
		{
		public:
			List();
			~List();

			uint32_t Size() const;
			bool IsEmpty() const;
			const Type* Front() const;
			const Type* Back() const;
			void PushFront(const Type & object);
			void PushBack(const Type & object);
			bool PopFront();
			bool PopBack();
			void Clear();

			Type * operator[](uint32_t index);

		private:
			struct Node
			{
				Type* object;
				Node *next;
			};

			Node *_head;
			Node *_tail;
		};
}

#include <libUtils/List.tpp>