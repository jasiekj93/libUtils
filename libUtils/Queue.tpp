#pragma once

namespace Utils
{
	template<typename T>
	Queue<T>::Queue(size_t size)
			: _size(size)
		, _buffer(size)
	{
	}

	template<typename T>
	size_t Queue<T>::DequeueAllTo(T *destination)
	{
		size_t result = _buffer.Count();
		if (this->DequeueTo(destination, _buffer.Count()))
			return result;
		else
			return UINT32_MAX;
	}

	template<typename T>
	size_t Queue<T>::DequeueAllTo(Buffer<T> &destination)
	{
		size_t size = _buffer.Count();
		bool result = destination.Add({_buffer.Data(), size});
		_buffer.Clear();
		if (result == true)
			return size;
		else
			return UINT32_MAX;
	}

	template<typename T>
	size_t Queue<T>::DequeueAll()
	{
		size_t result = _buffer.Count();
		this->Dequeue(_buffer.Count());
		return result;
	}

	template<typename T>
	bool Queue<T>::DequeueTo(T *destination, size_t count)
	{
		if (count > _buffer.Count())
			return false;

		if (destination == nullptr)
			return false;

		std::memcpy(destination, _buffer.Data(), count);
		_buffer.ShiftLeft(0, count);

		return true;
	}

	template<typename T>
	T Queue<T>::PopBack()
	{
		auto result = Back();
		_buffer.Shrink(1);
		return result;
	}

	template<typename T>
	T Queue<T>::PopFront()
	{
		auto result = Front();
		_buffer.ShiftLeft(0, 1);
		return result;
	}
}