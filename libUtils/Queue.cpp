#include "Queue.hpp"

using namespace Utils;

Queue::Queue(size_t size)
	: _size(size)
	, _buffer(size)
{
}


uint32_t Queue::DequeueAllTo(byte *destination)
{
	uint32_t result = _buffer.Count();
	if (this->DequeueTo(destination, _buffer.Count()))
		return result;
	else
		return UINT32_MAX;
}

uint32_t Queue::DequeueAllTo(Buffer &destination)
{
	uint32_t size = _buffer.Count();
	bool result = destination.Add({_buffer.Data(), size});
	_buffer.Clear();
	if (result == true)
		return size;
	else
		return UINT32_MAX;
}

uint32_t Queue::DequeueAll()
{
	uint32_t result = _buffer.Count();
	this->Dequeue(_buffer.Count());
	return result;
}

bool Queue::DequeueTo(byte *destination, uint32_t count)
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

uint16_t Queue::GetUint16(uint32_t index) const
{
	if ((index + 1) >= _buffer.Count())
		return UINT16_MAX;

	return ((uint16_t)_buffer[index] << 8) |
		   (uint16_t)_buffer[index + 1];
}

uint32_t Queue::GetUint32(uint32_t index) const
{
	if ((index + 3) >= _buffer.Count())
		return UINT32_MAX;
	else
		return ((uint32_t)_buffer[index] << 24) |
			   ((uint32_t)_buffer[index + 1] << 16) |
			   ((uint32_t)_buffer[index + 2] << 8) |
			   (uint32_t)_buffer[index + 3];
}
