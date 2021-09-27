#pragma once

#include <libUtils/Static/Queue.hpp>

namespace Utils::Static
{
	template<typename T, size_t SIZE>
		class MessageQueue
		{		
		private:
			Queue<T, SIZE> _objects;
			Queue<uint32_t, SIZE / 2> _sizes;
		
		public:
			MessageQueue();
		
			virtual bool Enqueue(const T &element);
			virtual bool Enqueue(const Span<T> & buffer);
			virtual bool DequeueTo(T *);
			virtual void Dequeue();
			virtual uint32_t DequeueAllTo(T *);
			virtual uint32_t DequeueAll();
			
			inline uint32_t GetFirstMessageSize() const { return (_sizes.IsEmpty() ? 0 : _sizes.Front()); }
			inline uint32_t GetMessageCount() const { return _sizes.GetCount(); }
			
			inline uint32_t GetCount() const { return _objects.GetCount(); }
			inline uint32_t GetSize() const { return SIZE; }
		};
}

#include <libUtils/Static/MessageQueue.tpp>