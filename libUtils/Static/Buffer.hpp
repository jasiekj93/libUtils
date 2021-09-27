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
#include <libUtils/Copy.hpp>

namespace Utils::Static
{
    template<typename T, size_t SIZE>
	class Buffer
	{
	public:
		Buffer();

		bool Add(const Span<T> &);
		bool Add(const T &);
		bool Add(const T *, size_t);

		bool Insert(size_t index, const Span<T> &);
		bool Insert(size_t index, const T &);
		bool Insert(size_t index, const T *, size_t);

		inline void Clear() { _count = 0; }
		void DeepClear();
		bool Shrink(size_t size);
		bool ShiftLeft(size_t startPosition, size_t count);

		inline auto Data() const { return _data; }
		inline auto Data(size_t i) const { return ((i < _count) ? &_data[i] : nullptr); }
		inline auto Count() const { return _count; }
		inline auto Capacity() const { return SIZE; }
		inline bool IsFull() const { return (_count == SIZE); }
		inline bool IsEmpty() const { return (_count == 0); }
		inline bool IsNotEmpty() const { return (_count != 0); }
		inline Span<T> ToSpan() const { return Span<T>{ _data, _count }; }

		inline const T & operator[](size_t i) const { return _data[i]; }
		inline T & begin() { return _data[0]; }
		inline T & end() { return _data[_count]; }
		inline const T & begin() const { return _data[0]; }
		inline const T & end() const { return _data[_count]; }

	private:
		T _data[SIZE];
		size_t _count;
	};
}

#include <libUtils/Static/Buffer.tpp>