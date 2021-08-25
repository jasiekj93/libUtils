#pragma once

/**
 * @file	List.tpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

namespace Utils
{
	template<class Type>
		List<Type>::List()
		{
			_head = nullptr;
			_tail = nullptr;
		}

	template<class Type>
		List<Type>::~List()
		{
			Clear();
		}

	template<class Type>
		uint32_t List<Type>::Size() const
		{
			if (_head == nullptr)
				return 0;

			Node *tmp = _head;

			int i = 1;
			while (tmp != _tail)
			{
				i++;
				tmp = tmp->next;
			}
	
			return i;
		}

	template<class Type>
		bool List<Type>::IsEmpty() const
		{
			if (_head == nullptr)
				return true;
			else
				return false;
		}

	template<class Type>
		const Type* List<Type>::Front() const
		{
			if (_head != nullptr)
				return _head->object;
			else
				return nullptr;
		}

	template<class Type>
		const Type* List<Type>::Back() const
		{
			if (_tail != nullptr)
				return _tail->object;
			else
				return nullptr;
		}

	template<class Type>
		void List<Type>::PushFront(const Type & object)
		{
			Node *newNode = new Node;
			newNode->object = new Type(object);
	
			if (_head == nullptr)
			{
				newNode->next = nullptr;
				_head = newNode;
				_tail = newNode;
			}
			else
			{
				newNode->next = _head;
				_head = newNode;
			}
		}

	template<class Type>
		void List<Type>::PushBack(const Type & object)
		{
			Node *newNode = new Node;
			newNode->object = new Type(object);
			newNode->next = nullptr;
	
			if (_tail == nullptr)
			{
				_head = newNode;
				_tail = newNode;
			}
			else
			{
				_tail->next = newNode;
				_tail = newNode;
			}
		}

	template<class Type>
		bool List<Type>::PopFront()
		{
			if (_head == nullptr)
				return false;

			Node *tmp = _head;
	
			if (_head == _tail)
			{
				_head = nullptr;
				_tail = nullptr;
			}
			else
				_head = _head->next;

			if(tmp->object != nullptr)
				delete tmp->object;

			delete tmp;

			return true;
		}

	template<class Type>
		bool List<Type>::PopBack()
		{
			if (_tail == nullptr)
				return false;

			Node *tmp = _tail;
	
			if (_head == _tail)
			{
				_head = nullptr;
				_tail = nullptr;
			}
			else
			{
				Node *tmp2 = _head;

				while (tmp2->next != _tail)
					tmp2 = tmp2->next;

				tmp2->next = nullptr;
				_tail = tmp2;
			}

			delete tmp->object;
			delete tmp;

			return true;
		}

	template<class Type>
		void List<Type>::Clear()
		{
			while (PopFront() == true)
				;
		}

	template<class Type>
		Type * List<Type>::operator[](uint32_t index)
		{
			Node *tmp = _head;

			uint32_t i = 0;
			while (tmp != nullptr && i < index)
			{
				i++;
				tmp = tmp->next;
			}
			if (tmp == nullptr)
				return nullptr;
			else
				return tmp->object;
		}

}