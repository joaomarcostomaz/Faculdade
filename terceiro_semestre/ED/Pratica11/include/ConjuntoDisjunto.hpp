
class ConjuntoDisjunto {
private:
	int* parent;
	int* rank;

public:	
	ConjuntoDisjunto(int n);
	~ConjuntoDisjunto();
	void makeSet(long x);
	void unionSet(long x, long y);
	long findSet(long x);
};
