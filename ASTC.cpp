// Loskutnikov Games inc. 2022

//#include "ASTC.h"
//#include <GL/GL.h>
//#include <filesystem>
namespace fs = std::filesystem;

static const int OFFSEtF = 0;

enum textureFormat {
    kformatDefaultAuto = 0,
    kFormat5551,
    kFormat565,

    webpk8888,
    webpk888,
};




void LoadASTCImage(const char* name,losFormatASTC astcs, unsigned int* texutID)
{
    //unsigned char* buffer_forLosImage = NULL;
 

 
  // filesystem 

   std::cout << "Current path is " << fs::current_path() << '\n'; 

   // std::string filename = "C:\\Users\\loskutnikov\\Desktop\\cpp\\Out\\Values.bin";
   //  std::ifstream is (filename, std::ifstream::binary);
      

   //  is.seekg (0, is.end);
   //  int length = is.tellg();
   //  is.seekg (0, is.beg);
 


    //AAssetManager *mgrLok = backAssetMan();
    //AAsset* assetImage = AAssetManager_open(mgrLok, name, AASSET_MODE_STREAMING); // was AASSET_MODE_STREAMING // AASSET_MODE_BUFFER
    

    //size_t nSizeImageLos = AAsset_getLength(assetImage);

    //unsigned char* buffer_forLosImage = (unsigned char*)calloc(nSizeImageLos, sizeof(unsigned char));

   // buffer_forLosImage = new unsigned char[nSizeImageLos]; // was  nSizeImageLos + 1]

   // AAsset_read(assetImage, buffer_forLosImage, nSizeImageLos);

   // AAsset_close(assetImage);

   //  unsigned int n_bytes_to_read = 0;
   //  int xblocks = 0;
   //  int yblocks = 0;
   //  int zblocks = 0;

   //  /* Number of bytes for each dimension. */
   //  int xsize = 0;
   //  int ysize = 0;
   //  int zsize = 0;

   //  astc_header* astc_data_ptr = (astc_header*) buffer_forLosImage;

   //  /* Merge x,y,z-sizes from 3 chars into one integer value. */
   //  xsize = astc_data_ptr->xsize[0] + (astc_data_ptr->xsize[1] << 8) + (astc_data_ptr->xsize[2] << 16);
   //  ysize = astc_data_ptr->ysize[0] + (astc_data_ptr->ysize[1] << 8) + (astc_data_ptr->ysize[2] << 16);
   //  zsize = astc_data_ptr->zsize[0] + (astc_data_ptr->zsize[1] << 8) + (astc_data_ptr->zsize[2] << 16);

   //  /* Compute number of blocks in each direction. */
   //  xblocks = (xsize + astc_data_ptr->blockdim_x - 1) / astc_data_ptr->blockdim_x;
   //  yblocks = (ysize + astc_data_ptr->blockdim_y - 1) / astc_data_ptr->blockdim_y;
   //  zblocks = (zsize + astc_data_ptr->blockdim_z - 1) / astc_data_ptr->blockdim_z;

   //  /* Each block is encoded on 16 bytes, so calculate total compressed image data size. */
   //  n_bytes_to_read = xblocks * yblocks * zblocks << 4;

   //  /* We now have file contents in memory so let's fill a texture object with the data. */
   //  (glGenTextures(1, texutID));
   //  (glBindTexture(GL_TEXTURE_2D, *texutID));

   //   //         BIG versus стрелочка вниз !
   //   //  GL_COMPRESSED_RGBA_ASTC_10x8_KHR  or GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR
   //  GLenum compressed_data_internal_format;

   //  switch (astcs)
   //  {
   //      case  tenForsixe:
   //          compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR;
   //          break;

   //      case tenForEight:
   //          compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
   //          break;

   //      case tenForTen:
   //          compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR;
   //          break;

   //      case   tenForTenNotAlpha:
   //          compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x10_KHR;
   //          break;


   //       default:
   //           compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR;
   //         break;
   //  }


   // // GLenum compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
   //  /* Upload texture data to ES. */
   //  (glCompressedTexImage2D(GL_TEXTURE_2D,
   //                                  0,
   //                                  compressed_data_internal_format,
   //                                  xsize,
   //                                  ysize,
   //                                  0,
   //                                  n_bytes_to_read,
   //                                  (const GLvoid*)&astc_data_ptr[1]));

   //  (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
   //  (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
   //  (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT));
   //  (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT));

   //  /* Unbind texture from target. */
   //  (glBindTexture(GL_TEXTURE_2D, 0));

}