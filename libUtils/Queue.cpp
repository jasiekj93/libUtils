#include "Queue.hpp"

using namespace Utils;

Queue::Queue(size_t size)
	: _size(size)
	, _buffer(size)
{
}


size_t Queue::DequeueAllTo(byte *destination)
{
	size_t result = _buffer.Count();
	if (this->DequeueTo(destination, _buffer.Count()))
		return result;
	else
		return UINT32_MAX;
}

size_t Queue::DequeueAllTo(Buffer &destination)
{
	size_t size = _buffer.Count();
	bool result = destination.Add({_buffer.Data(), size});
	_buffer.Clear();
	if (result == true)
		return size;
	else
		return UINT32_MAX;
}

size_t Queue::DequeueAll()
{
	size_t result = _buffer.Count();
	this->Dequeue(_buffer.Count());
	return result;
}

bool Queue::DequeueTo(byte *destination, size_t count)
{
	if (count > _buffer.Count())
		return false;

	if (destination == nullptr)
		return false;

	std::memcpy(destination, _buffer.Data(), count);
	_buffer.ShiftLeft(0, count);

	return true;
}

byte Queue::PopBack()
{
	auto result = Back();
	_buffer.Shrink(1);
	return result;
}

byte Queue::PopFront()
{
	auto result = Front();
	_buffer.ShiftLeft(0, 1);
	return result;
}

uint16_t Queue::GetUint16(size_t index) const
{
	if ((index + 1) >= _buffer.Count())
		return UINT16_MAX;

	return ((uint16_t)_buffer[index] << 8) |
		   (uint16_t)_buffer[index + 1];
}

word Queue::GetUint32(size_t index) const
{
	if ((index + 3) >= _buffer.Count())
		return WORD_MAX;
	else
		return BytesToWord(&_buffer[index]);
}
