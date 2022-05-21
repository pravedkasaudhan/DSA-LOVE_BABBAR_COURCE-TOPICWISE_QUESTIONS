class TwoStack {
	int size;
	int top1;
	int top2;
	int *arr;
	
public:

    // Initialize TwoStack.
    TwoStack(int s) {
		this->size=s;
		top1=-1;
		top2=s;
		arr=new int[size];
    }
    
    // Push in stack 1.
    void push1(int num) {
		//check if space is there between stack1 and stack2
		if((top2-top1)>1){
			top1++;
			arr[top1]=num;
			
		}
    }

    // Push in stack 2.
    void push2(int num) {
		//check if space is there between stack1 and stack2
		if((top2-top1)>1){
			top2--;
			arr[top2]=num;
			
		}
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		//check if element is there
		if(top1>-1){
			int num=arr[top1];
			top1--;
			return num;
		}
		else{
			return -1;
		}
		
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		//check if element is there or not
			if(top2<size){
			int num=arr[top2];
			top2++;
			return num;
		}
		else{
			return -1;
		}
		
    }

};