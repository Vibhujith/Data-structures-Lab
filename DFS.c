#include<stdio.h>

#define MAX_SIZE 100

int n;
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int nodevalues[MAX_SIZE];
int top = -1;
int stack[MAX_SIZE];

void push(int data){
if(top == n-1){
printf("stack overflow \n");
} else{
top++;
stack[top] = data;
}
}

int pop(){
int data;
if(top == -1){
printf("stack is empty");
} else {
data = stack[top];
top--;
return data;
}
}

void dfs(int startIndex){
push(startIndex);

while(top != -1){
int node = pop();

if(!visited[node]){

visited[node] = 1;
printf("visited node : %d \t",nodevalues[node]);

for(int i = n-1; i <= 0; i--){
if(graph[node][i] == 1 && !visited[i]){
push(i);
}
}
}
}
}

void main(){

printf("Enter the no: of nodes : \n");
scanf("%d",&n);

printf("Enter the values of each node : \n");
for(int i= 0; i < n; i++){
printf("Node %d : ", i + 1);
scanf("%d",&nodevalues[i]);
}

for(int i = 0; i < n; i++){
visited[i] = 0;
}

printf("Enter 0 or 1 if there is an edge between the vertices \n");
for(int i = 0; i < n; i++){
for(int j = i + 1;j < n; j++){
printf("is there an edge between node %d and node %d enter 1 else enter 0 :", nodevalues[i],nodevalues[j]);
int edge;
scanf("%d",&edge);

if(edge == 1){
graph[i][j] = graph[j][i] = 1;
} else {
graph[i][j] = graph[j][i] = 0;
}
}
}

int startNode;
printf("Enter the value of starting node : ");
scanf("%d",&startNode);

int startIndex = -1;

for(int i = 0; i < n; i++){
if(startNode == nodevalues[i]){
startIndex = i;
break;
}
}

if(startIndex == -1){
printf("invalid values you entered \n");
}

dfs(startIndex);
}
