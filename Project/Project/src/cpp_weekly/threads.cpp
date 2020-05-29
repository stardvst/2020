#include <thread>
#include <chrono>

void doNothingT()
{
}

// jthread accepts stop stop_token
void doNothingJT(std::stop_token st)
{
	// Killed - processing time exceeded
	//while (true)
	//{
	//}

	puts("start");
	while (!st.stop_requested())
	{
		puts("working");
		// do work
	}
	puts("stop");
}

int main()
{
	//std::thread t{ doNothing };

	//t.join();
	// terminate called without an active exception
	// because unjoined thread will call terminate() at destruction

	std::jthread jt{ doNothingJT };

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);

	/*
	   for (auto i = 0; i < 1000; ++i)
		{
			std::this_thread::yield();
			std::this_thread::yield();
			std::this_thread::yield();
		}
	*/
	// joins thread if it can, something like this
	/*
	jt.request_stop();
	jt.join();
	*/
}
