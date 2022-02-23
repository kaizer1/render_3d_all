// Loskutnikov Games inc. 2022

#include <map>


/* ASTC texture compression internal formats. */
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR            (0x93B0)
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR            (0x93B1)
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR            (0x93B2)
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR            (0x93B3)
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR            (0x93B4)
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR            (0x93B5)
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR            (0x93B6)
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR            (0x93B7)
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR           (0x93B8)
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR           (0x93B9)
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR           (0x93BA)
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR          (0x93BB)
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR          (0x93BC)
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR          (0x93BD)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR    (0x93D0)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR    (0x93D1)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR    (0x93D2)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR    (0x93D3)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR    (0x93D4)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR    (0x93D5)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR    (0x93D6)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR    (0x93D7)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR   (0x93D8)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR   (0x93D9)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR   (0x93DA)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR  (0x93DB)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR  (0x93DC)
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR  (0x93DD)


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