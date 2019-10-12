#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

SDL_Window *screen;
SDL_Renderer *renderer;

void inputs();
void render();
void init();
void step();

/************************** YOUR PROGRAM STARTS HERE **************************/

SDL_Surface *surface;
SDL_Texture *texture;

/* prototypes */
void setPixel(SDL_Surface *surface, int x, int y, unsigned int r,
	      unsigned int g, unsigned int b);
void drawShape(SDL_Surface *surface);

void setPixel(SDL_Surface *surface, int x, int y, unsigned int r,
	      unsigned int g, unsigned int b)
{
	Uint32 color;
	Uint8 *p;

	/* turn r, g, b into a color */
	color = SDL_MapRGB(surface->format, r, g, b);

	/* set the pixel to a color */
	p = (Uint8 *)surface->pixels + y * surface->pitch +
	    x * surface->format->BytesPerPixel;
	*(Uint32 *)p = color;
}
void draw315(SDL_Surface *surface, int xpos, int ypos, float length)
{
	int x;
	int y;
	int i;
	int m;
	int b = 0;
	m = -1;
	for (x = 0; x <= length; x++)
	{
		y = m * x + b;
		setPixel(surface, x + xpos, -y + ypos, 50, 133, 190);
	}
}
void draw45(SDL_Surface *surface, int xpos, int ypos, float length)
{
	int x;
	int y;
	int i;
	int m;
	int b = 0;
	m = 1;
	for (x = 0; x <= length; x++)
	{
		y = m * x + b;
		setPixel(surface, x + xpos, -y + ypos, 50, 133, 190);
	}
}
void draw135(SDL_Surface *surface, int xpos, int ypos, float length)
{
	int x;
	int y;
	int i;
	int m;
	int b = 0;
	m = -1;
	for (x = 0; x <= length; x++)
	{
		y = m * x + b;
		setPixel(surface, -x + xpos, y + ypos, 50, 133, 190);
	}
}
void draw225(SDL_Surface *surface, int xpos, int ypos, float length)
{
	int x;
	int y;
	int i;
	int m;
	int b = 0;
	m = 1;
	for (x = 0; x <= length; x++)
	{
		y = m * x + b;
		setPixel(surface, -x + xpos, y + ypos, 50, 133, 190);
	}
}
void drawbranch(SDL_Surface *surface, int xpos, int ypos, int deg, int count,
		float length)
{
	unsigned y = 0;
	unsigned x = 0;
	float m;
	unsigned b = 0;
	int angle;
	float changeleng = 0;

	angle = deg;

	if (count > 8)
	{
		deg = 550;
	}
	count++;
	changeleng = .6666667;
	length = length * changeleng;
	if (deg == 0)
	{
		deg = 315;
		xpos = xpos + (length / changeleng);
		draw315(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		angle = 45;
		draw45(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}
	else if (deg == 45)
	{
		deg = 0;
		xpos = xpos + (length / changeleng);
		ypos = ypos - (length / changeleng);
		for (x = 0; x <= length; x++)
		{
			setPixel(surface, x + xpos, y + ypos, 50, 133, 190);
		}
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		angle = 90;
		x = 0;
		for (y = 0; y <= length; y++)
		{
			setPixel(surface, x + xpos, -y + ypos, 50, 133, 190);
		}
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}
	else if (deg == 90)
	{

		deg = 45;
		ypos = ypos - (length / changeleng);
		draw45(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		angle = 135;
		draw135(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}
	else if (deg == 135)
	{

		deg = 90;
		ypos = ypos - (length / changeleng);
		xpos = xpos - (length / changeleng);
		for (y = 0; y <= length; y++)
		{
			setPixel(surface, x + xpos, -y + ypos, 50, 133, 190);
		}
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		y = 0;
		angle = 180;
		for (x = 0; x <= length; x++)
		{
			setPixel(surface, -x + xpos, y + ypos, 50, 133, 190);
		}
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}
	else if (deg == 180)
	{

		deg = 135;
		xpos = xpos - (length / changeleng);

		draw135(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		angle = 225;
		draw225(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}
	else if (deg == 225)
	{
		deg = 180;
		ypos = ypos + (length / changeleng);
		xpos = xpos - (length / changeleng);
		for (x = 0; x <= length; x++)
		{
			setPixel(surface, -x + xpos, y + ypos, 50, 133, 190);
		}

		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		angle = 270;
		x = 0;
		for (y = 0; y <= length; y++)
		{

			setPixel(surface, x + xpos, y + ypos, 50, 133, 190);
		}
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}
	else if (deg == 270)
	{
		deg = 225;
		ypos = ypos + (length / changeleng);
		draw225(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		angle = 315;
		draw315(surface, xpos, ypos, length);
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}
	else if (deg == 315)
	{
		deg = 270;
		ypos = ypos + (length / changeleng);
		xpos = xpos + (length / changeleng);

		for (y = 0; y <= length; y++)
		{

			setPixel(surface, x + xpos, y + ypos, 50, 133, 190);
		}
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, deg, count, length);
		angle = 0;
		y = 0;
		for (x = 0; x <= length; x++)
		{
			setPixel(surface, x + xpos, y + ypos, 50, 133, 190);
		}
		SDL_UpdateTexture(texture, NULL, surface->pixels,
				  surface->pitch);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		drawbranch(surface, xpos, ypos, angle, count, length);
	}

	/* send the pixels to the texture buffer */
	SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);

	SDL_RenderCopy(renderer, texture, NULL,
		       NULL); /* copy the texture directly to the backbuffer */
}
void drawShape(SDL_Surface *surface)
{
	unsigned y;
	int x;
	unsigned m;
	unsigned b;

	int xpos;
	int ypos;

	xpos = 400;
	ypos = 450;

	y = m * x + b;

	for (y = 0; y < 100; y++)
	{
		for (x = 0; x < 1; x++)
		{
			setPixel(surface, x + xpos, y + ypos, 50, 133, 190);
			/* red 50,150,50 */
		}
	}

	/* send the pixels to the texture buffer */
	SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);

	/* copy the texture directly to the backbuffer */
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	drawbranch(surface, xpos, ypos + 100, 90, 0, 100);
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

void init()
{
	surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0x00FF0000,
				       0x0000FF00, 0x000000FF, 0xFF000000);
	if (surface == NULL)
	{
		fprintf(stderr, "Could not setup surface %s", SDL_GetError());
		exit(1);
	}

	/* enable the surface to be a renderable texture */
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		fprintf(stderr, "Could not setup texture %s", SDL_GetError());
		exit(1);
	}
}

/************************** YOUR PROGRAM ENDS HERE **************************/

void inputs()
{
	SDL_Event event;

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		exit(0);
		break;

	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
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

int main(int argc, char *argv[])
{
	int b;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Could not start SDL %s\n", SDL_GetError());
		exit(1);
	}

	atexit(SDL_Quit);

	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &screen, &renderer);

	init();

	/* clear screen to black */
	SDL_SetRenderDrawColor(renderer, 1, 0, 0, 0);
	SDL_RenderClear(renderer);

	
		step();

		/* avoid slamming the CPU */
		SDL_Delay(10);
	
	scanf("%d", &b);
	return 0;
}