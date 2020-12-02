#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <omp.h>
#include <list> 

using namespace std;


int nodesExplored;
int nodesGenerated;
string optrs[] = {"UP", "DOWN", "LEFT", "RIGHT"};
int goal[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,15};

class Node{

  public:

     int puzzle[16];
     Node *parent;
     string optr;
     int static id;

     Node(){
		 parent = NULL;
		 optr = "";
		 id++;
     }
    Node(int board[]){
		optr = "";
		parent = NULL;

		for(int i=0;i<16;i++)
			this->puzzle[i] = board[i];
		id++;
    }
     Node(Node *temp){
		 this->parent = temp->parent;
		 optr = temp->optr;

		 for(int i=0;i<16;i++)
			this->puzzle[i] = temp->puzzle[i];
		 id++;
    }
    string ToString(){
		string retStr="";
		for(int i=0;i<16;i++){
			stringstream ss;
			ss << puzzle[i];
			string str = ss.str();
			retStr = retStr + str;	
		}	
		return retStr;
    }

};

int Node::id=0;

void Print(int puzzle[], int num){
	
	if(num == 0) cout<<"Solution Found: ";
	else 		 cout<<"Step#"<<num<<":";
	
	cout<<endl;

	for(int i=0;i<16;i++){
    	cout<<puzzle[i]<<" ";
    	if((i+1)%4 == 0)
			cout<<endl;   
	}
}
void SolPath(Node *head){

    Node *p = head;
    
	if(p==NULL)
    	return;
	  
    int i = 0;
    
	while(p!=NULL){
		Print(p->puzzle,i);
		p = p->parent;
		i++;
    }
    
	cout<<endl;
}
bool GoalTest(int board[]){

	int count = 0;
	for(int i=0;i<16;i++){
		if(board[i] == goal[i])
			count++;
	}

	if(count == 16)
		return true;

	return false;
}
bool validate(int board[], string o){
    
     if(o == "UP"){
        if(board[0] == 0 || board[1] == 0 || board[2]== 0 || board[3]== 0)
            return false;
        else 
            return true;
     }
     
     else if(o == "DOWN"){
        if(board[15] == 0 || board[14] == 0 || board[13]== 0 || board[12]== 0)
            return false;
        else 
            return true;         
     }
     
     else if(o == "LEFT"){
        if(board[0] == 0 || board[4] == 0 || board[8]== 0 || board[12]== 0)
           return false;
        else 
           return true;
     }
     
     else{
        if(board[3] == 0 || board[7] == 0 || board[11]== 0 || board[15]== 0)
            return false;
        else 
            return true;
     }
}
int SearchBlank(int board[]){
	for(int i=0;i<16;i++)
	  if(board[i] == 0)
		return i;
}

int m=0,n=4;
int cal(int temp[10][10],int t[10][10])
{
	int i,j,m=0;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(temp[i][j]!=t[i][j])
                m++;
		}
	return m;
}

int check(int a[10][10],int t[10][10])
{
	int i,j,f=1;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(a[i][j]!=t[i][j])
            {
				f=0;
				break;
			}
	return f;
}
int main() {
  
int p,i,j,n=4,a[10][10],t[10][10],temp[10][10],r[10][10],ch1=0;
	int m=0,x=0,y=0,d=1000,dmin=0,l=0,x1,y1;
    printf("\n19BCE0531 KARTIK KHANNA | 19BCE0675 ANMOL BHARDWAJ\n");
    printf("\nEnter the 4*4 matrix to be solved,space with zero :\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d",&a[i][j]);
    printf("\nEnter the 4*4 target matrix,space with zero :\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d",&t[i][j]);

    printf("\nYour Entered Matrix is :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        printf("%d\t",a[i][j]);
        }
        printf("\n");

    }
    printf("\nYour Target Matrix is :\n");
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        printf("%d\t",t[i][j]);
        }
        printf("\n");

    }
	ofstream out;
	out.open("input.txt");
    	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		{ out<< a[i][j];
	  	  out<<" ";
		}
		 out<<"\n";
		}
	//Close the file
	out.close();
     int z=0;
	 for(i=0;i<4;i++){
		 for(j=0;j<4;j++){
         goal[z]=t[i][j];
		 z++;
		 }
	 }

    int ch;
    printf("\n");
    printf("1.Solve using computer by array method\n\n2.Solve manually\n\n3. Solve using computer by backtracking\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    printf("\n");
    int b=0;

    if(ch==1){
        while(!(check(a,t)))
        {   
            l++;
            d=1000;
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                {
                    if(a[i][j]==0)
                    {
                        x=i;
                        y=j;
                    }
                }
            //To move upwards
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(x!=0)
            {
                p=temp[x][y];
                temp[x][y]=temp[x-1][y];
                temp[x-1][y]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            //To move downwards
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(x!=n-1)
            {
                p=temp[x][y];
                temp[x][y]=temp[x+1][y];
                temp[x+1][y]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            //To move right side
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(y!=n-1)
            {
                p=temp[x][y];
                temp[x][y]=temp[x][y+1];
                temp[x][y+1]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            //To move left
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                    temp[i][j]=a[i][j];
            if(y!=0)
            {
                p=temp[x][y];
                temp[x][y]=temp[x][y-1];
                temp[x][y-1]=p;
            }
            m=cal(temp,t);
            dmin=l+m;
            if(dmin < d)
            {
                d=dmin;
                for(i=0;i < n;i++)
                    for(j=0;j < n;j++)
                        r[i][j]=temp[i][j];
            }
            printf("\nCalculated Intermediate Matrix Value :\n");
            for(i=0;i < n;i++)
            {
                for(j=0;j < n;j++)
                printf("%d\t",r[i][j]);
			printf("\n");
            }
            for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                {
                    a[i][j]=r[i][j];
                    temp[i][j]=0;
                }
            if(b>5)
               break;
                b++;
        }
        if(check(a,t)){
            printf("\nCongratulations!");

        }
        else
        {
            printf("\nFailure");
        }
        
	}
    else if(ch==2){

        while(1)
        {
            for(i=0;i < n;i++)
        {
                for(j=0;j < n;j++)
                {
                    if(a[i][j]==0)
                    {
                        x1=i;
                        y1=j;
                    }
                }
        }
            printf("\n1.Up\n2.Down\n3.Left\n4.Right\n");
            printf("Choose your next move: ");
            scanf("%d",&ch1);
            switch(ch1)
            {
            case 1:
                if(x1!=0)
                {
                    p=a[x1][y1];
                    a[x1][y1]=a[x1-1][y1];
                    a[x1-1][y1]=p;
                    if(!check(a,t))
                    {
                        	for(i=0;i<n;i++)
                            {
                                for(j=0;j < n;j++){
                                    printf("%d\t",a[i][j]);
                                }
                                printf("\n");
                            }

                    }
                    else
                    {
                        printf("\nCongratulations !!!\n");
                        exit(0);
                    }

                }
                break;
            case 2:
                if(x1!=n-1)
                {
                    p=a[x1][y1];
                    a[x1][y1]=a[x1+1][y1];
                    a[x1+1][y1]=p;

                    if(!check(a,t))
                    {
                        	for(i=0;i < n;i++)
                            {
                                for(j=0;j < n;j++)
                                    printf("%d\t",a[i][j]);
                                printf("\n");
                            }

                    }
                    else
                    {
                        printf("\nCongratulations !!!\n");
                        exit(0);
                    }

                }
                break;
            case 3:
                if(y1!=0)
                {
                    p=a[x1][y1];
                    a[x1][y1]=a[x1][y1-1];
                    a[x1][y1-1]=p;

                    if(!check(a,t))
                    {
                        	for(i=0;i < n;i++)
                            {
                                for(j=0;j < n;j++)
                                    printf("%d\t",a[i][j]);
                                printf("\n");
                            }

                    }
                    else
                    {
                        printf("\nCongratulations !!!\n");
                        exit(0);
                    }

                }
                break;
            case 4:
                if(y1!=n-1)
                {
                    p=a[x1][y1];
                    a[x1][y1]=a[x1][y1+1];
                    a[x1][y1+1]=p;

                if(!check(a,t))
                    {
                        	for(i=0;i < n;i++)
                            {
                                for(j=0;j < n;j++)
                                    printf("%d\t",a[i][j]);
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("\nCongratulations !!!\n");
                        exit(0);
                    }

                }
                break;
            default:
                printf("Wrong Choice");
            }
        }
	}
     else if(ch==3){

	ifstream in;
	in.open("input.txt");

	int puzzle[16];

	
	for(int i=0;i<16;i++)
		in >> puzzle[i];
	
	in.close();
	
	
	Node node = new Node(puzzle);

	static bool flag = true;
	
	queue<Node> BFS_Q;

	BFS_Q.push(node);


	if(GoalTest(node.puzzle)){
		Print(node.puzzle,0);
	}
	else{
	
	
		list<string> hashSet;
		
		
		#pragma omp parallel num_threads(8) shared(BFS_Q, hashSet, nodesExplored, nodesGenerated)
		{	
			
			while(flag){
					
				#pragma omp critical
				{ if(!BFS_Q.empty()){
				}
						       	
					Node* current =  new Node (BFS_Q.front());
					
					//Pop it
					BFS_Q.pop();
				
					
					hashSet.push_back(current->ToString());
					
					//Increment the nodes explored
					nodesExplored++;

					
			       		for(int i=0;i<4 && flag;i++){
						
						
						 if(validate(current->puzzle,optrs[i]) == true){
						 
						 	
							int board[16];
							for(int j=0;j<16;j++)
								board[j] = current->puzzle[j];
							   
							
							int blankIndex = SearchBlank(board);
							
							
							if(optrs[i] == "UP"){
							    board[blankIndex] = board[blankIndex-4];
							    board[blankIndex-4] = 0;
							}
							else if(optrs[i] == "DOWN"){
							    board[blankIndex] = board[blankIndex+4];
							    board[blankIndex+4] = 0;
							}
							else if(optrs[i] == "LEFT"){
							    board[blankIndex] = board[blankIndex-1];
							    board[blankIndex-1] = 0;
							}
							else{
							    board[blankIndex] = board[blankIndex+1];
							    board[blankIndex+1] = 0;
							}	
							
							
							Node* child = new Node(board);
							
						
							child->parent = current;
							
						
							child->optr = optrs[i];
							
							
							nodesGenerated++;

							
							if(!(find(hashSet.begin(),hashSet.end(),child->ToString())
								!= hashSet.end())){	
								
													
								if(GoalTest(child->puzzle) == true){
									
									SolPath(child);
									
									flag = false;
									
								}
								
								
								BFS_Q.push(child);
					       	
							}
						  }
					}
				  }
			}
		 }
	}

   

    cout<<"Depth First Search Completed"<<endl;
    cout<<"Nodes Explored: "<<nodesExplored<<endl;
    cout<<"Nodes Generated: "<<nodesGenerated<<endl;	
   }
    return 0;
}


