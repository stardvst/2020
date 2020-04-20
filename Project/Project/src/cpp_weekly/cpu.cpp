#include <array>
#include <numeric>

// to vectorize
// gcc, clang: -march=native
// msvc: /arch:AVX2

int sum(const std::array<int, 16> &a)
{
	return std::accumulate(begin(a), end(a), 0);
}
