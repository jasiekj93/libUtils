#pragma once

/**
 * @file	MutexQueue.hpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

#include <libUtils/Mutex.hpp>
#include <libUtils/Queue.hpp>

namespace Utils
{
	template<typename T>
	class MutexQueue : public Queue<T>
	{
	public:
		MutexQueue(size_t);

		bool Enqueue(const T &element) override;
		bool Enqueue(const Span<T> &buffer) override;
		bool DequeueTo(T *, size_t count) override;
		size_t DequeueAllTo(T *) override;
		size_t DequeueAllTo(Buffer<T> &destination) override;
		
		bool TryEnqueue(const T &element);
		bool TryEnqueue(const Span<T> &buffer);
		bool TryDequeueTo(T *, size_t count);
		bool TryDequeueAllTo(T *);

	protected:
		T operator[](size_t index) { return 0; }
		T * GetData(size_t index) { return nullptr; }

	private:
		Mutex _mutex;
	};
}

#include <libUtils/MutexQueue.tpp>