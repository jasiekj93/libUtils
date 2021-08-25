#pragma once

/**
 * @file	Mutex.hpp
 * @author	Adrian Szczepanski
 * @date	24-03-2021
 * @brief
 * @details
**/

#include <atomic>

namespace Utils
{
	class Mutex
	{
	public:
		Mutex() { atomic_flag_clear(&_guard); }

		inline bool TryLock() { return !atomic_flag_test_and_set(&_guard); }
		inline void Lock() { do {} while (TryLock()); }
		inline void Unlock() { atomic_flag_clear(&_guard); }

	private:
		volatile std::atomic_flag _guard;
	};

}