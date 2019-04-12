#include<iostream>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>
#include <graphics.h>
#include<string>
#include <stdlib.h>

using namespace std;


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main(){
	int arr[1000];
	for(int i=0; i<1000; i++){
		arr[i] = i+1;
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle (arr, arr + 1000, std::default_random_engine(seed));

	/*for(int i=0; i<1000; i++){
		cout <<  arr[i] << " ";
	}
	cout << endl;*/


	int i, j, min_idx; 
	int arr2[1000];

	int gd = DETECT, gm; 
	char* em;
    initgraph(&gd, &gm, em); 

	for(int i=0; i<1000; i++){
		arr2[i] = arr[i];
		line( (i +1)/2, 500, (i +1)/2, 400 - arr[i]/3);
	}

	cleardevice();
  
    for (i = 0; i < 1000-1; i++) {  
        min_idx = i; 
        for (j = i+1; j < 1000; j++) 
          if (arr2[j] < arr2[min_idx]) 
            min_idx = j; 
        swap(&arr2[min_idx], &arr2[i]);

        for(int k=0; k<1000; k++){
		 	//arr2[i] = arr[i];
		 	line( (k +1)/2, 400, (k +1)/2, 400 - arr2[k]/3);
	 	}
	 	cleardevice();

    }

     /*for(int i=0;i < 1000; i++){
     	cout << arr2[i] << endl;
     }*/ 

    for(int k=0; k<1000; k++){
		 	line((k +1)/2, 400, (k +1)/2, 400 - arr2[k]/3);
	 }

	 cleardevice();
    //sleep(5000);

	 for(int i=0; i<1000; i++){
		arr2[i] = arr[i];
		line( (i +1)/2, 500, (i +1)/2, 400 - arr[i]/3);
	}

	cleardevice();

	 for (i = 0; i < 1000-1; i++){   
       for (j = 0; j < 1000-i-1; j++){  
           if (arr2[j] > arr2[j+1]) 
              swap(&arr2[j], &arr2[j+1]);
      	}

      	for(int k=0; k<1000; k++){
		 	//arr2[i] = arr[i];
		 	line( (k +1)/2, 400, (k +1)/2, 400 - arr2[k]/3);
	 	}
	 	cleardevice();
    }

    for(int k=0; k<1000; k++){
		 	line((k +1)/2, 400, (k +1)/2, 400 - arr2[k]/3);
	 }

	 cleardevice();




    // left, top, right, bottom denotes 
    // location of rectangular bar 
    
  
    // y axis line 
    //line(100, 50, 100, 350); 
  
    // x axis line 
    //line(100, 350, 2100, 350); 
  
    getch();
    closegraph(); 
}