#include<stdio.h>
struct queue{
	int size;
	int q[size];
	int front;
	int rear;
};
// void enque(struct que , int data){
	
// }
// struct node{
// 	int data1;
// 	int data2;
// };
// void check(struct node n){
// 	printf("in check function n.data1 = %d",n.data1);
// 	printf("in check function n.data2 = %d",n.data2);	
// }
int main(){
	struct queue que;
	que.size = 4;
	printf("%d",sizeof(que.q)/sizeof(que.q[0]));
}