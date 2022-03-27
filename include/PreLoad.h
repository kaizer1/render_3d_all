// Loskutnikov Games inc. 2022
 
#pragma once

#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <functional>

//#include <ASTC.h>

#include <glmain.h>


#define DEBUG_SOURCE_API                                 0x8246
#define DEBUG_SOURCE_WINDOW_SYSTEM                       0x8247
#define DEBUG_SOURCE_SHADER_COMPILER                     0x8248
#define DEBUG_SOURCE_THIRD_PARTY                         0x8249
#define DEBUG_SOURCE_APPLICATION                         0x824A
#define DEBUG_SOURCE_OTHER                               0x824B





#define DEBUG_TYPE_ERROR                                 0x824C
#define DEBUG_TYPE_DEPRECATED_BEHAVIOR                   0x824D
#define DEBUG_TYPE_UNDEFINED_BEHAVIOR                    0x824E
#define DEBUG_TYPE_PORTABILITY                           0x824F
#define DEBUG_TYPE_PERFORMANCE                           0x8250
#define DEBUG_TYPE_OTHER                                 0x8251
#define DEBUG_TYPE_MARKER                                0x8268


// my math 
#include <MatAndVectOperators.hpp>
#include <ASTC.h>

#include <stdlib.h>
//#include <unistd.h>

typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef   signed int    int32;
// TODO: Controllers 

//#include <xinput.h> 


inline uint32 Float32SubnormalToNormal(uint32 i)
{
    uint32 mantissa = i;
    uint32 exponent = 0;          // Zero exponent


    // Recall that a float represents a (base 2) binary number using scientific notation, which is of the format: MANTISSA x 2^(EXPONENT-EXP_BIAS).
    // So to represent the "normal" version of a "subnormal" float, where the exponent==0 AND mantissa!=0 indicates "subnormal" via IEEE float 754 specification,
    // we just need to make the exponent non-zero while still having the overall float value represent the same number..
    // We do this by subtracting

    // While not normalized..
    while(!(mantissa&0x00800000))
    {
        exponent -= 0x00800000;   // Decrement exponent (1<<23). This is the same as subtracting 1 from the 8bit mantissa, but in the context of a uint32 instead of a uint8.
        mantissa <<= 1;           // Left shift mantissa 1, which is multiplying by 2..
    }

    mantissa &= ~0x00800000;        // Clear first exponent bit
    exponent += 0x38800000;         // Adjust bias ((127-14)<<23)
    return (mantissa | exponent);   // Return finalized float including new mantissa and exponent
}

inline float HalfToFloat( uint16 bits )
{
    // This accounts for normal 2byte floats, but what about the special cases..
    uint32 ret = ((bits&0x8000)<<16) | (((bits&0x7c00)+0x1C000)<<13) | ((bits&0x03FF)<<13);
    // When exponent is zero: we're dealing with either +/- zero (when mantissa is also zero), OR subnormal values (when mantissa is also non-zero)
    // However zero exponents are handled by the above logic, and it also properly handles mantissas of any values.
    // When exponent is 31: we're dealing with either +/- infinity (when mantissa is also zero), OR NaN (Not a Number) (when mantissa is also non-zero)
    // For the case when the 5-bit exponent is 31, we're converting to an 8-bit exponent, and our logic will not expand the exponent to 255 like it needs to.

    // If the 2byte float (masking off the sign/mantissa bits) is equal to the mask for the exponent bits...
    if( (bits & 0x7c00) == 0x7c00)
    {  // Exponent==31 special case..
        ret|= 0x7F800000;    // Set the 8bits of the exponent for the 4 byte return value.
    }
    else if( 0 == (bits&0x7c00) && 0 != (bits&0x03FF)) // If 2byte float was a subnormal number...
    {
        // Return the normalized version of 4byte float, since operating on subnormal floating point numbers
        // will introduce "floating point drift" (loss of precision), after arithmetic, sooner..
        ret = Float32SubnormalToNormal(ret);
    }

    return *((float*)&ret);
}



 inline uint16 FloatToHalf( float v )
{
    uint32 src = *(uint32*)(&v);
    uint32 sign = src >> 31;   // Shifts on unsigned int types are always supposed to zero fill, is this the case for Mac, and Linux, etc. as well..
    uint16 ret;

    // Extract mantissa
    uint32 mantissa = src  &  (1 << 23) - 1;

    // extract & convert exp bits
    int32 exp = int32( src >> 23  &  0xFF ) - 127;
    if( exp > 15 )
    {
        // The largest-possible positive 2-byte-float exponent value would be 11110-01111 = 11110 = 15.
        exp = 15;
        mantissa = (1 << 23) - 1;
    }
    else if( exp < -14 )
    {
        // handle wraparound of shifts (done mod 64 on PPC)
        // All float32 denormal/0 values map to float16 0
        if( exp <= - 14 - 24 )
        {
            mantissa = 0;
        }
        else
        {
            mantissa = ( mantissa | 1 << 23 )  >>  (-exp - 14);
        }
        exp = -14;
    }
    // TODO: exp is a *signed* int, left shifting it could extend the signed bit,
    // will have to mask off the first bits where the mantissa should go.
    ret = (sign << 15)  |  ((uint16)(exp + 15)  << 10) |  (mantissa >> 13);
    return ret;
}



enum losFormatASTC : uint32_t {
    tenForsixe,
    tenForEight,
    tenForTen,
    tenForTenNotAlpha
};

typedef struct
{
    unsigned char  magic[4];
    unsigned char  blockdim_x;
    unsigned char  blockdim_y;
    unsigned char  blockdim_z;
    unsigned char  xsize[3];   /* x-size = xsize[0] + xsize[1] + xsize[2] */
    unsigned char  ysize[3];   /* x-size, y-size and z-size are given in texels */
    unsigned char  zsize[3];   /* block count is inferred */
} astc_header;

void LoadASTCImage(const char* name, losFormatASTC astcs, unsigned int* texutID);


struct aabbReturn
{
public:
    aabbReturn() = default;

    bool aabbExist = false;
    int sizes = 0;
};



struct lObject
{
public:


    lObject(float maX, float Xmi, float Yma7, float Ymi, float Zma, float Zmi)
            : xmin{Xmi}, xmax {maX}, ymin{Ymi}, ymax{Yma7}, zmin{Zmi}, zmax{Zma}, levels{0}
    { }



    lObject()
    {
        xmin = 0.0f;
        xmax = 0.0f;

        ymin = 0.0f;
        ymax = 0.0f;

        zmax = 0.0f;
        zmin = 0.0f;

        seeMinimum = false;

        //mMatrix = identity();
    }

    ~ lObject(){
        xmin = 0.0f;
        xmax = 0.0f;

        ymin = 0.0f;
        ymax = 0.0f;

        zmax = 0.0f;
        zmin = 0.0f;
    }




    bool interAABB(lObject& objectAnotjer)
    {

        if(this->xmin >= objectAnotjer.xmax || objectAnotjer.xmin >= this->xmax)
              return false;

        // printf(" ok is \n");
        // printf("this->losMesh->ymin= %f otherObject.losMesh->ymax= %f otherObject.losMesh->ymin= %f this->losMesh->ymax= %f \n", this->losMesh->ymin, otherObject.losMesh->ymax, otherObject.losMesh->ymin, this->losMesh->ymax);

        if(this->ymin >= objectAnotjer.ymax || objectAnotjer.ymin >= this->ymax)
            return false;

        //printf(" ok is 2 \n");

        if(this->zmin >= objectAnotjer.zmax || objectAnotjer.zmin >= this->zmax)
            return false;

        //(" intersection ! \n");
        return true;
    }


    bool isEarth(lObject& llobj)
    {

        if(this->ymin <= llobj.ymax)
            return true;


        return false;
    }


    int aConnectSize(lObject& llobj) noexcept {
         if(this->xmin <= llobj.xmax)
             return 1;

         if(this->xmax <= llobj.xmin)
             return 2;


        if(this->zmin <= llobj.zmax)
            return 3;

        if(this->zmax <= llobj.zmin)
            return 4;


         return 0;
    }



    float xmin;
    float xmax;

    float ymin;
    float ymax;

    float zmin;
    float zmax;

    bool seeMinimum;

    LosMatrix4_4 mMatrix;

    int levels;
    LosVector3 vecColor;
    LosVector3 transFormVector;

    const LosVector3& transBack() const
    {
        return transFormVector;
    }


    LosVector4 oneF;
    LosVector4 twoF;
    LosVector4 threeF;
    LosVector4 fourF;
    LosVector4 fiveF;
    LosVector4 sixF;
    LosVector4 sevenF;
    LosVector4 eightF;


    aabbReturn aStruct;

private:

};




struct LosModel
{
    LosModel() :  texID{0}, vao{0}, drawIndexs{0}, name{nullptr}, PhysLos{false}, removably{false}
    {

    }

    ~ LosModel() = default;

    GLuint texID;
    GLuint vao;
    unsigned int drawIndexs;
    lObject object;
    LosVector3 transVector;

    std::function<void(void)> alFunction;
    const char* name;

    bool PhysLos;
    bool removably;
};


class PreLoad {

 
   public: 
   	   PreLoad();
   	   ~PreLoad();


       void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
       void loadDDSTexture(const char* name, unsigned int* texutID);
       bool InstallWindow(HINSTANCE hInstance, int nCmdShow);
       const void QuitToApp() const noexcept;
       const void CallingLoadingExtension() const noexcept;
       void PreRender();
       const bool LoadingOpenGLPrograms(int w, int h, HDC cinte);
       const void setHWND(HWND* hwnds);
       void TriangleActive( bool activeTriangles);
       void RotateEnable();


 private: 

   bool waitOrNorToExitConsole = true;
   bool loadingAllElements = false;
   void MainRender() noexcept;
  const void loadMyMatrix() const noexcept;
  HDC mainContext;
  HWND *hwndLos = nullptr;
  GLuint  loadGLShader(GLenum enumsha, const char* shaderSource );
  GLuint  loadGLShaderRes(GLenum enumsha, const char* shaderSource );
  void Loaded3DStaticModel(LosModel& model, const char* nameModel, bool vaos); 
  void  LinkProgramLos(GLuint program);
  void LoadASTCImage(const char* name, losFormatASTC astcs, unsigned int* texutID);
  void callChange() noexcept;


  GLuint VAo_toSimpleProgram;
  GLuint simpleProgram;

  int32_t  mainWidth, mainHeight;

  GLuint testRecrangleProgram;
  GLuint matrixTestRect;
  float rotateY;
  //LosMatrix4_4 pers, LookAt;
  LosModel testRec;

  GLuint l3DViewProgram;
  LosModel main3DObjects;
  bool drawTriangles = true;
  bool rotateYes = false;


 GLuint matrix3dModelView, matrix3dPositionView, vLight,vCam; 
 GLuint swordID, samplerSword;
 
  };  