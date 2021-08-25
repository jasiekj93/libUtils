#pragma once

/**
 * @file	Span.hpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

#include <cstddef>
#include <cstring>
#include <libUtils/DataUnit.hpp>

namespace Utils
{
	template <typename T>
	struct Span
	{
		const T *data;
		size_t size;


		bool operator==(const Span<T> &span)
		{
			if(this->size == span.size)
				return (std::memcmp(this->data, span.data, (span.size * sizeof(T))) == 0);
			else
				return false;
		}
	};

	using ByteSpan = Span<byte>;
	using HwordSpan = Span<hword>;
	using WordSpan = Span<word>;
	using DwordSpan = Span<dword>;
}