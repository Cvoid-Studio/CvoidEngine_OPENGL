#pragma once
// ======================================== //
//			CV Geometric Objects			//
// ======================================== //
namespace CV_Obj_List
{
	typedef enum Geometric_Object_Type
	{
		Point = 0,
		Line = 1,
		Brezier = 2,
		Triangle = 3,
		Rect = 4,
		Polygon = 5,
		//-----------//
		Grid2D = 6,
		//-----------//
		Cube = 7,
		Sphere = 8,
		Cylinder = 9,
		Torus = 10,
		Tube = 11,
		//...

		None = 50
	}CV_Obj_Type;
}


typedef struct CV_Point
{
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
} Point;

