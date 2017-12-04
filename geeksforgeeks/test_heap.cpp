void makeHeap(vector<int> &B){
    int n=B.size();
    int i=(n-1)/2;
    while (i >= 0){
        maxHeapify(B, i);
        i--;
    }
}

void maxHeapify(vector<int> &B, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    int temp;
    
    if (l < B.size() && B[l] > B[i])
        largest = l;
    if (r < B.size() && B[r] > B[largest])
        largest = r;
    if (largest != i)
    {
        temp=B[i];
        B[i]=B[largest];
        B[largest]=temp;
        maxHeapify(B, largest);
    }
}

int Solution::kthsmallest(const vector<int> &A, int k) {
    vector<int> B;
    
    for(int i=0; i<k; i++){
        B.push_back(A[i]);
    }
    makeHeap(B);

    for(int i=k+1; i<A.size(); i++){
        if(A[i] <= B[0]){
            B[0]=A[i];
            maxHeapify(B,i);
        }
    }
    
    return B[0];
}

int main(){
    vector<int> A;
    for(int i=0; i<10; i++){
        A.push_back((i*340)%77);
    }
    makeHeap(A);
}