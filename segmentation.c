#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <err.h>
#include <math.h>
#include "gradient.h"

void horizontal(SDL_Surface *img )
{
  Uint32 pixel;
  Uint8 r;
  Uint8 g;
  Uint8 b;
  int cut = 1;
  int white = 1;
  int num_char=0;

  for( int j = 0; j < (img->h); j++)
    {
      for( int i = 0; i < img->w; i++)
	{
	  pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);

	  if ( !r && !b && !g)
	    {
	      white = 0;
	      break;
	    }
	  
	}

      if( cut && !white)
	{
	  pixel = SDL_MapRGB(img->format,255,0,0);
	  for( int l = 0; l<(img->w) ; l++)
	    {
	      putpixel(img, l, j, pixel);
          
	    }
	  cut = 0;
      num_char+=1;
	}
      
      if( !cut && white)
	{
	  pixel = SDL_MapRGB(img->format,255,0,0);
	  for( int l = 0; l<(img->w) ; l++)
	    {
	      putpixel(img, l, j, pixel);
	    }
	  cut = 1;
	}
      white = 1;
    }  
    printf("%d",num_char);
    
}

void resize (SDL_Surface *scr ,int **src_bin, int (*dest)[28]){
	int a, b, adlarg, adhaut;
	//adlarg=0;
	//adhaut=0;
	adlarg=28 - ((scr->w)%28);
	
	a= ((scr->w)+adlarg)/28 ;

	adhaut=28 - ((scr->h)%28);
	
	
	b= ((scr->h)+adhaut)/28 ;
    
    printf( " %d %d %d %d %d %d\n", a, adlarg , b , adhaut, scr->w , scr -> h );
    
    
	for (int i=0; i<28; i++){
		//printf("aa");
		for(int j=0; j<28; j++){
			/*Uint8 R, G, B;
			R=0;
			G=0;
			B=0;*/
            float  S=0;
			for (int I=0; I<a; I++){
			 for(int J=0; J<b; J++){
				/*Uint8 r, g, b;
				r=0;
				b=0;
				g=0;*/
                int s=0;
                int x=(i*a)+I;
                int y=((j*b)+J);
				if(  (x < 100 )&& (y < 100 ) ){
					
					//Uint32 pix= getpixel(src, I+i, J+j);
					//SDL_GetRGB(pix, src->format, &r, &g, &b);
                    s=src_bin[x][y];
                   
				}
				//printf("%d ",src_bin[I+i][J+j]);
				/*R=r+R;
				G=g+G;
				B=b+B;*/
                S=S+s;
            }
            // printf("  ");
           }
           
          // printf(" - ");

           if ( ( S/(a*b)  ) < 0.5 ){
			//if ( (R/(a * b)) >127 && (B/(a * b)) > 127 && (G/(a * b)) >127){
				/*R = 255;
				B = 255;
				G = 255;*/
                dest[i][j]=0;
			}

			else {
				/*R=0;
				G=0;
				B=0;*/
                
                dest[i][j]=1;
			}
			/*Uint32 pixel = SDL_MapRGB( dest-> format, R, G, B);
			putpixel(dest, i, j, pixel);*/
        
			
		//printf("\n");
		}
	}
}


void binarised(SDL_Surface *img){
    Uint8 r,g,b;
    Uint32 pixel;
    int **img_bin=calloc(img->w,sizeof(int * ));
    for (int i=0;i<img->w;i++)
        img_bin[i]=calloc(img->h,sizeof(int * ));
    
    for(int i=0; i<img->w; i++){
        for (int j=0;j<img->h;j++){
        pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);
	  if( r==0 && b==0 && g ==0){
          img_bin[i][j]=1;
        }
        else
        {
        img_bin[i][j]=0;
          
          }
          printf("%d", img_bin[i][j]);
          
        }
        printf("\n");
        }
    int r_img[28][28];
    //r_img = calloc(28 * sizeof(*r_img));
    
    for (int i=0; i<28;i++){
        for (int j=0; j<28; j++){
            r_img[i][j]=0;
             //printf(" %d", r_img[i][j]);
            
        }
    }
    
    resize(img,img_bin,r_img);
    for (int i=0; i<28; i++){
        for (int j=0; j<28; j++){
            printf(" %d", r_img[i][j]);

        }
        
        printf("\n");
        
    }
    free(img_bin);
    //free(r_img);
}





 
void vertical(SDL_Surface *img, int starter, int ending)
{
  Uint32 pixel;
  Uint8 r;
  Uint8 g;
  Uint8 b;
  int cut = 1;
  int white = 1;
  int num_char=0;

  for(int i = 0; i < img->w; i++)
    {
      for(int j = 0; j < 0; j++)
	{
	  pixel = getpixel(img, i, starter + j);
	  putpixel(img, i, j, pixel);
	}
    }

  for( int i = 0; i < img->w; i++)
    {
      for(int j = starter; j < ending; j++)
	{
	  pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);

	  if( !r && !b && !g)
	    {
	      white = 0;
	      break;
	    }
	}
      if( cut && !white)
	{
	  pixel = SDL_MapRGB(img->format, 255, 0, 0);
	  for( int l = starter; l < ending ; l++)
	    {
	      putpixel(img, i-1, l, pixel);
	    }
	  cut = 0;
      num_char+= 1;
	}
      if( !cut && white)
	{
	  pixel = SDL_MapRGB(img->format, 255, 0, 0);
	  for( int l = starter; l < ending; l++)
	    {
	      putpixel(img, i, l, pixel);
	    }
	  cut = 1;
	}
      white = 1;
    }
    
    printf("%d \n",num_char);
}

void separate(SDL_Surface *img )
{
  Uint32 pixel;
  Uint8 r;
  Uint8 g;
  Uint8 b;
  int starter = 0;
  int ending = 0;
  

  for ( int i = 0; i < (img->h); i++)
    {
      pixel = getpixel(img, 0, i);
      SDL_GetRGB(pixel, img->format, &r, &g, &b);
      
      if( r == 255 && b==0 && g == 0)
	{
	  
	  starter = i + 1;

	  for (int j = starter + 1; j < (img->h); j++)
	    {
	      pixel = getpixel(img, 0, j);
	      SDL_GetRGB(pixel, img->format, &r, &g, &b);

	      if( r == 255 && b == 0 && g == 0)
		{
		  ending = j;
		  vertical(img, starter, ending);
		  break;
		}
	    }
	}
    }
}


