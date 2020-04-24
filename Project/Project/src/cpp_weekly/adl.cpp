#include <iostream>
#include <vector>

namespace std
{
	// begin();
}

namespace ns
{
	struct S{};
	void useS(const S &)
	{
	}
}

namespace ns2
{
	struct S {};
	void useS(const S &)
	{
	}
}

namespace ns3
{
	struct S {};
	void useS(const ns2::S &)
	{
	}
}

int main()
{
	std::vector<int> vec;
	begin(vec);

	ns::S s;
	useS(s); // uses ADL

	ns2::S s2;
	useS(s2); // calls ns2::useS

	//ns3::S s3;
	//useS(s3); // no conversion from ns3::S to ns2::S

	std::cout << "Hello world\n"; // << exists in std namespace
}
