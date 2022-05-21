class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       //we maintain defiecit to keep track of petrol defiecency to reach from 0 to start when it starts from some other point other then 0 as it wont need to traverse that certain length 0 to start again to find whther it can reach there or not as if deficit+currBal>=0 then it can reach there or not
       int defeicit=0;
       int balance=0;
       int start=0;
       for(int i=0;i<n;i++){
           balance+=p[i].petrol-p[i].distance;
        //    when bal becomes <0 then we shift the start point to i+1 and store the defiency petrol to reach till i th point from 0 point
           if(balance<0){
               defeicit+=balance;
               start=i+1;
               balance=0;
           }
       }
       if(defeicit+balance>=0){
           return start;
       }
       else{
           return -1;
       }
    }
};


