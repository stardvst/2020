#include <iostream>
#include <functional>

class A
{
private:
	using tCallback = std::function<void(int result)>;

	void longRunningFunction(tCallback cb)
	{
		// ...
		int result = 0;
		cb(result);
	}

	void theCallback(int result)
	{
		std::cout << "Result: " << result << '\n';
	}

public:
	int longRunningFunctionAsync()
	{
		auto callback = std::bind(&A::theCallback, this, std::placeholders::_1);

		// could be called from another thread
		longRunningFunction(callback);
	}

};

int main()
{
	A o;
	o.longRunningFunctionAsync();
}
