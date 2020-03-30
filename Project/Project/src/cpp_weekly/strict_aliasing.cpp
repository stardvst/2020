#include <cstdint>
#include <cstddef>

enum struct Data : std::uint8_t
{
};

/*
    pointer to character types are allowed to 'alias' with different types,
    where other's usually aren't

    src and dest could overlap, if so, move one byte at a time
    otherwise, do operations all at once

    lea rax, [rdi+16]
    cmp rsi, rax
    jnb .L5
    lea rax, [rsi+64]
    cmp rdi, rax
    jb .L2
*/
void extendEight(const std::uint8_t *src, std::uint32_t *dest)
{
    // tt takes two pointers, each to what we must hope is an array with 16 elements,
    // and copies from src to dest one element at a time.
	for (std::size_t idx = 0; idx < 16; ++idx)
		dest[idx] = src[idx];
}

// uint16_t* and uint32_t* aren't allowed to alias,
// so the compiler can optimize more aggressively
void extendSixteen(const std::uint16_t *src, std::uint32_t *dest)
{
}

/*
   now compiler thinks there's no way source and destination
   can overlap because they're different types,
   and either one is const char *, so it removes the check to see if
   they overlap
*/
void extendData(const Data *src, std::uint32_t *dest)
{
	for (std::size_t idx = 0; idx < 16; ++idx)
		dest[idx] = static_cast<std::uint8_t>(src[idx]);
}

void callExtend(Data *src)
{
    // UB: alias pointer in context where it's not allowed
    // as src wasn't const char * or unsigned char or something
    // that is char or a std::byte or uint8
    //extendEight(src, reinterpret_cast<std::uint32_t *>(src));
}

int main()
{
}
