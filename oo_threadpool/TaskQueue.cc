 ///
 /// @file    TaskQueue.cc
 /// @author  xiu(1107040857@qq.com)
 /// @date    2018-03-20 20:01:40
 ///

#include "TaskQueue.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd{

	TaskQueue::TaskQueue(int queSize)
	: _mutex()
	, _notFull(_mutex)
	, _notEmpty(_mutex)
	, _queSize(queSize)
	, _flag(true)
	{}

	bool TaskQueue::full() const{
		return _queSize == _que.size();
	}

	bool TaskQueue::empty() const{
		return _que.size() == 0;
	}

	void TaskQueue::push(TaskQueue::Product product){
		MutexLockGuard mlg(_mutex);
		while(full()){
			_notFull.wait();
		}

		_que.push(product);
		_notEmpty.notify();
	}
	
	void TaskQueue::wakeup(){
		_flag = false;
		_notEmpty.notifyall();	
	}

	TaskQueue::Product TaskQueue::pop(){
		MutexLockGuard mlg(_mutex);

		while(_flag && empty()){
			_notEmpty.wait();
		}

		if(_flag){
			Product product = _que.front();
			_que.pop();
			_notFull.notify();
	
			return product;
		}else
			return NULL;
	}


}//end of namespace wd



