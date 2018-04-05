 ///
 /// @file    MutexLock.cc
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 17:33:09
 ///

#include "MutexLock.h"

namespace wd{

	MutexLock::MutexLock(){
		pthread_mutex_init(&_mutex, NULL);
	}

	void MutexLock::lock(){
		pthread_mutex_lock(&_mutex);
	}

	void MutexLock::unlock(){
		pthread_mutex_unlock(&_mutex);
	}

	pthread_mutex_t * MutexLock::getMutexLockPtr(){
		return &_mutex;
	}
	
	MutexLock::~MutexLock(){
		pthread_mutex_destroy(&_mutex);
	}


}// end of namespace wd
