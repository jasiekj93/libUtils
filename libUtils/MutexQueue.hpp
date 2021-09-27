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
	class MutexQueue : public Queue
	{
	public:
		MutexQueue(size_t);

		bool Enqueue(const byte &element) override;
		bool Enqueue(const ByteSpan &buffer) override;
		bool DequeueTo(byte *, size_t count) override;
		size_t DequeueAllTo(byte *) override;
		size_t DequeueAllTo(Buffer &destination) override;
		
		bool TryEnqueue(const byte &element);
		bool TryEnqueue(const ByteSpan &buffer);
		bool TryDequeueTo(byte *, uint32_t count);
		bool TryDequeueAllTo(byte *);

	protected:
		byte operator[](size_t index) { return 0; }
		byte *GetData(size_t index) { return nullptr; }

	private:
		Mutex _mutex;
	};
}