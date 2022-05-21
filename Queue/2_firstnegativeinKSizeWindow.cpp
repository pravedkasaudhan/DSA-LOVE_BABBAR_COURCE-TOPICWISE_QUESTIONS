vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        deque<long long> dq;
        vector<long long> ans;

        //push the negative no. till k in dequeue
        for(long long i=0;i<K;i++){
            if(A[i]<0){
                dq.push_back(i);
            }
        }

        // take the answer from dequeue as it holds the first negative no ok first k window
        if(dq.size()>0){
           ans.push_back(A[dq.front()]); 
        }
        else{
            ans.push_back(0);
        }
        
        // iterate the next n-k windows
        for(long long i=K;i<N;i++){
            //for current windows check keep the front of dequeue within k block of windows
            while(!dq.empty() && i-dq.front()>=K){
                dq.pop_front();
            }

            // if element in negative add in dequeue
            if(A[i]<0){
                dq.push_back(i);
            }

            // push in answer the first coming negative no of current block of k windows ,i.e present at front of dequeue
             if(dq.size()>0){
           ans.push_back(A[dq.front()]); 
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
 }