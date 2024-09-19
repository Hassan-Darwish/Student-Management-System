/* Hassan Darwish Embedded Diploma Standard 91*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // used in the NumberinString function
#include "header.h"

// struct that carries all the students data
struct student{
	int id;
	char name[50];
	int age;
	float gpa;
};
// struct that holds the data as a linked list
struct node{
	struct student data;
	struct node *next;
};
// defining the struct node as name 'node'
typedef struct node node;

struct node *head = NULL;

void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
int NumberinString(const char *str);

int main(void){
	struct student s; // defining the struct student as name 's'

	while(1){ // the loop which contains all the operation the user can choose from
		int operation;
		int id;
		printf(lining
				"What operation would you like to do:\n"
				"1)Add Students\n"
				"2)Display All Student\n"
				"3)Search for a Student by ID\n"
				"4)Update Student Information\n"
				"5)Delete a Student\n"
				"6)Calculate Average GPA\n"
				"7)Find Student with Highest GPA\n"
				"8)Exit"
				"\n"lining
				"enter the number of the operation you want: ");
		scanf("%d", &operation);
		printf(lining);

		if(operation){
			switch(operation){
			case 1:// add the students data


				printf("enter the student's name: ");
				scanf(" %[^\n]%*c", s.name);
				if(NumberinString(s.name)){
					printf("enter the student's ID: ");
					scanf("%d", &s.id);

					if(s.id){

						printf("enter the student's age: ");
						scanf("%d",&s.age);

						if(s.age && s.age > 0){

							printf("enter the student's GPA: ");
							scanf("%f",&s.gpa);

							if(s.gpa && (s.gpa >= 0.0 && s.gpa <= 4.0)){
								addStudent(&s);
								break;

							}else{
								printf("\n"lining
										"ERROR: enter a valid GPA.\n");
								break;
							}
						}else{
							printf("\n"lining
									"ERROR: enter a valid age.\n");
							break;
						}
					}else{
						printf("\n"lining
								"ERROR: please enter a valid ID.\n");
						break;
					}

					break;
				}else{
					printf(lining
					"ERROR: enter a valid name.\n");
					break;
				}

			case 2: // displays all the student's data
				displayStudents();
				break;
			case 3: // searches the student by ID
				printf("enter the student's ID you want to search for: ");
				scanf("%d",&id);

				if(id){
					searchStudentByID(id);
					break;
				}else{
					printf("\n"lining
							"ERROR: enter a valid ID."
							"\n"lining);
					continue;
				}
			case 4: // updates the student's data
				printf("enter the student's ID you want to update: ");
				scanf("%d",&id);

				if(id){
					updateStudent(id);
					break;
				}else{
					printf("\n"lining
							"ERROR: enter a valid ID."
							"\n"lining);
					continue;
				}
			case 5: // deletes the student's data
				printf("enter the student's ID you want to delete: ");
				scanf("%d",&id);
					if(id){
					deleteStudent(id);
					break;
					}else{
					printf("\n"lining
							"ERROR: enter a valid ID."
							"\n"lining);
					continue;
					}
			case 6: // calculates the average GPA of the students
				if(!(calculateAverageGPA())){
					break;
				}else{
					printf("the average GPA of the students is : %f\n", calculateAverageGPA());
					break;
				}
			case 7: // automatically searches for the highest GPA among students
				searchHighestGPA();
				break;

			case 8:
				printf("Application terminated, exit value: 0.");
				printf("\n"lining);
				return 0;
			default:
				printf("ERROR: please enter a valid operation.");
				continue;
			}
		}else{
			printf("ERROR: please enter a valid operation.");
			int c;
			while ((c = getchar()) != '\n' && c != EOF) { }// clears the input buffer if operation was given a string
			continue;
		}
	}
}
void addStudent(const struct student *const ptr){

	node* new_node = (node*)malloc(sizeof(node));
	node* last;

	new_node -> data = *ptr;

	if(head != NULL){ // checks if the head is empty or contains other nodes

		last = head;

		while(last -> next != NULL){ // loops to the end of nodes to create a new one
			if(last -> data.id == new_node -> data.id){ // checks for duplicate ID's along the way
				printf("\n"lining
					   "ID already exists\n"); // return the the main function if there were any duplicates
				return;
			}else{
				last = last -> next;
			}
		}

		if(last -> data.id == new_node -> data.id){ // checks if the last node is a duplicate or not
			printf("\n"lining
				   "ID already exists\n");
			return;
		}


		last -> next = new_node; // creates a new node if last is empty
		new_node->next = NULL;

	}else{
		head = new_node; // creates a new node if the head is empty
		new_node -> next = NULL;
	}

}
void displayStudents(void){
	if(head == NULL){ // checks if the head is empty to end the function
		printf("there are no students present\n");
	}
	else{
		node *leader = head;

		while(leader != NULL){// displays each of the students data
			printf("{ ID: %d, Name: %s, Age: %d, GPA: %f }",
				leader->data.id,
				leader->data.name,
				leader->data.age,
				leader->data.gpa);
			leader = leader->next;
			printf("\n");
		}
	}
	return;
}
void searchStudentByID(int id){
	if(head == NULL){
		printf(lining
				"there are no students present\n");
		return;
	}else{
		node* leader = head;

		while(leader != NULL){
			if(id == leader -> data.id){ // displays the student data if the id matched the nodes id
				printf("{ ID: %d, Name: %s, Age: %d, GPA: %f }\n",
						leader->data.id,
						leader->data.name,
						leader->data.age,
						leader->data.gpa);
				return;
			}else{
				printf(lining
						"Student with this ID could not be found.\n");
				return;
			}
		}

	}
	printf("there are no students with that ID\n");
	return;
}
void updateStudent(int id){
	if(head == NULL){
		printf("\n"lining
				"there are no students present\n");
			return;
		}
		else{
			node* leader = head;
			int operation;
			int new_age;
			float new_gpa;

			while(leader != NULL){
				if(id == leader -> data.id){ // checks if the user's given id matches any of the id's in the node
					printf(lining
							"Student Found !"
							"\n"lining
							"what would you like to change ?:\n"
							"1)Student Name.\n"
							"2)Age.\n"
							"3)GPA."
							"\n"lining
							"enter the number of the operation you want: ");
					scanf("%d",&operation);

					switch(operation){
						case 1: // changes the student's name
							printf(lining
									"enter the new student's name: ");
							scanf(" %[^\n]%*c",leader->data.name);
							if(NumberinString(leader->data.name)){
								printf("\n"lining
										"Operation Complete!\n");

							}else{
								printf("\n"lining
									   "ERROR: enter a valid name\n");
							}
							return;
						case 2: // changes the student's age
							printf("enter the new student's age: ");
							scanf("%d",&new_age);

							if(new_age){
								leader -> data.age = new_age;
								printf("\n"lining
										"Operation Complete!\n");
								return;
							}else{
								printf("\n"lining
										"ERROR enter a valid age.\n");
								return;
							}
						case 3: // changes the student's ID
							printf("\n"lining
									"enter the new student's gpa: "
									"\n"lining);
							scanf("%f",&new_gpa);

							if(new_gpa && new_gpa < 4.0 && new_gpa > 0.0){
								leader -> data.gpa = new_gpa;
								printf("\n"lining
										"Operation Complete!\n");
								return;
							}else{
								printf("\n"lining
										"ERROR: enter a valid GPA (OUT OF BOUNDRIES)\n");
								return;
							}
						default:
							printf("ERROR: please enter a valid operation\n");
							continue;

					}
					return;
				}else{
					printf("\n"lining
							"Student with this ID could not be found.");
					return;
				}
			}

		}
		printf("there are no students with that ID"
				"\n"lining);
		return;
}
float calculateAverageGPA(void){
	if(head == NULL){
		printf("there are no students present\n");
		return 0.0;
	}
	else{
		node *leader = head;
		int node_counter = 0;
		float gpa_summation = 0.0;
		float average_gpa = 0.0;

		while(leader != NULL){
			node_counter ++; // increments the counter that counts the number of nodes
			gpa_summation += leader->data.gpa; // sum the gpa of each node
			leader = leader->next;
		}
		average_gpa = gpa_summation/node_counter; // average value

		return average_gpa;

	}
}
void searchHighestGPA(void){
	if(head == NULL){
		printf("there are no students present\n");
		return;
	}
	else{
		node* leader = head;
		node* follower = leader;

		if(leader -> next != NULL){
			leader = leader -> next; // skips first node for the follower to be the first node
		}else{
			printf("{ ID: %d, Name: %s, Age: %d, GPA: %f }\n",
					follower->data.id,
					follower->data.name,
					follower->data.age,
					follower->data.gpa);
			return;
		}

		while(leader != NULL){
			if(leader -> data.gpa > follower -> data.gpa){// checking which node's GPA is larger
				follower = leader;
				leader = leader -> next;
			}else{
				leader = leader -> next;
			}
		}

		printf("{ ID: %d, Name: %s, Age: %d, GPA: %f }\n",
				follower->data.id,
				follower->data.name,
				follower->data.age,
				follower->data.gpa);
		return;
	}
}
void deleteStudent(int id){
	if(head == NULL){
		printf("\n"lining
				"there are no students present\n");
			return;
		}
		else{
			node* leader = head;
			node* follower = NULL;

			if(leader -> data.id == id){// checks if the head is matches the id
				head = leader -> next;// head starts from the head's next node
				free(leader); // deletes leader
				printf(lining
					   "Student Data Removed\n");
				return;

			}else{
				while(leader -> next!= NULL && leader -> data.id != id){ // checks if leader id matches the given id
					follower = leader;
					leader = leader -> next;
				}// follower follows leader  follower -> next = leader
				if(leader -> data.id == id && leader -> next == NULL){ // if the leader id matches the given id and if next node after leader is empty
					follower -> next = NULL; // follower points next node to empty node instead of leader node
					free(leader); // deletes leader
					printf(lining
						  "Student Data Removed\n");
					return;
				}else if(leader -> data.id == id && leader -> next != NULL){// if the leader id matches the given id and if next node after leader is not empty
					follower -> next = leader -> next; // follower points next node to the leader's next node;
					free(leader); // deletes leader
					printf(lining
						   "Student Data Removed\n");
					return;

				}else{
				printf(lining
					  "Student with this ID could not be found.\n");
				return;
				}
		}
	}
		printf(lining
				"there are no students with that ID\n");
		return;
}
int NumberinString(const char *str) { // function that checks if there are any numbers in the string
    while(*str) {
        if(isdigit((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
