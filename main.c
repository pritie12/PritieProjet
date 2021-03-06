#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <err.h>
#include <math.h>

#include "gradient.h"
#include "segmentation.h"
#include "nn.h"
#include "dataprep.h"

void run_image_treatment(char *img)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *img_surface = load_image(img);
    open_image(img_surface);
    wait_for_keypressed();

    /*grayscale(img);
      open_image(img);
      wait_for_keypressed();*/
    
      blacknwhite(img_surface);
      open_image(img_surface);
      wait_for_keypressed();
      
      /*horizontal(img_surface);
      open_image(img_surface);
      wait_for_keypressed();
      separate(img_surface);
      open_image(img_surface);
      wait_for_keypressed();*/
      binarised(img_surface);
      /*resize(img);
      wait_for_keypressed();
      open_image(img);
      wait_for_keypressed();*/

    SDL_FreeSurface(img_surface);
    SDL_Quit();
}


int main(int argc, char *argv[])
{
    run_image_treatment(argv[1]);

    //data preparation train
   /* float **train = calloc(60000, sizeof(float *));
    for (int i = 0; i < 60000; i++)
    {
        train[i] = calloc(784, sizeof(float));
    }
    int *label_train = calloc(60000, sizeof(int));
    put_train_value_in_array(train, label_train);

    //training
    int in = 28 *28;
    int hid = 16;
    int out = 10;
    int epoch = 1000;
    net *a = init_neural_network(in, hid, out);
    run_neural_network(a, train, label_train, epoch);
    printf("TRAINED!\n");
    free_train(train);
    free(label_train);
    printf("free!\n");


    //data preparation test
    int *label_test = calloc(10000, sizeof(float));
    float **test = calloc(10000, sizeof(float*));
    for (int i = 0; i < 10000; i++)
    {
        test[i] = calloc(784, sizeof(float));
    }
    put_test_value_in_array(test, label_test);
    free(label_test);
    for (int i = 0; i < a -> nbr_input; i++)
    {
        a -> input[i] = test[0][i];
    }
    feedforward(a);
    int m = max_array( a -> output, a -> nbr_output);
    printf("%d\n", m);
    free_test(test);*/

    return argc;
}
