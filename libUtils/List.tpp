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
	template<class T>
		List<T>::List()
		{
			_head = nullptr;
			_tail = nullptr;
		}

	template<class T>
		List<T>::~List()
		{
			Clear();
		}

	template<class T>
		size_t List<T>::Size() const
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

	template<class T>
		bool List<T>::IsEmpty() const
		{
			if (_head == nullptr)
				return true;
			else
				return false;
		}

	template<class T>
		const T* List<T>::Front() const
		{
			if (_head != nullptr)
				return _head->object;
			else
				return nullptr;
		}

	template<class T>
		const T* List<T>::Back() const
		{
			if (_tail != nullptr)
				return _tail->object;
			else
				return nullptr;
		}

	template<class T>
		void List<T>::PushFront(const T & object)
		{
			Node *newNode = new Node;
			newNode->object = new T(object);
	
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

	template<class T>
		void List<T>::PushBack(const T & object)
		{
			Node *newNode = new Node;
			newNode->object = new T(object);
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

	template<class T>
		bool List<T>::PopFront()
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

	template<class T>
		bool List<T>::PopBack()
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

	template<class T>
		void List<T>::Clear()
		{
			while (PopFront() == true)
				;
		}

    template<class T>
		int List<T>::At(const T &object)
		{
			Node *tmp = _head;
            int i = 0;

			while (tmp != nullptr)
			{
                if(*(tmp->object) == object)
                    return i;

                i++;
				tmp = tmp->next;
			}
			
            return -1;
		}

    template<class T>
        bool List<T>::Remove(size_t index)
        {
            auto size = Size();

            if(index >= size)
                return false;

            if(index == 0)
                return PopFront();
            else if(index == (size - 1))
                return PopBack();
            else
            {
                Node *tmp = _head;

                for(size_t i = 0; i < (index - 1); i++)
                    tmp = tmp->next;

                auto prev = tmp;
                tmp = tmp->next;

                prev->next = tmp->next;
                delete tmp->object;
                delete tmp;

                return true;
            }
        }

	template<class T>
		T * List<T>::operator[](size_t index)
		{
			Node *tmp = _head;

			size_t i = 0;
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