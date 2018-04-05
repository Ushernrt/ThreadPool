 ///
 /// @file    MutexLock.h
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 16:03:01
 ///
#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__


#include "Noncopyable.h"
#include <pthread.h>

namespace wd{

class MutexLock
: public Noncopyable
{
	public:
		MutexLock();
		~MutexLock();

		pthread_mutex_t * getMutexLockPtr();

		void lock();
		void unlock();
	private:
		pthread_mutex_t _mutex;
		bool _isLocking;
};

class MutexLockGuard{
	public:
		MutexLockGuard(MutexLock & mutex)
		: _mutex(mutex){
			_mutex.lock();
		}

		~MutexLockGuard(){
			_mutex.unlock();
		}
	private:
		MutexLock & _mutex;
};

}//end of namespace wd


#endif
