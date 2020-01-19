#include <iostream>

namespace detail
{

struct deleterBase
{
	virtual ~deleterBase() = default;
	virtual void operator()(void *ptr) = 0;
};

// inheritance is necessary to be able to hold pointer
// to base class where the actual type is not known
template <typename TDeleter>
struct deleter : deleterBase
{
	void operator()(void *ptr) override
	{
		std::cout << __FUNCTION__ << '\n';
		delete static_cast<TDeleter *>(ptr);
	}
};

}

template <typename T>
class simplePtr
{
public:
	template <typename U>
	simplePtr(U *ptr)
		: m_ptr(ptr)
		, m_deleter(new detail::deleter<U>())
	{
	}

	~simplePtr()
	{
		(*m_deleter)(m_ptr);
		delete m_deleter;
	}

	T get() const
	{
		if (m_ptr)
			return *m_ptr;
		throw std::runtime_error("Dereferencing nullptr.");
	}

private:
	T *m_ptr = nullptr;

	// actual type is erased
	detail::deleterBase *m_deleter = nullptr;
};

int main()
{
	try
	{
		simplePtr<int> ptr(new int(5));
		std::cout << ptr.get() << '\n';
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << '\n';
	}
}
