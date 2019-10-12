#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
float * rotationaroundpoint(float x0, float y0, float x1, float y1, float deg, int f, float x, float y);
float * translation(float x0, float y0, float x1, float y1, float tx, float ty, int f);

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

float ran(int max, int min)
{
float number = 0; 
time_t seconds;
	
seconds = time(NULL);
srand(seconds);


number = (rand() % (max + 1 - min) + min);

return number;
}

void drawlinelow(SDL_Surface *surface, int x0, int y0,int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int d = 2*dy - dx;
	int y = y0;
	int i;
	for(i=x0; i<x1; i++)
	{
		
	setPixel(surface, i, y, 50, 150, 50);
	if(d > 0)
	{
		y = y + yi;
		d=d-2*dx;
	}
	d = d + 2*dy;
	}

	
}

void drawlinehigh(SDL_Surface *surface, int x0, int y0,int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int d = 2*dx - dy;
	int x = x0;
	int i;
	for(i=y0; i<y1; i++)
	{
		
	setPixel(surface, x, i, 50, 150, 50);
	if(d > 0)
	{
		x = x + xi;
		d=d-2*dy;
	}
	d = d + 2*dx;
	}

	
}
void drawliner(float x0, float y0,float x1, float y1)
{
	
	if(abs(y1-y0) < abs(x1-x0))
		{
			if(x0 > x1)
			{
				drawlinelow(surface, x1, y1,x0,y0);
			}
			else
			{
				drawlinelow(surface, x0,y0,x1,y1);
			}
		}
		else
		{
			if(y0 > y1)
			{
				drawlinehigh(surface,x1,y1,x0,y0);
			}
			else
			{
				drawlinehigh(surface,x0,y0,x1,y1);
			}
		}
}

float *multiply(float matrix[3][3], float vector[3])
{
	
	static float svector[3];
	
	svector[0] = (matrix[0][0] * vector[0]) + (matrix[0][1] * vector[1]) + (matrix[0][2] * vector[2]);
	svector[1]= (matrix[1][0] * vector[0]) + (matrix[1][1] * vector[1]) + (matrix[1][2] * vector[2]);
	svector[2]= (matrix[2][0] * vector[0]) + (matrix[2][1] * vector[1]) + (matrix[2][2] * vector[2]);
	
	return svector;
}

float* scaling(float x0, float y0, float x1, float y1, float scalex,float scaley)
{
	float scalingm[3][3];
	float vector[3];
	float static final[4];
	float *p;
	float *r;
	float tx;
	float ty;

	scalingm[0][0]= scalex;		scalingm[0][1]= 0;			scalingm[0][2]= 0;
	scalingm[1][0]= 0;			scalingm[1][1]= scaley;		scalingm[1][2]= 0;
	scalingm[2][0]= 0;			scalingm[2][1]= 0;			scalingm[2][2]= 1;
	
	
	vector[0] = x1;
	vector[1] = y1;
	vector[2] = 1;
	tx = x0;
	ty= y0;
	r = translation(x0,y0,x1,y1,-tx,-ty,2);
	
	x0 = *r;
	x1 = *(r+1);
	y0 = *(r+2);
	y1 = *(r+3);
	vector[0] = x1;
	vector[1] = y1;
	vector[2] = 1;
	r= multiply(scalingm,vector);
	x1 = *r;
	y1 = *(r+1);
	r = translation(x0,y0,x1,y1,tx,ty,2);
	x0 = *r;
	x1 = *(r+1);
	y0 = *(r+2);
	y1 = *(r+3);
	
	
	final[0] = x0;
	final[1] = x1;
	final[2] = y0;
	final[3] = y1;
	
	return final;
}
float* rotationaroundorigin(float x0, float y0, float x1, float y1, float deg, int f)
{
	float rotationm[3][3];
	float vector[3];
	
	float *p;
	float *r;
	float static final[4];
	
	if(f == 2)
	{
		rotationm[0][0]= cos((deg * (M_PI/180)));	rotationm[0][1]= -sin((deg * (M_PI/180)));	rotationm[0][2]= 0;
		rotationm[1][0]= sin((deg * (M_PI/180)));	rotationm[1][1]= cos((deg * (M_PI/180)));	rotationm[1][2]= 0;
		rotationm[2][0]= 0;			rotationm[2][1]= 0;			rotationm[2][2]= 1;
		
		vector[0] = x0;
		vector[1] = y0;
		vector[2] = 1;
		
		p = multiply(rotationm,vector);
		x0= *p;
		y0= *(p+1);
		vector[0] = x1;
		vector[1] = y1;
		vector[2] = 1;
		r= multiply(rotationm,vector);
		x1=*r;
		y1=*(r+1);
		
		
	
	final[0] = x0;
	final[1] = x1;
	final[2] = y0;
	final[3] = y1;
	
	return final;
	}
	else
	{
		rotationm[0][0]= cos((deg * (M_PI/180)));	rotationm[0][1]= -sin((deg * (M_PI/180)));	rotationm[0][2]= 0;
		rotationm[1][0]= sin((deg * (M_PI/180)));	rotationm[1][1]= cos((deg * (M_PI/180)));	rotationm[1][2]= 0;
		rotationm[2][0]= 0;			rotationm[2][1]= 0;			rotationm[2][2]= 1;
		
		vector[0] = x0;
		vector[1] = y0;
		vector[2] = 1;
		
		p = multiply(rotationm,vector);
		x0= *p;
		y0= *(p+1);
		
		
	
	final[0] = x0;
	final[2] = y0;
	
	
	return final;
	}
}
float* rotationaroundpoint(float x0, float y0, float x1, float y1, float deg, int f, float x, float y)
{
	float rotationm[3][3];
	float vector[3];
	float point[3];
	float newpoint[3];
	float *p;
	float *r;
	float *m;
	float static final[4];
	
	if (f ==2)
	{
		rotationm[0][0]= cos((deg * (M_PI/180)));	rotationm[0][1]= -sin((deg * (M_PI/180)));	rotationm[0][2]= 0;
		rotationm[1][0]= sin((deg * (M_PI/180)));	rotationm[1][1]= cos((deg * (M_PI/180)));	rotationm[1][2]= 0;
		rotationm[2][0]= 0;			rotationm[2][1]= 0;			rotationm[2][2]= 1;
		
		vector[0] = x0;
		vector[1] = y0;
		vector[2] = 1;
		point[0]=x;
		point[1]= y;
		point[2]=1;
		
		newpoint[0]= vector[0]-point[0];
		newpoint[1]=vector[1]-point[1];
		
		m = multiply(rotationm,newpoint);
		x0 = *m+x;
		y0 = *(m+1) + y;
		
		vector[0] = x1;
		vector[1] = y1;
		vector[2] = 1;
		point[0]=x;
		point[1]= y;
		point[2]=1;
		
		newpoint[0]= vector[0]-point[0];
		newpoint[1]=vector[1]-point[1];
		
		m = multiply(rotationm,newpoint);
		x1 = *m+x;
		y1 = *(m+1) + y;
		

		final[0] = x0;
	final[1] = x1;
	final[2] = y0;
	final[3] = y1;
	
	return final;
	}
	else
	{
		rotationm[0][0]= cos((deg * (M_PI/180)));	rotationm[0][1]= -sin((deg * (M_PI/180)));rotationm[0][2]= 0;
		rotationm[1][0]= sin((deg * (M_PI/180)));	rotationm[1][1]= cos((deg * (M_PI/180)));	rotationm[1][2]= 0;
		rotationm[2][0]= 0;											rotationm[2][1]= 0;											rotationm[2][2]= 1;
		
		vector[0] = x0;
		vector[1] = y0;
		vector[2] = 1;
		point[0]  = x;
		point[1]= y;
		point[2]=1;
		
		newpoint[0]= vector[0]-point[0];
		newpoint[1]=vector[1]-point[1];
		setPixel(surface,x,y,255,0,0);
		m = multiply(rotationm,newpoint);
		x0 = *m+x;
		y0 = *(m+1) + y;
		
		setPixel(surface,x0,y0,0,255,0);
		
		final[0] = x0;
	
	final[2] = y0;
	
	
	return final;
	}
}
float* translation(float x0, float y0, float x1, float y1, float tx, float ty, int f)
{
	float translationm[3][3];
	float vector[3];
	float *p;
	float *r;
	float static final[4];
	
	if (f == 2)
	{
		translationm[0][0]= 1;	translationm[0][1]= 0;	translationm[0][2]= tx;
		translationm[1][0]= 0;	translationm[1][1]= 1;	translationm[1][2]= ty;
		translationm[2][0]= 0;	translationm[2][1]= 0;	translationm[2][2]= 1;
		
		vector[0] = x0;
		vector[1]=y0;
		vector[2]=1;
		
		p = multiply(translationm,vector);
		
		
		
		x0= *p;
		y0= *(p+1);
		vector[0] = x1;
		vector[1] = y1;
		r= multiply(translationm,vector);
		x1=*r;
		y1=*(r+1);
		
		
		
		final[0] = x0;
	final[1] = x1;
	final[2] = y0;
	final[3] = y1;
	
	return final;
	}
	else
	{
		translationm[0][0]= 1;	translationm[0][1]= 0;	translationm[0][2]= tx;
		translationm[1][0]= 0;	translationm[1][1]= 1;	translationm[1][2]= ty;
		translationm[2][0]= 0;	translationm[2][1]= 0;	translationm[2][2]= 1;
		
		vector[0] = x0;
		vector[1]=y0;
		vector[2]=1;
		
		p = multiply(translationm,vector);
		
		
		
		x0= *p;
		y0= *(p+1);
		
		setPixel(surface,x0,y0,0,255,0);
		
		final[0] = x0;
	
	final[2] = y0;
	
	
	return final;
	}
	}
void drawy(float x0,float x1,float y0,float y1, float scale, int i)
{
float * cord;
int deg = 0;
i++;
time_t seconds;
	
seconds = time(NULL);
srand(seconds);



if(i >= 12)
{
	
	return;
}
fflush(stdout);

deg = ran(165, 105);
	cord = rotationaroundpoint(x0,y0,x1,y1,deg,2,x1,y1);//135
	x1 = *cord;
	x0 = *(cord+1);
	y1 = *(cord+2);
	y0 = *(cord+3); 
	//scale=ran(.8,.5);
	cord = scaling(x0,y0,x1,y1,scale,scale);
	x0 = *cord;
	x1 = *(cord+1);
	y0 = *(cord+2);
	y1 = *(cord+3);
	drawliner(x0,y0,x1,y1);
	drawy(x0,x1,y0,y1,scale, i);
	deg = ran(120, 60);
	cord = rotationaroundpoint(x0,y0,x1,y1,90,2,x0,y0);//90
	x0 = *cord;
	x1 = *(cord+1);
	y0 = *(cord+2);
	y1 = *(cord+3); 
	drawliner(x0,y0,x1,y1);
	drawy(x0,x1,y0,y1,scale, i);
	
}
void drawShape(SDL_Surface *surface)
{
	unsigned y = 0;
	int x = 0;
	unsigned m;
	unsigned b;
	float *cord;
	int xpos;
	int ypos;

	float x0,y0,x1,y1;
	x0 = 400;
	x1=400;
	y0=600;
	y1=500;
	drawliner(x0,y0,x1,y1);
	drawy(x0,x1,y0,y1,.666,0);
	
	//y = m * x + b;
//setPixel(surface, x + xpos, y + ypos, 50, 133, 190);
	
fflush(stdout);
printf("\ntre" );
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
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
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

	while(1)
	{
		
	
		step();

		/* avoid slamming the CPU */
		SDL_Delay(10);
	}
	
	return 0;
}