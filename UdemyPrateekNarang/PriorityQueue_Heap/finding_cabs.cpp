#include<bits/stdc++.h>

using namespace std;

class Car{
public:
	string id;
	int x,y;

	Car(string id,int x,int y){
		this->id = id;
		this->x = x;
		this->y = y;
	}
	public:
		int dist() const{
		return x*x+y*y;
	}
};

class carCompare{
	bool operator()(const Car A,const Car B){
		return A.dist()<B.dist();//Willl create a minheap
	}
};

bool distCompare(Car A,Car B){
	return A.dist()>B.dist();
}

void printNearestCars(vector<Car> cars,int k)
{
	// Create a max heap of size k
	priority_queue<Car,vector<Car>,carCompare> max_heap(cars.begin(),cars.begin()+k);
	for(int i=k;i<cars.size();i++){
		auto car = cars[i];
		if(car.dist()<max_heap.top().dist())
		{
			max_heap.pop(); //Removes the root node largest.
			max_heap.push(car);
		}
	}
	// print all the cars inside the heap they will be the smallest.
	vector<Car> output;
	while(!max_heap.empty()){
		// cout<<max_heap.top().id<<endl;
		output.push_back(max_heap.top());
		max_heap.pop();
	}
	sort(output.begin(),output.end(),distCompare);
}
// Here we have created the vector in which we are storing all the cars which are present.
int main()
{
    int N,K;
    cin>>N>>K;

    string id;
    int x,y;

    vector<Car> cars;

    for(int i=0;i<N;i++){
    	cin>>id>>x>>y;
    	Car car(id,x,y);
    	cars.push_back(car);
    }

    printNearestCars(cars,K);
}