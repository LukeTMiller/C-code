#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include<time.h>

#define WIDTH 800
#define HEIGHT 600

int it = 0;
SDL_Surface *surface;
SDL_Window *screen;
SDL_Renderer *renderer;
SDL_Texture *texture;



int ran(int max, int min)
{
int number = 0; 

number = (rand() % (max + 1 - min) + min);

return number;
}

void setPixel(SDL_Surface *surface, int x, int y, unsigned int r, unsigned int g, unsigned int b)
{
	Uint32 color;
	Uint8 *p;
	
	/* turn r, g, b into a color */
	color = SDL_MapRGB(surface->format, r, g, b);
	
	/* set the pixel to a color */
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel;
	*(Uint32 *)p = color;
}

void Barnsleyleaf(SDL_Surface *surface, int i)
{
	double x0 = 0, x1, y0 = 0, y1;
	int rand = 0;
	time_t seconds;
	
	seconds = time(NULL);
	srand(seconds);
	
	
	
	while(i>0){
		
	rand = ran(21,0);
		if(rand==0){
			x1 = 0;
			y1 = .16*y0;//.16
		}
 
		else if(rand>=1 && rand<=7){
			x1 = -0.15*x0 + 0.28*y0;//-.15 .28
			y1 = .26*x0 + 0.24*y0 + 0.44; //.26 .24 .44
		}
 
		else if(rand>=8 && rand<=15){
			x1 = 0.2*x0 - 0.26*y0;// .2 .26
			y1 = 0.23*x0 + 0.22*y0 + 1.6; // .23 .22 1.6
		}
 
		else{
			x1 = 0.85*x0 + 0.04*y0; // .85 .04
			y1 = -0.04*x0 + 0.85*y0 + 1.6; // -.04 0.85 1.6
		}
 
		setPixel(surface,(30*x1 + WIDTH/2.0),30*y1,0,255,0);
 
		x0 = x1;
		y0 = y1;
 
		i--;
	}
 
}

void drawShape(SDL_Surface *surface)
{
	unsigned y;
	unsigned x;
	
	unsigned xpos;
	unsigned ypos;
	
	xpos = 50;
	ypos = 50;
	if (it == 0)
	{
		printf("How many iterations?");
		scanf("%d", &it);
	}
	Barnsleyleaf(surface, 300);
	/* send the pixels to the texture buffer */
	SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
	
	/* copy the texture directly to the backbuffer */
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}


void render()
{
	/* clear the screen */
	SDL_RenderClear(renderer);

	/* draw the shape on the screen */
	drawShape(surface);

	/* flip the back with the front buffer */
	SDL_RenderPresent(renderer);
}


void inputs()
{
	SDL_Event event;
	
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			exit(0);
			break;
			
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_ESCAPE)
			{
				exit(0);
			}
			break;
			
		default:
			break;
	}
}


void step()
{	
	render();
	
	inputs();
}


int main(int argc, char * argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Could not start SDL %s\n", SDL_GetError());
		exit(1);
	}
	
	atexit(SDL_Quit);
	
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &screen, &renderer);	
	
	surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32,
                                        0x00FF0000,
                                        0x0000FF00,
                                        0x000000FF,
                                        0xFF000000);
	if(surface == NULL)
	{
		fprintf(stderr, "Could not setup surface %s", SDL_GetError());
		exit(1);
	}
	
	/* enable the surface to be a renderable texture */
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if(texture == NULL)
	{
		fprintf(stderr, "Could not setup texture %s", SDL_GetError());
		exit(1);
	}	
	
	/* clear screen to black */
	SDL_SetRenderDrawColor(renderer, 1, 0, 0, 0);
	SDL_RenderClear(renderer);
	
	while(1)
	{
		step();
		
		/* avoid slamming the CPU */
		SDL_Delay(10);
	}
	
	return 0;
}
