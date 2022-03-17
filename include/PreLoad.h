// Loskuntikov Games inc. 2022
 
#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <functional>

#ifdef OPENGL_VARIANT
//#include <ASTC.h>
// #include <GL/GL.h>
// #include <GL/glext.h>

#include <glmain.h>
//#include <glad.h>

#endif


// my math 
#include <MatAndVectOperators.hpp>

// TODO: Controllers 

//#include <xinput.h> 




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
   	 void callMainBuildWindow() noexcept; 
       bool InstallWindow(HINSTANCE hInstance, int nCmdShow);
       const void QuitToApp() const noexcept;
       const void CallingLoadingExtension() const noexcept;
        void PreRender();
       const bool LoadingOpenGLPrograms(int w, int h, HDC cinte);
       const void setHWND(HWND* hwnds);


 private: 

   bool waitOrNorToExitConsole = true;
   bool loadingAllElements = false;
   void MainRender() noexcept;
  const void loadMyMatrix() const noexcept;
  HDC mainContext;
  HWND *hwndLos = nullptr;
  GLuint  loadGLShader(GLenum enumsha, const char* shaderSource );
  GLuint  loadGLShaderRes(GLenum enumsha, const char* shaderSource );
  void  LinkProgramLos(GLuint program);
  void callChange() noexcept;

  GLuint VAo_toSimpleProgram;
  GLuint simpleProgram;

  int32_t  mainWidth, mainHeight;

  GLuint testRecrangleProgram;
  GLuint matrixTestRect;
  float rotateY;
  //LosMatrix4_4 pers, LookAt;
  LosModel testRec;
  };  