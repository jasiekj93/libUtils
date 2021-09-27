#include "Buffer.hpp"

using namespace Utils;

Buffer::Buffer(size_t size)
	: _size(size)
	, _data(new byte[size])
	, _count(0)

{
}

Buffer::~Buffer()
{
	delete[] _data;
}


bool Buffer::Add(const ByteSpan &buffer)
{
	if (buffer.data == nullptr)
		return false;

	if ((_count + buffer.size) > _size)
		return false;

	for (size_t i = 0; i < buffer.size; i++)
		_data[_count++] = buffer.data[i];

	return true;
}

bool Buffer::Add(byte object)
{
	if (_count == _size)
		return false;

	_data[_count++] = object;
	return true;
}

bool Buffer::Add(const byte *pointer, size_t size) 
{ 
	return Add(ByteSpan{ pointer, size }); 
}

void Buffer::DeepClear()
{
	for(size_t i = 0; i < _count; i++)
		_data[i] = 0;
	_count = 0;
}

bool Buffer::Shrink(size_t shrinkSize)
{
	if (shrinkSize > _count)
		return false;

	_count -= shrinkSize;
	return true;
}

bool Buffer::ShiftLeft(size_t startPosition, size_t size)
{
	auto endPosition = startPosition + size;

	if (endPosition > _count)
		return false;

	std::memmove(&_data[startPosition], &_data[endPosition], _count - endPosition);

	_count -= size;
	return true;
}

bool Buffer::Insert(size_t index, const ByteSpan &span)
{
	if((_count + span.size) > _size)
		return false;

	if (index > _count)
		return false;

	std::memmove(&_data[index + span.size], &_data[index], _count - index);	
	std::memcpy(&_data[index], span.data, span.size);
	_count += span.size;

	return true;
}

bool Buffer::Insert(size_t index, byte object)
{
	if(IsFull() == true)
		return false;

	if (index >= _count)
		return false;

	std::memmove(&_data[index+1], &_data[index], _count - index);	
	_data[index] = object;
	_count++;
	return true;
}

bool Buffer::Insert(size_t index, const byte *data, size_t size) 
{ 
	return Insert(index, ByteSpan{ data, size }); 
}
