#include<iostream>
using namespace std;
int main() {
   int i,n;
   cout<<"Enter number of elements:\n";
   cin>>n;
   int *arr = new int(n);
   cout<<"Enter "<<n<<" elements:"<<endl;
   for(i = 0;i<n;i++) {
      cin>>arr[i];
   }
   cout<<"Array elements are: ";
   for(i = 0;i<n;i++) {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
   delete (arr);
   return 0;
}
