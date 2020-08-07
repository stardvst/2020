#include <utility>
#include <string>

template <typename Type>
struct OptionalNonTrivial
{
	~OptionalNonTrivial()
	{
		static_cast<Type *>(this)->data.~OptionalNonTrivial();
	}
};

struct OptionalTrivial
{
};

template <typename Contained>
struct Optional : std::conditional_t<std::is_trivially_destructible_v<Contained>,
	OptionalTrivial,
	OptionalNonTrivial<Optional<Contained>>>
{
	union
	{
		Contained data;
	};

	bool inited = false;

	constexpr Optional &operator=(Contained &&d)
	{
		data = std::move(d);
		inited = true;
		return *this;
	}

	// trivially destructible
	//~Optional() = default;

	// non-trivially destructible
	//~Optional() {}

	// non-trivially destructible
	/*~Optional()
	{
		if (inited)
		{
			data.~Contained();
		}
	}*/
};

template <typename Contained>
struct OptionalCpp20
{
	union
	{
		Contained data;
	};

	bool inited = false;

	constexpr OptionalCpp20 &operator=(Contained &&d)
	{
		data = std::move(d);
		inited = true;
		return *this;
	}

	~OptionalCpp20() requires(!std::is_trivially_destructible_v<Contained>)
	{
		if (inited)
		{
			data.~Contained();
		}
	}

	~OptionalCpp20() = default;
};

int main()
{
	Optional<int> obj;
	obj = 5;
	static_assert(std::is_trivially_destructible_v<Optional<int>>);
	static_assert(!std::is_trivially_destructible_v<Optional<std::string>>);

	OptionalCpp20<int> obj2;
	obj2 = 5;
	static_assert(std::is_trivially_destructible_v<OptionalCpp20<int>>);
}
