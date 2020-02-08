struct SOld
{
	SOld() : value(5)
	{
	}
	int value;
};

struct SNew
{
	int value = 5;
};

int main()
{
	SOld s1;
	SNew s2;

	//return s1.value;
	return s2.value;
}