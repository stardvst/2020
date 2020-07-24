#include <iostream>

template <typename T, size_t size>
class Array
{
public:
	constexpr int Size() const
	{
		return size;
	}

	T &operator[](size_t index)
	{
		if (!(index < size))
			__debugbreak();
		return m_data[index];
	}

	const T &operator[](size_t index) const
	{
		if (!(index < size))
			__debugbreak();
		return m_data[index];
	}

	T *Data() { return m_data; }
	const T *Data() const { return m_data; }

private:
	T m_data[size];

};

int main()
{
	constexpr int size = 5;
	Array<int, size> data;

	memset(&data[0], 0, data.Size() * sizeof(int));

	data[1] = 4;
	data[2] = 5;

	const auto &ref = data;
	for (auto i = 0; i < data.Size(); ++i)
	{
		std::cout << data[i] << ' ';

		// cannot call without const version of operator[]:
		// binary '[': no operator found which takes a left - hand operand of
		// type 'const Array<int,5>' (or there is no acceptable conversion)
		std::cout << ref[i] << '\n';
	}
}
