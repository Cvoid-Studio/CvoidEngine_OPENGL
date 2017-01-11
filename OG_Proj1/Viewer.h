#pragma once
class CVA_Camera
{
public:
	CVA_Camera();
	~CVA_Camera();

	bool SetCamera(float eyex, float eyey, float eyez,
		float Tox, float Toy, float Toz);
private:

};

CVA_Camera::CVA_Camera()
{
}

CVA_Camera::~CVA_Camera()
{
}
//----------------------------------------------------//
/*					Class Realization				  */
//----------------------------------------------------//

bool CVA_Camera::SetCamera(float eyex, float eyey, float eyez,
	float Tox, float Toy, float Toz)
{
	return true;
}