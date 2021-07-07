#include <bits/stdc++.h> 
using namespace std; 

class petrolPump 
{ 
	public: 
	int petrol; 
	int distance; 
}; 

int circularTour(vector<petrolPump> arr) 
{ 
	int start = 0; 
    int extraPetrol=0;
	int less = 0;
    int n= arr.size();

	for(int i = 0; i<n; i++){
        extraPetrol += arr[i].petrol - arr[i].distance;
        if(extraPetrol < 0){
            start = i+1;
            less = less + abs(extraPetrol);
            extraPetrol = 0;
        }
    }

    if(extraPetrol-less>=0){
        return start;
    }
    else{
        return -1;
    }
} 

int main() 
{ 
	vector<petrolPump> arr = {{4,6},{6,5}, {7,3}, {0,5}}; 
	int start = circularTour(arr); 

	(start == -1)? cout<<"No solution": cout<<"Start = "<<start; 

	return 0; 
} 
