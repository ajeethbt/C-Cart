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
//Splits strings and compares them(make sure the value in the compare string has a space at the end or it will always output 0), either 0(false) 1(true);
int compare_strn(char *initial, char *cmpared)
{
    char name[6];
    int b=0;
    int c = 2;
    int results = 0;
        for(int a = 0; a<=(strlen(cmpared)); a++)
        {

            if(cmpared[a] == ' ' || name[b-1] == ' ')
            {
                name[b] = '\0';
                if(c%2 == 0){
                    if(strcmp(initial,name) == 0){
                        results = 1;
                        break;
                    }/*else{
                        results = 0;
                        break;
                        }*/
                            }
                c++;
                b = 0;
            }
        name[b] = cmpared[a];
        b++;

        }
    return results;
}

int item_add(){

   printf("\n adding items\n");
   scanf("%s %d %d",&item[item_count].name_item,&item[item_count].item_serial, &item[item_count].item_quantity);
   item_count++;
}
//Prints the item values
int item_show(int x){
//printf("\n %d \n", x);
printf("\n%s %d %d\n",item[x].name_item, item[x].item_serial, item[x].item_quantity);
}

int item_edit(int x,char *wut,char *input_item){


if(compare_strn(wut,"Name name naam Naam N n ")){
   strcpy(item[x].name_item, input_item);
 }

 if(compare_strn(wut,"quantity Quantity quan Quan qu Qu Qua qua q Q ")){
   int conversion;
   conversion = atoi(input_item);
   item[x].item_quantity = conversion;
 }

 if(compare_strn(wut,"serial Serial S s ser Ser ")){
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
if(compare_strn(function_cart,"add Add 1 ")){

  item_add();
}


if(compare_strn(function_cart, "show Show 2 ") ){
  int show_no;
  printf("show: ");
  scanf("%d",&show_no);
  item_show(show_no);
 }

if(compare_strn(function_cart, "edit Edit 3 ")){
  int edit_which;
  char edit[20];
  char input_edit[20];
  printf("Editing: ");
  scanf("%d %s %s",&edit_which,edit,input_edit);
  item_edit(edit_which, edit, input_edit);

}


}
        }


