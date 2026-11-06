#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct student{
	int roll;
	char name[50];
	int  marks;
}student;




int main(){
int num, newSize = 0,n = 0,oldSize,totalSize;
student *arr = NULL;
student *temp = NULL;

while (1){
printf("\n=================================================\n");
printf("           STUDENT RESULT MANAGEMENT\n");
printf("\n=================================================\n");

printf("1. Register Students\n");
printf("2. Add More Students\n");
printf("3. Display All Students\n");
printf("4. Search Student\n");
printf("5. Exit\n");

printf("Enter Your Choice : ");
scanf("%d",&num);

switch(num){
	case 1:{
		printf("Enter number of students: ");
		if(scanf("%d",&n) != 1 || n <= 0){
			printf("Invalid Quantity \n");
			return 1;
				}
		arr = malloc(n * sizeof(student));
		if(arr == NULL){
			printf("Memory Alocation Failed !\n");
			return 1;
		}

		for(int i = 0;i < n; i++){
			int rollCheck;
			int exists ;
			do{
				exists = 0;

				printf("Enter %d Student Roll Number : ",i+ 1);
				scanf("%d",&rollCheck);

				for(int j = 0; j <= n; j++){
					if(rollCheck == arr[j].roll){
						exists = 1;
						printf("Roll number already exists! Try again.\n");
						break;
					}
				}
			}while(exists == 1);
			arr[i].roll = rollCheck;
			printf("Enter %d Student Name  : ",i+ 1);
			scanf("%s",arr[i].name);
			printf("Enter %d Student Marks : ",i+ 1);
			scanf("%d",&arr[i].marks);
			printf("\n");
		}

		break ;
			}

	case 2:{
		oldSize = n;
		totalSize = oldSize + newSize;
		
		printf("Enter number of students: ");
		if(scanf("%d",&newSize) != 1 || newSize <= 0){
			printf("Invalid Quantity !");
			return 0;
		}

		temp = realloc(arr, totalSize * sizeof(student));
		if(temp == NULL){
			printf("Memory Resizinig Failled !");
			return 0;
		}
		else {
			arr = temp;
			printf("Memory Sucessfuly increasesd \n\n");
		
			for(int i = n ; i <= totalSize + 1  ; i++){
				int rollCheck,exists;
				do{
					exists = 0;

					printf("\nEnter %d Student Roll Number : ",i+1);
					scanf("%d",&rollCheck);

					for(int j = 0;j <= totalSize; j++){
						if(rollCheck == arr[j].roll ){
							exists = 1;
							printf("Roll number already exists! Try again.\n");
							break;
						}
					}
					
				}while (exists == 1);
				arr[i].roll = rollCheck;
				
				printf("Enter %d Student Name : ",i+1);
				scanf("%s",arr[i].name);
				printf("Enter %d Student Marks : ",i+1);
				scanf("%d",&arr[i].marks);

			}	
		}	
		n = totalSize;
		break;
		}

	case 3 :{
		printf("\nRoll No.\t Name\t   Total Marks\n\n");
		for(int i = 0; i <= n + 1 ;i++){
			printf("%d\t\t %s\t    %d\n",arr[i].roll,arr[i].name,arr[i].marks);
		}
		break ;
		}

	case 4:{
		int search;
		int exists = 0;
		int k;
		printf("\nEnter Studebt Roll Number : ");
		scanf("%d",&search);
		
		for(int i = 0; i <= n+1 ; i++){
			if(search == arr[i].roll){
				exists = 1;
				k = i;
				}
		}
		if(exists == 1){
			printf("\nStudent founded !\n");
			printf("Name : %s\n",arr[k].name);
			printf("Marks : %d\n",arr[k].marks);
			
		}
		else 
			printf("Student not exists !\n");
		break;	
	}
	case 5:
		return 0;
		break;

	default:
	        printf("Invalid choice!");
}

}
	return 0;
}
