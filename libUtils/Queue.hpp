#pragma once

/**
 * @file	Queue.hpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

#include <libUtils/Buffer.hpp>

namespace Utils
{
	class Queue
	{
	public:
		Queue(size_t);

		virtual inline bool Enqueue(const byte &element) { return _buffer.Add(element); }
		virtual inline bool Enqueue(const ByteSpan & buffer) { return _buffer.Add(buffer); }
		virtual bool DequeueTo(byte *, size_t count);
		inline virtual bool Dequeue(size_t count) { return _buffer.ShiftLeft(0, count); }
		virtual size_t DequeueAllTo(byte *);
		virtual size_t DequeueAllTo(Buffer &);
		virtual size_t DequeueAll();

		virtual inline bool PushBack(const byte &obj) { return _buffer.Add(obj); }
		virtual inline bool PushFront(const byte &obj) { return _buffer.Insert(0, obj); }
		virtual byte PopBack();
		virtual byte PopFront();
		virtual inline byte Front() const { return _buffer[0]; }
		virtual inline byte Back() const { return _buffer[_buffer.Count() - 1]; }
		virtual inline void Clear() { _buffer.Clear(); }

		virtual inline size_t GetSize() const { return _buffer.Capacity(); }
		virtual inline size_t GetCount() const { return _buffer.Count(); }
		virtual inline size_t GetFreeSize() const { return (_buffer.Capacity() - _buffer.Count()); }
		virtual inline bool IsEmpty() const { return (_buffer.Count() == 0); }
		virtual inline bool IsNotEmpty() const { return (_buffer.Count() != 0); }
		virtual inline bool IsFull() const { return (_buffer.Count() == _buffer.Capacity()); }

		virtual inline byte operator[](size_t index) const { return _buffer[index]; }
		virtual inline const byte * Data(size_t index) const { return _buffer.Data(index); }
		virtual inline const byte * Data() const { return _buffer.Data(); }

		hword GetUint16(size_t index) const;
		word GetUint32(size_t index) const;

	protected:
		const size_t _size;
		Buffer _buffer;
	};
}
