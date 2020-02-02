// old way
namespace org
{
	namespace group
	{
		namespace project
		{
			namespace gui
			{
				struct MyStructOld
				{
				};
			}
		}
	}
}

// c++17
namespace org::group::project::core
{
	struct MyStructNew
	{
	};
}

int main()
{
	org::group::project::gui::MyStructOld sOld;
	org::group::project::core::MyStructNew sNew;
}
