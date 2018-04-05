 ///
 /// @file    TaskQueue.h
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 19:55:39
 ///

#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"

#include <queue>

namespace wd{

class Task;

class TaskQueue{

	using Product = Task *;

	public:
		TaskQueue(int queSize);
		
		void push(Product);
		Product pop();

		bool full() const;
		bool empty() const;

		void wakeup();

	private:
		MutexLock _mutex;
		Condition _notFull;
		Condition _notEmpty;
		size_t _queSize;
		std::queue<Product> _que;
		bool _flag;
};


}//end of namespace wd
#endif


