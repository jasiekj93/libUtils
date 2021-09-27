#pragma once

#include <libUtils/Static/MessageQueue.hpp>
#include <libUtils/Mutex.hpp>

namespace Utils::Static
{
	template<typename T, uint32_t SIZE>
		class MutexMessageQueue : public MessageQueue<T, SIZE>
		{
		private:
			Mutex _mutex;
		
		public:
			MutexMessageQueue();
		
			bool Enqueue(const T &element);
			bool TryEnqueue(const T &element);
			bool Enqueue(const Span<T> & buffer);
			bool TryEnqueue(const Span<T> & buffer);
			bool DequeueTo(T *);
			bool TryDequeueTo(T *);
			uint32_t DequeueAllTo(T *);
			uint32_t TryDequeueAllTo(T *);
			uint32_t DequeueAll();
			uint32_t TryDequeueAll();
		};
}

#include <libUtils/Static/MutexMessageQueue.tpp>