class animal {
	public:
		virtual void bark()
		{
			throw "What is bark?";
		}
};

class elephant : public animal { };

int main()
{
	elephant e;
	e.bark();
	return 0;
}
