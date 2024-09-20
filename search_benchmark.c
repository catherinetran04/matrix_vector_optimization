// Complete this main to benchmark the search algorithms outlined in
// the project specification
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "search.h"

int main(int argc, char *argv[]){
  // set to run no searches
  int run_linear_array = 0;
  int run_linked_list  = 0;
  int run_binary_array = 0;
  int run_binary_tree = 0;

  // set imn, max, reps
  int min = atoi(argv[1]);
  int max = atoi(argv[2]);
  int reps = atoi(argv[3]);

  printf("%10s ", "SIZE");
  printf("%10s ", "NSEARCH");

  // set to run given searches
  if(argc > 4){
    for(int i=4; i < argc; i++){   
      if(strcmp(argv[i],"la") == 0){
        run_linear_array = 1;
      }
      if(strcmp(argv[i],"ll") == 0){
        run_linked_list = 1;
      }
      if(strcmp(argv[i],"ba") == 0){
        run_binary_array = 1;
      }
      if(strcmp(argv[i],"bt") == 0){
        run_binary_tree = 1;
      }
    }
  }
  else{   //runs all tests
    run_linear_array = 1;
    run_linked_list = 1;
    run_binary_array = 1;
    run_binary_tree = 1;
  }

  // printing which tests are run
  if(run_linear_array == 1){
    printf("%10s ", "array");
  }
  if(run_linked_list == 1){
    printf("%10s ", "list");
  }
  if(run_binary_array == 1){
    printf("%10s ", "binary");
  }
  if(run_binary_tree == 1){
    printf("%10s ", "tree");
  }
  
  printf("\n"); 

  // for timing
  clock_t begin, end;
  
  // set min size
  int min_size = 2;
  for(int i = 0; i<min-1; i++){
    min_size *= 2;
  }

  // set max size
  int max_size = 2;
  for(int i = 0; i<max-1; i++){
    max_size *= 2;
  }

   
  for(int i = min_size; i<(max_size+1); i = i*2){  // sizes
    printf("%10d", i);
    printf("%10d  ", i*reps*2);

    if(run_linear_array == 1){ // time linear array search 
      int *array = malloc(sizeof(int)*i);
      array = make_evens_array(i);
      begin = clock();

      for(int x = 0; x<reps; x++){
        for(int y = 2; y<max_size; y = y*2){
          linear_array_search(array, i, y);
        }
      }

      end = clock();
      free(array);
      double time = ((double) (end-begin)) / CLOCKS_PER_SEC;
      printf("%10e  ", time);
    }

    if(run_linked_list == 1){ // time linked list search 
      list_t *list = malloc(sizeof(list_t)*i);
      list = make_evens_list(i);
      begin = clock();

      for(int x = 0; x<reps; x++){
        for(int y = 2; y<max_size; y = y*2){
          linkedlist_search(list, i, y);
        }
      }

      list_free(list);
      end = clock();
      double time = ((double) (end-begin)) / CLOCKS_PER_SEC;
      printf("%10e  ", time);
    }

    if(run_binary_array == 1){ // time binary array search 
      int *array = malloc(sizeof(int)*i);
      array = make_evens_array(i);
      begin = clock();

      for(int x = 0; x<reps; x++){
        for(int y = 2; y<max_size; y = y*2){
          binary_array_search(array, i, y);
        }
      }

      end = clock();
      free(array);
      double time = ((double) (end-begin)) / CLOCKS_PER_SEC;
      printf("%10e  ", time);
    }

    if(run_binary_tree == 1){ // time binary tree search 
      bst_t *bst = malloc(sizeof(bst_t)*i);
      bst = make_evens_tree(i);
      begin = clock();

      for(int x = 0; x<reps; x++){
        for(int y = 2; y<max_size; y = y*2){
          binary_tree_search(bst, i, y);
        }
      }

      end = clock();
      bst_free(bst);
      double time = ((double) (end-begin)) / CLOCKS_PER_SEC;
      printf("%10e  ", time);
    }
    printf("\n");
  }

  return 0;
}

