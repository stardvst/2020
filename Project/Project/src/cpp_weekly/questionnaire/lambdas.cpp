#include <iostream>
#include <vector>

// #1. reasons for wanting lambda to function pointer conversion

// 1. use in place of c function pointer
extern "C" {
	void useCallback(int (*)(int))
	{
	}
}

void func()
{
	useCallback([](int i)
	{
		return i + 2;
	});
}

// 2. avoid overhead of std::function
void useFunctions()
{
	std::vector<int(*)(int, int)> vec;
	vec.push_back([](int i, int j)
	{
		return i + j;
	});
	vec.push_back([](int i, int j)
	{
		return i * j;
	});
}

// #2. practical applications of inheriting from lambdas

// 1. direct access to operator()()

// #3. implement this in c++98:
// [n0 = 0, n1 = 1]() mutable { n0 = std::exchange(n1, n0 + n1); return n0; }

struct Fib
{
	int n0;
	int n1;

	int operator()() /*const*/
	{
		//n0 = std::exchange(n1, n0 + n1);
		const int oldN1 = n1;
		n1 = n0 + n1;
		n0 = oldN1;
		return n0;
	}
};

// #4. implement this in c++98:
// a) auto add = [](const auto &lhs, const auto &rhs) { return lhs + rhs; };
// b) auto lazy = [](const auto &func, const auto &lhs, const auto &rhs)
//		{
//			return [func, lhs, rhs]
//			{
//				return func(lhs, rhs);
//			};
//		};

struct add
{
	//template <typename LHS, typename RHS>
	template <typename Param>
	Param operator()(const Param &lhs, const Param &rhs) const
	{
		return lhs + rhs;
	}

	template <typename LHS, typename RHS>
	struct Return_Type
	{
		typedef LHS type;
	};
};

struct lazy
{
	template <typename Func, typename LHS, typename RHS>
	struct Inner
	{
		Func cb;
		LHS lhs;
		RHS rhs;

		Inner(const Func &c, const LHS &l, const RHS &r)
			: cb(c)
			, lhs(l)
			, rhs(r)
		{
		}

		typename Func::template Return_Type<LHS, RHS>::type operator()() const
		{
			return cb(lhs, rhs);
		}
	};

	template <typename Func, typename LHS, typename RHS>
	Inner<Func, LHS, RHS>
		operator()(const Func &cb, const LHS &lhs, const RHS &rhs) const
	{
		return Inner<Func, LHS, RHS>(cb, lhs, rhs);
	}
};

//int main()
//{
//	std::cout << lazy()(add(), 3, 4)() << '\n';
//}

// #5. explain the difference

template <typename First, typename Second>
struct pair1
{
	First first;
	Second second;
};

template <typename First, typename Second>
struct pair2
{
	// needs to perform move operations to initialize first/second
	template <typename First_, typename Second_>
	pair2(First_ &&first_, Second_ &&second_)
		: first(std::forward<First_>(first_))
		, second(std::forward<Second_>(second_))
	{
	}

	First first;
	Second second;
};

// helper class to reason about object lifetime
struct Helper
{
	Helper() { std::puts("Helper()"); }
	~Helper() { std::puts("~Helper()"); }
	Helper(const Helper &) { std::puts("Helper(const Helper &)"); }
	Helper(Helper &&) { std::puts("Helper(Helper &&)"); }
	Helper &operator=(const Helper &) { std::puts("operator=(const Helper &)"); }
	Helper &operator=(Helper &&) { std::puts("operator=(Helper &&)"); }
};

// what happens when constructing the objects?
// what is the constexpr story?
// should pair2's constructor be explicit?
// in what context can pair1 be constructed?

/*
int main()
{
	{
		// construct two (in-place), destroy two; no copy/move
		std::puts("pair1");
		pair1<Helper, Helper> p1{ Helper{}, Helper{} };
	}

	{
		// needs to perform move operations to initialize first/second
		std::puts("\npair2");
		pair2<Helper, Helper> p2{ Helper{}, Helper{} };
	}
}
*/

// #6. how and why are two options generating so different code?
// why does option 2 compile into more code (1300 lines for many parameters vs 416)?

#include <cstdio>
#include <string>

#define OPTION_1

template <typename ...Param>
void printList(const std::string &c1, const Param &...params)
{
#ifdef OPTION_1
	auto printElement = [&](const auto &p)
	{
		std::puts((c1 + ": " + p).c_str());
	};

	// we have function, and call it n times, which is fine
	(printElement(params), ...);
#endif

#ifdef OPTION_2
	// we have lambda being defined inside fold expression =>
	// compiler is forced to expand (generate) it n times,
	// and not able to optimize it
	([&](const auto &p)
	{
		std::puts((c1 + ": " + p).c_str());
	}(params), ...);
#endif
}

int main()
{
	printList("Hello", "1", "2", "3", "4", "5", "6", "7");
}

// #7. do lambda objects follow normal lifetime rules?
// yes, captures are destroyed when lambda goes out of scope

// #8. how do lambdas help us write efficient code?

void theVec()
{
	// const vector
	const auto vec = []
	{
		std::vector<int> vec(10, 10);
		vec.push_back(42);
		return vec;
	}();
}

// #9. how is it possible to overuse lambdas?
// lambdas inside of templates
