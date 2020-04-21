#include <iostream>
#include <list>

struct Task;

struct TD
{
	TD(Task *t)
		: m_t(t)
	{
	}

	Task *m_t = nullptr;

};

struct Engine
{
	std::list<TD> lst;
	void add(Task *t)
	{
		TD td(t);
		lst.push_back(td);
	}

	void print()
	{
		std::cout << lst.front().m_t << '\n';
	}
};

Engine *e = nullptr;

struct Task
{
	Task()
	{
		if (!e)
			e = new Engine;

		e->add(this);
	}
	virtual ~Task() = default;
};

struct MyTask : Task
{
	MyTask() : Task()
	{
	}
};

struct MyEngine
{
	MyEngine()
		: m_task(new MyTask())
	{
	}

	void reset()
	{
		m_task = nullptr;
	}

	MyTask *m_task = nullptr;
};

int main()
{
	MyEngine myE;
	e->print();
	myE.reset();
	e->print();
}