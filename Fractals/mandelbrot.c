#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>



#define WIDTH 800
#define HEIGHT 600
float zoom = 1;
float xin = 0;
int max = 150;
float yin = 0;
SDL_Surface *surface;
SDL_Window *screen;
SDL_Renderer *renderer;
SDL_Texture *texture;

struct complex_number 
{
	float r;
	float i;
};



int calculate(SDL_Surface *surface, float x, float y);

void setPixel(SDL_Surface *surface, int x, int y, unsigned int r, unsigned int g, unsigned int b)
{
	Uint32 color;
	Uint8 *p;
	
	if (r > 256)
	{
		r = r % 256;
	}
	/* turn r, g, b into a color */
	color = SDL_MapRGB(surface->format, r, r, r);
	
	
	
	/* set the pixel to a color */
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel;
	*(Uint32 *)p = color;
}


void drawShape(SDL_Surface *surface)
{
	int red = 0;
	
	float x = 0;
	float y = 0;
	
	fflush(stdout);
	//printf("%d	%d", yin, xin);
	for(y = 0; y <= 600; y++)
	{
		for(x = 0; x <= 800; x++)
		{
			
			red = calculate(surface, x,y);
			setPixel(surface, x, y, red, 0, 0); /* forest green */
			/* send the pixels to the texture buffer */
	
		}
	}
printf("done");
	
	/* send the pixels to the texture buffer */
	SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
	
	/* copy the texture directly to the backbuffer */
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}


int calculate(SDL_Surface *surface, float x, float y)
{
	float temp = 0;
	
	int i = 0;
	struct complex_number z;
	struct complex_number c;
	
	z.r = 0;
	z.i = 0;
	
	c.i = (y- HEIGHT/2)*4.0/WIDTH;
	c.r = (x-WIDTH/2)*4.0/WIDTH;
	
	
		c.r = c.r * zoom;
		
		c.i = c.i * zoom;
		
		
		c.i= c.i +(yin * .01);
		c.r = c.r +(xin * .01);

	fflush(stdout);
	while (z.r * z.r + z.i * z.i <= 4.0)
	{
		
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = z.r * z.i * 2.0 + c.i;
		z.r = temp;
		
		i++;
		if (i == max)
		{
			return i;
		}
		
	}
	
	
	return i;
}

/*while (z.r * z.r + z.i * z.i <= 4.0) -- same as abs(z) <= 2
{
	temp = z.r *z.r - z.i * z.i + c.r; -- find the new real portion
	z.i = z.r * z.i * 2 + c.i; -- find the new imaginary portion
	z.r = temp; --housekeeping step, now we can overwrite this because we needed it for the imaginary calculation
}*/

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
	AGAIN:
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			exit(0);
			break;
			
		case SDL_KEYDOWN:
		fflush(stdout);
			if(event.key.keysym.sym == SDLK_ESCAPE)
			{
				fflush(stdout);
				printf("right");

				exit(0);
			}
			 else if(event.key.keysym.sym == SDLK_UP)
			{
				yin = yin - 10;
printf("up");
			}
			else if(event.key.keysym.sym == SDLK_DOWN)
			{
				yin = yin + 10;
printf("down");
			}
			else if(event.key.keysym.sym == SDLK_LEFT)
			{
				xin = xin - 10;
printf("left");
			}
			else if(event.key.keysym.sym == SDLK_RIGHT)
			{
				xin = xin + 10;
				printf("right");
				
			}
			else if(event.key.keysym.sym == SDLK_w)
			{
				yin = yin -.2;
printf("up");
			}
			else if(event.key.keysym.sym == SDLK_s)
			{
				yin = yin + .2;
printf("down");
			}
			else if(event.key.keysym.sym == SDLK_a)
			{
				xin = xin - .2;
printf("left");
			}
			else if(event.key.keysym.sym == SDLK_d)
			{
				xin = xin + .2;
				printf("right");
				
			}
			else if(event.key.keysym.sym == SDLK_r)
			{
				
				setPixel(surface, 400, 300, 0, 255, 0);
				SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
				SDL_RenderCopy(renderer, texture, NULL, NULL);
				SDL_RenderPresent(renderer);
			}
			else if(event.key.keysym.sym == SDLK_MINUS)
			{
				zoom = zoom *  1.2;
				if(max > 200)
				{
					
					max = max /1.1;
				}
				
			}
			else if(event.key.keysym.sym == SDLK_EQUALS)
			{
				zoom = zoom * 0.8;
			
			}
			else if(event.key.keysym.sym == SDLK_PAGEUP)
			{
				max= max + 50;
			
			}
			else if(event.key.keysym.sym == SDLK_PAGEDOWN)
			{
				max = max - 50;
			
			}
			else if(event.key.keysym.sym == SDLK_c)
			{
				zoom = 1;
				max = 150;
				xin = 0;
				yin = 0;
			
			}
			printf("%fl		%fl", yin, xin);
			break;
		
			
		default:
		goto AGAIN;
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
		SDL_Delay(0);
	}
	
	return 0;
}
