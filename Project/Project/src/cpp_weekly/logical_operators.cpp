#include <iostream>

bool checkCondition()
{
	return true;
}

bool tryDoingWork()
{
	return false;
}

int main()
{
	// if checkCondition() fails, tryDoingWork() won't execute!
	if (checkCondition() && tryDoingWork())
	{
	}

	bool bDidWork = false;
	while (checkCondition())
	{
		// subtle bug: if bDidWork became true ONCE, then
		// tryDoingWork() will never be called again in the loop
		bDidWork = bDidWork || tryDoingWork();

		// so correct way to do this is:
		const auto bNewWork = tryDoingWork();
		bDidWork = bDidWork || bNewWork;

		// another option; seems like a good idea, but
		// seems too fragile for refactoring, so leave
		// a comment when doing short circuiting like this
		bDidWork = tryDoingWork() || bDidWork;
	}

	if (bDidWork)
	{
		// some other operation
	}

	int *ptr = nullptr;
	// ...

	// okay to do
	if (ptr != nullptr && *ptr == 4)
	{
	}
}
