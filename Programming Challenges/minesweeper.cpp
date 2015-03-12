//A minesweeper generator
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

char arr[102][102] = {0}; //2D dynamic array used temporarily

int main() {
    int n, m; //Rows and columns
    int count = 0, recordNum = 0; //Number of mines around the current dot

    while(true) { //Keep processing records until "0 0" is encountered
        scanf("%d%d",&n,&m);

        if(n == 0 && m == 0 ) //End of input
            break;

        //Read the values into the array
        for(int i = 1; i < n+1; i++) { //Rows
            for(int j = 1; j < m+1; j++) { //Columns
                //scanf("%c",arr+i*102*j);
								cin>>arr[i][j];
            }
        }

        //Process the values of the array and generate the numbers
        for(int i = 1; i < n+1; i++) { //Rows
            for(int j = 1; j < m+1; j++) { //Columns
                if(arr[i][j] == '*')
                    continue;
                else { //Count the number of mines around this dot
                    if(arr[i-1][j-1] == '*')
                                        count++;
                                    if(arr[i-1][j] == '*')
                                        count++;
                                    if(arr[i-1][j+1] == '*')
                        count++;
                    if(arr[i][j-1] == '*')
                                        count++;
                                    if(arr[i][j+1] == '*')
                                        count++;
                                    if(arr[i+1][j-1] == '*')
                        count++;
                    if(arr[i+1][j] == '*')
                                        count++;
                                    if(arr[i+1][j+1] == '*')
                        count++;
                }
                arr[i][j] = 48+count;//This converts the count value to char type 1 to '1'

                count = 0; //Finally reset the counter
            }
        }

        if(recordNum > 0)
            printf("\n");
        recordNum++;
        printf("Field #%d:\n",recordNum );

        //Output the values
        for(int i = 1; i < n+1; i++) { //Rows
            for(int j = 1; j < m+1; j++) { //Columns
                printf("%c",arr[i][j]);
            }
            printf("\n");
        }
				
				memset(arr, 0, sizeof(char)*102*102);
    }
    return 0;
}