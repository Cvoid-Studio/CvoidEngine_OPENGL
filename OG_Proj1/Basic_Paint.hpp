#pragma once
#include "ObjType.h"

struct PixelInfo
{
	int R;
	int G;
	int B;
	float A;
};

/* -----------------------------------------------
-- Set object by			<Geometric_Object>
-- Paint at each frame		<Paint>
----------------------------------------------- */

/* =====================================================
........................................................
					Geometric Painting
........................................................
===================================================== */
//----------------------------------------------------//
/*					Class Definition				  */
//----------------------------------------------------//
typedef class Geometric_Object
{
public:
	// set Vertices //
	Geometric_Object();
	~Geometric_Object();
	Geometric_Object(CV_Obj_List::CV_Obj_Type Type, Point Vertices[]);

	// set color and Texture //
	void SetColor(int R, int G, int B);
	void SetColor(int R, int G, int B, int index[]);
	void SetColor(int R, int G, int B, float A);
	void SetColor(int R, int G, int B, float A, int index[]);

	void SetTexture(char* filename, float A);

	// Final Paint //
	void Paint(Point Position);

private:
	CV_Obj_List::CV_Obj_Type	ObjType;
	
	unsigned int Num_Vertices;
	unsigned int Num_Faces;

	Point*		 Vertices;

} BasicObj;

//----------------------------------------------------//
/*					Class Realization				  */
//----------------------------------------------------//
Geometric_Object::Geometric_Object()
{
	Vertices = 0;
	Num_Vertices = 0;
	Vertices = new(Point);
	ObjType = CV_Obj_List::None;
}

Geometric_Object::~Geometric_Object()
{
	delete Vertices;
	Vertices = 0;
}

Geometric_Object::Geometric_Object(CV_Obj_List::CV_Obj_Type Type, Point Vertices[])
{
	Vertices = 0;
	ObjType = Type;

	switch (ObjType)
	{
		//-----------------------------------//
	case 0:			//Point
		Num_Vertices = 1;
		Vertices = new(Point);
		break;
		//-----------------------------------//
	case 1:			//Line
		Num_Vertices = 2;
		Vertices = new(Point[2]);
		break;
		//-----------------------------------//
	case 2:			//Brezier
		Num_Vertices = sizeof(Vertices) / sizeof(Point);
		Vertices = new(Point[Num_Vertices]);
		break;
		//-----------------------------------//
	case 3:			//Triangle
		Vertices = new(Point[3]);
		break;
		//-----------------------------------//
	case 4:			//Rect
		Vertices = new(Point[4]);
		break;
		//-----------------------------------//
	case 5:			//Polygon
		Num_Vertices = sizeof(Vertices) / sizeof(Point);
		Vertices = new(Point[Num_Vertices]);
		break;
		//-----------------------------------//
	case 6:			//Grid2D
		Num_Vertices = sizeof(Vertices) / sizeof(Point);
		Vertices = new(Point[Num_Vertices]);
		break;
		//-----------------------------------//
	default:
		Num_Vertices = 0;
		Vertices = new(Point);
		break;
	}
}


void Geometric_Object::SetColor(int R, int G, int B)
{
}

void Geometric_Object::SetColor(int R, int G, int B, int index[])
{
}

void Geometric_Object::SetColor(int R, int G, int B, float A)
{
}

void Geometric_Object::SetColor(int R, int G, int B, float A, int index[])
{
}

void Geometric_Object::SetTexture(char * filename, float A)
{
}


void Geometric_Object::Paint(Point Position)
{

}