#pragma once

/**
 * @file	Buffer.hpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

#include <cstring>
#include <array>
#include <libUtils/Span.hpp>

namespace Utils
{
	class Buffer
	{
	public:
		explicit Buffer(size_t);
		~Buffer();

		bool Add(const ByteSpan &);
		bool Add(byte);
		bool Add(const byte *, size_t);

		bool Insert(size_t index, const ByteSpan &);
		bool Insert(size_t index, byte);
		bool Insert(size_t index, const byte *, size_t);

		inline void Clear() { _count = 0; }
		void DeepClear();
		bool Shrink(size_t size);
		bool ShiftLeft(size_t startPosition, size_t count);

		inline auto Data() const { return _data; }
		inline byte *Data(size_t i) const { return ((i < _count) ? &_data[i] : nullptr); }
		inline auto Count() const { return _count; }
		inline auto Capacity() const { return _size; }
		inline bool IsFull() const { return (_count == _size); }
		inline bool IsEmpty() const { return (_count == 0); }
		inline bool IsNotEmpty() const { return (_count != 0); }
		inline ByteSpan ToSpan() const { return ByteSpan{ _data, _count }; }

		inline const byte &operator[](size_t i) const { return _data[i]; }
		inline byte &begin() { return _data[0]; }
		inline byte &end() { return _data[_count]; }
		inline const byte &begin() const { return _data[0]; }
		inline const byte &end() const { return _data[_count]; }

	private:
		const size_t _size;
		byte *_data;
		size_t _count;
	};
}
