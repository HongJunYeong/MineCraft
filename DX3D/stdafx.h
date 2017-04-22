// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

// >> : 
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <assert.h>

using namespace std;

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND	g_hWnd;
#define SAFE_RELEASE(p) { if(p) p->Release(); p = NULL; }
#define SAFE_DELETE(p) {if(p) delete p; p = NULL;}

#define SINGLETONE(class_name)\
   private : \
      class_name(void); \
      ~class_name(void); \
   public : \
      static class_name* GetInstance() \
      {\
         static class_name instance;\
         return &instance;\
      }

struct ST_PC_VERTEX
{
	ST_PC_VERTEX(float x, float y, float z)
	{
		p.x = x;
		p.y = y;
		p.z = z;
		c = D3DCOLOR_XRGB(255, 255, 255);
	}
	D3DXVECTOR3 p;
	D3DCOLOR	c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE};
};

struct ST_PNT_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR3	n;
	D3DXVECTOR2 t;

	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };
};

#define SYNTHESIZE(varType, varName, funName)\
private: varType varName;\
public: inline varType Get##funName(void) const { return varName; }\
public: inline void Set##funName(varType var) { varName = var; }

#include "cDeviceManager.h"
// << 

//struct Normal_Tex_Vertex
//{
//	Normal_Tex_Vertex(float _x, float _y,float _z ,
//		/*float _nx,float _ny,float _nz,*/
//		float _u, float _v)
//	{
//		x = _x; y = _y; z = _z;
//		/*nx = _nx; ny = _ny; nz = _nz;*/
//		u = _u; v = _v;
//	}
//	float x, y, z;
//	/*float nx, ny, nz;*/
//	float u, v;
//	enum { FVF = D3DFVF_XYZ | /*D3DFVF_NORMAL |*/D3DFVF_TEX1};
//};