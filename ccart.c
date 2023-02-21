#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Intializing the structure for storing data
struct cart  {

             char name_item[20];
             signed int item_serial;
             int item_quantity;

             };

//An array of structure to store multiple products
 struct cart item[2];
//Counts the number of items added, refer to the "item_add" function
 int item_count = 0;

int item_add(){

   printf("\n adding items\n");
   scanf("%s %d %d",item[item_count].name_item,&item[item_count].item_serial, &item[item_count].item_quantity);
   item_count++;
}
//Prints the item values
int item_show(int x){
//printf("\n %d \n", x);
printf("\n%s %d %d\n",item[x].name_item, item[x].item_serial, item[x].item_quantity);
}

int item_edit(int x,char *wut,char *input_item){


if((strcmp(wut,"name")==0 || strcmp(wut,"Name")==0 )){
   strcpy(item[x].name_item, input_item);
 }

 if((strcmp(wut,"quantity")==0 || strcmp(wut,"Quantity")==0 || strcmp(wut,"Q")==0 || strcmp(wut,"q")==0)|| strcmp(wut,"quan")==0|| strcmp(wut,"quan")==0){
   int conversion;
   conversion = atoi(input_item);
   item[x].item_quantity = conversion;
 }

 if((strcmp(wut,"serial")==0 || strcmp(wut,"Serial")==0 || strcmp(wut,"S")==0 || strcmp(wut,"s")==0)|| strcmp(wut,"ser")==0|| strcmp(wut,"Ser")==0){
   int conversion;
   conversion = atoi(input_item);
   item[x].item_serial = conversion;
 }

}

int main(){
char function_cart[5];
while(1){
printf("\n Input: ");
scanf("%s",function_cart);
if(strcmp("add",function_cart)== 0 || strcmp("Add",function_cart)== 0  ){

  item_add();
}


if(strcmp("show",function_cart)== 0 || strcmp("Show",function_cart)== 0  ){
  int show_no;
  printf("show: ");
  scanf("%d",&show_no);
  item_show(show_no);
 }

if(strcmp("edit",function_cart)== 0 || strcmp("Edit",function_cart)== 0  ){
  int edit_which;
  char edit[20];
  char input_edit[20];
  printf("Editing: ");
  scanf("%d %s %s",&edit_which,edit,input_edit);
  item_edit(edit_which, edit, input_edit);

}

}
        }


