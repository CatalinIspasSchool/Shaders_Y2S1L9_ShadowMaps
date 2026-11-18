// Application.h
#ifndef _APP1_H
#define _APP1_H

// Includes
#include "DXF.h"	// include dxframework
#include "TextureShader.h"
#include "ShadowShader.h"
#include "DepthShader.h"
#include <chrono>

class App1 : public BaseApplication
{
public:

	App1();
	~App1();
	void init(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight, Input* in, bool VSYNC, bool FULL_SCREEN);

	bool frame();

protected:
	bool render();
	void depthPass();
	void finalPass();
	void gui();

private:
	TextureShader* textureShader;
	PlaneMesh* mesh;
	CubeMesh* cube;
	SphereMesh* sphere;
	SphereMesh* lightSphere;

	Light* light;
	AModel* model;
	ShadowShader* shadowShader;
	DepthShader* depthShader;
	OrthoMesh* depthOrthoMesh;
	RenderTexture* depthRenderTexture;

	ShadowMap* shadowMap;

	std::chrono::steady_clock::time_point startTime;
	std::chrono::milliseconds duration;

	XMFLOAT3* lightDirection;
	XMFLOAT3* lightPosition;
};

#endif