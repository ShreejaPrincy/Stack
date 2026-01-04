//my code //approach
//Sorting a smaller stack
//Inserting one element at its correct position

//Important Pitfall

// - Never call top() on an empty stack.
// - While combining conditions, always check empty() before top():
//✅ if (st.empty() || st.top() <= x)
//❌ if (st.top() <= x || st.empty()) → causes undefined behavior

#include <bits/stdc++.h> 
void insert_at_position(stack<int>&st,int x){
	if(st.empty() || st.top()<=x){
		st.push(x);
		return;
	}

	int t=st.top();
	st.pop();
	insert_at_position(st,x);
	st.push(t);
}
void sortStack(stack<int> &stack)
{
	if(stack.size()==1)	return;

	int x=stack.top();
	stack.pop();
	sortStack(stack);
	insert_at_position(stack,x);

}



