#pragma once
#include <libUtils/Copy.hpp>

namespace Utils
{
	template<typename T>
	Buffer<T>::Buffer(size_t size)
		: _size(size)
		, _data(std::make_unique<T[]>(size))
		, _count(0)

	{
	}

	template<typename T>
	bool Buffer<T>::Add(const Span<T> &buffer)
	{
		if (buffer.data == nullptr)
			return false;

		if ((_count + buffer.size) > _size)
			return false;

		for (size_t i = 0; i < buffer.size; i++)
			_data[_count++] = buffer.data[i];

		return true;
	}

	template<typename T>
	bool Buffer<T>::Add(const T &object)
	{
		if (_count == _size)
			return false;

		_data[_count++] = object;
		return true;
	}

	template<typename T>
	bool Buffer<T>::Add(const T *pointer, size_t size) 
	{ 
		return Add(Span<T>{ pointer, size }); 
	}

	template<typename T>
	void Buffer<T>::DeepClear()
	{
		for(size_t i = 0; i < _size; i++)
			_data[i] = T();
		_count = 0;
	}

	template<typename T>
	bool Buffer<T>::Shrink(size_t shrinkSize)
	{
		if (shrinkSize > _count)
			return false;

		_count -= shrinkSize;
		return true;
	}

	template<typename T>
	bool Buffer<T>::ShiftLeft(size_t startPosition, size_t size)
	{
		auto endPosition = startPosition + size;

		if (endPosition > _count)
			return false;

		std::memmove(&_data[startPosition], &_data[endPosition], _count - endPosition);

		_count -= size;
		return true;
	}

	template<typename T>
	bool Buffer<T>::Insert(size_t index, const Span<T> &span)
	{
		if((_count + span.size) > _size)
			return false;

		if (index > _count)
			return false;

		Move<T>(&_data[index + span.size], &_data[index], _count - index);	
		Copy<T>(&_data[index], span.data, span.size);
		_count += span.size;

		return true;
	}

	template<typename T>
	bool Buffer<T>::Insert(size_t index, const T &object)
	{
		if(IsFull() == true)
			return false;

		if (index >= _count)
			return false;

		Move<T>(&_data[index+1], &_data[index], _count - index);	
		_data[index] = object;
		_count++;
		return true;
	}

	template<typename T>
	bool Buffer<T>::Insert(size_t index, const T *data, size_t size) 
	{ 
		return Insert(index, ByteSpan{ data, size }); 
	}

}