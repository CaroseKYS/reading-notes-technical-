#include <stdio.h>
#include "readline.h" 

#define NAME_LEN  25
#define MAX_PARTS 100

struct part{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;	
};

struct part inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void){
	char code;
	
	while(1){
		printf("Enter preration code : ");
		scanf(" %c", &code);
		
		while(getchar() != '\n');
		
		switch(code){
			case 'i':
				insert();
				break;
			case 's':
				search();
				break;
			case 'u':
				update();
				break;
			case 'p':
				print();
				break;
			case 'q':
				return 0;
			default:
				printf("Illegal code !\n");
		}
		
		printf("\n");
	}
}



int find_part(int number){
	int i;
	
	for(i = 0; i < num_parts; i++){
		if(number == inventory[i].number){
			return i;
		}
	}
	
	return -1;
}

void insert(void){
	int part_number;
	
	if(num_parts == MAX_PARTS){
		printf("Database if full; can't add more parts.\n'");
		return;
	}
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	if(find_part(part_number) >= 0){
		printf("Part already exists.\n");
		return;
	}
	
	inventory[num_parts].number = part_number;
	
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	
	num_parts++;
}

void search(void){
	int part_number, i;
	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	i = find_part(part_number);
	
	if(i < 0){
		printf("Part not found.\n");
		return;
	}
	
	printf("Part name: %s\n", inventory[i].name);
	printf("Quantity on hand: %d\n", inventory[i].on_hand);
	
}
void update(void){
	int part_number, i, change;
	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	i = find_part(part_number);
	
	if(i < 0){
		printf("Part not found.\n");
		return;
	}
	
	printf("Enter change in quantity on hand: ");
	scanf("%d", &change);
	
	inventory[i].on_hand += change; 
}
void print(void){
	int i;
	
	printf("Part Number     ""Part Name     ""Quantity on hand""\n");
	
	for(i = 0; i < num_parts; i++){
		printf("%7d         %-14s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
	}
}
