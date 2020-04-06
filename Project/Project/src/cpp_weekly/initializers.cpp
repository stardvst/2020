struct S1
{
	int i;
	float f;
};

struct S2
{
	int i;
	float f;
	double d;

	// warning
	/*S() : d(1.0), i(2)
	{
	}*/
};

struct Parameters
{
	int i;
	float f;
	double d;
};

void useParams(Parameters p)
{
}

int main()
{
	// either all initializer clauses should be designated or
	// none of them should be
	//S1 s1{ .i = 1, 3.4 };

	S1 s2{ .i = 1, .f = 3.4 };

	// missing initializer for member 'S1::i'
	// must appear in the same order as the data members
	//S1 s3{ .f = 3.4, .i = 1 };

	// missing initializer for member 'S::d'
	//S2 s4{ .i = 1, .f = 3.4 };

	// missing initializer for member 'S::f'
	//S2 s5{ .i = 1, .d = 3.4 };

	// missing initializer for member 'S2::f'
	//S2 s6{ .i = 1, .d = 3.4 };

	// can we leave the type off completely?
	useParams(Parameters{ .i = 3, .d = 4.5 });
	useParams({ .i = 3, .d = 4.5 });
}
