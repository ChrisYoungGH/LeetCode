class Temp {
public:
	Temp() {
		++N;
		Sum += N;
	}

	static void Reset() {
		N = 0;
		Sum = 0;
	}

	static int GetSum() {
		return Sum;
	}

private:
	static int N;
	static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

class Solution1 {
public:
    int Sum_Solution(int n) {
    	Temp::Reset();

    	Temp *a = new Temp[n];
    	delete [] a;
    	a = NULL;

    	return Temp::GetSum();
    }
};




class A {
public:
	virtual int Sum(int n ) {
		return 0;
	}
};
A* Array[2];

class B : public A {
public:
	virtual int Sum(int n) {
		return Array[!!n]->Sum(n-1) + n;
	}
};

class Solution2 {
public:
    int Sum_Solution(int n) {
  		A a;
  		B b;
  		Array[0] = &a;
  		Array[1] = &b;

  		return Array[1]->Sum(n);
    }
};




typedef int (*fun)(int);

int terminator(int n) {
	return 0;
}

class Solution3 {
public:
    static int Sum_Solution(int n) {
        static fun f[2] = {terminator, Sum_Solution};
        return n + f[!!n](n-1);
    }
};