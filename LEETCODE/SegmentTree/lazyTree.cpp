#include<bits/stdc++.h>
using namespace std;

void buildTree(int *a, int *tree, int start, int end, int treeIndex){
	
	if(start==end){
		tree[treeIndex]=a[start];
		return;
	}
	
	int mid=(start+end)/2;
	
	buildTree(a,tree,start,mid,2*treeIndex);
	buildTree(a,tree,mid+1,end,2*treeIndex+1);
	
	tree[treeIndex]=min(tree[2*treeIndex],tree[2*treeIndex+1]);
	return;
}

void updateTree(int *tree, int *lazy, int start, int end, int left, int right, int value,int treeIndex){
	
	if(start>end){
		return;
	}
	
	//updation in lazy array
	if(lazy[treeIndex]!=0){
		tree[treeIndex]+=lazy[treeIndex];
		
		//check if it is not the leaf node
		if(start!=end){
			lazy[2*treeIndex]+=value;
			lazy[2*treeIndex+1]+=value;
		}
		lazy[treeIndex]=0;
	}
	
	// no overlap 
	if(end<left || start>right)
		return;
	
	// complete overlap
	
	if(start>=left && end<=right){
		tree[treeIndex]+=value;
		if(start!=end){
			lazy[2*treeIndex]+=value;
			lazy[2*treeIndex+1]+=value;
		}
		return;
	}
	//partial overlap
	
	int mid=(start+end)/2;
	
	updateTree(tree, lazy, start, mid,  left, right,  value, 2*treeIndex);
	updateTree(tree, lazy, mid+1, end,  left, right,  value, 2*treeIndex+1);
	
	tree[treeIndex]=min(tree[2*treeIndex],tree[2*treeIndex+1]);
}


int querry(int *tree, int *lazy, int start, int end, int left, int right,int treeIndex){
	
//	if(start>end){
//		return INT_MAX;
//	}
	
	// no overlap 
	if(end<left || start>right){
		return INT_MAX;
		}
	
	// complete overlap
	
	if(start>=left && end<=right){
		if(start==end){
		tree[treeIndex]+=lazy[treeIndex];
		lazy[treeIndex]=0;
		return tree[treeIndex];
	}
	}
	//partial overlap
	
	int mid=(start+end)/2;
	
	int x=querry(tree, lazy, start, mid,  left, right, 2*treeIndex);
	int y=querry(tree, lazy, mid+1, end,  left, right, 2*treeIndex+1);
	
	tree[treeIndex]=min(x,y);
}


int main(){
	
	int n;
	cin>>n;
	
	int *a=new int[n]();
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int *tree=new int[3*n]();
	int *lazy=new int[3*n]();
	
	int start=0,end=n-1,treeIndex=1;
	
	buildTree(a,tree,start,end,treeIndex);
	
	cout<<"SEGMENT TREE"<<"\n";
	for(int i=1;i<3*n;i++){
		cout<<tree[i]<<"\n";
	}
	cout<<"\n"<<"\n";
	
//	int left,right;
//	cout<<"Enter left and right ranges"<<"\n";
//	cin>>left>>right;
		
	updateTree(tree,lazy,start,end,0,3,3,treeIndex);
	updateTree(tree,lazy,start,end,0,1,2,treeIndex);
		
	cout<<"SEGMENT TREE"<<"\n";
	for(int i=1;i<3*n;i++){
		cout<<tree[i]<<"\n";
	}
	cout<<"\n"<<"\n";
	
	cout<<"LAZY TREE"<<"\n";
	for(int i=1;i<3*n;i++){
		cout<<lazy[i]<<"\n";
	}
	cout<<"\n"<<"\n";	
	
	int ans= querry(tree, lazy, start,  end,  0,  5, treeIndex);
	cout<<ans<<"\n";
	
		
}
