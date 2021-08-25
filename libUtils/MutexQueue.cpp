#include "MutexQueue.hpp"

using namespace Utils;

MutexQueue::MutexQueue(size_t size)
	: Queue(size), _mutex()
{
}


bool MutexQueue::Enqueue(const ByteSpan &buffer)
{
	_mutex.Lock();
	bool result = Queue::Enqueue(buffer);
	_mutex.Unlock();

	return result;
}

bool MutexQueue::Enqueue(const byte &element)
{
	_mutex.Lock();
	bool result = Queue::Enqueue(element);
	_mutex.Unlock();

	return result;
}

uint32_t MutexQueue::DequeueAllTo(byte *destination)
{
	_mutex.Lock();
	uint32_t result = Queue::DequeueAllTo(destination);
	_mutex.Unlock();

	return result;
}

uint32_t MutexQueue::DequeueAllTo(Buffer &destination)
{
	_mutex.Lock();
	uint32_t result = Queue::DequeueAllTo(destination);
	_mutex.Unlock();

	return result;
}

bool MutexQueue::DequeueTo(byte *destination, uint32_t count)
{
	_mutex.Lock();
	bool result = Queue::DequeueTo(destination, count);
	_mutex.Unlock();

	return result;
}

bool MutexQueue::TryEnqueue(const ByteSpan &buffer)
{
	bool result;

	if (_mutex.TryLock() == false)
		return false;

	result = Queue::Enqueue(buffer);
	_mutex.Unlock();

	return result;
}

bool MutexQueue::TryEnqueue(const byte &element)
{
	bool result;

	if (_mutex.TryLock() == false)
		return false;

	result = Queue::Enqueue(element);
	_mutex.Unlock();

	return result;
}

bool MutexQueue::TryDequeueAllTo(byte *destination)
{
	if (_mutex.TryLock() == false)
		return false;

	Queue::DequeueAllTo(destination);
	_mutex.Unlock();

	return true;
}

bool MutexQueue::TryDequeueTo(byte *destination, uint32_t count)
{
	if (_mutex.TryLock() == false)
		return false;

	bool result = Queue::DequeueTo(destination, count);
	_mutex.Unlock();

	return result;
}