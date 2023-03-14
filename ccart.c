#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Intializing the structure for storing data
struct cart
{

    char name_item[20];
    char item_serial[20];
    int item_quantity;

};

//An array of structure to store multiple products
struct cart item[5];
//Counts the number of items added, refer to the "item_add" function
int item_count = 1;

//Piece of shit, the strings.h lib doesnt have this function and i had a headache coz i suck at pointers and kept getting segmentation fault
char lwrc(char *input_string)
{
    char conlwr[15];
    int a = 0;
    char converstr;
    while(input_string[a])
        {
            converstr = input_string[a];
            if(converstr >= 65 && converstr<=91)
                {
                    conlwr[a] = (converstr+=32);
                }
            else
                {
                    conlwr[a] = converstr;
                }
            a++;
            conlwr[a] = '\0';
        }
    strcpy(input_string,conlwr);

}

//Splits strings and compares them(make sure the value in the compare string has a space at the end or it will always output 0, either 0(false) 1(true)
int compare_strn(char *initial, char *cmpared)
{
    //Any input error, please check this function, it's horribly built (if you are debugging this function with item_edit's inputs it's going to take years!!!)
    char name[15];
    int b=0;
    int c = 2;
    int results = 0;
    lwrc(initial);
    for(int a = 0; a<=(strlen(cmpared)); a++)
        {

            if(cmpared[a] == ' ' || name[b-1] == ' ')
                {
                    name[b] = '\0';
                    if(c%2 == 0)
                        {
                            if(strcmp(initial,name) == 0)
                                {
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

//Removes the spaces and all that, coz like i am adding more features and the SPACE is a problem in the gets() function.
void space_remover(char *givestr)
{
    int b = strlen(givestr);
    char conver[b];
    int a = 0;
    int c = 0;
    while(givestr[a])
        {
            if(givestr[a]!= ' ')
                {
                    conver[c] = givestr[a];
                    c++;
                }
            a++;
            conver[c] = '\0';
        }
    strcpy(givestr,conver);
}

//Checks if that item exists or not, if it does not, then well it returns that.
int exist_check(int check)
{
    if(check > (item_count-1) || check == 0)
        {
            printf("There is no value on %d, please add the value and try again",check);
            return 1;
        }
    else
        {

            return 0;
        }

}

int item_add()
{

    printf("\n adding items\n");
    scanf("%s %s %d",item[item_count].name_item,item[item_count].item_serial, &item[item_count].item_quantity);
    item_count++;
}
//Prints the item values
void item_show(int x)
{
    if(exist_check(x))
        {
            return;
        }
    else
//printf("\n %d \n", x);
        printf("\n%s %s %d\n",item[x].name_item, item[x].item_serial, item[x].item_quantity);
}

void item_edit(int x,char *wut,char *input_item)
{
    if(exist_check(x))
        {
            return;
        }
    if(compare_strn(wut,"name naam n "))
        {
            strcpy(item[x].name_item, input_item);
        }
    else

        if(compare_strn(wut,"quantity quan qu qua q "))
            {
                int conversion;
                conversion = atoi(input_item);
                item[x].item_quantity = conversion;
            }
        else

            if(compare_strn(wut,"serial s ser "))
                {
                    strcpy(item[x].item_serial, input_item);
                }
            else
                {

                    printf("\nInvalid input, please try again.\n");

                }

}


int main()
{
    char function_cart[5];
    while(1)
        {
            printf("\n Input: ");
            scanf("%s",function_cart);
            //space_remover(function_cart);
            if(compare_strn(function_cart,"add 1 "))
                {

                    item_add();
                }


            else   if(compare_strn(function_cart, "show 2 ") )
                {

                    int show_no;
                    printf("show: ");
                    scanf("%d",&show_no);
                    item_show(show_no);
                }

            else     if(compare_strn(function_cart, "edit 3 "))
                {
                    int edit_which;
                    char edit[20];
                    char input_edit[20];
                    printf("Editing: ");
                    scanf("%d %s %s",&edit_which,edit,input_edit);
                    item_edit(edit_which, edit, input_edit);

                }
            else
                {

                    printf("\nInvalid input, please try again.\n");

                }


        }
}


