#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

	class BaseException
	{
	public:
		BaseException() {}
		virtual ~BaseException(){}

		virtual const char * what() const throw() = 0;  // or noexcept
	};

	class QueueEmpty : public BaseException
	{
	public:
		QueueEmpty() {}
		virtual const char * what() const throw();  // or noexcept
	};

	inline const char * QueueEmpty::what() const throw()
	{
		return "Queue Empty";
	}

#endif